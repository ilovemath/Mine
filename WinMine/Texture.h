#pragma once
class CTexture
{
public:
	CTexture();
	~CTexture();
public:
	enum Icon{
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
		BM,
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

		/*������ʱ��*/
		Led,
		LedBk

	};

protected:
	// ��ǰ��ʾͼƬ
	Icon ico;
	// ͼƬ����
	int num;
public:
	//λͼ����
	CBitmap bitmap;
	//����Ŀ��
	static const int H = 16;
	static const int W = 16;
public:
	void SetBitmap(UINT id);
	void SetIcon(Icon ico);				//������Ҫ��ʾͼƬ״̬
	CRect GetIconRect(Icon ico=Null);		//��ȡ��Ҫ��ʾͼƬ��λ��

};

