#include "stdafx.h"
#include "map.h"



Map::Map()
{
}

Map::~Map()
{
}

HRESULT Map::init()
{
	

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			_map[i][j].mapimg = IMAGEMANAGER->addFrameImage("타일", "image/오브젝트/tile.bmp", 205, 41, 5, 1, true, RGB(255, 0, 255));
			_map[i][j].map = RectMakeCenter(33+(i * _map[i][j].mapimg->getFrameWidth()), 55+(j * _map[i][j].mapimg->getFrameHeight()), _map[i][j].mapimg->getFrameWidth(), _map[i][j].mapimg->getFrameHeight());
			_map[i][j].bomb = false;
			_map[i][j].move = true;

		}
	}
	_BicMap = RectMake(_map[0][0].map.left, _map[0][0].map.top, 41*15,41*13);


	debug = false;

	return S_OK;
}

void Map::release()
{
}

void Map::update()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		debug = !debug;
	}
}

void Map::render()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 13; j++)
		{
		
			if (i < 5)
			{
				IMAGEMANAGER->frameRender("타일", getMemDC(), _map[i][j].map.left, _map[i][j].map.top, 0, 0);
			}
			else if(i>=5&&i<10)
			{
				if (j % 2 == 0)
				{
					IMAGEMANAGER->frameRender("타일", getMemDC(), _map[i][j].map.left, _map[i][j].map.top, 2, 0);
				}
				else
				{
					IMAGEMANAGER->frameRender("타일", getMemDC(), _map[i][j].map.left, _map[i][j].map.top, 4, 0);
				}
			}
			else if (i >= 10 && i < 15)
			{
				IMAGEMANAGER->frameRender("타일", getMemDC(), _map[i][j].map.left, _map[i][j].map.top, 1, 0);
			}
		}
	}


	

	if (debug)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				Rectangle(getMemDC(), _map[i][j].map.left, _map[i][j].map.top, _map[i][j].map.right, _map[i][j].map.bottom);
				char str[120];
				wsprintf(str, " %d",(i*13)+j);
				TextOut(getMemDC(), _map[i][j].map.left, _map[i][j].map.top, str, strlen(str));

			}
		}
	
	}
}
