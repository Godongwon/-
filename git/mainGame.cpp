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
	
	_mouseimg = IMAGEMANAGER->addImage("���콺", "image/��Ÿ/mouse.bmp", _mousePointX, _mousePointY, 33, 36, true, RGB(255, 0, 255));
	_mouse = RectMakeCenter(_mousePointX, _mousePointY, _mouseimg->getWidth(), _mouseimg->getHeight());
	//��
	SCENEMANAGER->addScene("���ӽ���ȭ��", new gameStart);
	SCENEMANAGER->addScene("���ӷ���ȭ��", new sceneReady);
	SCENEMANAGER->addScene("�ΰ���ȭ��", new inGame);



	SCENEMANAGER->changeScene("���ӽ���ȭ��");
	
	

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
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	SCENEMANAGER->render();
	ShowCursor(FALSE);


	IMAGEMANAGER->render("���콺",getMemDC(),_mouse.left,_mouse.top);
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void mainGame::MouseMove()
{
	_mousePointX = m_ptMouse.x;
	_mousePointY =m_ptMouse.y;
	_mouse = RectMakeCenter(_mousePointX, _mousePointY, _mouseimg->getWidth(), _mouseimg->getHeight());

	
}

