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

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

};



