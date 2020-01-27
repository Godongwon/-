#include "stdafx.h"
#include "sceneReady.h"


sceneReady::sceneReady()
{
}


sceneReady::~sceneReady()
{
}

HRESULT sceneReady::init()
{
	
	IMAGEMANAGER->addImage("게임레디화면", "image/Scene/readyScene.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_inGameButtonimg=IMAGEMANAGER->addImage("인게임버튼","image/Scene/startButton.bmp",213,62,true,RGB(255,0,255));
	_inGameButton = RectMakeCenter(WINSIZEX - 190, WINSIZEY - 78, _inGameButtonimg->getWidth(), _inGameButtonimg->getHeight());
	//플레이어 디스플레이
	player1_display = RectMakeCenter(77, 145, 54, 63);
	player2_display= RectMakeCenter(185, 145, 54, 63);
	player1Chrater = IMAGEMANAGER->addImage("다오", "image/다오/daoReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));
	player1Chrater = IMAGEMANAGER->addImage("배찌", "image/배찌/bazziReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));

	//캐릭터 선택 디스플레이
	Dao_Display=RectMakeCenter(532, 150,65+(65*0.5),43+ (43*0.50));
	bazzi_Display = RectMakeCenter(Dao_Display.right+ 50 , (Dao_Display.top+ Dao_Display.bottom)/2, 65 + (65 * 0.5), 43 + (43 * 0.50));
	dizni_Display = RectMakeCenter(bazzi_Display.right+50, (Dao_Display.top + Dao_Display.bottom) / 2, 65 + (65 * 0.5), 43 + (43 * 0.50));

	_daoReatyimg=IMAGEMANAGER->addFrameImage("다오래디화면","image/다오/daoReady.bmp", (65 + (65 * 0.5))*2,43 + (43 * 0.50),2,1,true,RGB(255,0,255));
	_bazziReatyimg=IMAGEMANAGER->addFrameImage("배찌래디화면", "image/배찌/BazziReady.bmp", (65 + (65 * 0.5)) * 2, 43 + (43 * 0.50), 2, 1, true, RGB(255, 0, 255));
	_dizniReatyimg= IMAGEMANAGER->addFrameImage("디지니래디화면", "image/디지니/dizniReady.bmp", (65 + (65 * 0.5)) * 2, 43 + (43 * 0.50), 2, 1, true, RGB(255, 0, 255));;

	

	


	return S_OK;
}

void sceneReady::release()
{
}


void sceneReady::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if ((m_ptMouse.x > _inGameButton.left&&m_ptMouse.x < _inGameButton.right) && (m_ptMouse.y > _inGameButton.top&&m_ptMouse.y < _inGameButton.bottom))
		{
			SCENEMANAGER->changeScene("인게임화면");
		}
	}

	
	if ((m_ptMouse.x > Dao_Display.left&&m_ptMouse.x < Dao_Display.right) && (m_ptMouse.y > Dao_Display.top&&m_ptMouse.y < Dao_Display.bottom))
	{
		_daoReatyimg->setFrameX(1);
	}
	else
	{
		_daoReatyimg->setFrameX(0);
	}
	if ((m_ptMouse.x > bazzi_Display.left&&m_ptMouse.x < bazzi_Display.right) && (m_ptMouse.y > bazzi_Display.top&&m_ptMouse.y < bazzi_Display.bottom))
	{
		_bazziReatyimg->setFrameX(1);
	}
	else
	{
		_bazziReatyimg->setFrameX(0);
	}
	if ((m_ptMouse.x > dizni_Display.left&&m_ptMouse.x < dizni_Display.right) && (m_ptMouse.y > dizni_Display.top&&m_ptMouse.y < dizni_Display.bottom))
	{
		_dizniReatyimg->setFrameX(1);
	}
	else
	{
		_dizniReatyimg->setFrameX(0);
	}

	



}

void sceneReady::render()
{
	IMAGEMANAGER->render("게임레디화면", getMemDC());
	IMAGEMANAGER->render("인게임버튼", getMemDC(), _inGameButton.left, _inGameButton.top);
	IMAGEMANAGER->render("다오", getMemDC(), player1_display.left, player1_display.top);
	IMAGEMANAGER->render("배찌", getMemDC(), player2_display.left, player2_display.top);
	IMAGEMANAGER->frameRender("다오래디화면", getMemDC(), Dao_Display.left, Dao_Display.top, _daoReatyimg->getFrameX(), 0);
	IMAGEMANAGER->frameRender("배찌래디화면", getMemDC(), bazzi_Display.left, bazzi_Display.top, _bazziReatyimg->getFrameX(),0);
	IMAGEMANAGER->frameRender("디지니래디화면", getMemDC(), dizni_Display.left, dizni_Display.top, _dizniReatyimg->getFrameX(),0);
}
