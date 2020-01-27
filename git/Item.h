#pragma once
#include"gameNode.h"
class player1;
class player2;
class map;

struct Itemtag
{
	itemName _itemName;
	RECT _item;
	image* _itemimg;
	//int item_x, item_y;
	int effect;


};
class Item:public gameNode
{
private:


	
	
	vector<Itemtag> v_item;
	vector<Itemtag>::iterator vi_item;


	player1* player_1;
	player2* player_2;
	Map* _map;

	

	//Itemtag _posion;//물풍선 줄기
	//Itemtag _bollon;//물풍선 개수
	//Itemtag _shose;//플레이어 스피드 증가


public:
	Item();
	~Item();

	HRESULT init();
	void release();
	void update();
	void render();

	
	void itemInput();


};

