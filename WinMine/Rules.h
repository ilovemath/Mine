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
	//Ц����ť
	CFace *face;
	//�������
	CBoard *time;
	CBoard *mine;
	//����
	CMineField *field;

	//�׹�ģ
	Scale scale;
	//�ѱ������
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

