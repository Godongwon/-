#pragma once
//class playerManager;
#include"gameNode.h"
#include"map.h"
#include"bomb1.h"
#include"object.h"
//#include"player2.h"

enum player1_Move
{
	RIGHT = 0,
	LEFT,
	UP,
	DOWN
};
struct PLAYER1_INFO
{
	string name;			//캐릭터 이름
	
	RECT player1;
	image* characterimgMove;	//캐릭터이미지-왼쪽

	image* characterimgBubble;	//캐릭터이미지-버블상태
	image* characterimgdie;	//캐릭터이미지-죽는모션
	image* characterimgSence;	//캐릭터이미지-상태모션
	bool _player1_Live;
	bool _player1_Die;
	float player1_speed;
	int player1_X;
	int player1_Y;

	RECT Collision;
	bool player1_Go;
	float bombNumber;	//물풍선 개수
	float bombPower;	//물풍선 물줄기
	float bompPopTop;
	float bompPopBottom;
	float bompPopLeft;
	float bompPopRight;

};
class player1 : public gameNode
{
private:
	//player2* player_2;

	player1_Move _playerMove;
	Map* map;
	object* _object;
	int _count;
	int _index;
	RECT player1_senceRC;
	image* player1_sence;
public:
	player1();
	~player1();
	PLAYER1_INFO _player_1;
	bomb1* player1_bomb;

	
	HRESULT init();	//초기화
	void release();//해제
	void update();//연산하는곳
	void render();//그리는곳

	

	
	
};

