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
	IMAGEMANAGER->addImage("����", "images/����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}

void scene3::release()
{
}

void scene3::update()
{
	_player->update();
	//_player->set_final();

	if (_player->get_finalX() < 0)//�����ʹ濡�� �����°Ŵ�
	{
		SCENEMANAGER->changeScene("scene1");
	}
}

void scene3::render()
{
	IMAGEMANAGER->render("����", getMemDC());
	
	_player->render();
}
