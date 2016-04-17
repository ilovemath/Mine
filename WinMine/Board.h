#pragma once
#include"Draw.h"
#include "Picture.h"

class CBoard: 
	public CDraw, public CPicture
{
private:
	int one, ten, hun;
public:
	CBoard(void);
	~CBoard(void);

	void SetNum(int num);

	void Draw(CDC *pDC);
	void Invalidate(bool bErase = false);
};

