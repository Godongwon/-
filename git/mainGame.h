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

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	void MouseMove();
	

	
};

