#include "stdafx.h"
#include "scene1.h"
//#include"player.h"

scene1::scene1()
{
}


scene1::~scene1()
{
}

HRESULT scene1::init()
{
	_scene2 = new scene2;
	_player = new player;
	_player->init();
	if (_scene2->out)
	{
		_player->_player = RectMakeCenter(100, WINSIZEY / 2, _player->i_player->getFrameWidth(), _player->i_player->getFrameHeight());
		_scene2->out = false;
	}
	//_player->_player = RectMakeCenter(WINSIZEX, WINSIZEY / 2, _player->i_player->getFrameWidth(), _player->i_player->getFrameHeight());
	
	IMAGEMANAGER->addImage("대기방", "images/대기방.bmp", WINSIZEX, WINSIZEY,true, RGB(255,0,255));

	return S_OK;
}

void scene1::release()
{
	//SAFE_DELETE(_player);
}
/*
SCENEMANAGER->changeScene("scene1");
*/

void scene1::update()
{
	_player->update();
	//_player->set_final();
	
	if (_player->get_finalX()< 0)//윈쪽방-보스
	{
		SCENEMANAGER->changeScene("scene2");
	}

	if (_player->get_finalX() > WINSIZEX)//오른쪽방-상점
	{
		SCENEMANAGER->changeScene("scene3");
	}


	if (_player->get_finalY() < 0)//위쪽방-몬스터1
	{
		SCENEMANAGER->changeScene("scene4");
	}

	if (_player->get_finalY() > WINSIZEY)//아래방-몬스터2
	{
		SCENEMANAGER->changeScene("scene5");
	}
	/*if (KEYMANAGER->isOnceKeyDown('2'))
	{
		씬체인지
		SCENEMANAGER->changeScene("scene2");
	}*/
}

void scene1::render()
{
	IMAGEMANAGER->render("대기방", getMemDC());
	wsprintf(str, " _finalX : %d|_finaly : %d", _player->get_finalX(), _player->get_finalY());
	TextOut(getMemDC(), WINSIZEX / 2, 0, str, strlen(str));
	_player->render();
	
}
