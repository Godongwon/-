#pragma once
//#include"singletonBase.h"
//#include"gameNode.h"
//#include"image.h"
class gameNode;
struct CHARACTER_INFO
{
	string name[120];			//ĳ���� �̸�
	image* characterimg;		//ĳ�����̹���-��� ȭ��
	image* characterimgLeft;	//ĳ�����̹���-����
	image* characterimgRight;	//ĳ�����̹���-������
	image* characterimgUp;		//ĳ�����̹���-�ö�
	image* characterimgDown;	//ĳ�����̹���-������
	image* characterimgBubble;	//ĳ�����̹���-�������
	image* characterimgdie;	//ĳ�����̹���-�״¸��
	image* characterimgSence;	//ĳ�����̹���-���¸��

	float bombNumber = 1;		//��ǳ�� ����
	float bombPower = 1;		//��ǳ�� ���ٱ�
	float bompPopTop = 1;
	float bompPopBottom = 1;
	float bompPopLeft = 1;
	float bompPopRight = 1;

};
CHARACTER_INFO _character;
class playerManager 
{


public:
	playerManager();
	~playerManager();


	void character_Dao();
	void character_Bazzi();
	void character_Dizni();

};

