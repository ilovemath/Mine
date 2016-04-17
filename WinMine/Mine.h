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
	// �ܱ��׵ĸ���
	// -1��������Ϊ��
	int mine;
	
	//������
	int row;
	int col;

	//�Ƿ���Ҫ�ػ�
	bool redraw;

public:
	void IncMine();//�ܱ�������һ
	bool IsMine();//�ж��Ƿ�Ϊ��
	void SetMine();//����Ϊ��
	int GetMine();//��ȡ����

	CRect GetPic();//����CPicture�еĺ���

	CRect GetPos();//��ȡ����λ��
	void SetPos(int row, int col);//��������������

	bool IsFlagged();//�Ƿ񱻱��Ϊ��
	bool IsMarked();//�Ƿ񱻱��Ϊ�ʺ�
	bool IsOpened();//�Ƿ��Ѵ򿪣���ʾ���֣�
	bool IsPressed();//�Ƿ񱻰���
	bool IsMPressed();//�ʺ��Ƿ񱻰���
	bool IsNone();//�Ƿ�Ϊδ�򿪵�״̬
	bool IsBlank();//�Ƿ�Ϊ�հף��ܱ�������ף�

	bool IsReDraw();//�Ƿ���Ҫ�ػ�
	void NotReDraw();//��Ҫ�ػ�
	void ForceReDraw();//ǿ���ػ�
};

