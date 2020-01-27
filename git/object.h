#pragma once
#include"gameNode.h"

#include"map.h"

struct tagObject
{
	RECT _object;
	image* _objectimg;

	int num;

};
enum itemName
{
	posion = 0,
	bollon,
	shose,
	EMP
};
struct Itemtag
{
	itemName _itemName;
	RECT _item;
	image* _itemimg;

	int effect;


};
class object : public gameNode
{
private:
	typedef vector<tagObject>			_VObject;
	typedef vector<tagObject>::iterator _VIObject;
	
	_VObject _vObject;
	_VIObject _viObject;
	
	typedef vector<Itemtag> _VItem;
	typedef vector<Itemtag>::iterator _VIItem;
	_VItem _vItem;
	_VIItem _viItem;

	Map* _map;


public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();


	void Objectinput(const char* fileName);


	void itemInput();
	void itemDelete(int Itemnum);

	_VObject getVobject() { return _vObject; }
	_VIObject getVIobject() { return _viObject; }

	vector<tagObject>& getobj() { return _vObject; }

	vector<Itemtag>& getitem(){ return _vItem; }
};

