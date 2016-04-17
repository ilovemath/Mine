#pragma once
class CPicture
{

public:
	enum Pic{
		//未设置
		Null,
		/*雷状态图*/
		None,  //未打开的状态
		Num,   //数字，0则显示空白
		Mark,  //问号
		Flag,  //红旗标记
		Mine,  //标记正确的雷
		XMine, //标记错误的雷
		RMine, //被踩中的雷
		Press, //被按下时的状态
		MPress,//问号被按下的状态

		/*笑脸按钮*/
		Sad,
		Cool,
		Amaze,
		Smile,
		SPress,

		/*分数、时间Board*/
		Led,
		LedBk,

		/*边框*/
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
	// 当前显示图片
	Pic pic;
	// 当图片为数字时
	int num;
public:
	CRect GetPic(Pic p=Null);//获取所要显示图片的位置
	void SetPic(Pic state);//设置所要显示图片状态

};

