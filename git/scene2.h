#pragma once
#include"gameNode.h"
#include"player.h"

class scene2 : public gameNode
{
private:
	player* _player;
	char str[120];
public:
	scene2();
	~scene2();

	bool out;

	HRESULT init();
	void release();
	void update();
	void render();
};

