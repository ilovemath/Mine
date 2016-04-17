#include "stdafx.h"
#include "MineField.h"
 
CMineField::CMineField()
{
	easy.num = 10;
	easy.row = 8;
	easy.col = 8;

	medium.num = 40;
	medium.row = 16;
	medium.col = 16;

	hard.num = 99;
	hard.row = 16;
	hard.col = 30;

	custom = hard;

	type = Hard;
	scale = GetScale();

	pMine = NULL;
}
 
CMineField::~CMineField(void)
{
	if(pMine!=NULL)
		delete []pMine;
}
 

Scale CMineField::GetScale()
{	
	Scale scale;
	switch (type)
	{
	case Easy:		scale=easy;		break;
	case Medium:	scale=medium;	break;
	case Hard:		scale=hard;		break;
	case Custom:	scale=custom;	break;
	}
	return scale;
}

void CMineField::SetType(Type type)
{
	this->type = type;
	scale = GetScale();
}

void CMineField::SetCustom(Scale custom)
{
	this->custom = custom;
}
Scale CMineField::GetCustom()
{
	return custom;
}

void CMineField::InitMine()
{
	flagged = 0;
	if (pMine != NULL)
	{
		delete []pMine;
		pMine = NULL;
	}
	int total = scale.row * scale.col; 
	pMine = new CMine[total];
	//随机产生雷的位置	
	srand((unsigned)time(NULL));
	int num = 0;
	while (num < scale.num)
	{
		int id = rand() % total;
		if (!pMine[id].IsMine())
			pMine[id].SetMine();
		num++;
	}
	
	//遍历雷区，计算方格周边雷数
	num = 0;
	while (num < total)
	{
		int r = num / scale.col; //行
		int c = num % scale.col; //列
		pMine[num].SetPos(r,c);
		if (!pMine[num].IsMine())
		{
			for (int i = max(0,r-1); i < min(scale.row,r+2); i++)
				for (int j = max(0,c-1); j < min(scale.col,c+2); j++)
					if(pMine[i*scale.col+j].IsMine())
						pMine[num].IncMine();
		}
		num++;
	}
/*	调试雷矩阵
	CString s,t;

	for (int i = 0;i<scale.row;i++){
		for (int j = 0;j<scale.col;j++)
		{
			t.Format("%d ",pMine[i*scale.col+j].GetMine());
			s+=t;
		}
		s+="\n";
	}
	AfxMessageBox(s);
	*/
}

CRect CMineField::GetFieldRect()
{
	CPoint end(origin);
	end.x += scale.col * CMine::width;
	end.y += scale.row * CMine::height;
	return CRect(origin,end);
}

int CMineField::PtToIndex(CPoint pt)
{
	if (GetFieldRect().PtInRect(pt))
	{
		CPoint real = pt - origin;
		int r = real.y / CMine::height;
		int c = real.x / CMine::width;
		return scale.col * r + c;
	}
	else
		return -1;
}


void CMineField::Draw(CDC *pDC)
{
	if (pMine==NULL)
	{
		AfxMessageBox(L"还未初始化pMine！");
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
		CMine &m = pMine[index++];
	    CDraw::Draw(&tmpDc, m.GetPos(),m.GetPic());
	}
	pDC->StretchBlt(rt.left, rt.top, rt.Width(), rt.Height(), &tmpDc, 
		                        0,0, rt.Width(), rt.Height(), SRCCOPY);
}

void CMineField::Invalidate(bool bErase)
{
	int index = 0;
	int total = scale.col * scale.row;
	while (index < total)
	{
		CMine &m = pMine[index++];
		if (m.IsReDraw())
		{
			CRect rt = m.GetPos();
			rt.OffsetRect(origin);
			InvalidateRect(hWnd,rt,bErase);
			m.NotReDraw();
		}
	}
}
