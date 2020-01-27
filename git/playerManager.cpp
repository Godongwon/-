#include "stdafx.h"
#include "playerManager.h"


playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}




void playerManager::character_Dao()
{
	*_character.name = "Dao";
	_character.characterimg = IMAGEMANAGER->addImage("�ٿ�", "image/�ٿ�/daoReadyCharacter.bmp", 54, 63,true,RGB(255,0,255));
	_character.characterimgLeft= IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoLeft.bmp", 308, 60,7,1, true, RGB(255, 0, 255));
	_character.characterimgRight = IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoRight.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgUp = IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoUp.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgDown= IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoDown.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgBubble=	IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoBubble.bmp", 960, 65, 16, 1, true, RGB(255, 0, 255));
	_character.characterimgdie=		IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_character.characterimgSence=	IMAGEMANAGER->addFrameImage("�ٿ�", "image/�ٿ�/daoGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
}

void playerManager::character_Bazzi()
{
	*_character.name = "Bazzi";
	_character.characterimg =		IMAGEMANAGER->addImage("����", "image/����/bazziReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));
	_character.characterimgLeft =	IMAGEMANAGER->addFrameImage("����", "image/����/bazziLeft.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgRight =	IMAGEMANAGER->addFrameImage("����", "image/����/bazziRight.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgUp =		IMAGEMANAGER->addFrameImage("����", "image/����/bazziUp.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgDown =	IMAGEMANAGER->addFrameImage("����", "image/����/bazziDown.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgBubble =	IMAGEMANAGER->addFrameImage("����", "image/����/bazziBubble.bmp", 960, 65, 16, 1, true, RGB(255, 0, 255));
	_character.characterimgdie =		IMAGEMANAGER->addFrameImage("����", "image/����/bazziDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_character.characterimgSence =	IMAGEMANAGER->addFrameImage("����", "image/����/bazziGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
}

void playerManager::character_Dizni()
{
	*_character.name = "Dizni";
	_character.characterimg =		IMAGEMANAGER->addImage("������", "image/������/dizniReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));
	_character.characterimgLeft =	IMAGEMANAGER->addFrameImage("������", "image/������/dizniLeft.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgRight =	IMAGEMANAGER->addFrameImage("������", "image/������/dizniRight.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgUp =		IMAGEMANAGER->addFrameImage("������", "image/������/dizniUp.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgDown =	IMAGEMANAGER->addFrameImage("������", "image/������/dizniDown.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgBubble =	IMAGEMANAGER->addFrameImage("������", "image/������/dizniBubble.bmp", 960, 65, 16, 1, true, RGB(255, 0, 255));
	_character.characterimgdie =		IMAGEMANAGER->addFrameImage("������", "image/������/dizniDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_character.characterimgSence =	IMAGEMANAGER->addFrameImage("������", "image/������/dizniGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
}




