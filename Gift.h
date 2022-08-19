#pragma once
#include <iostream>
#include "SaleRecords.h"

using namespace std;

class Gift
{
private:
	string number;//��Ʒ���
	string name;//��Ʒ����
	double cost;//���۳ɱ�
	double price;//�����۸�
	int amount;//��Ʒ����

public:
	Gift();//�޲ι���
	//�вι�����Ʒ��ţ���Ʒ���ƣ����ۣ��ۼۣ�����
	Gift(string number, string name, double cost, double price, int amount);
	~Gift();

	//������Ʒ�����
	friend ostream& operator << (ostream& os, const Gift& gift);

	string getNumber();//��ȡ��Ʒ���
	void setNumber(string number);//�޸���Ʒ���

	string getName();//��ȡ��Ʒ����
	void setName(string name);//�޸���Ʒ����

	double getCost();//��ȡ��Ʒ����
	void setCost(double cost);//�޸Ľ��۳ɱ�

	double getPrice();//��ȡ��Ʒ�ۼ�
	void setPrice(double price);//�޸������۸�

	int getAmount();//��ȡ��Ʒ����
	void setAmount(int amount);//�޸���Ʒ������
};