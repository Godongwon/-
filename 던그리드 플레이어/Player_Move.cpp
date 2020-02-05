#include "stdafx.h"
#include "Player_Move.h"


void Player_Move::player_Move()
{
	if (_playerWay == Left)
	{
		switch (_playerMove)
		{
		case Idle:
			_playerimg = IMAGEMANAGER->findImage("LEFT_IDLE");
			break;
		case Move:
			_playerimg = IMAGEMANAGER->findImage("LEFT_MOVE");
			break;
		case Jump:
			_playerimg = IMAGEMANAGER->findImage("LEFT_JUMP");
			break;
		}
	}
	else if (_playerWay == Right)
	{
		switch (_playerMove)
		{
		
			case Idle:
				_playerimg = IMAGEMANAGER->findImage("RIGHT_IDLE");
								break;
			case Move:
				_playerimg = IMAGEMANAGER->findImage("RIGHT_MOVE");
			
				break;
			case Jump:
				_playerimg = IMAGEMANAGER->findImage("RIGHT_JUMP");
				break;
			
		}
	}
	
}
void Player_Move::player_Jump()
{
	if (_playerJumpCount <=60)
	{
		OffsetRect(&_playerRC, 0, -(_playerSpeed+2));
		_playerJumpCount++;
	}
	if (_playerJumpCount >= 60)
	{
		OffsetRect(&_playerRC, 0, _playerSpeed+2);
		_playerJumpCount++;
	}

	if (_playerRC.bottom < _Ground.top)
	{
		_playerMove = Jump;
	}
	else
	{
		//_playerMove = Idle;
		_playerJumpCount = 0;
		b_isJump = false;
	}
}
/////////////////////////////////////////////////////
Player_Move::Player_Move()
{
}


Player_Move::~Player_Move()
{
}
////////////////////////////////////////////////////////
HRESULT Player_Move::init()
{
	//아이들상태
	IMAGEMANAGER->addFrameImage("LEFT_IDLE", "images/플레이어/왼쪽아이들.bmp", 68*2, 21*2, 4, 1,  true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RIGHT_IDLE", "images/플레이어/오른쪽아이들.bmp", 68*2, 21*2, 4, 1, true, RGB(255, 0, 255));
	//이동
	IMAGEMANAGER->addFrameImage("LEFT_MOVE", "images/플레이어/왼쪽이동.bmp", 238*2, 21*2, 14, 1,  true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RIGHT_MOVE", "images/플레이어/오른쪽이동.bmp", 238*2, 21*2, 14, 1, true, RGB(255, 0, 255));
	//점프
	IMAGEMANAGER->addImage("LEFT_JUMP", "images/플레이어/왼쪽점프.bmp", 17*2, 21*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("RIGHT_JUMP", "images/플레이어/오른쪽점프.bmp", 17*2, 21*2, true, RGB(255, 0, 255));
	

	//////////////////////////////////////////////////////////////////////////////////////////////
	_Ground = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 50, WINSIZEX, 50);//나중에 지워 가상의 땅이야
	/////////////////////////////////////////////////////////////////////////////////////////////

	_playerWay = Left;
	_playerMove = Idle;
	_playerimg = IMAGEMANAGER->findImage("LEFT_IDLE");
	_playerRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 17*2, 21*2);
	_playerSpeed = 3;
	_playerMoveCount = 0;//움직일떄 플레이어 점프 
	_playerJumpCount = 0;//점프에만 사용할 카운트
	b_isJump=false;

	

	b_Debug = false;
	return S_OK;
}

void Player_Move::release()
{
	SAFE_DELETE(_playerimg);
}
//================================================
//##					업데이트					##
//================================================
void Player_Move::update()
{
	_playerFocusX = _playerRC.right - (_playerRC.right - _playerRC.left) / 2;//플레이어 렉트 중점
	//플레이어 방향 지정
	if (m_ptMouse.x < _playerFocusX)
	{
		_playerWay = Left;
	}
	else
	{
		_playerWay = Right;
	}
	if (KEYMANAGER->isStayKeyDown('A'))//left_rc
	{
		_playerMoveCount++;	
		_playerMove = Move;
		OffsetRect(&_playerRC, -_playerSpeed, 0);
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			b_isJump = true;
		}

	}
	else if (KEYMANAGER->isStayKeyDown('D'))//right_rc
	{
		_playerMoveCount++;
		_playerMove = Move;
		OffsetRect(&_playerRC, _playerSpeed, 0);
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			b_isJump = true;
		}
	}
	else
	{
		_playerMoveCount++;
		_playerMove = Idle;
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			b_isJump = true;
		}
	}
	if (b_isJump)
	{
	player_Jump();
	}
	if (_playerMoveCount > 280)
	{
		_playerMoveCount = 0;
	}
	player_Move();



	//================================================
	//##				디버그 : F1					##
	//================================================
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		b_Debug= !b_Debug;
	}

}

void Player_Move::render()
{

	if (b_Debug)
	{
		char str[128];
		wsprintf(str, "|플레이어 무브 카운트 : %d | 플레이어 점프 카운트 : %d | 플레이어 무브 : %d", _playerMoveCount, _playerJumpCount, _playerMove);
		TextOut(getMemDC(), WINSIZEX / 2 - 200, 0, str, strlen(str));

		Rectangle(getMemDC(), _Ground.left, _Ground.top, _Ground.right, _Ground.bottom);
		Rectangle(getMemDC(), _playerRC.left, _playerRC.top, _playerRC.right, _playerRC.bottom);
	}

	if (_playerMove == Move)
	{
		_playerimg->frameRender(getMemDC(), _playerRC.left, _playerRC.top, (_playerMoveCount / 15) % 14, 0);
	}
	else if (_playerMove == Idle)
	{
		_playerimg->frameRender(getMemDC(), _playerRC.left, _playerRC.top, (_playerMoveCount / 15) % 4, 0);
	}
	else if (_playerMove == Jump)
	{
		_playerimg->render(getMemDC(), _playerRC.left, _playerRC.top);
	}
}
