#pragma once
#include"gameNode.h"
#include"map.h"

struct tagbomb
{
	image* bombimg;
	RECT bomb_rc;
	float x, y;
	//float angle;
	
	int bombcount;//프레임돌리는 카운터
	int boomcount;//물풍선돌리는 카운터
	bool boom;//터졌냐?
	bool fire;

	image*	boomRightimg;
	image*	boomLeftimg;
	image*	boomUpimg;
	image*	boomDownimg;
	image*	boomCenterimg;

	RECT	boomRight_rc;
	RECT	boomLeft_rc;
	RECT	boomUp_rc;
	RECT	boomDown_rc;
	RECT	boomCenter_rc;
	

};
class bomb1 : public gameNode
{
private:
	
	typedef vector<tagbomb> _Vbomb;
	typedef vector<tagbomb> ::iterator _VIbomb;

	_Vbomb _vbomb;
	_VIbomb _vibomb;
	Map* _map;
public:
	bomb1();
	~bomb1();

	HRESULT init(int bombmax);
	void release();
	void update();
	void render();
	void boom(float x, float y);

	_Vbomb getVbomb() { return _vbomb; }
	_VIbomb getVibomb() { return _vibomb; }

	vector<tagbomb>& getBombVector() { return _vbomb; }

	//void bombBoomimg();
	
};

