#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);
	_playerMove = new Player_Move;
	_playerMove -> init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	_playerMove->release();

}

void mainGame::update()
{
	gameNode::update();
	_playerMove->update();

}

void mainGame::render(/*HDC hdc*/)
{
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//====================================================================
	


	_playerMove->render();




	//====================================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}









