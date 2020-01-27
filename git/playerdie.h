#pragma once
#include"gameNode.h"
#include"player1.h"
#include"player2.h"



class playerdie:public gameNode
{
private:
	player1* player_1;
	player2* player_2;

public:
	playerdie();
	~playerdie();
	HRESULT init();

	bool player1Die();
	bool player2Die();
};

