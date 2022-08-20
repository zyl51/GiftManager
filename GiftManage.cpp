#include "GiftManage.h"
#include <iomanip>
#include <string>
#include <cstring>
#include <stdio.h>

GiftManage::GiftManage()
{
	ifstream fin(GIFTFILE, ios::in);//打开礼品信息文件

	if (!fin.is_open())//判断文件是否存在
	{
		cout << "礼品信息文件不存在" << endl;
	}
	else
	{
		char ch;
		fin >> ch;//读入单个字符

		if (!fin.eof())//判断文件是否为空
		{
			int GiftSize = getGiftSize();//获取数据的数量
			gift = vector<Gift>(GiftSize);//初始化vector<Gift>
			GiftInit();//读取文件数据
		}
		else
		{
			cout << "礼品信息文件为空" << endl;
		}
	}
	
	fin.close();//关闭文件
	
	/*******************************************/
	fin.open(BUYERFILE, ios::in);//打开顾客信息文件

	if (!fin.is_open())//判断文件是否存在
	{
		cout << "顾客信息文件不存在" << endl;
	}
	else
	{
		char ch;
		fin >> ch;

		if (!fin.eof())//判断文件是否为空
		{
			int BuyerSize = getBuyerSize();//获取长度
			buyer = vector<Buyer>(BuyerSize);//初始化顾客
			BuyerInit();//读取顾客文件
		}
		else
		{
			cout << "顾客文件为空" << endl;
		}
	}
	
	fin.close();//关闭文件

	/*******************************************/
	fin.open(SALERECORDSFILE, ios::in);//打开顾客销售记录文件

	if (!fin.is_open())//判断文件是否存在
	{
		cout << "销售记录文件不存在" << endl;
	}
	else
	{
		char ch;
		fin >> ch;
		if (!fin.eof())//判断文件是否为空
		{
			int saleRecordsSize = getSaleRecordsSize();//获取长度
			saleRecords = vector<SaleRecords>(saleRecordsSize);//初始化长度
			SaleRecordsInit();//获取销售记录的内容
		}
		else
		{
			cout << "销售记录文件为空" << endl;
		}
	}

	fin.close();//关闭文件
}

GiftManage::~GiftManage()
{
	save();//将数据存入文件中，实现可持久化
	gift.clear();//清空礼品信息
	buyer.clear();//清空顾客信息
	saleRecords.clear();//清空销售记录
}

void GiftManage::save()
{
	if (gift.size())//如果长度不为0，即有数据才保存
	{
		ofstream fout(GIFTFILE, ios::out);//打开礼品文件进行输出

		fout.setf(ios::left);//输出都保持15个字符并且靠左
		//输出提示信息，方便用户查看
		fout << setw(15) << "礼品编号" << setw(15) << "礼品名称" << setw(15) <<
			"进价成本" << setw(15) << "售卖价格" << setw(15) << "产品数量" << endl;

		//输出所有礼品的信息，礼品信息按照临聘编号字典序排序
		for (int i = 0; i < gift.size(); i++)
			fout << gift[i] << endl;
		
		//取消输出靠左的设定
		cout.unsetf(ios::left);
		fout.close();//关闭文件
	}

	/*******************************************/

	if (buyer.size())//如果长度不为0，即有数据才保存
	{
		ofstream fout(BUYERFILE, ios::out); ///打开礼品顾客进行输出

		fout.setf(ios::left);
		//输出顾客的信息提示，方便查看
		fout << setw(15) << "姓名" << setw(15) << "电话号码" <<
			setw(15) << "是会员吗" << setw(15) << "消费金额" << endl;

		//输出用户的信息，顾客信息按照名字字典序排序
		for (int i = 0; i < buyer.size(); i++)
			fout << buyer[i] << endl;
		
		//取消输出靠左的设定
		cout.unsetf(ios::left);
		fout.close();//关闭文件
	}

	/*******************************************/

	if (saleRecords.size())//如果长度不为0，即有数据才保存
	{
		ofstream fout(SALERECORDSFILE, ios::out); // 打开销售记录进行输出

		fout.setf(ios::left);
		//输出销售记录的提示信息，方便查看
		fout << setw(15) << "姓名" << setw(15) << "电话号码" << setw(15) << "礼品名称"
			<< setw(15) << "礼品编号" << setw(15) << "礼品成本" << setw(15) << "礼品售价" 
			<< setw(15) << "实际售价" << setw(15) << "购买数量" << setw(15) << "购买日期" << endl;

		//输出销售记录
		for (int i = 0; i < saleRecords.size(); i++)
			fout << saleRecords[i] << endl;
		
		//取消输出靠左的设定
		cout.unsetf(ios::left);
		fout.close();
	}
}

int GiftManage::getGiftSize()
{//获取礼品信息的长度
	ifstream fin(GIFTFILE, ios::in);//打开礼品文件

	string s;
	getline(fin, s);//将第一行的提示信息吃掉
	int Size = 0;//文件中数据的长度
	while (getline(fin, s)) Size++;//一行一行的读取记录，记录长度

	fin.close();//关闭文件
	return Size;
}

void GiftManage::GiftInit()
{//初始化礼品信息，将文件的信息放入程序中
	ifstream fin(GIFTFILE, ios::in);//打开礼品文件

	string number;//礼品编号
	string name;//礼品名称
	double cost;//进价成本
	double price;//售卖价格
	int amount;//产品数量
	getline(fin, number);//吞掉第一行的信息
	for (int i = 0; i < gift.size(); i++)
	{//将文件数据挨个输入
		fin >> number >> name >> cost >> price >> amount;
		gift[i] = Gift(number, name, cost, price, amount);
	}

	fin.close();//关闭文件
}

int GiftManage::getBuyerSize()
{//获取顾客的文件长度
	ifstream fin(BUYERFILE, ios::in);//打开顾客文件
	
	string s;
	getline(fin, s);//将第一行提示信息吃掉
	int Size = 0;
	while (getline(fin, s)) Size++;//一行一行的读取，获取长度

	fin.close();//关闭文件
	return Size;
}

void GiftManage::BuyerInit()
{//初始化顾客信息，将顾客文件放入程序中
	ifstream fin(BUYERFILE, ios::in);

	string name;//买者的姓名
	string phone;//买者的电话号码
	string isMember;//是否是会员
	double money;//消费金额,消费金额达到200成为会员

	getline(fin, name);//吃掉第一行提示信息
	for (int i = 0; i < buyer.size(); i++)
	{//将顾客的信息一点一点读入
		fin >> name >> phone >> isMember >> money;
		buyer[i] = Buyer(name, phone, isMember == "是", money);
	}
	fin.close();//文件关闭
}

int GiftManage::getSaleRecordsSize()
{//获取销售记录的长度
	ifstream fin(SALERECORDSFILE, ios::in);//打开销售记录的文件

	string s;//吃掉第一行数据
	getline(fin, s);
	int Size = 0;
	while (getline(fin, s)) Size++;//记录行数

	fin.close();//关闭文件 
	return Size;
}

void GiftManage::SaleRecordsInit()
{//初始化销售记录
	ifstream fin(SALERECORDSFILE, ios::in);//打开销售记录文件

	string name;//人名
	string phone;//电话号码
	string giftName;//礼品名称
	string number;//礼品编号
	double cost;//礼品成本
	double price;//礼品售价
	double actualPrice;//实际售价
	int amount;//数量
	int year = 0, month = 0, day = 0;//定义年月日

	getline(fin, name);//吃掉第一行提示信息
	for (int i = 0; i < saleRecords.size(); i++)
	{//将文件里面的数据挨个读入
		fin >> name >> phone >> giftName >> number >> cost >> price >> actualPrice >> amount;
		string s;
		fin >> s;
		//以下是计算年月日的
		year = 0, month = 0, day = 0;
		for (int j = 0; j < 4; j++) year = year * 10 + s[j] - '0';//计算年
		for (int j = 5; j < 7; j++) month = month * 10 + s[j] - '0';//计算月
		for (int j = 8; j < 10; j++) day = day * 10 + s[j] - '0';//计算日
		saleRecords[i] = SaleRecords(name, phone, giftName, number, cost, price, actualPrice, amount, Date(year, month, day));
	}
	fin.close();//关闭文件
}

//通过礼品编号查找礼品存不存在
int GiftManage::checkGift(string number)
{//查询有没有礼品，存在返回位置，不存在返回-1
	for (int i = 0; i < gift.size(); i++)
		if (gift[i].getNumber() == number)
			return i;//返回位置
		else if (gift[i].getNumber() > number)
			return -1;//因为礼品文件按照礼品编号排序，
					  //所以编号大于所要查询的，就可以直接返回没有了
	return -1;
}

//通过手机号查询顾客
int GiftManage::checkBuyer(string phone)
{//查询顾客存不存在，存在返回位置，不存在返回-1
	for (int i = 0; i < buyer.size(); i++)
		if (buyer[i].getPhone() == phone) 
			return i;
	return -1;
}

void GiftManage::menu()
{
	cout << "************** 欢迎来到礼品专卖店管理系统 **************" << endl;
	cout << "****************** A.显示所有礼品信息 ******************" << endl;
	cout << "****************** B.显示所有顾客信息 ******************" << endl;
	cout << "****************** C.显示所有销售记录 ******************" << endl;
	cout << "****************** D.添加礼品入仓库   ******************" << endl;
	cout << "****************** E.将礼品售出       ******************" << endl;
	cout << "****************** F.修改礼品的信息   ******************" << endl;
	cout << "****************** G.修改顾客的信息   ******************" << endl;
	cout << "****************** H.查询礼品信息     ******************" << endl;
	cout << "****************** I.查询顾客信息     ******************" << endl;
	cout << "****************** J.查询销售记录     ******************" << endl;
	cout << "****************** K.计算总利润       ******************" << endl;
	cout << "****************** L.退出礼品专卖店管理系统 ************" << endl;
}

void GiftManage::showGift()//显示所有礼品信息
{
	if (gift.size() == 0)
	{
		cout << "礼品信息为空" << endl;
		return;
	}
	cout.setf(ios::left);
	//输出礼品提示信息
	cout << setw(15) << "礼品编号" << setw(15) << "礼品名称" << setw(15) <<
		"进价成本" << setw(15) << "售卖价格" << setw(15) << "产品数量" << endl;
	for (int i = 0; i < gift.size(); i++)
		cout << gift[i] << endl;
	cout.unsetf(ios::left);
}

void GiftManage::showBuyer()//显示所有顾客信息
{
	if (buyer.size() == 0)
	{
		cout << "顾客信息为空" << endl;
		return;
	}
	//输出顾客提示信息
	cout.setf(ios::left);
	cout << setw(15) << "姓名" << setw(15) << "电话号码" <<
		setw(15) << "是会员吗" << setw(15) << "消费金额" << endl;
	for (int i = 0; i < buyer.size(); i++)
		cout << buyer[i] << endl;
	cout.unsetf(ios::left);
}

void GiftManage::showSaleRecords()//显示所有销售记录
{
	if (saleRecords.size() == 0)
	{
		cout << "销售记录为空" << endl;
		return;
	}
	//输出销售记录的提示信息
	cout.setf(ios::left);
	cout << setw(15) << "姓名" << setw(15) << "电话号码" << setw(15) << "礼品名称"
			<< setw(15) << "礼品编号" << setw(15) << "礼品成本" << setw(15) << "礼品售价" 
			<< setw(15) << "实际售价" << setw(15) << "购买数量" << setw(15) << "购买日期" << endl;
	for (int i = 0; i < saleRecords.size(); i++)
		cout << saleRecords[i] << endl;
	cout.unsetf(ios::left);
}

//增加礼品
void GiftManage::addGift()//添加礼品入仓库
{
	string number;//礼品编号
	int amount;//产品数量
	cout << "请输入你要添加的礼品的礼品编号：" << endl;
	cin >> number;

	int idx = checkGift(number);//获取礼品的位置
	if (~idx)//如果产品已经存在
	{//就可以直接在其基础上增加数量
		cout << "请输入你要添加的礼品的产品数量：" << endl;
		cin >> amount;
		gift[idx].setAmount(gift[idx].getAmount() + amount);
		return;
	}

	string name;//礼品名称
	double cost;//进价成本
	double price;//售卖价格

	cout << "请输入你要添加的礼品的礼品名称：" << endl;
	cin >> name;

	cout << "请输入你要添加的礼品的进价：" << endl;
	cin >> cost;

	cout << "请输入你要添加的礼品的售价：" << endl;
	cin >> price;

	cout << "请输入你要添加的礼品的产品数量：" << endl;
	cin >> amount;

	//加入新的礼品
	gift.push_back(Gift(number, name, cost, price, amount));
	//将新加入的礼品放到合适的位置
	for (int i = gift.size() - 1; i >= 1; i--)//gift按照编号字典序排序
		if (gift[i].getNumber() < gift[i - 1].getNumber())
			swap(gift[i], gift[i - 1]);
}

//新增顾客
int GiftManage::addBuyer(string name, string phone, double money)
{
	buyer.push_back(Buyer(name, phone));//加入新的顾客
	buyer[buyer.size() - 1].setMoney(money);//修改顾客的消费
	//按照名字字典序排序
	for (int i = buyer.size() - 1; i >= 1; i--)
		if (buyer[i].getName() < buyer[i - 1].getName())
			swap(buyer[i], buyer[i - 1]);
		else return i;//返回加入的顾客的位置
	return 0;
}

//增加销售记录
void GiftManage::addSaleRecords(string name, string phone, string giftName, string number,
	double cost, double price, double actualPrice, int amount)//添加销售记录
{
	int year = 0, month = 0, day = 0;
	//获取本事实时时间
	time_t now;
	time(&now);
	tm* t = new tm;
	localtime_s(t, &now);
	year = 1900 + t-> tm_year, month = 1 + t->tm_mon, day = t->tm_mday;
	//增加销售记录
	saleRecords.push_back(SaleRecords(name, phone, giftName, number, cost, price, actualPrice, amount, Date(year, month, day)));
}

void GiftManage::sellGift()//将礼品售出
{
	cout << "请输入要售出的礼品的编号：" << endl;
	string number;
	cin >> number;

	int idx = checkGift(number);//获得礼品的位置
	if (idx == -1)
	{
		cout << "产品不存在" << endl;
	}
	else
	{
		cout << "请输入要售出的产品的数量：" << endl;
		int amount;
		cin >> amount;
		if (gift[idx].getAmount() < amount)
		{
			cout << "出售失败，产品库存不足" << endl;
			cout << "库存容量：" << gift[idx].getAmount() << endl;
		}
		else
		{
			//同步修改顾客信息和销售记录
			cout << "请输入购买礼品的顾客信息" << endl;
			string name;
			string phone;
			cout << "请输入购买礼品的顾客姓名" << endl;
			cin >> name;

			cout << "请输入购买礼品的顾客手机号码" << endl;
			cin >> phone;

			int buyerIdx = checkBuyer(phone);//获得顾客的位置

			/*********增加顾客信息*********/
			double discount = 1;//标记是否折扣
			if (~buyerIdx)//如果顾客已经存在
			{//直接修改价格即可
				if (buyer[buyerIdx].getIsMember())
				{//会员打八折
					discount = 0.8;//会员打折
					//修改顾客消费金额
					buyer[buyerIdx].setMoney(buyer[buyerIdx].getMoney() + amount * 0.8 * gift[idx].getPrice());
				}
				else
				{//修改顾客消费金额
					buyer[buyerIdx].setMoney(buyer[buyerIdx].getMoney() + amount * gift[idx].getPrice());
				}
			}
			else
			{//顾客不存在的话增加入新的顾客
				buyerIdx = addBuyer(name, phone, amount * gift[idx].getPrice());
			}
			/*********增加销售记录*********/
			//增加新的销售记录，消费过之后才会成为会员
			addSaleRecords(name, phone, gift[idx].getName(), number, gift[idx].getCost(), gift[idx].getPrice(), 
				gift[idx].getPrice() * discount, amount);
			//更新数量
			gift[idx].setAmount(gift[idx].getAmount() - amount);
			cout << "出售成功" << endl;
		}
	}
}

void GiftManage::updateGift()//修改礼品的信息
{//修改礼品信息的时候，记录不能同步修改，因为礼品已经卖出去，售价等诸多信息不宜修改
	string number;//礼品编号
	cout << "请输入你要修改的礼品编号" << endl;
	cin >> number;

	int idx = checkGift(number);//查找礼品位置
	if (idx == -1)
	{
		cout << "产品不存在" << endl;
		return;
	}

	cout << "请输入你要修改的礼品的新信息" << endl;
	string name;//礼品名称
	double cost;//进价成本
	double price;//售卖价格
	int amount;//产品数量

	cout << "请输入你要修改的礼品的新的编号" << endl;
	cin >> number;

	cout << "请输入你要修改的礼品的新的名称：" << endl;
	cin >> name;

	cout << "请输入你要修改的礼品的新的进价：" << endl;
	cin >> cost;

	cout << "请输入你要修改的礼品的新的售价：" << endl;
	cin >> price;


	//库存量有多少就是多少
	amount = gift[idx].getAmount();

	string choice;
	cout << "你要修改库存量吗？(YES/NO)" << endl;
	cin >> choice;

	if(choice == "YES")
	{
		cout << "请输入你要修改的礼品的新的库存量：" << endl;
		cin >> amount;
	}

	gift[idx] = Gift(number, name, cost, price, amount);
	cout << "修改成功" << endl;
}

void GiftManage::updateBuyer()//修改顾客的信息
{//修改顾客信息的时候，需要同步将记录同步修改
	string phone;//买者的电话号码

	cout << "请输入你要修改的顾客的电话号码" << endl;
	cin >> phone;

	int idx = checkBuyer(phone);//查找顾客的位置
	if (idx == -1)
	{
		cout << "此顾客不存在" << endl;
		return;
	}

	string lastPhone = phone;//记录一下修改前的手机号

	cout << "请输入你要修改的顾客的新的信息" << endl;
	string name;//买者的姓名
	 
	cout << "请输入你要修改的顾客的新的姓名" << endl;
	cin >> name;

	cout << "请输入你要修改的顾客的新的手机号" << endl;
	cin >> phone;

	buyer[idx].setName(name);
	buyer[idx].setPhone(phone);

	//同步修改销售记录信息
	for (int i = 0; i < saleRecords.size(); i++)
	{
		if (saleRecords[i].getPhone() == lastPhone)
		{
			saleRecords[i].setName(name);
			saleRecords[i].setPhone(phone);
		}
	}
	
	cout << "修改成功" << endl;
}

void GiftManage::queryGift()//查询礼品信息
{
	cout << "请输入查找礼品的方式" << endl;
	cout << "1.通过礼品编号查找" << endl;
	cout << "2.通过礼品名称查找" << endl;

	int choice;
	cin >> choice;
	int num = 0;//用于记录是否查到礼品信息了
	if (choice == 1)
	{
		cout << "请输入你想查询的礼品编号" << endl;
		string number;
		cin >> number;

		cout.setf(ios::left);
		cout << setw(15) << "礼品编号" << setw(15) << "礼品名称" << setw(15) <<
			"进价成本" << setw(15) << "售卖价格" << setw(15) << "产品数量" << endl;
		for (int i = 0; i < gift.size(); i++)
			if (gift[i].getNumber() == number)
			{
				num++;
				cout << gift[i] << endl;
			}
		
		cout.unsetf(ios::left);
	}
	else
	{
		cout << "请输入你要查询的礼品名称" << endl;
		string name;
		cin >> name;

		cout.setf(ios::left);
		cout << setw(15) << "礼品编号" << setw(15) << "礼品名称" << setw(15) <<
			"进价成本" << setw(15) << "售卖价格" << setw(15) << "产品数量" << endl;
		
		for (int i = 0; i < gift.size(); i++)
			if (gift[i].getName() == name)
			{
				num++;
				cout << gift[i] << endl;
			}
		
		cout.unsetf(ios::left);
	}

	if (!num)
	{
		cout << "您查找的礼品不存在" << endl;
	}
}

void GiftManage::queryBuyer()//查询顾客信息
{
	cout << "请输入查找顾客的方式" << endl;
	cout << "1.通过姓名查找" << endl;
	cout << "2.通过手机号查找" << endl;

	int choice, num = 0;//num用于标记是否查到顾客信息了
	cin >> choice;
	if (choice == 1)
	{
		cout << "请输入你要查找的顾客姓名" << endl;
		string name;
		cin >> name;

		cout.setf(ios::left);
		cout << setw(15) << "姓名" << setw(15) << "电话号码" <<
			setw(15) << "是会员吗" << setw(15) << "消费金额" << endl;
		for (int i = 0; i < buyer.size(); i++)
			if (buyer[i].getName() == name) 
			{
				num++;
				cout << buyer[i] << endl;
			}
		
		cout.unsetf(ios::left);
	}
	else
	{
		cout << "请你输入你要查找的顾客的手机号" << endl;
		string phone;
		cin >> phone;

		cout.setf(ios::left);
		cout << setw(15) << "姓名" << setw(15) << "电话号码" <<
			setw(15) << "是会员吗" << setw(15) << "消费金额" << endl;
		for (int i = 0; i < buyer.size(); i ++ )
			if (buyer[i].getPhone() == phone)
			{
				num++;
				cout << buyer[i] << endl;
			}
		
		cout.unsetf(ios::left);
	}

	if (!num)
	{
		cout << "你要查找的顾客不存在" << endl;
	}
}

void GiftManage::querySaleRecords()//查询销售记录
{
	cout << "请输入查找销售记录的方式" << endl;
	cout << "1.通过顾客姓名查找" << endl;
	cout << "2.通过顾客手机号查找" << endl;
	cout << "3.通过礼品编号查找" << endl;
	cout << "4.通过礼品名称查找" << endl;

	string name;
	string phone;
	string number;
	string giftName;
	int num = 0;//用于记录是否查到销售记录了

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "请输入你要查询的顾客的姓名" << endl;
		cin >> name;
		cout.setf(ios::left);
		cout << setw(15) << "姓名" << setw(15) << "电话号码" << setw(15) << "礼品名称"
			<< setw(15) << "礼品编号" << setw(15) << "礼品成本" << setw(15) << "礼品售价" 
			<< setw(15) << "实际售价" << setw(15) << "购买数量" << setw(15) << "购买日期" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getName() == name)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	case 2:
		cout << "请输入你要查询的顾客的手机号码" << endl;
		cin >> phone;
		cout.setf(ios::left);
		cout << setw(15) << "姓名" << setw(15) << "电话号码" << setw(15) << "礼品名称"
			<< setw(15) << "礼品编号" << setw(15) << "礼品成本" << setw(15) << "礼品售价"
			<< setw(15) << "实际售价" << setw(15) << "购买数量" << setw(15) << "购买日期" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getPhone() == phone)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	case 3:
		cout << "请输入你要查询的礼品编号" << endl;
		cin >> number;
		cout.setf(ios::left);
		cout << setw(15) << "姓名" << setw(15) << "电话号码" << setw(15) << "礼品名称"
			<< setw(15) << "礼品编号" << setw(15) << "礼品成本" << setw(15) << "礼品售价"
			<< setw(15) << "实际售价" << setw(15) << "购买数量" << setw(15) << "购买日期" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getNumber() == number)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	case 4:
		cout << "请输入你要查询的礼品名称" << endl;
		cin >> giftName;
		cout.setf(ios::left);
		cout << setw(15) << "姓名" << setw(15) << "电话号码" << setw(15) << "礼品名称"
			<< setw(15) << "礼品编号" << setw(15) << "礼品成本" << setw(15) << "礼品售价"
			<< setw(15) << "实际售价" << setw(15) << "购买数量" << setw(15) << "购买日期" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getGiftName() == giftName)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	default:
		break;
	}

	if (!num)
	{
		cout << "销售记录不存在" << endl;
	}
}

void GiftManage::totalProfit()
{
	double total = 0;

	for (int i = 0; i < saleRecords.size(); i++)
	{
		total += (saleRecords[i].getActualPrice() - saleRecords[i].getCost()) * saleRecords[i].getAmount();
	}

	//输出两位小数
	cout << "总利润为：" << setiosflags(ios::fixed) << setprecision(2) << total << endl;
}
