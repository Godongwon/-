#pragma once
#include "base/gameNode.h"
#include "base/singletonBase.h"
enum player_WAY
{
	Left=0,
	Right
};

enum player_MOVE
{
	Idle=0,
	Move,
	Jump
};
class Player : public gameNode  ,public singletonBase<Player>
{
private:

	player_WAY _playerWay;
	player_MOVE _playerMove;
	RECT _playerRC;
	image* _playerimg;
	int _playerFocusX;
	int _playerSpeed;
	int _playerJumpCount;
	bool b_isJump;
	bool b_Debug;
	//나중에 합시다.
	//int _playerAtk;
	//int _playerDef;
	//bool b_playerFight;




	RECT _Ground;//테스트용 바닥 -> 나중에 지워라

	int _playerMoveCount;

	void player_Move();
	void player_Jump();


public:
	

	Player();
	~Player();
	RECT get_player() { return _playerRC; }



	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);

};

#define PLAYER	Player::getSingleton()
