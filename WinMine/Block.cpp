#include "stdafx.h"
#include "Block.h"


CBlock::CBlock(void)
{
	num = 0;
	ico = None;
	redraw = true;
}

CBlock::~CBlock(void){
}

int CBlock::GetNum()
{
	return num;
}

void CBlock::Increase(void)
{
	num++;
}

void CBlock::SetMine()
{
	num = -1;
}

bool CBlock::IsMine(void)
{
	return (num == -1);
}

bool CBlock::IsBlank()
{
	return (num == 0);
}

bool CBlock::IsFlagged()
{
	return (ico == Flag);
}

bool CBlock::IsMarked()
{
	return (ico == Mark);
}

bool CBlock::IsOpened()
{
	return (ico == Num);
}

bool CBlock::IsPressed()
{
	return (ico == Press);
}
bool CBlock::IsMPressed()
{
	return (ico == MPress);
}

bool CBlock::IsNone()
{
	return (ico == None);
}


void CBlock::SetPos(int r, int c)
{
	row = r;
	col = c;
}

CRect CBlock::GetPos()
{
	int l = col * W;
	int t = row * H;
	int r = l + W;
	int b = t + H;
	return CRect(l, t, r, b);
}

bool CBlock::IsReDraw()
{
	return redraw;
}

void CBlock::SetReDraw(bool draw)
{
	redraw = draw;
}
