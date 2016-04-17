#pragma once
#include"Mine.h"
#include"Draw.h"
#include"Rules.h"

class CMineField: public CDraw, public CRules
{
public:
	enum Type{
		Hard,
		Medium,
		Easy,
		Custom
	};

	CMineField();
	~CMineField();
private:
	
	Type type;//类型
    Scale hard,medium,easy,custom;//级别

private:
	Scale GetScale();//获取当前级别（简单、中等、困难、自定义）
public:
	void SetType(Type type);//设置类型（简单、中等、困难、自定义）
	Scale GetCustom();//获取自定义数据
	void SetCustom(Scale custom);//设置自定义

	void InitMine();//初始化雷区
	CRect GetFieldRect();//获取雷区矩阵
	int PtToIndex(CPoint point);//将坐标转化为雷索引

	void Draw(CDC *pDC);//绘制MineField
	void Invalidate(bool bErase=false);//使区域无效
};

