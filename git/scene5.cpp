#include "stdafx.h"
#include "scene5.h"


scene5::scene5()
{
}


scene5::~scene5()
{
}

HRESULT scene5::init()
{
	_player = new player;
	_player->init();
	_player->_player = RectMakeCenter(WINSIZEX/2, 100, _player->i_player->getFrameWidth(), _player->i_player->getFrameHeight());
	IMAGEMANAGER->addImage("����2", "images/���͹�2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}

void scene5::release()
{
}

void scene5::update()
{
	_player->update();
	//_player->set_final();

	if (_player->get_finalY() < 0)//���ʹ�-����
	{
		SCENEMANAGER->changeScene("scene1");
	}
}

void scene5::render()
{
	IMAGEMANAGER->render("����2", getMemDC());
	
	_player->render();
}
