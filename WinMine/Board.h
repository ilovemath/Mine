#pragma once
#include"Draw.h"

class CBoard :
	public CDraw, public CTexture
{
private:
	int one, ten, hun;
public:
	CBoard(void);
	~CBoard(void);

	void Inc();
	void Dec();
	void SetNum(int num);
	void Draw(CDC *pDC);
	void Invalidate(bool bErase = false);

	CBoard &operator--();
	CBoard &operator++();
};

