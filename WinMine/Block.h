#pragma once
#include "Texture.h"
class CBlock :
	public CTexture
{
public:
	CBlock();
	~CBlock();

private:

	//行与列
	int row;
	int col;

	//是否需要重绘
	bool redraw;

public:
	bool IsMine();//判断是否为雷
	void SetMine();//设置为雷

	int GetNum();//获取雷数
	void Increase();//周边雷数加一

	CRect GetPos();//获在雷区的取绘制位置
	void SetPos(int row, int col);//设置所在行与列

	bool IsFlagged();//是否被标记为雷
	bool IsMarked();//是否被标记为问号
	bool IsOpened();//是否已打开（显示数字）
	bool IsPressed();//是否被按下
	bool IsMPressed();//问号是否被按下
	bool IsNone();//是否为未打开的状态
	bool IsBlank();//是否为空白（周边有零个雷）

	bool IsReDraw();//是否需要重绘
	void SetReDraw(bool draw = true);//设置是否重绘

};

