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
	
	Type type;//����
    Scale hard,medium,easy,custom;//����

private:
	Scale GetScale();//��ȡ��ǰ���𣨼򵥡��еȡ����ѡ��Զ��壩
public:
	void SetType(Type type);//�������ͣ��򵥡��еȡ����ѡ��Զ��壩
	Scale GetCustom();//��ȡ�Զ�������
	void SetCustom(Scale custom);//�����Զ���

	void InitMine();//��ʼ������
	CRect GetFieldRect();//��ȡ��������
	int PtToIndex(CPoint point);//������ת��Ϊ������

	void Draw(CDC *pDC);//����MineField
	void Invalidate(bool bErase=false);//ʹ������Ч
};

