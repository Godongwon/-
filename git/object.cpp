#include "stdafx.h"
#include "object.h"


object::object()
{
}


object::~object()
{
}

HRESULT object::init()
{

	
	_map = new Map;
	_map->init();

	
	itemInput();
	Objectinput("image/오브젝트/box.bmp");
	


	_vObject.erase(_vObject.begin() + 1);
	_vObject.erase(_vObject.begin() + 12);
	_vObject.erase(_vObject.begin() + 167);
	_vObject.erase(_vObject.begin() + 180);
	_vObject.erase(_vObject.begin() + 179);

	_vObject.erase(_vObject.begin() );

	

	itemDelete(0);
	itemDelete(1);
	itemDelete(13);
	itemDelete(169);
	itemDelete(182);
	itemDelete(183);


	for (int i = 0; i < 150; i++)
	{
		itemDelete(RND->getInt(194));
	}
	



	
	

	return S_OK;
}

void object::release()
{
}

void object::update()
{
}

void object::render()
{

	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); _viItem++)
	{
		
		_viItem->_itemimg->render(getMemDC(), _viItem->_item.left, _viItem->_item.top);
	}
	
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); _viObject++)
	{
		
		_viObject->_objectimg->frameRender(getMemDC(), _viObject->_object.left, _viObject->_object.top, _viObject->num, 0);
	}

	
}

void object::Objectinput(const char* fileName)
{

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			
			tagObject object;
			ZeroMemory(&object, sizeof(tagObject));
			object._objectimg = new image;
			object._objectimg->init(fileName, 0, 0, 124, 41, 3, 1, true, RGB(255, 0, 255));
			object._object = RectMake(_map->_map[i][j].map.left, _map->_map[i][j].map.top, 41, 41);
		
			object.num = RND->getInt(2);
			_vObject.push_back(object);
		}
	}


}



void object::itemInput()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			
			if (((i * 13) + j) % 3 == 0)
			{
				Itemtag itemtag;
				ZeroMemory(&itemtag, sizeof(Itemtag));
				itemtag._itemName = posion;
				itemtag._itemimg = IMAGEMANAGER->addImage("포션", "image/아이템/포션.bmp", 35, 35, true, RGB(255, 0, 255));
				itemtag._item = RectMakeCenter(_map->_map[i][j].map.right-(_map->_map[i][j].map.right- _map->_map[i][j].map.left)/2, 
					_map->_map[i][j].map.bottom- (_map->_map[i][j].map.bottom-_map->_map[i][j].map.top)/2, 35, 35);
				itemtag.effect = 41;//물줄기
				_vItem.push_back(itemtag);
			}
			else if (((i * 13) + j) % 3 == 1)
			{
				Itemtag itemtag;
				ZeroMemory(&itemtag, sizeof(Itemtag));
				itemtag._itemName = bollon;
				itemtag._itemimg=IMAGEMANAGER->addImage("물풍선","image/아이템/물풍선.bmp", 35, 35, true, RGB(255, 0, 255));
				itemtag._item = RectMakeCenter(_map->_map[i][j].map.right - (_map->_map[i][j].map.right - _map->_map[i][j].map.left) / 2,
					_map->_map[i][j].map.bottom - (_map->_map[i][j].map.bottom - _map->_map[i][j].map.top) / 2, 35, 35);
				itemtag.effect = 1;//물풍선 개수
				_vItem.push_back(itemtag);
			}
			else if (((i * 13) + j) % 3 == 2)
			{
				Itemtag itemtag;
				ZeroMemory(&itemtag, sizeof(Itemtag));
				itemtag._itemName = shose;
				itemtag._itemimg = IMAGEMANAGER->addImage("신발","image/아이템/신발.bmp", 35, 35, true, RGB(255, 0, 255));
				itemtag._item = RectMakeCenter(_map->_map[i][j].map.right - (_map->_map[i][j].map.right - _map->_map[i][j].map.left) / 2,
					_map->_map[i][j].map.bottom - (_map->_map[i][j].map.bottom - _map->_map[i][j].map.top) / 2, 35, 35);
				itemtag.effect = 1.0f;//속도
				_vItem.push_back(itemtag);
			}

		}
	}
}

void object::itemDelete(int Itemnum)
{
	_vItem[Itemnum]._itemimg= IMAGEMANAGER->addImage("EMP","image/아이템/emp.bmp", 35, 35, true, RGB(255, 0, 255));
	_vItem[Itemnum]._itemName = EMP;
	_vItem[Itemnum].effect = 0;
}




