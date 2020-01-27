#pragma once
#include "gameNode.h"
#include "map.h"
#include"player1.h"
#include"player2.h"
#include"object.h"

class inGame:public gameNode
{
private:
	Map* map;
	player1* _player1;
	player2* _player2;
	object* _object;
	
	RECT outButton;

public:
	inGame();
	~inGame();
	HRESULT init();
	void release();
	void update();
	void render();

	void playerDie();
	void Objectdelete();
	void ItemEat();

	
};

