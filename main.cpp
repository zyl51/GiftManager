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

void clearScreen()//ʵ����������
{
	system("pause");
	system("cls");
}

int main()
{
	GiftManage gm;//������Ʒ����ϵͳ����
	int choice;

	while (true)
	{
		gm.menu();//���˵����
		cout << "���������ѡ��" << endl;
		string c;
		cin >> c;
		choice = c.back() - 'A' + 1;//��ȡ�û���ѡ��

		string yesOrNo;//�����ж��Ƿ��˳�����ϵͳ
		switch (choice)
		{
		case 1://��ʾ������Ʒ��Ϣ
			gm.showGift();
			clearScreen();
			break;
		case 2://��ʾ���й˿���Ϣ
			gm.showBuyer();
			clearScreen();
			break;
		case 3://��ʾ�������ۼ�¼
			gm.showSaleRecords();
			clearScreen();
			break;
		case 4://�����Ʒ��ֿ�
			gm.addGift();
			clearScreen();
			break;
		case 5://����Ʒ�۳�
			gm.sellGift();
			clearScreen();
			break;
		case 6://�޸���Ʒ����Ϣ
			gm.updateGift();
			clearScreen();
			break;
		case 7://�޸Ĺ˿͵���Ϣ
			gm.updateBuyer();
			clearScreen();
			break;
		case 8://��ѯ��Ʒ��Ϣ
			gm.queryGift();
			clearScreen();
			break;
		case 9://��ѯ�˿���Ϣ
			gm.queryBuyer();
			clearScreen();
			break;
		case 10://��ѯ���ۼ�¼
			gm.querySaleRecords();
			clearScreen();
			break;
		case 11://����������
			gm.totalProfit();
			clearScreen();
			break;
		case 12:
			cout << "ȷ��Ҫ�˳���(YES/NO)" << endl;
			cin >> yesOrNo;
			if (yesOrNo == "YES")
			{
				cout << "�˳��ɹ�" << endl;
				return 0;
			}
			clearScreen();
			break;
		default:
			cout << "�����������������룺" << endl;
			clearScreen();
			break;
		}
	}
	return 0;
}