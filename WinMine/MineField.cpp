#include "stdafx.h"
#include "MineField.h"
 
CMineField::CMineField()
{
	pBlocks = NULL;
}
 
CMineField::~CMineField(void)
{
	if(pBlocks!=NULL)
		delete[]pBlocks;
}

void CMineField::InitField()
{
	if (pBlocks != NULL)
	{
		delete[]pBlocks;
		pBlocks = NULL;
	}
	scale = CLevel::GetScale();

	pBlocks = new CBlock[scale.total];
	//随机产生雷的位置	
	srand((unsigned)time(NULL));
	int num = 0;
	while (num < scale.num)
	{
		int id = rand() % scale.total;
		if (!pBlocks[id].IsMine())
			pBlocks[id].SetMine();
		num++;
	}
	
	//遍历雷区，计算方格周边雷数
	num = 0;
	while (num < scale.total)
	{
		int r = num / scale.col; //行
		int c = num % scale.col; //列
		pBlocks[num].SetPos(r,c);
		if (!pBlocks[num].IsMine())
		{
			for (int i = max(0,r-1); i < min(scale.row,r+2); i++)
				for (int j = max(0,c-1); j < min(scale.col,c+2); j++)
					if(pBlocks[i*scale.col+j].IsMine())
						pBlocks[num].Increase();
		}
		num++;
	}
	Invalidate();
}

CBlock *CMineField::GetBlock(int index){
	if (pBlocks)
		return &pBlocks[index];
	else{
		return NULL;
	}
}

CRect CMineField::GetFieldRect()
{
	CPoint end(origin);
	end.x += scale.col * CBlock::W;
	end.y += scale.row * CBlock::H;
	return CRect(origin,end);
}

int CMineField::PtToIndex(CPoint pt)
{
	if (GetFieldRect().PtInRect(pt))
	{
		CPoint real = pt - origin;
		int c = real.x / CBlock::W;
		int r = real.y / CBlock::H;
		return scale.col * r + c;
	}
	else
		return -1;
}


void CMineField::Draw(CDC *pDC)
{
	if (pBlocks==NULL)
	{
		AfxMessageBox(L"pBlocks hasn't been initialized！");
		return;
	}
	CDC tmpDc;
	if (tmpDc.CreateCompatibleDC(pDC) == NULL)
	{
		AfxMessageBox(L"Cannot Create tmpDc");
		return;
	}
	CBitmap tmpbMap;
	CRect rt = GetFieldRect(); 
	if (tmpbMap.CreateCompatibleBitmap(pDC, rt.Width(), rt.Height()) == NULL)
	{
		AfxMessageBox(L"Cannot Create tmpbMap");
		return;
	}
	tmpDc.SelectObject(tmpbMap);

	int index = 0;
	int total = scale.col * scale.row;
	while (index < total)
	{
		CBlock &m = pBlocks[index++];
	    CDraw::Draw(&tmpDc, m.GetPos(),m);
	}
	pDC->StretchBlt(rt.left, rt.top, rt.Width(), rt.Height(), &tmpDc, 
		                        0,0, rt.Width(), rt.Height(), SRCCOPY);
}

void CMineField::Invalidate(bool bErase)
{
	int index = 0;
	while (index < scale.total)
	{
		CBlock &m = pBlocks[index++];
		if (m.IsReDraw())
		{
			CRect rt = m.GetPos();
			rt.OffsetRect(origin);
			InvalidateRect(hWnd,rt,bErase);
			m.SetReDraw(false);
		}
	}
}
