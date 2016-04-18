#pragma once
struct Scale{
	int num;	//雷的个数
	int total;	//雷区方格总数
	int row;	//雷区方格行数
	int col;	//雷区方格列数
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
	static Level level;		//级别
	static Scale custom;	//自定义级别

public:
	static Scale GetScale();//获取当前级别（简单、中等、困难、自定义）
	static void SetType(Level type);//设置类型（简单、中等、困难、自定义）
	static Scale GetCustom();//获取自定义数据
	static void SetCustom(int n, int t, int r, int c);//设置自定义
};

