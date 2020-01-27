#include "stdafx.h"
#include "playerdie.h"


playerdie::playerdie()
{
	

}


playerdie::~playerdie()
{
}

HRESULT playerdie::init()
{
	player_1 = new player1;
	player_1->init();
	player_2 = new player2;
	player_2->init();
	return S_OK;
}

bool playerdie::player1Die()
{
	RECT temp;
	//ÀÚ½ÅÀÇ ¹°Ç³¼±¿¡ Á×´Â...
	for (int i = 0; i <player_1->_player_1.bombNumber;i++)
	{
		
		if (player_1->player1_bomb->getVbomb()[i].boom
			&& (IntersectRect(&temp, &player_1->_player_1.player1, &player_1->player1_bomb->getVbomb()[i].boomRight_rc) ||
				IntersectRect(&temp, &player_1->_player_1.player1, &player_1->player1_bomb->getVbomb()[i].boomLeft_rc) ||
				IntersectRect(&temp, &player_1->_player_1.player1, &player_1->player1_bomb->getVbomb()[i].boomUp_rc) ||
				IntersectRect(&temp, &player_1->_player_1.player1, &player_1->player1_bomb->getVbomb()[i].boomDown_rc)))
		{
			return player_1->_player_1._player1_Live = false;

		}
	}
	//»ó´ë¹æ ¹°Ç³¼±ÀÇ Á×´Â....
	for (int i = 0; i < player_2->_player_2.bombNumber; i++)
	{
		if (player_2->player2_bomb->getVbomb2()[i].boom2		
			&& (IntersectRect(&temp, &player_1->_player_1.player1, &player_2->player2_bomb->getVbomb2()[i].boomRight_rc2) ||
				IntersectRect(&temp, &player_1->_player_1.player1, &player_2->player2_bomb->getVbomb2()[i].boomLeft_rc2) ||
				IntersectRect(&temp, &player_1->_player_1.player1, &player_2->player2_bomb->getVbomb2()[i].boomUp_rc2) ||
				IntersectRect(&temp, &player_1->_player_1.player1, &player_2->player2_bomb->getVbomb2()[i].boomDown_rc2)))
		{
			return player_1->_player_1._player1_Live = false;
		}
	}

}

bool playerdie::player2Die()
{
	return false;
}
