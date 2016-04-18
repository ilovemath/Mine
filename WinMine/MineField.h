#pragma once
#include"Draw.h"
#include"Block.h"
#include"Level.h"

class CMineField: public CDraw
{
public:
	CMineField();
	~CMineField();
private:	
	Scale scale;
	CBlock *pBlocks;
public:
	CBlock *GetBlock(int index);	//获取相应方格
	void InitField();			//初始化雷区
	CRect GetFieldRect();		//获取雷区矩阵
	int PtToIndex(CPoint point);//将坐标转化为雷索引

	void Draw(CDC *pDC);		//绘制MineField
	void Invalidate(bool bErase=false);//使区域无效
};

