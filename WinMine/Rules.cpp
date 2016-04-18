#include "stdafx.h"
#include "Rules.h"

CRules::CRules()
{
}

CRules::~CRules(void)
{

}

void CRules::Init(CLayout &layout){
	scale = CLevel::GetScale();
	face = &layout.face;
	time = &layout.time;
	mine = &layout.mine;
	field = &layout.field;
	ReStart();
}

void CRules::ReStart()
{
	Stop();
	flagged = 0;
	field->InitField();
	time->SetNum(0);
	mine->SetNum(scale.num);
	face->SetIcon(CFace::Smile);
	time->Invalidate();
	mine->Invalidate();
	face->Invalidate();
	field->Invalidate();
}

void CRules::Stop()
{
	stop = true;
	KillTimer(CDraw::hWnd, 1);
}
void CRules::Start()
{
	stop = false;
	SetTimer(CDraw::hWnd, 1, 1000, NULL);
}

int CRules::AroundFlag(int index)
{
	int count = 0;
	int row = index / scale.col;
	int col = index % scale.col;
	for (int r = max(row - 1, 0); r < min(row + 2, scale.row); r++)
	for (int c = max(col - 1, 0); c < min(col + 2, scale.col); c++)
	{
		index = r*scale.col + c;
		CBlock *blk = field->GetBlock(index);
		if (blk->IsFlagged())
			count++;
	}
	return count;
}

void CRules::Expand(int index)
{
	int row = index / scale.col;
	int col = index % scale.col;
	for (int r = max(row - 1, 0); r < min(row + 2, scale.row); r++)
	for (int c = max(col - 1, 0); c < min(col + 2, scale.col); c++)
	{
		index = r*scale.col + c;
		CBlock *blk = field->GetBlock(index);
		if (r == row&&c == col)//打开当前雷
		{
			blk->SetIcon(CBlock::Num);
			blk->SetReDraw();
			continue;
		}
		if (!blk->IsOpened() && !blk->IsFlagged())//没有被打开，且没有被标记
		{
			if (blk->IsBlank())//如果为空白，则打开周边雷
			{
				Expand(index);
			}
			else//否则为数字（空白周边不可能有雷），打开
			{
				blk->SetIcon(CBlock::Num);
				blk->SetReDraw();
			}
		}

	}
}

void CRules::RButtonDown(CPoint &point)
{
	int index = field->PtToIndex(point);
	if (index == -1)//不在雷区
	{
		return;
	}
	face->SetIcon(CFace::Amaze);
	face->Invalidate();
	CBlock *blk = field->GetBlock(index);
	if (blk->IsNone())
	{
		flagged++;
		mine->Dec();
		if (stop)Start();
		blk->SetIcon(CBlock::Flag);
		blk->SetReDraw();
	}
	else if (blk->IsFlagged())
	{
		flagged--;
		mine->Inc();
		blk->SetIcon(CBlock::Mark);
		blk->SetReDraw();
	}
	else if (blk->IsMarked())
	{
		blk->SetIcon(CBlock::None);
		blk->SetReDraw();
	}
	field->Invalidate();
}

void CRules::LButtonDown(CPoint &point)
{
	int index = field->PtToIndex(point);
	if (index == -1)//不在雷区
	{
		if (face->PtInFace(point))
		{
			face->SetIcon(CFace::SPress);
			face->Invalidate();
		}
		return;
	}
	face->SetIcon(CFace::Amaze);
	face->Invalidate();
	CBlock *blk = field->GetBlock(index);
	if (blk->IsNone())
	{
		blk->SetIcon(CBlock::Press);
		blk->SetReDraw();
	}
	else if (blk->IsMarked())
	{
		blk->SetIcon(CBlock::MPress);
		blk->SetReDraw();
	}
	field->Invalidate();
}

void CRules::LButtonUp(CPoint &point)
{
	int index = field->PtToIndex(point);
	if (index == -1)//不在雷区
	{
		if (face->PtInFace(point)){
			ReStart();
		}
		return;
	}
	face->SetIcon(CFace::Smile);
	face->Invalidate();
	CBlock *blk = field->GetBlock(index);
	if (blk->IsFlagged())	//已被标记，则无反应
	{
		return;
	}
	if (stop)Start();
	if (blk->IsBlank())		//空白，展开
	{
		Expand(index);
	}
	else if (blk->IsMine())	//踩到雷，结束
	{
		if (!stop)Stop();
		face->SetIcon(CFace::Sad);
		face->Invalidate();
		AfxMessageBox(L"Game Over!");
	}
	else if (blk->IsPressed() || blk->IsMPressed())
	{
		blk->SetIcon(CBlock::Num);
		blk->SetReDraw();
	}
	field->Invalidate();
}

void CRules::RButtonUp(CPoint &point)
{
	face->SetIcon(CFace::Smile);
	face->Invalidate();
}

void CRules::Release()
{
	int index = 0;
	while (index < scale.total)
	{
		CBlock *blk = field->GetBlock(index);
		if (blk->IsPressed())
		{
			blk->SetIcon(CBlock::None);
			blk->SetReDraw();
		}
		if (blk->IsMPressed())
		{
			blk->SetIcon(CBlock::Mark);
			blk->SetReDraw();
		}
		index++;
	}
	field->Invalidate();
}

void CRules::LRButtonUp(CPoint &point)
{
	Release();
	int index = field->PtToIndex(point);
	if (index == -1)//不在雷区
	{
		return;
	}
	face->SetIcon(CFace::Smile);
	face->Invalidate();
	CBlock *blk = field->GetBlock(index);
	if (blk->IsOpened() && !blk->IsBlank() && (blk->GetNum() == AroundFlag(index)))
	{
		int row = index / scale.col;
		int col = index % scale.col;
		for (int r = max(row - 1, 0); r < min(row + 2, scale.row); r++)
		for (int c = max(col - 1, 0); c < min(col + 2, scale.col); c++)
		{
			CBlock *blk = field->GetBlock(r*scale.col + c);
			if (blk->IsFlagged())
			{
				continue;
			}
			if (blk->IsBlank())
			{
				Expand(index);
				continue;
			}
			if (blk->IsMine())
			{
				AfxMessageBox(L"Game Over!");
				return;
			}
			blk->SetIcon(CBlock::Num);
			blk->SetReDraw();
		}
		field->Invalidate();
	}
}

void CRules::LButtonPress(CPoint &point)
{
	Release();
	int index = field->PtToIndex(point);
	if (index == -1)//不在雷区
	{
		return;
	}
	CBlock *blk = field->GetBlock(index);
	if (blk->IsNone())
	{
		blk->SetIcon(CBlock::Press);
		blk->SetReDraw();
	}
	else if (blk->IsMarked())
	{
		blk->SetIcon(CBlock::MPress);
		blk->SetReDraw();
	}
	field->Invalidate();
}

void CRules::LRButtonPress(CPoint &point)
{
	Release();
	int index = field->PtToIndex(point);
	if (index == -1)//不在雷区
	{
		return;
	}
	int row = index / scale.col;
	int col = index % scale.col;
	for (int r = max(row - 1, 0); r < min(row + 2, scale.row); r++)
	for (int c = max(col - 1, 0); c < min(col + 2, scale.col); c++)
	{
		index = r*scale.col + c;
		CBlock *blk = field->GetBlock(index);
		if (blk->IsNone())
		{
			blk->SetIcon(CBlock::Press);
			blk->SetReDraw();
		}
		else if (blk->IsMarked())
		{
			blk->SetIcon(CBlock::MPress);
			blk->SetReDraw();
		}
	}
	field->Invalidate();
}