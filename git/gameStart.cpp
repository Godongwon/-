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
	
	_startButtonimg = IMAGEMANAGER->addImage("시작버튼", "image/Scene/bigButton.bmp", 599, 154, true, RGB(255, 0, 255));
	_startButton = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 127, _startButtonimg->getWidth(), _startButtonimg->getHeight());
	IMAGEMANAGER->addImage("게임시작화면", "image/Scene/startScene.bmp", WINSIZEX, WINSIZEY,true,RGB(255,0,255));

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
			SCENEMANAGER->changeScene("게임레디화면");
		}
	}
}

void gameStart::render()
{
	IMAGEMANAGER->render("게임시작화면", getMemDC());
	IMAGEMANAGER->render("시작버튼", getMemDC(), _startButton.left, _startButton.top);
}
