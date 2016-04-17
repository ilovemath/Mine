#include "stdafx.h"
#include "Mine.h"

CMine::CMine(void)
{
	mine = 0;
	pic  = None;
	redraw = false;
}

int CMine::GetMine()
{
	return mine;
}
void CMine::IncMine(void)
{
	mine++;
}


void CMine::SetMine()
{
	mine = -1;
}

bool CMine::IsMine(void)
{
	return (mine == -1);
}

bool CMine::IsBlank()
{
	return (mine == 0);
}

bool CMine::IsFlagged()
{
	return (pic==Flag);
}

bool CMine::IsMarked()
{
	return (pic==Mark);
}

bool CMine::IsOpened()
{
	return (pic==Num);
}

bool CMine::IsPressed()
{
	return (pic == Press);
}
bool CMine::IsMPressed()
{
	return (pic == MPress);
}

bool CMine::IsNone()
{
	return (pic==None);
}

CRect CMine::GetPic()
{
	num = mine;
	return CPicture::GetPic();
}

void CMine::SetPos(int r,int c)
{
	row = r;
	col = c;
}

CRect CMine::GetPos()
{
	int l = col * width;
	int t = row * height;
	int r = l + width;
	int b = t + height;
	return CRect(l,t,r,b);
}

bool CMine::IsReDraw()
{
	return redraw;
}

void CMine::NotReDraw()
{
	redraw = false;
}
void CMine::ForceReDraw()
{
	redraw = true;
}