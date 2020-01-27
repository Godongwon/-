#pragma once
//#include"singletonBase.h"
//#include"gameNode.h"
//#include"image.h"
class gameNode;
struct CHARACTER_INFO
{
	string name[120];			//캐릭터 이름
	image* characterimg;		//캐릭터이미지-대기 화면
	image* characterimgLeft;	//캐릭터이미지-왼쪽
	image* characterimgRight;	//캐릭터이미지-오른쪽
	image* characterimgUp;		//캐릭터이미지-올라감
	image* characterimgDown;	//캐릭터이미지-내려감
	image* characterimgBubble;	//캐릭터이미지-버블상태
	image* characterimgdie;	//캐릭터이미지-죽는모션
	image* characterimgSence;	//캐릭터이미지-상태모션

	float bombNumber = 1;		//물풍선 개수
	float bombPower = 1;		//물풍선 물줄기
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

