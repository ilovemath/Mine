#include "stdafx.h"
#include "Picture.h"


CPicture::CPicture()
{
}


CPicture::~CPicture()
{
}


void CPicture::SetPic(Pic state)
{
	pic = state;
}

CRect CPicture::GetPic(Pic p)
{
	if (p == Null)
		p = pic;
	int l, t, r, b;
	switch (p)
	{
	case Num: l = num * 16; t = 0; r = l + 16; b = t + 16; break;
	case None:	l = 0;  t = 16; r = l + 16; b = t + 16; break;
	case Press: l = 16; t = 16; r = l + 16; b = t + 16; break;
	case Mine:	l = 32; t = 16; r = l + 16; b = t + 16; break;
	case Flag:	l = 48; t = 16; r = l + 16; b = t + 16; break;
	case XMine:	l = 64; t = 16; r = l + 16; b = t + 16; break;
	case RMine:	l = 80; t = 16; r = l + 16; b = t + 16; break;
	case Mark:	l = 96; t = 16; r = l + 16; b = t + 16; break;
	case MPress:l = 112; t = 16; r = l + 16; b = t + 16; break;

	case Smile: l = 0;  t = 55; r = l + 26; b = t + 25; break;
	case Amaze: l = 27; t = 55; r = l + 26; b = t + 25; break;
	case Sad:   l = 54; t = 55; r = l + 26; b = t + 25; break;
	case Cool:  l = 81; t = 55; r = l + 26; b = t + 25; break;
	case SPress:l = 108; t = 55; r = l + 26; b = t + 25; break;
	
	case Led:	l = num * 12; t = 33; r = l + 10; b = t + 20; break;
	case LedBk:	l = 28; t = 82; r = 68; b = 106; break;

	case LT:	l = 0; t = 82; r = 11; b = 92; break;
	case LTM:	l = 0; t = 94; r = 11; b = 94; break;
	case LM:	l = 0; t = 96; r = 11; b = 106; break;
	case LBM:	l = 0; t = 108; r = 11; b = 108; break;
	case LB:	l = 0; t = 110; r = 11; b = 121; break;

	case RT:	l = 15; t = 82; r = 26; b = 92; break;
	case RTM:	l = 15; t = 94; r = 26; b = 94; break;
	case RM:	l = 15; t = 96; r = 26; b = 106; break;
	case RBM:	l = 15; t = 108; r = 26; b = 108; break;
	case RB:	l = 15; t = 110; r = 26; b = 121; break;

	case TM:	l = 13; t = 82; r = 13; b = 92; break;
	case MM:	l = 13; t = 96; r = 13; b = 106; break;
	case BM:	l = 13; t = 110; r = 13; b = 121; break;	
	}
	return CRect(l, t, r, b);
}
