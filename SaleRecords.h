#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

class SaleRecords
{
private:
	string name;//����
	string phone;//�绰����
	string giftName;//��Ʒ����
	string number;//��Ʒ���
	double cost;//�ɱ�
	double price;//��Ʒ�ۼ�
	double actualPrice;//ʵ���ۼ�
	int amount;//���۵�����
	Date date;//��������

public:
	SaleRecords();//�޲ι���
	//�вι���˿��������ֻ����룬�˿���Ʒ���ƣ���Ʒ��ţ����ۣ��ۼۣ�����������
	SaleRecords(string name, string phone, string giftName, string number, double cost,
		double price, double actualPrice, int amount, Date date);//���캯��
	~SaleRecords();//����

	//�������
	friend ostream& operator << (ostream& os, const SaleRecords& t);//�������
	
	string getName();//��ȡ�˿�����
	void setName(string name);//�޸Ĺ˿���������Ҫ�����޸Ĺ˿���Ϣʱͬ���޸�

	string getPhone();//��ȡ�˿��ֻ���
	void setPhone(string phone);//�޸Ĺ˿��ֻ��ţ���Ҫ�����޸Ĺ˿���Ϣʱͬ���޸�

	string getGiftName();//��ȡ��Ʒ������
	string getNumber();//��ȡ��Ʒ�ı��

	double getCost();//��ȡ�ɱ�
	double getPrice();//��ȡ��Ʒ���ۼ�
	double getActualPrice();//��ȡ��Ʒ��ʵ���ۼۣ���Ϊ��Ա�����
	int getAmount();//��ȡ���������
};