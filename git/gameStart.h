#pragma once
#include"gameNode.h"
#include"sceneReady.h"

class gameStart:public gameNode
{
private:
	RECT _startButton;
	image* _startButtonimg;
	
public:
	gameStart();
	~gameStart();

	HRESULT init();
	void release();
	void update();
	void render();
};

