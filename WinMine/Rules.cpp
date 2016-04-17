#include "stdafx.h"
#include "Rules.h"

CRules::CRules()
{
}


CRules::~CRules(void)
{

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
		CMine &m = pMine[index];
		if (m.IsFlagged())
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
		CMine &m = pMine[index];
		if (r == row&&c == col)//打开当前雷
		{
			m.SetPic(CMine::Num);
			m.ForceReDraw();
			continue;
		}
		if (!m.IsOpened() && !m.IsFlagged())//没有被打开，且没有被标记
		{
			if (m.IsBlank())//如果为空白，则打开周边雷
			{
				Expand(index);
			}
			else//否则为数字（空白周边不可能有雷），打开
			{
				m.SetPic(CMine::Num);
				m.ForceReDraw();
			}
		}

	}
}

void CRules::RButtonDown(int index)
{
	if (index == -1)//不在雷区
	{
		return;
	}
	CMine &m = pMine[index];
	if (m.IsNone())
	{
		m.SetPic(CMine::Flag);
		m.ForceReDraw();
	}
	else if (m.IsFlagged())
	{
		m.SetPic(CMine::Mark);
		m.ForceReDraw();
	}
	else if (m.IsMarked())
	{
		m.SetPic(CMine::None);
		m.ForceReDraw();
	}
}

void CRules::LButtonDown(int index)
{
	if (index == -1)//不在雷区
	{
		return;
	}
	CMine &m = pMine[index];
	if (m.IsNone())
	{
		m.SetPic(CMine::Press);
		m.ForceReDraw();
		return;
	}
	if (m.IsMarked())
	{
		m.SetPic(CMine::MPress);
		m.ForceReDraw();
		return;
	}
}

void CRules::LButtonUp(int index)
{
	if (index == -1)//不在雷区
	{
		return;
	}
	CMine &m = pMine[index];
	if (m.IsFlagged())
	{
		return;
	}
	if (m.IsMine())
	{
		AfxMessageBox(L"Game Over!"); 
		return;
	}
	if (m.IsBlank())
	{
		Expand(index);
		return;
	}
	if (m.IsPressed() || m.IsMPressed())
	{
		m.SetPic(CMine::Num);
		m.ForceReDraw();
		return;
	}
}

void CRules::LRButtonUp(int index)
{
	NotPress();
	if (index == -1)//不在雷区
	{
		return;
	}
	CMine &m = pMine[index];
	if (m.IsOpened() && !m.IsBlank() && (m.GetMine() == AroundFlag(index)))
	{
		int row = index / scale.col;
		int col = index % scale.col;
		for (int r = max(row - 1, 0); r < min(row + 2, scale.row); r++)
		for (int c = max(col - 1, 0); c < min(col + 2, scale.col); c++)
		{
			index = r*scale.col + c;
			LButtonPress(index);
			LButtonUp(index);
		}
	}
}

void CRules::NotPress()
{
	int id = 0;
	int total = scale.col * scale.row;
	while (id < total)
	{
		CMine &m = pMine[id];
		if (m.IsPressed())
		{
			m.SetPic(CMine::None);
			m.ForceReDraw();
		}
		if (m.IsMPressed())
		{
			m.SetPic(CMine::Mark);
			m.ForceReDraw();
		}
		id++;
	}
}

void CRules::LButtonPress(int index)
{
	NotPress();
	if (index == -1)//不在雷区
	{
		return;
	}
	CMine &m = pMine[index];
	if (m.IsNone())
	{
		m.SetPic(CMine::Press);
		m.ForceReDraw();
	}
	if (m.IsMarked())
	{
		m.SetPic(CMine::MPress);
		m.ForceReDraw();
	}
}

void CRules::LRButtonPress(int index)
{
	NotPress();
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
		CMine &m = pMine[index];
		if (m.IsNone())
		{
			m.SetPic(CMine::Press);
			m.ForceReDraw();
		}
		if (m.IsMarked())
		{
			m.SetPic(CMine::MPress);
			m.ForceReDraw();
		}
	}

}