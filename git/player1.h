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
	string name;			//ĳ���� �̸�
	
	RECT player1;
	image* characterimgMove;	//ĳ�����̹���-����

	image* characterimgBubble;	//ĳ�����̹���-�������
	image* characterimgdie;	//ĳ�����̹���-�״¸��
	image* characterimgSence;	//ĳ�����̹���-���¸��
	bool _player1_Live;
	bool _player1_Die;
	float player1_speed;
	int player1_X;
	int player1_Y;

	RECT Collision;
	bool player1_Go;
	float bombNumber;	//��ǳ�� ����
	float bombPower;	//��ǳ�� ���ٱ�
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

	
	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render();//�׸��°�

	

	
	
};

