#include "stdafx.h"
#include "Texture.h"
#include "resource.h"


CTexture::CTexture()
{
	num = 0;
	ico = None;
	bitmap.LoadBitmap(IDB_DEFAULT);
}


CTexture::~CTexture()
{
}

void CTexture::SetBitmap(UINT id)
{
	bitmap.LoadBitmap(id);
}

void CTexture::SetIcon(Icon ico)
{
	this->ico = ico;
}

CRect CTexture::GetIconRect(Icon ico)
{
	if (ico == Null)
		ico = this->ico;
	int l, t, r, b;
	switch (ico)
	{
		case Num: l = num * 16; t = 0; r = l + W; b = t + H; break;
		case None:	l = 0;  t = 16; r = l + W; b = t + H; break;
		case Press: l = 16; t = 16; r = l + W; b = t + H; break;
		case Mine:	l = 32; t = 16; r = l + W; b = t + H; break;
		case Flag:	l = 48; t = 16; r = l + W; b = t + H; break;
		case XMine:	l = 64; t = 16; r = l + W; b = t + H; break;
		case RMine:	l = 80; t = 16; r = l + W; b = t + H; break;
		case Mark:	l = 96; t = 16; r = l + W; b = t + H; break;
		case MPress:l = 112; t = 16; r = l + W; b = t + H; break;

		case Smile: l = 0;  t = 55; r = l + 26; b = t + 25; break;
		case Amaze: l = 27; t = 55; r = l + 26; b = t + 25; break;
		case Sad:   l = 54; t = 55; r = l + 26; b = t + 25; break;
		case Cool:  l = 81; t = 55; r = l + 26; b = t + 25; break;
		case SPress:l = 108; t = 55; r = l + 26; b = t + 25; break;

		case Led:	l = num * 12; t = 33; r = l + 11; b = t + 21; break;
		case LedBk:	l = 28; t = 82; r = 69; b = 107; break;

		case LT:	l = 0; t = 82; r = 12; b = 93; break;
		case LTM:	l = 0; t = 94; r = 12; b = 95; break;
		case LM:	l = 0; t = 96; r = 12; b = 107; break;
		case LBM:	l = 0; t = 108; r = 12; b = 109; break;
		case LB:	l = 0; t = 110; r = 12; b = 122; break;

		case RT:	l = 15; t = 82; r = 27; b = 93; break;
		case RTM:	l = 15; t = 94; r = 27; b = 95; break;
		case RM:	l = 15; t = 96; r = 27; b = 107; break;
		case RBM:	l = 15; t = 108; r = 27; b = 109; break;
		case RB:	l = 15; t = 110; r = 27; b = 122; break;

		case TM:	l = 13; t = 82; r = 14; b = 93; break;
		case MM:	l = 13; t = 96; r = 14; b = 107; break;
		case BM:	l = 13; t = 110; r = 14; b = 122; break;
	}
	return CRect(l, t, r, b);
}