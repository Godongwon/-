#pragma once
#include"gameNode.h"
#include"player.h"
class scene5:public gameNode
{
private:
	player* _player;
public:
	scene5();
	~scene5();
	HRESULT init();
	void release();
	void update();
	void render();
};

