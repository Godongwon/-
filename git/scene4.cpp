#include "stdafx.h"
#include "scene4.h"


scene4::scene4()
{
}


scene4::~scene4()
{
}

HRESULT scene4::init()
{
	_player = new player;
	_player->init();
	_player->_player = RectMakeCenter(WINSIZEX/2,WINSIZEY-100, _player->i_player->getFrameWidth(), _player->i_player->getFrameHeight());
	IMAGEMANAGER->addImage("몬스터1", "images/몬스터방1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}

void scene4::release()
{

}

void scene4::update()
{
	_player->update();
	if (_player->get_finalY() > WINSIZEY)//위쪽방-몬스터1
	{
		SCENEMANAGER->changeScene("scene1");
	}

}

void scene4::render()
{
	IMAGEMANAGER->render("몬스터1", getMemDC());
	
	_player->render();
}
