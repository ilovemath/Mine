#pragma once
#include "Mine.h"

typedef struct {
	int row;
	int col;
	int num;
}Scale;

class CRules
{
public:
	CRules();
	~CRules(void);
protected:
	//������
	CMine *pMine;
	//�׹�ģ
	Scale scale;
	//�ѱ������
	int flagged;
private:
	int  AroundFlag(int index);
	void Expand(int index);
public:
	void NotPress();
	void RButtonDown(int index);
	void LButtonDown(int index);
	void LButtonUp(int index);
	void LRButtonUp(int index);
	void LButtonPress(int index);
	void LRButtonPress(int index);
};

