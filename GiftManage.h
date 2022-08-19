#pragma once
#include <iostream>
#include <vector>
#include "Buyer.h"
#include "Gift.h"
#include "SaleRecords.h"
#include <fstream>

#define GIFTFILE "Gift.txt" //����귽���Ժ�����ļ���
#define BUYERFILE "Buyer.txt" //����귽���Ժ�����ļ���
#define SALERECORDSFILE "saleRecords.txt" //����귽���Ժ�����ļ���

using namespace std;

class GiftManage
{
private:
	vector<Gift> gift;//�����������Ϣ��������Ʒ����ֵ�������
	vector<Buyer> buyer;//����˿͵���Ϣ
	vector<SaleRecords> saleRecords;//�������Ѽ�¼
	
public:
	GiftManage();//���캯����ȡ�ļ�����
	~GiftManage();//�������������ݴ����ļ��У�����ճ��򴢴�

	void save();//����Ϣ�����ļ���

	int getGiftSize();//��ȡ��Ʒ�ļ�����
	void GiftInit();//��ȡ�����ļ�����

	int getBuyerSize();//��ȡ�˿��ļ�����
	void BuyerInit();//��ȡ�˿��ļ�����

	int getSaleRecordsSize();//��ȡ���ۼ�¼����
	void SaleRecordsInit();//��ȡ���ۼ�¼����

	int checkGift(string number);//ͨ����Ʒ��Ų�ѯ��Ʒ�治����
	int checkBuyer(string phone);//ͨ���ֻ��Ų�ѯ�˿ʹ治����

	void menu();//��ʾ�˵�
	void showGift();//��ʾ������Ʒ��Ϣ
	void showBuyer();//��ʾ���й˿���Ϣ
	void showSaleRecords();//��ʾ�������ۼ�¼
	void addGift();//�����Ʒ��ֿ�
	int addBuyer(string name, string phone, double amount);//��ӹ˿�
	void addSaleRecords(string name, string phone, string giftName, string number, 
		double cost, double price, double actualPrice, int mount);//������ۼ�¼
	void sellGift();//����Ʒ�۳�
	void updateGift();//�޸���Ʒ����Ϣ
	void updateBuyer();//�޸Ĺ˿͵���Ϣ
	void queryGift();//��ѯ��Ʒ��Ϣ
	void queryBuyer();//��ѯ�˿���Ϣ
	void querySaleRecords();//��ѯ���ۼ�¼
	void totalProfit();//����������
};