#pragma once
class CPicture
{

public:
	enum Pic{
		//δ����
		Null,
		/*��״̬ͼ*/
		None,  //δ�򿪵�״̬
		Num,   //���֣�0����ʾ�հ�
		Mark,  //�ʺ�
		Flag,  //������
		Mine,  //�����ȷ����
		XMine, //��Ǵ������
		RMine, //�����е���
		Press, //������ʱ��״̬
		MPress,//�ʺű����µ�״̬

		/*Ц����ť*/
		Sad,
		Cool,
		Amaze,
		Smile,
		SPress,

		/*������ʱ��Board*/
		Led,
		LedBk,

		/*�߿�*/
		LT,
		LTM,
		LM,
		LBM,
		LB,

		RT,
		RTM,
		RM,
		RBM,
		RB,

		TM,
		MM,
		BM

	};
public:
	CPicture();
	~CPicture();
protected:
	// ��ǰ��ʾͼƬ
	Pic pic;
	// ��ͼƬΪ����ʱ
	int num;
public:
	CRect GetPic(Pic p=Null);//��ȡ��Ҫ��ʾͼƬ��λ��
	void SetPic(Pic state);//������Ҫ��ʾͼƬ״̬

};

