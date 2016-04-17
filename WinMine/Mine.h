#pragma once
#include "Picture.h"
class CMine:public CPicture
{
public:
	static const int width = 16;
	static const int height = 16;
public:
	CMine(void);

private:
	// 周边雷的个数
	// -1代表自身为雷
	int mine;
	
	//行与列
	int row;
	int col;

	//是否需要重绘
	bool redraw;

public:
	void IncMine();//周边雷数加一
	bool IsMine();//判断是否为雷
	void SetMine();//设置为雷
	int GetMine();//获取雷数

	CRect GetPic();//重载CPicture中的函数

	CRect GetPos();//获取绘制位置
	void SetPos(int row, int col);//设置所在行与列

	bool IsFlagged();//是否被标记为雷
	bool IsMarked();//是否被标记为问号
	bool IsOpened();//是否已打开（显示数字）
	bool IsPressed();//是否被按下
	bool IsMPressed();//问号是否被按下
	bool IsNone();//是否为未打开的状态
	bool IsBlank();//是否为空白（周边有零个雷）

	bool IsReDraw();//是否需要重绘
	void NotReDraw();//不要重绘
	void ForceReDraw();//强制重绘
};

