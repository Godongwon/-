#pragma once
#include"gameNode.h"
#include"gameStart.h"
#include"sceneReady.h"
#include"inGame.h"

class mainGame :  public gameNode
{
private:

	RECT _mouse;
	image* _mouseimg;
	int _mousePointX;
	int _mousePointY;


public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	void MouseMove();
	

	
};

