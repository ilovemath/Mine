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
	CBlock *GetBlock(int index);	//��ȡ��Ӧ����
	void InitField();			//��ʼ������
	CRect GetFieldRect();		//��ȡ��������
	int PtToIndex(CPoint point);//������ת��Ϊ������

	void Draw(CDC *pDC);		//����MineField
	void Invalidate(bool bErase=false);//ʹ������Ч
};

