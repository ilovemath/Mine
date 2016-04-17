#include "stdafx.h"
#include "Board.h"


CBoard::CBoard()
{
	one = 0;
	ten = 0;
	hun = 0;
}


CBoard::~CBoard(void)
{
}


void CBoard::SetNum(int num)
{
	if (num<0 || num>10)
	{
		hun = -1;
		ten = -1;
		one = -1;
	}
	else
	{
		hun = num / 100;
		ten = num % 100 / 10;
		one = num % 10;
	}
}

void CBoard::Draw(CDC *pDC)
{

}

void CBoard::Invalidate(bool bErase)
{

}