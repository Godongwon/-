#pragma once
#include"gameNode.h"
#include"Player_Move.h"

class mainGame : public gameNode
{
private:
	Player_Move* _playerMove;
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
};

