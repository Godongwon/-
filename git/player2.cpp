#include "stdafx.h"
#include "player2.h"
//#include"playerManager.h"


player2 ::player2()
{

}


player2 ::~player2()
{
}

HRESULT player2::init()
{
	_object = new object;
	_object->init();
	_playerMove = Player2_LEFT;
	map = new Map;
	map->init();
	player2_bomb = new bomb2;
	_player_2.bombNumber = 1;
	player2_bomb->init(_player_2.bombNumber);
	_player_2.name = "¹èÂî";
	_player_2.player2 = RectMakeCenter	(map->_map[14][0].map.right-(map->_map[14][0].map.right- map->_map[14][0].map.left)/2,
										map->_map[14][0].map.bottom-(map->_map[14][0].map.bottom- map->_map[14][0].map.top)/2,
										41, 41);
	_player_2.characterimgMove = IMAGEMANAGER->addFrameImage("¹èÂî¿òÁ÷ÀÓ", "image/¹èÂî/°íµ¿¿ø.bmp", 287, 164, 7, 4, true, RGB(255, 0, 255));
	_player_2.player2_speed = 5.0f;
	_player_2.characterimgBubble = IMAGEMANAGER->addFrameImage("¹èÂî¹°Ç³¼±", "image/¹èÂî/bazziBubble.bmp", 41*16, 41, 16, 1, true, RGB(255, 0, 255));
	_player_2.characterimgdie = IMAGEMANAGER->addFrameImage("¹èÂî´ÙÀÌ", "image/¹èÂî/bazziDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_player_2.characterimgSence = IMAGEMANAGER->addFrameImage("¹èÂîµð½ºÇÃ·¹ÀÌ", "image/¹èÂî/bazziGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
	_player_2._player2_Live = true;
	_player_2._player2_Die = false;
	_player_2.player2_Go = true;
	_player_2.Collision2 = RectMake(_player_2.player2.right, _player_2.player2.top, 1, 1);
	_count = 0;
	_index = 0;
	player2_senceRC = RectMake(659, 142, 45, 34);

	return S_OK;
}

void player2::release()
{
}

void player2::update()
{
	RECT temp;
	if (_player_2._player2_Live)
	{
		_player_2.player2_X = _player_2.player2.right - (_player_2.player2.right - _player_2.player2.left) / 2;
		_player_2.player2_Y = _player_2.player2.bottom - (_player_2.player2.bottom - _player_2.player2.top) / 2;
		if (KEYMANAGER->isOnceKeyDown(VK_RSHIFT))
		{
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (
						_player_2.player2_Y > map->_map[i][j].map.top&&
						_player_2.player2_Y <map->_map[i][j].map.bottom&&
						_player_2.player2_X >map->_map[i][j].map.left&&
						_player_2.player2_X < map->_map[i][j].map.right)


					{
						player2_bomb->boom(map->_map[i][j].map.right - (map->_map[i][j].map.right - map->_map[i][j].map.left) / 2,
							map->_map[i][j].map.bottom - (map->_map[i][j].map.bottom - map->_map[i][j].map.top) / 2);


					}
				}
			}
		}
		player2_bomb->update();
		if (KEYMANAGER->isStayKeyDown(VK_UP))//up
		{
			_playerMove = Player2_UP;
			_player_2.Collision2.left	= _player_2.player2.left;
			_player_2.Collision2.right	= _player_2.player2.right;
			_player_2.Collision2.bottom = _player_2.player2.top;
			_player_2.Collision2.top	= _player_2.Collision2.bottom - 1;




			if (_player_2.player2.top <= map->_BicMap.top)
			{
				_player_2.player2.bottom -= 0;
				_player_2.player2.top -= 0;
			}
			else
			{
				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					if (IntersectRect(&temp, &_player_2.Collision2, &_object->getVobject()[i]._object))
					{

						_player_2.player2.bottom += 0;
						_player_2.player2.top += 0;
						_player_2.player2_Go = false;
						break;
					}
					else
					{
						_player_2.player2_Go = true;
					}

				}
				if (_player_2.player2_Go)
				{
					_player_2.player2.bottom -= 5;
					_player_2.player2.top -= 5;

				}
			}

			_count++;

		}

		else if (KEYMANAGER->isStayKeyDown(VK_DOWN))//down
		{
			_playerMove = Player2_DOWN;
			_player_2.Collision2.left	= _player_2.player2.left;
			_player_2.Collision2.right	= _player_2.player2.right;
			_player_2.Collision2.top	= _player_2.player2.bottom;
			_player_2.Collision2.bottom	= _player_2.Collision2.top + 1;
			if (_player_2.player2.bottom >= map->_BicMap.bottom)
			{
				_player_2.player2.bottom += 0;
				_player_2.player2.top += 0;
				_player_2.player2_Go = false;
			}
			else
			{
				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					if (IntersectRect(&temp, &_player_2.Collision2, &_object->getVobject()[i]._object))
					{

						_player_2.player2.bottom += 0;
						_player_2.player2.top += 0;
						_player_2.player2_Go = false;
						break;
					}
					else
					{
						_player_2.player2_Go = true;
					}

				}

				if (_player_2.player2_Go)
				{					
					_player_2.player2.bottom += 5;
					_player_2.player2.top += 5;

				}
			}

			_count++;
		}

		else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))//right
		{
			_playerMove = Player2_RIGHT;

			_player_2.Collision2.left	= _player_2.player2.right;
			_player_2.Collision2.right	= _player_2.Collision2.left + 1;
			_player_2.Collision2.top	= _player_2.player2.top;
			_player_2.Collision2.bottom	= _player_2.player2.bottom;


			if (_player_2.player2.right >= map->_BicMap.right)
			{					
				_player_2.player2.right += 0;
				_player_2.player2.left += 0;
				_player_2.player2_Go = false;
			}
			else
			{
				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					if (IntersectRect(&temp, &_player_2.Collision2, &_object->getVobject()[i]._object))
					{

						_player_2.player2.right += 0;
						_player_2.player2.left += 0;
						_player_2.player2_Go = false;
						break;
					}
					else
					{
						_player_2.player2_Go = true;
					}

				}
				if (_player_2.player2_Go)
				{					
					_player_2.player2.right += 5;
					_player_2.player2.left += 5;

				}
			}

			_count++;
		}

		else if (KEYMANAGER->isStayKeyDown(VK_LEFT))//lefr
		{
			_playerMove = Player2_LEFT;
			_player_2.Collision2.right	= _player_2.player2.left;
			_player_2.Collision2.left	= _player_2.Collision2.right - 1;
			_player_2.Collision2.top	= _player_2.player2.top;
			_player_2.Collision2.bottom	= _player_2.player2.bottom;
			if (_player_2.player2.left <= map->_BicMap.left)
			{					
				_player_2.player2.right -= 0;
				_player_2.player2.left -= 0;
				_player_2.player2_Go = false;
			}
			else
			{

				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					if (IntersectRect(&temp, &_player_2.Collision2, &_object->getVobject()[i]._object))
					{

						_player_2.player2.right -= 0;
						_player_2.player2.left -= 0;
						_player_2.player2_Go = false;
						break;
					}
					else
					{
						_player_2.player2_Go = true;
					}

				}
				if (_player_2.player2_Go)
				{					
					_player_2.player2.right -= 5;
					_player_2.player2.left -= 5;

				}
			}

			_count++;
		}




		if (_count != 0 && _count % 10 == 0)
		{
			_count++;
			_index++;


		}
		else if (_count > 61)
		{
			_count = 0;
			_index = 0;
		}
	}
	for (int i = 0; i < _player_2.bombNumber; i++)
	{
		//RECT temp;

		if (player2_bomb->getVbomb2()[i].boom2		  
			&& (IntersectRect(&temp, &_player_2.player2, &player2_bomb->getVbomb2()[i].boomRight_rc2) ||
				IntersectRect(&temp, &_player_2.player2, &player2_bomb->getVbomb2()[i].boomLeft_rc2) ||
				IntersectRect(&temp, &_player_2.player2, &player2_bomb->getVbomb2()[i].boomUp_rc2) ||
				IntersectRect(&temp, &_player_2.player2, &player2_bomb->getVbomb2()[i].boomDown_rc2)||
				IntersectRect(&temp, &_player_2.player2, &player2_bomb->getVbomb2()[i].boomCenter_rc2)))
		{


			_player_2._player2_Live = false;

		}
	}

}

void player2::render()
{
	player2_bomb->render();


	Rectangle(getMemDC(), player2_senceRC.left, player2_senceRC.top, player2_senceRC.right, player2_senceRC.bottom);

	if (_player_2._player2_Live)
	{
		_player_2.characterimgMove->frameRender(getMemDC(), _player_2.player2.left, _player_2.player2.top, _index, _playerMove);
		_player_2.characterimgSence->frameRender(getMemDC(), player2_senceRC.left, player2_senceRC.top, 0, 0);
	}
	else
	{
		_player_2.characterimgSence->frameRender(getMemDC(), player2_senceRC.left, player2_senceRC.top, 1, 0);
		_player_2.characterimgBubble->frameRender(getMemDC(), _player_2.player2.left, _player_2.player2.top, _index, 0);
		if (_player_2._player2_Die)
		{
			_player_2.characterimgSence->frameRender(getMemDC(), player2_senceRC.left, player2_senceRC.top, 1, 0);
			_player_2.characterimgBubble->init("image/¿ÀºêÁ§Æ®/Æã.bmp", 41, 41, true, RGB(255, 0, 255));
			_player_2.characterimgdie->frameRender(getMemDC(), _player_2.player2.left, _player_2.player2.top, 11, 0);
		}
	}
}


