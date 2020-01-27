#pragma once
#include"gameNode.h"
#include"map.h"

struct tagbomb2
{
	image* bombimg2;
	RECT bomb_rc2;
	float x2, y2;
	//float angle;

	int bombcount2;//프레임돌리는 카운터
	int boomcount2;//물풍선돌리는 카운터
	bool boom2;//터졌냐?
	bool fire2;

	image*	boomRightimg2;
	image*	boomLeftimg2;
	image*	boomUpimg2;
	image*	boomDownimg2;
	image*	boomCenterimg2;

	RECT	boomRight_rc2;
	RECT	boomLeft_rc2;
	RECT	boomUp_rc2;
	RECT	boomDown_rc2;
	RECT	boomCenter_rc2;

};
class bomb2 : public gameNode
{
private:

	typedef vector<tagbomb2> _Vbomb2;
	typedef vector<tagbomb2> ::iterator _VIbomb2;


	_Vbomb2 _vbomb2;
	_VIbomb2 _vibomb2;

	Map* _map;
public:
	bomb2();
	~bomb2();

	HRESULT init(int bombmax);
	void release();
	void update();
	void render();

	void boom(float x, float y);

	_Vbomb2 getVbomb2() { return _vbomb2; }
	_VIbomb2 getVibomb2() { return _vibomb2; }

	vector<tagbomb2>& getBombVector2() { return _vbomb2; }
};

