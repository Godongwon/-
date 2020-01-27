#include"gameNode.h"
#include"map.h"
#include"bomb2.h"
#include"object.h"
enum player2_Move
{
	Player2_RIGHT = 0,
	Player2_LEFT,
	Player2_UP,
	Player2_DOWN
};
struct PLAYER2_INFO
{
	string name;			//캐릭터 이름
	RECT player2;
	image* characterimgMove;	//캐릭터이미지-왼쪽
	image* characterimgBubble;	//캐릭터이미지-버블상태
	image* characterimgdie;	//캐릭터이미지-죽는모션
	image* characterimgSence;	//캐릭터이미지-상태모션
	bool _player2_Live;
	bool _player2_Die;
	float player2_speed;
	int player2_X;
	int player2_Y;
	RECT Collision2;
	bool player2_Go;
	float bombNumber;	//물풍선 개수
	float bombPower;	//물풍선 물줄기
	float bompPopTop;
	float bompPopBottom;
	float bompPopLeft;
	float bompPopRight;

};
class player2 : public gameNode
{
private:
	player2_Move _playerMove;
	Map* map;
	object* _object;
	int _count;
	int _index;
	RECT player2_senceRC;
	
public:
	player2();
	~player2();
	bomb2* player2_bomb;
	PLAYER2_INFO _player_2;


	HRESULT init();	//초기화
	void release();//해제
	void update();//연산하는곳
	void render();//그리는곳




};
