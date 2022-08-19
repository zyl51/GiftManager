#include <iostream>
#include <fstream>
#include <cstring>
#include "Buyer.h"
#include "Gift.h"
#include "Date.h"
#include "SaleRecords.h"
#include "GiftManage.h"
#include <iomanip>

using namespace std;

void clearScreen()//实现清屏功能
{
	system("pause");
	system("cls");
}

int main()
{
	GiftManage gm;//创建礼品管理系统对象
	int choice;

	while (true)
	{
		gm.menu();//将菜单输出
		cout << "请输入你的选择" << endl;
		string c;
		cin >> c;
		choice = c.back() - 'A' + 1;//获取用户的选择

		string yesOrNo;//用来判断是否退出管理系统
		switch (choice)
		{
		case 1://显示所有礼品信息
			gm.showGift();
			clearScreen();
			break;
		case 2://显示所有顾客信息
			gm.showBuyer();
			clearScreen();
			break;
		case 3://显示所有销售记录
			gm.showSaleRecords();
			clearScreen();
			break;
		case 4://添加礼品入仓库
			gm.addGift();
			clearScreen();
			break;
		case 5://将礼品售出
			gm.sellGift();
			clearScreen();
			break;
		case 6://修改礼品的信息
			gm.updateGift();
			clearScreen();
			break;
		case 7://修改顾客的信息
			gm.updateBuyer();
			clearScreen();
			break;
		case 8://查询礼品信息
			gm.queryGift();
			clearScreen();
			break;
		case 9://查询顾客信息
			gm.queryBuyer();
			clearScreen();
			break;
		case 10://查询销售记录
			gm.querySaleRecords();
			clearScreen();
			break;
		case 11://计算总利润
			gm.totalProfit();
			clearScreen();
			break;
		case 12:
			cout << "确定要退出吗？(YES/NO)" << endl;
			cin >> yesOrNo;
			if (yesOrNo == "YES")
			{
				cout << "退出成功" << endl;
				return 0;
			}
			clearScreen();
			break;
		default:
			cout << "输入有误，请重新输入：" << endl;
			clearScreen();
			break;
		}
	}
	return 0;
}