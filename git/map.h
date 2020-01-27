#pragma once
#include"gameNode.h"
//#include"object.h"

class Map :public gameNode
{
private:
	struct MAP_INFO
	{
		RECT map;
		image* mapimg;
		bool bomb;
		bool move;
	};
	
	bool debug;
	

public:
	Map();
	~Map();
	RECT _BicMap;
	MAP_INFO _map[15][13];
	HRESULT init();	//초기화
	void release();//해제
	void update();//연산하는곳
	void render();//그리는곳
	

	
};

