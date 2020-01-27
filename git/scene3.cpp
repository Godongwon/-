#include "stdafx.h"
#include "scene3.h"


scene3::scene3()
{
}


scene3::~scene3()
{
}

HRESULT scene3::init()
{
	_player = new player;
	_player->init();
	_player->_player = RectMakeCenter(100, WINSIZEY / 2, _player->i_player->getFrameWidth(), _player->i_player->getFrameHeight());
	IMAGEMANAGER->addImage("상점", "images/상점.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}

void scene3::release()
{
}

void scene3::update()
{
	_player->update();
	//_player->set_final();

	if (_player->get_finalX() < 0)//오른쪽방에서 나가는거니
	{
		SCENEMANAGER->changeScene("scene1");
	}
}

void scene3::render()
{
	IMAGEMANAGER->render("상점", getMemDC());
	
	_player->render();
}
