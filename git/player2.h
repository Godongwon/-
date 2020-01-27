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
	string name;			//ĳ���� �̸�
	RECT player2;
	image* characterimgMove;	//ĳ�����̹���-����
	image* characterimgBubble;	//ĳ�����̹���-�������
	image* characterimgdie;	//ĳ�����̹���-�״¸��
	image* characterimgSence;	//ĳ�����̹���-���¸��
	bool _player2_Live;
	bool _player2_Die;
	float player2_speed;
	int player2_X;
	int player2_Y;
	RECT Collision2;
	bool player2_Go;
	float bombNumber;	//��ǳ�� ����
	float bombPower;	//��ǳ�� ���ٱ�
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


	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render();//�׸��°�




};
