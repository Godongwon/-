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
	
	IMAGEMANAGER->addImage("���ӷ���ȭ��", "image/Scene/readyScene.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_inGameButtonimg=IMAGEMANAGER->addImage("�ΰ��ӹ�ư","image/Scene/startButton.bmp",213,62,true,RGB(255,0,255));
	_inGameButton = RectMakeCenter(WINSIZEX - 190, WINSIZEY - 78, _inGameButtonimg->getWidth(), _inGameButtonimg->getHeight());
	//�÷��̾� ���÷���
	player1_display = RectMakeCenter(77, 145, 54, 63);
	player2_display= RectMakeCenter(185, 145, 54, 63);
	player1Chrater = IMAGEMANAGER->addImage("�ٿ�", "image/�ٿ�/daoReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));
	player1Chrater = IMAGEMANAGER->addImage("����", "image/����/bazziReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));

	//ĳ���� ���� ���÷���
	Dao_Display=RectMakeCenter(532, 150,65+(65*0.5),43+ (43*0.50));
	bazzi_Display = RectMakeCenter(Dao_Display.right+ 50 , (Dao_Display.top+ Dao_Display.bottom)/2, 65 + (65 * 0.5), 43 + (43 * 0.50));
	dizni_Display = RectMakeCenter(bazzi_Display.right+50, (Dao_Display.top + Dao_Display.bottom) / 2, 65 + (65 * 0.5), 43 + (43 * 0.50));

	_daoReatyimg=IMAGEMANAGER->addFrameImage("�ٿ�����ȭ��","image/�ٿ�/daoReady.bmp", (65 + (65 * 0.5))*2,43 + (43 * 0.50),2,1,true,RGB(255,0,255));
	_bazziReatyimg=IMAGEMANAGER->addFrameImage("�����ȭ��", "image/����/BazziReady.bmp", (65 + (65 * 0.5)) * 2, 43 + (43 * 0.50), 2, 1, true, RGB(255, 0, 255));
	_dizniReatyimg= IMAGEMANAGER->addFrameImage("�����Ϸ���ȭ��", "image/������/dizniReady.bmp", (65 + (65 * 0.5)) * 2, 43 + (43 * 0.50), 2, 1, true, RGB(255, 0, 255));;

	

	


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
			SCENEMANAGER->changeScene("�ΰ���ȭ��");
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
	IMAGEMANAGER->render("���ӷ���ȭ��", getMemDC());
	IMAGEMANAGER->render("�ΰ��ӹ�ư", getMemDC(), _inGameButton.left, _inGameButton.top);
	IMAGEMANAGER->render("�ٿ�", getMemDC(), player1_display.left, player1_display.top);
	IMAGEMANAGER->render("����", getMemDC(), player2_display.left, player2_display.top);
	IMAGEMANAGER->frameRender("�ٿ�����ȭ��", getMemDC(), Dao_Display.left, Dao_Display.top, _daoReatyimg->getFrameX(), 0);
	IMAGEMANAGER->frameRender("�����ȭ��", getMemDC(), bazzi_Display.left, bazzi_Display.top, _bazziReatyimg->getFrameX(),0);
	IMAGEMANAGER->frameRender("�����Ϸ���ȭ��", getMemDC(), dizni_Display.left, dizni_Display.top, _dizniReatyimg->getFrameX(),0);
}
