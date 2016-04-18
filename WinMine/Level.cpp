#include "stdafx.h"
#include "Level.h"

Level CLevel::level = Hard;
Scale CLevel::custom = Scale{ 99, 480, 16, 30 };

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
}

Scale CLevel::GetScale()
{
	Scale scale;
	switch (level)
	{
	case Easy:		
		scale.num = 10; scale.row = 8;
		scale.col = 8; scale.total = 64;
		break;
	case Medium:
		scale.num = 40; scale.total = 256;
		scale.row = 16; scale.col = 16;
		break;
	case Hard:
		scale.num = 99; scale.total = 480;
		scale.row = 16; scale.col = 30; 
		break;
	case Custom:
		return custom;
	}
	return scale;
}


void CLevel::SetType(Level type)
{
	level = type;
}

Scale CLevel::GetCustom()
{
	return custom;
}

void CLevel::SetCustom(int n, int t, int r, int c)
{
	custom = Scale{n,t,r,c};
}