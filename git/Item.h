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

	

	//Itemtag _posion;//��ǳ�� �ٱ�
	//Itemtag _bollon;//��ǳ�� ����
	//Itemtag _shose;//�÷��̾� ���ǵ� ����


public:
	Item();
	~Item();

	HRESULT init();
	void release();
	void update();
	void render();

	
	void itemInput();


};

