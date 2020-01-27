#include "stdafx.h"
#include "player1.h"



player1::player1()
{

}


player1::~player1()
{
}

HRESULT player1::init()
{
	
	_object = new object;
	_object->init();
	_playerMove = LEFT;
	_player_1.bombNumber = 1;
	map = new Map;
	map->init();
	player1_bomb = new bomb1;
	player1_bomb->init(_player_1.bombNumber);
	_player_1.name = "다오";
	_player_1.player1 = RectMakeCenter(map->_map[0][0].map.right - (map->_map[0][0].map.right - map->_map[0][0].map.left) / 2,
										map->_map[0][0].map.bottom - (map->_map[0][0].map.bottom - map->_map[0][0].map.top) / 2,
										41, 41); 
	_player_1.characterimgMove = IMAGEMANAGER->addFrameImage("다오움직임", "image/다오/권수민.bmp", 41 * 7, 41 * 4, 7, 4, true, RGB(255, 0, 255));
	_player_1.characterimgBubble = IMAGEMANAGER->addFrameImage("다오물풍선", "image/다오/daoBubble.bmp", 16 * 41, 41, 16, 1, true, RGB(255, 0, 255));
	_player_1.characterimgdie = IMAGEMANAGER->addFrameImage("다오다이", "image/다오/daoDie.bmp", 41 * 11, 41, 11, 1, true, RGB(255, 0, 255));
	_player_1.characterimgSence = IMAGEMANAGER->addFrameImage("다오씬", "image/다오/daoGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
	_player_1.player1_Go = true;
	_player_1.Collision = RectMake(_player_1.player1.right, _player_1.player1.top, 1, 1);
	_player_1._player1_Live = true;
	_player_1._player1_Die = false;
	_count = 0;
	_index = 0;
	player1_senceRC = RectMake(659, 100, 45, 34);
	
	return S_OK;
}

void player1::release()
{
}

void player1::update()
{
	
	if (_player_1._player1_Live)
	{
		_player_1.player1_X = _player_1.player1.right - (_player_1.player1.right - _player_1.player1.left) / 2;
		_player_1.player1_Y = _player_1.player1.bottom - (_player_1.player1.bottom - _player_1.player1.top) / 2;
		if (KEYMANAGER->isOnceKeyDown(VK_LSHIFT))
		{
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (_player_1.player1_Y> map->_map[i][j].map.top&&
						_player_1.player1_Y <map->_map[i][j].map.bottom&&
						_player_1.player1_X >map->_map[i][j].map.left&&
						_player_1.player1_X <map->_map[i][j].map.right)
					{
						player1_bomb->boom(map->_map[i][j].map.right - (map->_map[i][j].map.right - map->_map[i][j].map.left) / 2,
							map->_map[i][j].map.bottom - (map->_map[i][j].map.bottom - map->_map[i][j].map.top) / 2);
					}
				}
			}

		}
		player1_bomb->update();

	
		auto& objectVector = _object->getobj();

		if (KEYMANAGER->isStayKeyDown('W'))//up
		{
			_playerMove = UP;
			_player_1.Collision.left	 = _player_1.player1.left;
			_player_1.Collision.right	 = _player_1.player1.right;
			_player_1.Collision.bottom	 = _player_1.player1.top;
			_player_1.Collision.top		= _player_1.Collision.bottom-1;
			if (_player_1.player1.top <= map->_BicMap.top)
			{
				_player_1.player1.bottom -= 0;
				_player_1.player1.top -= 0;
				_player_1.player1_Go = false;
			}
			else
			{
				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					RECT temp;
					if (IntersectRect(&temp, &_player_1.Collision, &_object->getVobject()[i]._object))
					{

						_player_1.player1.bottom += 0;
						_player_1.player1.top += 0;
						_player_1.player1_Go = false;
						break;
					}
					

				}

				if (_player_1.player1_Go)
				{
					_player_1.player1.bottom -= 5;
					_player_1.player1.top -= 5;
				}
				

			}
			
			_count++;

		}

		else if (KEYMANAGER->isStayKeyDown('S'))//down
		{
			_playerMove = DOWN;

			_player_1.Collision.left = _player_1.player1.left;
			_player_1.Collision.right = _player_1.player1.right;
			_player_1.Collision.top = _player_1.player1.bottom;
			_player_1.Collision.bottom = _player_1.Collision.top+5;


			if (_player_1.player1.bottom >= map->_BicMap.bottom)
			{
				_player_1.player1.bottom += 0;
				_player_1.player1.top += 0;
				_player_1.player1_Go = false;
			}
			else
			{
				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					RECT temp;
					if (IntersectRect(&temp, &_player_1.Collision, &_object->getVobject()[i]._object))
					{
						
							_player_1.player1.bottom += 0;
							_player_1.player1.top += 0;
							_player_1.player1_Go = false;
							break;
					}
					/*else
					{
						_player_1.player1_Go = true;
					}*/
					
				}

				if (_player_1.player1_Go)
				{
					_player_1.player1.bottom += 5;
					_player_1.player1.top += 5;

				}
				
			}


			_count++;
		}

		else if (KEYMANAGER->isStayKeyDown('D'))//right
		{
			_playerMove = RIGHT;
			_player_1.Collision.left = _player_1.player1.right;
			_player_1.Collision.right = _player_1.Collision.left + 1;
			_player_1.Collision.top = _player_1.player1.top;
			_player_1.Collision.bottom = _player_1.player1.bottom;



			if (_player_1.player1.right >= map->_BicMap.right)
			{
			
				_player_1.player1.right += 0;
				_player_1.player1.left += 0;
				_player_1.player1_Go = false;
			}
			else
			{
				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					RECT temp;
					if (IntersectRect(&temp, &_player_1.Collision, &_object->getVobject()[i]._object))
					{
						
							_player_1.player1.right += 0;
							_player_1.player1.left += 0;
							_player_1.player1_Go = false;
							break;
					}
					else
					{
						_player_1.player1_Go = true;
					}
					
				}
				if (_player_1.player1_Go)
				{
					_player_1.player1.right += 5;
					_player_1.player1.left += 5;

				}
			}

			_count++;
		}
		else if (KEYMANAGER->isStayKeyDown('A'))//left
		{

			_playerMove = LEFT;
			_player_1.Collision.right = _player_1.player1.left;
			_player_1.Collision.left = _player_1.Collision.right-1;
			_player_1.Collision.top = _player_1.player1.top;
			_player_1.Collision.bottom = _player_1.player1.bottom;
			if (_player_1.player1.left <= map->_BicMap.left)
			{
				_player_1.player1.right -= 0;
				_player_1.player1.left -= 0;
				_player_1.player1_Go = false;
			}
			else
			{
				RECT temp;

				for (int i = 0; i < _object->getVobject().size(); i++)
				{
					if (IntersectRect(&temp, &_player_1.Collision, &_object->getVobject()[i]._object))
					{
						
							_player_1.player1.right -= 0;
							_player_1.player1.left -= 0;
							_player_1.player1_Go = false;
							break;
					}
					else
					{
						_player_1.player1_Go = true;
					}
					
				}
				if (_player_1.player1_Go)
				{
					_player_1.player1.right -= 5;
					_player_1.player1.left -= 5;

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
		_player_1.player1_Go = true;

	}

	//자신의 물풍선에 죽는...
	for (int i = 0; i < _player_1.bombNumber; i++)
	{
		RECT temp;

		if (player1_bomb->getVbomb()[i].boom
			&& (IntersectRect(&temp, &_player_1.player1, &player1_bomb->getVbomb()[i].boomRight_rc) ||
				IntersectRect(&temp, &_player_1.player1, &player1_bomb->getVbomb()[i].boomLeft_rc) ||
				IntersectRect(&temp, &_player_1.player1, &player1_bomb->getVbomb()[i].boomUp_rc) ||
				IntersectRect(&temp, &_player_1.player1, &player1_bomb->getVbomb()[i].boomDown_rc) ||
				IntersectRect(&temp, &_player_1.player1, &player1_bomb->getVbomb()[i].boomCenter_rc)))
		{
			_player_1._player1_Live = false;

		}
	}







}

void player1::render()
{
	player1_bomb->render();
	if (_player_1._player1_Live)
	{
		_player_1.characterimgMove->frameRender(getMemDC(), _player_1.player1.left, _player_1.player1.top, _index, _playerMove);
		_player_1.characterimgSence->frameRender(getMemDC(), player1_senceRC.left, player1_senceRC.top, 0, 0);
	}
	else
	{
		_player_1.characterimgSence->frameRender(getMemDC(), player1_senceRC.left, player1_senceRC.top, 1, 0);
		_player_1.characterimgBubble->frameRender(getMemDC(), _player_1.player1.left, _player_1.player1.top, 1, 0);
		if (_player_1._player1_Die)
		{
			_player_1.characterimgSence->frameRender(getMemDC(), player1_senceRC.left, player1_senceRC.top, 1, 0);
			_player_1.characterimgBubble->init("image/오브젝트/펑.bmp", 41, 41, true, RGB(255, 0, 255));
			_player_1.characterimgdie->frameRender(getMemDC(), _player_1.player1.left, _player_1.player1.top, 11, 0);
		}
	}
}


