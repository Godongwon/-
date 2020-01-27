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


	_mousePointX = WINSIZEX / 2;
	_mousePointY = WINSIZEY / 2;
	
	_mouseimg = IMAGEMANAGER->addImage("마우스", "image/기타/mouse.bmp", _mousePointX, _mousePointY, 33, 36, true, RGB(255, 0, 255));
	_mouse = RectMakeCenter(_mousePointX, _mousePointY, _mouseimg->getWidth(), _mouseimg->getHeight());
	//씬
	SCENEMANAGER->addScene("게임시작화면", new gameStart);
	SCENEMANAGER->addScene("게임레디화면", new sceneReady);
	SCENEMANAGER->addScene("인게임화면", new inGame);



	SCENEMANAGER->changeScene("게임시작화면");
	
	

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();


}
void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	MouseMove();
	
	
}

void mainGame::render(/*HDC hdc*/)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	SCENEMANAGER->render();
	ShowCursor(FALSE);


	IMAGEMANAGER->render("마우스",getMemDC(),_mouse.left,_mouse.top);
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void mainGame::MouseMove()
{
	_mousePointX = m_ptMouse.x;
	_mousePointY =m_ptMouse.y;
	_mouse = RectMakeCenter(_mousePointX, _mousePointY, _mouseimg->getWidth(), _mouseimg->getHeight());

	
}

