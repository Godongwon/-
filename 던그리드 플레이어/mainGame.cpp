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
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//====================================================================
	


	_playerMove->render();




	//====================================================================
	//������� ������ HDC�� �׸���.(��������!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}









