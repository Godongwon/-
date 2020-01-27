#include "stdafx.h"
#include "bomb1.h"


bomb1::bomb1()
{
}


bomb1::~bomb1()
{
}

HRESULT bomb1::init(int bombmax)
{


	_map = new Map;
	_map->init();

	for (int i = 0; i < bombmax; i++)
	{
		tagbomb bomb;
		ZeroMemory(&bomb, sizeof(tagbomb));
		bomb.bombimg = new image;
		bomb.bombimg->init("image/¹°Ç³¼±/player1bollon.bmp", 0, 0, 164, 41, 4, 1, true, RGB(255, 0, 255));

		bomb.boomLeftimg = new image;
		bomb.boomRightimg = new image;
		bomb.boomUpimg = new image;
		bomb.boomDownimg = new image;
		bomb.boomCenterimg = new image;
		bomb.boomRightimg->init("image/¹°Ç³¼±/right.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomLeftimg->init("image/¹°Ç³¼±/left.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomUpimg->init("image/¹°Ç³¼±/top.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomDownimg->init("image/¹°Ç³¼±/bottom.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomCenterimg->init("image/¹°Ç³¼±/center.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));

		bomb.fire = false;
		bomb.boom = false;
		//bomb.bombcount = 0;

		_vbomb.push_back(bomb);
	}
	return S_OK;
}

void bomb1::release()
{
	//SAFE_DELETE(_vibomb->bombimg);
}

void bomb1::update()
{
	//bombBoomimg();
}

void bomb1::render()
{
	for (_vibomb = _vbomb.begin(); _vibomb != _vbomb.end(); ++_vibomb)
	{
		if (!_vibomb->fire)continue;
		//if (!_vibomb->boom)continue;
		//Rectangle(getMemDC(), _vibomb->bomb_rc.left, _vibomb->bomb_rc.top, _vibomb->bomb_rc.right, _vibomb->bomb_rc.bottom);
			_vibomb->bombimg->frameRender(getMemDC(),
			_vibomb->bomb_rc.left, _vibomb->bomb_rc.top,
				_vibomb->bombimg->getFrameX(), 0);
			_vibomb->fire = true;
			_vibomb->bombcount++;
			if (_vibomb->bombcount % 30 == 0)
			{
				_vibomb->bombimg->setFrameX(_vibomb->bombimg->getFrameX() + 1);

				if (_vibomb->bombimg->getFrameX() >= _vibomb->bombimg->getMaxFrameX())
				{
					_vibomb->bombimg->setFrameX(0);
				}
				if (_vibomb->bombcount >= 120)
				{
					
					_vibomb->bombcount = 0;
					_vibomb->boom = true;
					
				}
			}
			
				
			if (_vibomb->boom)
			{
				
				if (_vibomb->boomUp_rc.top <= _map->_BicMap.top)
				{
					_vibomb->boomUp_rc.top = _map->_BicMap.top;
				}
					if (_vibomb->boomLeft_rc.left <= _map->_BicMap.left)
				{
					_vibomb->boomLeft_rc.left = _map->_BicMap.left;
				}
				if (_vibomb->boomRight_rc.right >= _map->_BicMap.right)
				{
					_vibomb->boomRight_rc.right = _map->_BicMap.right;
				}
				if (_vibomb->boomDown_rc.bottom >= _map->_BicMap.bottom)
				{
					_vibomb->boomDown_rc.bottom = _map->_BicMap.bottom;
				}
				
				_vibomb->boomCenterimg->frameRender(getMemDC(),_vibomb->boomCenter_rc.left, _vibomb->boomCenter_rc.top,_vibomb->boomCenterimg->getFrameX(), 0);
				_vibomb->boomLeftimg->frameRender(getMemDC(), _vibomb->boomLeft_rc.left, _vibomb->boomLeft_rc.top, _vibomb->boomLeftimg->getFrameX(), 0);
				_vibomb->boomUpimg->frameRender(getMemDC(), _vibomb->boomUp_rc.left, _vibomb->boomUp_rc.top, _vibomb->boomUpimg->getFrameX(), 0);
				if (_vibomb->boomRight_rc.right > _vibomb->boomRight_rc.left + 1)
				{
					_vibomb->boomRightimg->frameRender(getMemDC(), _vibomb->boomRight_rc.left, _vibomb->boomRight_rc.top, _vibomb->boomRightimg->getFrameX(), 0);
				}
				if (_vibomb->boomDown_rc.bottom > _vibomb->boomDown_rc.top + 1)
				{
					_vibomb->boomDownimg->frameRender(getMemDC(), _vibomb->boomDown_rc.left, _vibomb->boomDown_rc.top, _vibomb->boomDownimg->getFrameX(), 0);
				}
				_vibomb->boomcount++;
				if (!_vibomb->boomcount ==0&&_vibomb->boomcount % 10 == 0)
				{
					_vibomb->boomRightimg->setFrameX(_vibomb->boomRightimg->getFrameX() + 1);
					_vibomb->boomLeftimg->setFrameX(_vibomb->boomLeftimg->getFrameX() + 1);
					_vibomb->boomUpimg->setFrameX(_vibomb->boomUpimg->getFrameX() + 1);
					_vibomb->boomDownimg->setFrameX(_vibomb->boomDownimg->getFrameX() + 1);
					_vibomb->boomCenterimg->setFrameX(_vibomb->boomCenterimg->getFrameX() + 1);

					if (_vibomb->boomRightimg->getFrameX() >= _vibomb->boomRightimg->getMaxFrameX()&&
						_vibomb->boomLeftimg->getFrameX() >= _vibomb->boomLeftimg->getMaxFrameX() &&
						_vibomb->boomUpimg->getFrameX() >= _vibomb->boomUpimg->getMaxFrameX() &&
						_vibomb->boomDownimg->getFrameX() >= _vibomb->boomDownimg->getMaxFrameX() &&
						_vibomb->boomCenterimg->getFrameX() >= _vibomb->boomCenterimg->getMaxFrameX() )
					{
						_vibomb->fire = false;
						_vibomb->boomRightimg->setFrameX	(0);
						_vibomb->boomLeftimg->setFrameX		(0);
						_vibomb->boomUpimg->setFrameX		(0);
						_vibomb->boomDownimg->setFrameX		(0);
						_vibomb->boomCenterimg->setFrameX	(0);
					}
					if (_vibomb->boomcount>= 80)
					{
						_vibomb->boom =false;
						_vibomb->boomcount = 0;
					}
					
					
				}
			}
			
				
		
	}
}



void bomb1::boom(float x, float y)
{
	_vibomb = _vbomb.begin();
	for (_vibomb; _vibomb != _vbomb.end(); ++_vibomb)
	{
		if (_vibomb->fire)continue;
		_vibomb->x = x;
		_vibomb->y = y;
		_vibomb->fire = true;
		
		_vibomb->bomb_rc = RectMakeCenter(_vibomb->x, _vibomb->y,_vibomb->bombimg->getFrameWidth(),_vibomb->bombimg->getFrameHeight());

		
		_vibomb->boomCenter_rc = RectMake(_vibomb->bomb_rc.left, _vibomb->bomb_rc.top, _vibomb->boomCenterimg->getFrameWidth()-1, _vibomb->boomCenterimg->getFrameHeight()-1);
		_vibomb->boomRight_rc = RectMake(_vibomb->bomb_rc.right, _vibomb->bomb_rc.top, _vibomb->boomRightimg->getFrameWidth()-1, _vibomb->boomRightimg->getFrameHeight()-1);
		_vibomb->boomLeft_rc = RectMake(_vibomb->bomb_rc.left - 41, _vibomb->bomb_rc.top, _vibomb->boomLeftimg->getFrameWidth()-1, _vibomb->boomLeftimg->getFrameHeight()-1);
		_vibomb->boomUp_rc = RectMake(_vibomb->bomb_rc.left, _vibomb->bomb_rc.top - 41, _vibomb->boomUpimg->getFrameWidth()-1, _vibomb->boomUpimg->getFrameHeight()-1);
		_vibomb->boomDown_rc = RectMake(_vibomb->bomb_rc.left, _vibomb->bomb_rc.bottom, _vibomb->boomDownimg->getFrameWidth()-1, _vibomb->boomDownimg->getFrameHeight()-1);


		if (_vibomb->boom)
		{
			_vibomb->fire = false;
			_vibomb->boom = false;

		}
	
	}
}

