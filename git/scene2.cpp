#include "stdafx.h"
#include "scene2.h"
#include "player.h"
scene2::scene2()
{
}

scene2::~scene2()
{
}

HRESULT scene2::init()
{
	out = false;
	_player =new player;
	_player -> init();
	_player->_player = RectMakeCenter(WINSIZEX, WINSIZEY/2, _player->i_player->getFrameWidth(), _player->i_player->getFrameHeight());

	IMAGEMANAGER->addImage("보스방", "images/보스방1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	return S_OK;
}
void scene2::release()
{
	SAFE_DELETE(_player);
}

void scene2::update()
{
	_player->update();
	if (_player->get_finalX() > WINSIZEX)//윈쪽방-보스
	{
		out = true;
		SCENEMANAGER->changeScene("scene1");
		
	}
}

void scene2::render()
{
	
	IMAGEMANAGER->render("보스방", getMemDC());
	wsprintf(str, " _finalX : %d|_finaly : %d", _player->get_finalX(), _player->get_finalY());
	TextOut(getMemDC(), WINSIZEX / 2, 0, str, strlen(str));
	_player->render();
		
}
