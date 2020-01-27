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
	_character.characterimg = IMAGEMANAGER->addImage("다오", "image/다오/daoReadyCharacter.bmp", 54, 63,true,RGB(255,0,255));
	_character.characterimgLeft= IMAGEMANAGER->addFrameImage("다오", "image/다오/daoLeft.bmp", 308, 60,7,1, true, RGB(255, 0, 255));
	_character.characterimgRight = IMAGEMANAGER->addFrameImage("다오", "image/다오/daoRight.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgUp = IMAGEMANAGER->addFrameImage("다오", "image/다오/daoUp.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgDown= IMAGEMANAGER->addFrameImage("다오", "image/다오/daoDown.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgBubble=	IMAGEMANAGER->addFrameImage("다오", "image/다오/daoBubble.bmp", 960, 65, 16, 1, true, RGB(255, 0, 255));
	_character.characterimgdie=		IMAGEMANAGER->addFrameImage("다오", "image/다오/daoDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_character.characterimgSence=	IMAGEMANAGER->addFrameImage("다오", "image/다오/daoGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
}

void playerManager::character_Bazzi()
{
	*_character.name = "Bazzi";
	_character.characterimg =		IMAGEMANAGER->addImage("배찌", "image/배찌/bazziReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));
	_character.characterimgLeft =	IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziLeft.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgRight =	IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziRight.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgUp =		IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziUp.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgDown =	IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziDown.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgBubble =	IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziBubble.bmp", 960, 65, 16, 1, true, RGB(255, 0, 255));
	_character.characterimgdie =		IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_character.characterimgSence =	IMAGEMANAGER->addFrameImage("배찌", "image/배찌/bazziGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
}

void playerManager::character_Dizni()
{
	*_character.name = "Dizni";
	_character.characterimg =		IMAGEMANAGER->addImage("디지니", "image/디지니/dizniReadyCharacter.bmp", 54, 63, true, RGB(255, 0, 255));
	_character.characterimgLeft =	IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniLeft.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgRight =	IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniRight.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgUp =		IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniUp.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgDown =	IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniDown.bmp", 308, 60, 7, 1, true, RGB(255, 0, 255));
	_character.characterimgBubble =	IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniBubble.bmp", 960, 65, 16, 1, true, RGB(255, 0, 255));
	_character.characterimgdie =		IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniDie.bmp", 770, 110, 11, 1, true, RGB(255, 0, 255));
	_character.characterimgSence =	IMAGEMANAGER->addFrameImage("디지니", "image/디지니/dizniGameSenceCharacter.bmp", 90, 34, 2, 1, true, RGB(255, 0, 255));
}




