#pragma once
struct Scale{
	int num;	//�׵ĸ���
	int total;	//������������
	int row;	//������������
	int col;	//������������
};
enum Level{
	Hard,
	Medium,
	Easy,
	Custom
};
class CLevel
{
public:
	CLevel();
	~CLevel();

private:
	static Level level;		//����
	static Scale custom;	//�Զ��弶��

public:
	static Scale GetScale();//��ȡ��ǰ���𣨼򵥡��еȡ����ѡ��Զ��壩
	static void SetType(Level type);//�������ͣ��򵥡��еȡ����ѡ��Զ��壩
	static Scale GetCustom();//��ȡ�Զ�������
	static void SetCustom(int n, int t, int r, int c);//�����Զ���
};

