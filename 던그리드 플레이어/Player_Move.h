#pragma once
#include"Player.h"
class Player_Move : Player
{
private:
	
	RECT _Ground;//�׽�Ʈ�� �ٴ� -> ���߿� ������


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

