#include "stdafx.h"
#include "Item.h"
#include"player1.h"
#include"player2.h"
#include"map.h"

Item::Item()
{
}


Item::~Item()
{
}

HRESULT Item::init()
{
	player_1 = new player1;
	player_2 = new player2;
	_map = new Map;
	player_1->init();
	player_2->init();
	_map->init();

	itemInput();



	


	return S_OK;
}

void Item::release()
{
}

void Item::update()
{
}

void Item::render()
{
	for (vi_item = v_item.begin(); vi_item != v_item.end(); ++vi_item)
	{
		vi_item->_itemimg->render(getMemDC(), vi_item->_item.left, vi_item->_item.top);
	}
}

void Item::itemInput()
{
	
}
