#pragma once
#include "gameNode.h"
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
class Player : public gameNode
{
protected:

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
public:
	Player();
	~Player();
};

