#pragma once
#include"gameNode.h"
#include"player.h"
class scene4 :public gameNode
{
private:
	player* _player;
public:
	scene4();
	~scene4();

	HRESULT init();
	void release();
	void update();
	void render();
};

