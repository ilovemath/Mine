#pragma once
#include "Face.h"
#include "Board.h"
#include "MineField.h"

class CLayout:public CDraw
{
public:
	CLayout();
	~CLayout();

private:
	CRect rect;
	CRect corner[13];
	CTexture tool;
public:
	CFace face;
	CBoard time;
	CBoard mine;
	CMineField field;

public:
	void Init();
	void Draw(CDC*);		//»æÖÆ
	void Invalidate(bool bErase = false);
};

