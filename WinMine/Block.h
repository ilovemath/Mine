#pragma once
#include "Texture.h"
class CBlock :
	public CTexture
{
public:
	CBlock();
	~CBlock();

private:

	//������
	int row;
	int col;

	//�Ƿ���Ҫ�ػ�
	bool redraw;

public:
	bool IsMine();//�ж��Ƿ�Ϊ��
	void SetMine();//����Ϊ��

	int GetNum();//��ȡ����
	void Increase();//�ܱ�������һ

	CRect GetPos();//����������ȡ����λ��
	void SetPos(int row, int col);//��������������

	bool IsFlagged();//�Ƿ񱻱��Ϊ��
	bool IsMarked();//�Ƿ񱻱��Ϊ�ʺ�
	bool IsOpened();//�Ƿ��Ѵ򿪣���ʾ���֣�
	bool IsPressed();//�Ƿ񱻰���
	bool IsMPressed();//�ʺ��Ƿ񱻰���
	bool IsNone();//�Ƿ�Ϊδ�򿪵�״̬
	bool IsBlank();//�Ƿ�Ϊ�հף��ܱ�������ף�

	bool IsReDraw();//�Ƿ���Ҫ�ػ�
	void SetReDraw(bool draw = true);//�����Ƿ��ػ�

};

