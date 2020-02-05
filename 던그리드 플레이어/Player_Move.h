#pragma once
#include"Player.h"
class Player_Move : Player
{
private:
	
	RECT _Ground;//테스트용 바닥 -> 나중에 지워라


	int _playerMoveCount;

	void player_Move();
	void player_Jump();

public:
	Player_Move();
	~Player_Move();

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);



};

