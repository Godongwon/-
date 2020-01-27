#include "stdafx.h"
#include "bomb2.h"


bomb2::bomb2()
{
}


bomb2::~bomb2()
{
}

HRESULT bomb2::init(int bombmax)
{
	_map = new Map;
	_map->init();

	for (int i = 0; i < bombmax; i++)
	{
		tagbomb2 bomb;
		ZeroMemory(&bomb, sizeof(tagbomb2));
		bomb.bombimg2 = new image;
		bomb.bombimg2->init("image/¹°Ç³¼±/player2 bollon.bmp", 0, 0, 164, 41, 4, 1, true, RGB(255, 0, 255));

		bomb.boomLeftimg2 = new image;
		bomb.boomRightimg2 = new image;
		bomb.boomUpimg2 = new image;
		bomb.boomDownimg2 = new image;
		bomb.boomCenterimg2 = new image;
		bomb.boomRightimg2->init("image/¹°Ç³¼±/right.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomLeftimg2->init("image/¹°Ç³¼±/left.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomUpimg2->init("image/¹°Ç³¼±/top.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomDownimg2->init("image/¹°Ç³¼±/bottom.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));
		bomb.boomCenterimg2->init("image/¹°Ç³¼±/center.bmp", 0, 0, 369, 41, 9, 1, true, RGB(255, 0, 255));

		bomb.fire2 = false;
		bomb.boom2 = false;
		//bomb.bombcount = 0;

		_vbomb2.push_back(bomb);
	}
	return S_OK;
}

void bomb2::release()
{
}

void bomb2::update()
{
}

void bomb2::render()
{
	for (_vibomb2 = _vbomb2.begin(); _vibomb2 != _vbomb2.end(); ++_vibomb2)
	{
		if (!_vibomb2->fire2)continue;

		_vibomb2->bombimg2->frameRender(getMemDC(),
			_vibomb2->bomb_rc2.left, _vibomb2->bomb_rc2.top,
			_vibomb2->bombimg2->getFrameX(), 0);
		_vibomb2->fire2 = true;
		_vibomb2->bombcount2++;
		if (_vibomb2->bombcount2 % 30 == 0)
		{
			_vibomb2->bombimg2->setFrameX(_vibomb2->bombimg2->getFrameX() + 1);

			if (_vibomb2->bombimg2->getFrameX() >= _vibomb2->bombimg2->getMaxFrameX())
			{
				_vibomb2->bombimg2->setFrameX(0);
			}
			if (_vibomb2->bombcount2 >= 120)
			{
				
				_vibomb2->bombcount2 = 0;
				_vibomb2->boom2 = true;
			}
		}
		if (_vibomb2->boom2)
		{



			if (_vibomb2->boomUp_rc2.top <= _map->_BicMap.top)
			{
				_vibomb2->boomUp_rc2.top = _map->_BicMap.top;
			}
			if (_vibomb2->boomLeft_rc2.left <= _map->_BicMap.left)
			{
				_vibomb2->boomLeft_rc2.left = _map->_BicMap.left;
			}


			if (_vibomb2->boomRight_rc2.right >= _map->_BicMap.right)
			{
				_vibomb2->boomRight_rc2.right = _map->_BicMap.right;
			}
			if (_vibomb2->boomDown_rc2.bottom >= _map->_BicMap.bottom)
			{
				_vibomb2->boomDown_rc2.bottom = _map->_BicMap.bottom;
			}

			_vibomb2->boomCenterimg2->frameRender(getMemDC(),	_vibomb2->boomCenter_rc2.left,	_vibomb2->boomCenter_rc2.top,	_vibomb2->boomCenterimg2->getFrameX(), 0);
			_vibomb2->boomLeftimg2->frameRender(getMemDC(),		_vibomb2->boomLeft_rc2.left,	_vibomb2->boomLeft_rc2.top,		_vibomb2->boomLeftimg2->getFrameX(), 0);
			_vibomb2->boomUpimg2->frameRender(getMemDC(), _vibomb2->boomUp_rc2.left, _vibomb2->boomUp_rc2.top, _vibomb2->boomUpimg2->getFrameX(), 0);
			if (_vibomb2->boomRight_rc2.right > _vibomb2->boomRight_rc2.left + 1)
			{
				_vibomb2->boomRightimg2->frameRender(getMemDC(), _vibomb2->boomRight_rc2.left, _vibomb2->boomRight_rc2.top, _vibomb2->boomRightimg2->getFrameX(), 0);
			}
			if (_vibomb2->boomDown_rc2.bottom > _vibomb2->boomDown_rc2.top + 1)
			{
				_vibomb2->boomDownimg2->frameRender(getMemDC(), _vibomb2->boomDown_rc2.left, _vibomb2->boomDown_rc2.top, _vibomb2->boomDownimg2->getFrameX(), 0);
			}

			_vibomb2->boomcount2++;
			if (_vibomb2->boomcount2 % 10 == 0)
			{
				_vibomb2->boomRightimg2->setFrameX	(_vibomb2->boomRightimg2->getFrameX() + 1);
				_vibomb2->boomLeftimg2->setFrameX	(_vibomb2->boomLeftimg2->getFrameX() + 1);
				_vibomb2->boomUpimg2->setFrameX		(_vibomb2->boomUpimg2->getFrameX() + 1);
				_vibomb2->boomDownimg2->setFrameX	(_vibomb2->boomDownimg2->getFrameX() + 1);
				_vibomb2->boomCenterimg2->setFrameX	(_vibomb2->boomCenterimg2->getFrameX() + 1);

				if (_vibomb2->boomRightimg2->getFrameX() >= _vibomb2->boomRightimg2->getMaxFrameX() &&
					_vibomb2->boomLeftimg2->getFrameX() >=	_vibomb2->boomLeftimg2->getMaxFrameX() &&
					_vibomb2->boomUpimg2->getFrameX() >=	_vibomb2->boomUpimg2->getMaxFrameX() &&
					_vibomb2->boomDownimg2->getFrameX() >=	_vibomb2->boomDownimg2->getMaxFrameX() &&
					_vibomb2->boomCenterimg2->getFrameX() >=_vibomb2->boomCenterimg2->getMaxFrameX())
				{
					_vibomb2->boom2 = false;
					_vibomb2->boomRightimg2->setFrameX(0);
					_vibomb2->boomLeftimg2->setFrameX(0);
					_vibomb2->boomUpimg2->setFrameX(0);
					_vibomb2->boomDownimg2->setFrameX(0);
					_vibomb2->boomCenterimg2->setFrameX(0);
				}
				if (_vibomb2->boomcount2 >= 80)
				{
					_vibomb2->fire2 = false;
					_vibomb2->boomcount2 = 0;
				}

			}
		}

	}
	/*char str[120];
	wsprintf(str, "%d", _vibomb->bombcount);
	TextOut(getMemDC(), 0, 0, str, strlen(str));*/
}

void bomb2::boom(float x, float y)
{
	_vibomb2 = _vbomb2.begin();
	for (_vibomb2; _vibomb2 != _vbomb2.end(); ++_vibomb2)
	{
		if (_vibomb2->fire2)continue;
		_vibomb2->x2 = x;
		_vibomb2->y2 = y;
		_vibomb2->fire2 = true;

		_vibomb2->bomb_rc2 = RectMakeCenter(_vibomb2->x2, _vibomb2->y2,
			_vibomb2->bombimg2->getFrameWidth()
			, _vibomb2->bombimg2->getFrameHeight()
		);


		//_vibomb2->boomRight_rc2 = RectMake(_vibomb2->bomb_rc2.right, _vibomb2->bomb_rc2.top, 41, 41);
		_vibomb2->boomRight_rc2 = RectMake(_vibomb2->bomb_rc2.right, _vibomb2->bomb_rc2.top, _vibomb2->boomRightimg2->getFrameWidth()-1, _vibomb2->boomRightimg2->getFrameHeight() - 1);
		_vibomb2->boomLeft_rc2 = RectMake(_vibomb2->bomb_rc2.left - 41, _vibomb2->bomb_rc2.top, _vibomb2->boomLeftimg2->getFrameWidth()-1, _vibomb2->boomLeftimg2->getFrameHeight() - 1);
		_vibomb2->boomUp_rc2 = RectMake(_vibomb2->bomb_rc2.left, _vibomb2->bomb_rc2.top - 41, _vibomb2->boomUpimg2->getFrameWidth() - 1, _vibomb2->boomUpimg2->getFrameHeight() - 1);
		_vibomb2->boomDown_rc2 = RectMake(_vibomb2->bomb_rc2.left, _vibomb2->bomb_rc2.bottom, _vibomb2->boomDownimg2->getFrameWidth() - 1, _vibomb2->boomDownimg2->getFrameHeight() - 1);
		_vibomb2->boomCenter_rc2 = RectMake(_vibomb2->bomb_rc2.left, _vibomb2->bomb_rc2.top, _vibomb2->boomCenterimg2->getFrameWidth() - 1, _vibomb2->boomCenterimg2->getFrameHeight() - 1);

		if (_vibomb2->boom2)
		{
			_vibomb2->fire2 = false;
			_vibomb2->boom2 = false;

		}

	}
}
