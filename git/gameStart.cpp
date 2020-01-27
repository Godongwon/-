#include "stdafx.h"
#include "gameStart.h"


gameStart::gameStart()
{
}


gameStart::~gameStart()
{
}

HRESULT gameStart::init()
{
	
	_startButtonimg = IMAGEMANAGER->addImage("���۹�ư", "image/Scene/bigButton.bmp", 599, 154, true, RGB(255, 0, 255));
	_startButton = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 127, _startButtonimg->getWidth(), _startButtonimg->getHeight());
	IMAGEMANAGER->addImage("���ӽ���ȭ��", "image/Scene/startScene.bmp", WINSIZEX, WINSIZEY,true,RGB(255,0,255));

	return S_OK;
}

void gameStart::release()
{
}

void gameStart::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if ((m_ptMouse.x > _startButton.left&&m_ptMouse.x < _startButton.right) && (m_ptMouse.y > _startButton.top&&m_ptMouse.y < _startButton.bottom))
		{
			SCENEMANAGER->changeScene("���ӷ���ȭ��");
		}
	}
}

void gameStart::render()
{
	IMAGEMANAGER->render("���ӽ���ȭ��", getMemDC());
	IMAGEMANAGER->render("���۹�ư", getMemDC(), _startButton.left, _startButton.top);
}
