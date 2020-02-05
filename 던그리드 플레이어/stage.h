#pragma once
#include "base/gameNode.h"

class stage : public gameNode
{
private:
	image * _img;
	RECT ground;

public:
	stage();
	~stage();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

};



