#pragma once
#include "Face.h"
#include "Block.h"
#include "Level.h"
#include "Board.h"
#include "Layout.h"
#include "MineField.h"

class CRules
{
public:
	CRules();
	~CRules(void);
private:
	//笑脸按钮
	CFace *face;
	//数字面板
	CBoard *time;
	CBoard *mine;
	//雷区
	CMineField *field;

	//雷规模
	Scale scale;
	//已标记雷数
	int flagged;
	bool stop;

private:
	int  AroundFlag(int index);
	void Expand(int index);

public:
	void Stop();
	void Start();
	void ReStart();
	void Init(CLayout &layout);

	void Release();
	void RButtonDown(CPoint &point);
	void LButtonDown(CPoint &point);
	void RButtonUp(CPoint &point);
	void LButtonUp(CPoint &point);
	void LRButtonUp(CPoint &point);
	void LButtonPress(CPoint &point);
	void LRButtonPress(CPoint &point);
};

