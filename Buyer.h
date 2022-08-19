#pragma once
#include <iostream>
#include "SaleRecords.h"

using namespace std;

const int MEMBER = 2000;//���ѳ�����������Գ�Ϊ��Ա

//ʵ�ֹ˿͵��ඨ��
class Buyer
{
private:
	string name;//���ߵ�����
	string phone;//���ߵĵ绰����
	bool isMember;//�Ƿ��ǻ�Ա
	double money;//���ѽ��,���ѽ��ﵽ2000��Ϊ��Ա

public:
	Buyer();//�޲ι���
	Buyer(string name, string phone);//�вι������ֺ͵绰����
	//�вι����������ֻ����룬�Ƿ��Ա�����ѽ��
	Buyer(string name, string phone, bool isMember, double money);
	~Buyer();

	friend ostream& operator << (ostream& os, const Buyer& t);//���ع˿�������

	string getName();//��ȡ�˿�����
	void setName(string name);//�޸�����

	string getPhone();//��ȡ�ֻ�����
	void setPhone(string phone);//�޸��ֻ�����

	bool getIsMember();//��ȡ���ǲ��ǻ�Ա
	void setIsMember(bool sign);//�޸Ļ�Ա

	double getMoney();//��ù˿����ѽ��
	void setMoney(double money);//�޸Ĺ˿ͽ��
};