#pragma once
#include <iostream>
#include <vector>
#include "Buyer.h"
#include "Gift.h"
#include "SaleRecords.h"
#include <fstream>

#define GIFTFILE "Gift.txt" //定义宏方便以后更改文件名
#define BUYERFILE "Buyer.txt" //定义宏方便以后更改文件名
#define SALERECORDSFILE "saleRecords.txt" //定义宏方便以后更改文件名

using namespace std;

class GiftManage
{
private:
	vector<Gift> gift;//储存礼物的信息，按照礼品编号字典序排序
	vector<Buyer> buyer;//储存顾客的信息
	vector<SaleRecords> saleRecords;//储存消费记录
	
public:
	GiftManage();//构造函数读取文件内容
	~GiftManage();//析构函数将内容存入文件中，并清空程序储存

	void save();//将信息存入文件中

	int getGiftSize();//获取礼品文件长度
	void GiftInit();//读取礼物文件内容

	int getBuyerSize();//获取顾客文件长度
	void BuyerInit();//读取顾客文件内容

	int getSaleRecordsSize();//获取销售记录长度
	void SaleRecordsInit();//读取销售记录内容

	int checkGift(string number);//通过礼品编号查询产品存不存在
	int checkBuyer(string phone);//通过手机号查询顾客存不存在

	void menu();//显示菜单
	void showGift();//显示所有礼品信息
	void showBuyer();//显示所有顾客信息
	void showSaleRecords();//显示所有销售记录
	void addGift();//添加礼品入仓库
	int addBuyer(string name, string phone, double amount);//添加顾客
	void addSaleRecords(string name, string phone, string giftName, string number, 
		double cost, double price, double actualPrice, int mount);//添加销售记录
	void sellGift();//将礼品售出
	void updateGift();//修改礼品的信息
	void updateBuyer();//修改顾客的信息
	void queryGift();//查询礼品信息
	void queryBuyer();//查询顾客信息
	void querySaleRecords();//查询销售记录
	void totalProfit();//计算总利润
};