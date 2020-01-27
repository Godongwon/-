#pragma once
#include"gameNode.h"
#include"player.h"
#include"scene2.h"

class scene1 : public gameNode
{
private:
	player* _player;
	scene2* _scene2;
	char str[120];
public:
	scene1();
	~scene1();
	
	HRESULT init();
	void release();
	void update();
	void render();
	

	
};

