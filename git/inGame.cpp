#include "stdafx.h"
#include "inGame.h"



inGame::inGame()
{
}


inGame::~inGame()
{
}

HRESULT inGame::init()
{
	map = new Map;
	map->init();
	_player1 = new player1;
	_player2 = new player2;
	_player1->init();
	_player2->init();
	_object = new object;
	_object->init();
	
	outButton = RectMake(648, 563, 140, 30);


	IMAGEMANAGER->addImage("인게임화면", "image/Scene/map.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	return S_OK;
}

void inGame::release()
{
	SAFE_DELETE(map);
	SAFE_DELETE(_player1);
	SAFE_DELETE(_player2);
}

void inGame::update()
{
	map->update();
	_object->update();
	Objectdelete();
	ItemEat();
	playerDie();
	_player1->update();
	_player2->update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if ((m_ptMouse.x > outButton.left&&m_ptMouse.x < outButton.right) && (m_ptMouse.y > outButton.top&&m_ptMouse.y < outButton.bottom))
		{
			SCENEMANAGER->changeScene("게임레디화면");
		}
	}
}

void inGame::render()
{


	IMAGEMANAGER->render("인게임화면", getMemDC());;
	map->render();
	_object->render();
	_player1->render();
	_player2->render();




}

void inGame::playerDie()
{
	//상대방 풍선에 죽는 플레이어1
	for (int i = 0; i < _player2->_player_2.bombNumber; i++)
	{
		RECT temp;
		if (_player2->player2_bomb->getVbomb2()[i].boom2
			&& (IntersectRect(&temp, &_player1->_player_1.player1, &_player2->player2_bomb->getVbomb2()[i].boomRight_rc2) ||
				IntersectRect(&temp, &_player1->_player_1.player1, &_player2->player2_bomb->getVbomb2()[i].boomLeft_rc2) ||
				IntersectRect(&temp, &_player1->_player_1.player1, &_player2->player2_bomb->getVbomb2()[i].boomUp_rc2) ||
				IntersectRect(&temp, &_player1->_player_1.player1, &_player2->player2_bomb->getVbomb2()[i].boomDown_rc2) ||
				IntersectRect(&temp, &_player1->_player_1.player1, &_player2->player2_bomb->getVbomb2()[i].boomCenter_rc2)
				))
		{
			_player1->_player_1._player1_Live = false;
		}
	}

	//상대방 풍선에 죽는 플레이어2
	for (int i = 0; i < _player1->_player_1.bombNumber; i++)
	{
		RECT temp;
		if (_player1->player1_bomb->getVbomb()[i].boom
			&& (IntersectRect(&temp, &_player2->_player_2.player2, &_player1->player1_bomb->getVbomb()[i].boomRight_rc) ||
				IntersectRect(&temp, &_player2->_player_2.player2, &_player1->player1_bomb->getVbomb()[i].boomLeft_rc) ||
				IntersectRect(&temp, &_player2->_player_2.player2, &_player1->player1_bomb->getVbomb()[i].boomUp_rc) ||
				IntersectRect(&temp, &_player2->_player_2.player2, &_player1->player1_bomb->getVbomb()[i].boomDown_rc) ||
				IntersectRect(&temp, &_player2->_player_2.player2, &_player1->player1_bomb->getVbomb()[i].boomCenter_rc)))
		{
			_player2->_player_2._player2_Live = false;
		}
	}
	if (!_player1->_player_1._player1_Live && !_player1->_player_1._player1_Die)
	{
		RECT temp;
		if (IntersectRect(&temp, &_player1->_player_1.player1, &_player2->_player_2.player2))
		{
			_player1->_player_1._player1_Die = true;
		}

	}
	if (!_player2->_player_2._player2_Live && !_player2->_player_2._player2_Die)
	{
		RECT temp;
		if (IntersectRect(&temp, &_player2->_player_2.player2, &_player1->_player_1.player1))
		{
			_player2->_player_2._player2_Die = true;
		}

	}
}

void inGame::Objectdelete()
{
	auto& objectVector = _object->getobj();
	auto& player1Bombvector = _player1->player1_bomb->getBombVector();
	auto& player2Bombvector = _player2->player2_bomb->getBombVector2();

	for (auto bomb = player1Bombvector.begin(); bomb != player1Bombvector.end(); ++bomb)
	{
		RECT temp;
		if (bomb->boom)
		{
			for (auto object = objectVector.begin(); object != objectVector.end(); )
			{

				if (IntersectRect(&temp, &object->_object, &bomb->boomRight_rc))
				{
					object = objectVector.erase(object);

				}
				if (IntersectRect(&temp, &bomb->boomDown_rc, &object->_object))
				{
					object = objectVector.erase(object);

				}
				if (IntersectRect(&temp, &bomb->boomUp_rc, &object->_object))
				{
					object = objectVector.erase(object);

				}
				if (IntersectRect(&temp, &bomb->boomLeft_rc, &object->_object))
				{
					object = objectVector.erase(object);

				}


				else ++object;
			}
		}
	}




	for (auto bomb2 = player2Bombvector.begin(); bomb2 != player2Bombvector.end(); ++bomb2)
	{
		if (bomb2->boom2)
		{
			for (auto object = objectVector.begin(); object != objectVector.end(); )
			{
				RECT temp;

				if (IntersectRect(&temp, &bomb2->boomLeft_rc2, &object->_object))
				{
					object = objectVector.erase(object);

				}

				if (IntersectRect(&temp, &bomb2->boomRight_rc2, &object->_object))
				{
					object = objectVector.erase(object);

				}
				if (IntersectRect(&temp, &bomb2->boomUp_rc2, &object->_object))
				{
					object = objectVector.erase(object);

				}

				if (IntersectRect(&temp, &bomb2->boomDown_rc2, &object->_object))
				{
					object = objectVector.erase(object);

				}
				else ++object;
			}
		}
	}



}
void inGame::ItemEat()
{
	auto& itemVector = _object->getitem();
	auto& player1Bombvector = _player1->player1_bomb->getBombVector();
	auto& player2Bombvector = _player2->player2_bomb->getBombVector2();

	for (auto item = itemVector.begin(); item != itemVector.end();)
	{
		RECT temp;
		if (IntersectRect(&temp, &_player1->_player_1.player1, &item->_item))
			//플레이어 1 아이템 먹는 
		{
			
			/*if (item->_itemName == posion)
			{
				for (int i=0;i<_player1->_player_1.bombNumber;i++)
				{
					_player1->player1_bomb->getVbomb()[i].boomLeft_rc.left -= item->effect;
					_player1->player1_bomb->getVbomb()[i].boomRight_rc.right += item->effect;
					_player1->player1_bomb->getVbomb()[i].boomDown_rc.bottom += item->effect;
					_player1->player1_bomb->getVbomb()[i].boomUp_rc.top -= item->effect;
					
					
				}
			}
			if (item->_itemName == bollon)
			{
				_player1->_player_1.bombNumber += 1;
			}*/
			
			item = itemVector.erase(item);
		}
		if (IntersectRect(&temp, &_player2->_player_2.player2, &item->_item))
			//플레이어 1 아이템 먹는 
		{

			/*if (item->_itemName == posion)
			{
				for (int i=0;i<_player1->_player_1.bombNumber;i++)
				{
					_player1->player1_bomb->getVbomb()[i].boomLeft_rc.left -= item->effect;
					_player1->player1_bomb->getVbomb()[i].boomRight_rc.right += item->effect;
					_player1->player1_bomb->getVbomb()[i].boomDown_rc.bottom += item->effect;
					_player1->player1_bomb->getVbomb()[i].boomUp_rc.top -= item->effect;


				}
			}
			if (item->_itemName == bollon)
			{
				_player1->_player_1.bombNumber += 1;
			}*/

			item = itemVector.erase(item);
		}
		else item++;



	}




}
