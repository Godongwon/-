#pragma once
#include"gameNode.h"
#include"inGame.h"


class sceneReady : public gameNode
{
private:
	image* _inGameButtonimg;
	RECT _inGameButton;
	//플레이어의 캐릭터를 보여줄 디스플레이
	RECT player1_display;
	RECT player2_display;
	image*	player1Chrater;
	image*	player2Chrater;
	//캐릭터 선택 창 디스플레이
	RECT Dao_Display;
	RECT bazzi_Display;
	RECT dizni_Display;
	image* _daoReatyimg;
	image* _bazziReatyimg;
	image* _dizniReatyimg;
	
public:
	sceneReady();
	~sceneReady();


	HRESULT init();
	void release();
	void update();
	void render();
};

