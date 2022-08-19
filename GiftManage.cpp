#include "GiftManage.h"
#include <iomanip>
#include <string>
#include <cstring>
#include <stdio.h>

GiftManage::GiftManage()
{
	ifstream fin(GIFTFILE, ios::in);//����Ʒ��Ϣ�ļ�

	if (!fin.is_open())//�ж��ļ��Ƿ����
	{
		cout << "��Ʒ��Ϣ�ļ�������" << endl;
	}
	else
	{
		char ch;
		fin >> ch;//���뵥���ַ�

		if (!fin.eof())//�ж��ļ��Ƿ�Ϊ��
		{
			int GiftSize = getGiftSize();//��ȡ���ݵ�����
			gift = vector<Gift>(GiftSize);//��ʼ��vector<Gift>
			GiftInit();//��ȡ�ļ�����
		}
		else
		{
			cout << "��Ʒ��Ϣ�ļ�Ϊ��" << endl;
		}
	}
	
	fin.close();//�ر��ļ�
	
	/*******************************************/
	fin.open(BUYERFILE, ios::in);//�򿪹˿���Ϣ�ļ�

	if (!fin.is_open())//�ж��ļ��Ƿ����
	{
		cout << "�˿���Ϣ�ļ�������" << endl;
	}
	else
	{
		char ch;
		fin >> ch;

		if (!fin.eof())//�ж��ļ��Ƿ�Ϊ��
		{
			int BuyerSize = getBuyerSize();//��ȡ����
			buyer = vector<Buyer>(BuyerSize);//��ʼ���˿�
			BuyerInit();//��ȡ�˿��ļ�
		}
		else
		{
			cout << "�˿��ļ�Ϊ��" << endl;
		}
	}
	
	fin.close();//�ر��ļ�

	/*******************************************/
	fin.open(SALERECORDSFILE, ios::in);//�򿪹˿����ۼ�¼�ļ�

	if (!fin.is_open())//�ж��ļ��Ƿ����
	{
		cout << "���ۼ�¼�ļ�������" << endl;
	}
	else
	{
		char ch;
		fin >> ch;
		if (!fin.eof())//�ж��ļ��Ƿ�Ϊ��
		{
			int saleRecordsSize = getSaleRecordsSize();//��ȡ����
			saleRecords = vector<SaleRecords>(saleRecordsSize);//��ʼ������
			SaleRecordsInit();//��ȡ���ۼ�¼������
		}
		else
		{
			cout << "���ۼ�¼�ļ�Ϊ��" << endl;
		}
	}

	fin.close();//�ر��ļ�
}

GiftManage::~GiftManage()
{
	save();//�����ݴ����ļ��У�ʵ�ֿɳ־û�
	gift.clear();//�����Ʒ��Ϣ
	buyer.clear();//��չ˿���Ϣ
	saleRecords.clear();//������ۼ�¼
}

void GiftManage::save()
{
	if (gift.size())//������Ȳ�Ϊ0���������ݲű���
	{
		ofstream fout(GIFTFILE, ios::out);//����Ʒ�ļ��������

		fout.setf(ios::left);//���������15���ַ����ҿ���
		//�����ʾ��Ϣ�������û��鿴
		fout << setw(15) << "��Ʒ���" << setw(15) << "��Ʒ����" << setw(15) <<
			"���۳ɱ�" << setw(15) << "�����۸�" << setw(15) << "��Ʒ����" << endl;

		//���������Ʒ����Ϣ����Ʒ��Ϣ������Ƹ����ֵ�������
		for (int i = 0; i < gift.size(); i++)
			fout << gift[i] << endl;
		
		//ȡ�����������趨
		cout.unsetf(ios::left);
		fout.close();//�ر��ļ�
	}

	/*******************************************/

	if (buyer.size())//������Ȳ�Ϊ0���������ݲű���
	{
		ofstream fout(BUYERFILE, ios::out); ///����Ʒ�˿ͽ������

		fout.setf(ios::left);
		//����˿͵���Ϣ��ʾ������鿴
		fout << setw(15) << "����" << setw(15) << "�绰����" <<
			setw(15) << "�ǻ�Ա��" << setw(15) << "���ѽ��" << endl;

		//����û�����Ϣ���˿���Ϣ���������ֵ�������
		for (int i = 0; i < buyer.size(); i++)
			fout << buyer[i] << endl;
		
		//ȡ�����������趨
		cout.unsetf(ios::left);
		fout.close();//�ر��ļ�
	}

	/*******************************************/

	if (saleRecords.size())//������Ȳ�Ϊ0���������ݲű���
	{
		ofstream fout(SALERECORDSFILE, ios::out); // �����ۼ�¼�������

		fout.setf(ios::left);
		//������ۼ�¼����ʾ��Ϣ������鿴
		fout << setw(15) << "����" << setw(15) << "�绰����" << setw(15) << "��Ʒ����"
			<< setw(15) << "��Ʒ���" << setw(15) << "��Ʒ�ɱ�" << setw(15) << "��Ʒ�ۼ�" 
			<< setw(15) << "ʵ���ۼ�" << setw(15) << "��������" << setw(15) << "��������" << endl;

		//������ۼ�¼
		for (int i = 0; i < saleRecords.size(); i++)
			fout << saleRecords[i] << endl;
		
		//ȡ�����������趨
		cout.unsetf(ios::left);
		fout.close();
	}
}

int GiftManage::getGiftSize()
{//��ȡ��Ʒ��Ϣ�ĳ���
	ifstream fin(GIFTFILE, ios::in);//����Ʒ�ļ�

	string s;
	getline(fin, s);//����һ�е���ʾ��Ϣ�Ե�
	int Size = 0;//�ļ������ݵĳ���
	while (getline(fin, s)) Size++;//һ��һ�еĶ�ȡ��¼����¼����

	fin.close();//�ر��ļ�
	return Size;
}

void GiftManage::GiftInit()
{//��ʼ����Ʒ��Ϣ�����ļ�����Ϣ���������
	ifstream fin(GIFTFILE, ios::in);//����Ʒ�ļ�

	string number;//��Ʒ���
	string name;//��Ʒ����
	double cost;//���۳ɱ�
	double price;//�����۸�
	int amount;//��Ʒ����
	getline(fin, number);//�̵���һ�е���Ϣ
	for (int i = 0; i < gift.size(); i++)
	{//���ļ����ݰ�������
		fin >> number >> name >> cost >> price >> amount;
		gift[i] = Gift(number, name, cost, price, amount);
	}

	fin.close();//�ر��ļ�
}

int GiftManage::getBuyerSize()
{//��ȡ�˿͵��ļ�����
	ifstream fin(BUYERFILE, ios::in);//�򿪹˿��ļ�
	
	string s;
	getline(fin, s);//����һ����ʾ��Ϣ�Ե�
	int Size = 0;
	while (getline(fin, s)) Size++;//һ��һ�еĶ�ȡ����ȡ����

	fin.close();//�ر��ļ�
	return Size;
}

void GiftManage::BuyerInit()
{//��ʼ���˿���Ϣ�����˿��ļ����������
	ifstream fin(BUYERFILE, ios::in);

	string name;//���ߵ�����
	string phone;//���ߵĵ绰����
	string isMember;//�Ƿ��ǻ�Ա
	double money;//���ѽ��,���ѽ��ﵽ200��Ϊ��Ա

	getline(fin, name);//�Ե���һ����ʾ��Ϣ
	for (int i = 0; i < buyer.size(); i++)
	{//���˿͵���Ϣһ��һ�����
		fin >> name >> phone >> isMember >> money;
		buyer[i] = Buyer(name, phone, isMember == "��", money);
	}
	fin.close();//�ļ��ر�
}

int GiftManage::getSaleRecordsSize()
{//��ȡ���ۼ�¼�ĳ���
	ifstream fin(SALERECORDSFILE, ios::in);//�����ۼ�¼���ļ�

	string s;//�Ե���һ������
	getline(fin, s);
	int Size = 0;
	while (getline(fin, s)) Size++;//��¼����

	fin.close();//�ر��ļ� 
	return Size;
}

void GiftManage::SaleRecordsInit()
{//��ʼ�����ۼ�¼
	ifstream fin(SALERECORDSFILE, ios::in);//�����ۼ�¼�ļ�

	string name;//����
	string phone;//�绰����
	string giftName;//��Ʒ����
	string number;//��Ʒ���
	double cost;//��Ʒ�ɱ�
	double price;//��Ʒ�ۼ�
	double actualPrice;//ʵ���ۼ�
	int amount;//����
	int year = 0, month = 0, day = 0;//����������

	getline(fin, name);//�Ե���һ����ʾ��Ϣ
	for (int i = 0; i < saleRecords.size(); i++)
	{//���ļ���������ݰ�������
		fin >> name >> phone >> giftName >> number >> cost >> price >> actualPrice >> amount;
		string s;
		fin >> s;
		//�����Ǽ��������յ�
		year = 0, month = 0, day = 0;
		for (int j = 0; j < 4; j++) year = year * 10 + s[j] - '0';//������
		for (int j = 5; j < 7; j++) month = month * 10 + s[j] - '0';//������
		for (int j = 8; j < 10; j++) day = day * 10 + s[j] - '0';//������
		saleRecords[i] = SaleRecords(name, phone, giftName, number, cost, price, actualPrice, amount, Date(year, month, day));
	}
	fin.close();//�ر��ļ�
}

//ͨ����Ʒ��Ų�����Ʒ�治����
int GiftManage::checkGift(string number)
{//��ѯ��û����Ʒ�����ڷ���λ�ã������ڷ���-1
	for (int i = 0; i < gift.size(); i++)
		if (gift[i].getNumber() == number)
			return i;//����λ��
		else if (gift[i].getNumber() > number)
			return -1;//��Ϊ��Ʒ�ļ�������Ʒ�������
					  //���Ա�Ŵ�����Ҫ��ѯ�ģ��Ϳ���ֱ�ӷ���û����
	return -1;
}

//ͨ���ֻ��Ų�ѯ�˿�
int GiftManage::checkBuyer(string phone)
{//��ѯ�˿ʹ治���ڣ����ڷ���λ�ã������ڷ���-1
	for (int i = 0; i < buyer.size(); i++)
		if (buyer[i].getPhone() == phone) 
			return i;
	return -1;
}

void GiftManage::menu()
{
	cout << "************** ��ӭ������Ʒר�������ϵͳ **************" << endl;
	cout << "****************** A.��ʾ������Ʒ��Ϣ ******************" << endl;
	cout << "****************** B.��ʾ���й˿���Ϣ ******************" << endl;
	cout << "****************** C.��ʾ�������ۼ�¼ ******************" << endl;
	cout << "****************** D.�����Ʒ��ֿ�   ******************" << endl;
	cout << "****************** E.����Ʒ�۳�       ******************" << endl;
	cout << "****************** F.�޸���Ʒ����Ϣ   ******************" << endl;
	cout << "****************** G.�޸Ĺ˿͵���Ϣ   ******************" << endl;
	cout << "****************** H.��ѯ��Ʒ��Ϣ     ******************" << endl;
	cout << "****************** I.��ѯ�˿���Ϣ     ******************" << endl;
	cout << "****************** J.��ѯ���ۼ�¼     ******************" << endl;
	cout << "****************** K.����������       ******************" << endl;
	cout << "****************** L.�˳���Ʒר�������ϵͳ ************" << endl;
}

void GiftManage::showGift()//��ʾ������Ʒ��Ϣ
{
	if (gift.size() == 0)
	{
		cout << "��Ʒ��ϢΪ��" << endl;
		return;
	}
	cout.setf(ios::left);
	//�����Ʒ��ʾ��Ϣ
	cout << setw(15) << "��Ʒ���" << setw(15) << "��Ʒ����" << setw(15) <<
		"���۳ɱ�" << setw(15) << "�����۸�" << setw(15) << "��Ʒ����" << endl;
	for (int i = 0; i < gift.size(); i++)
		cout << gift[i] << endl;
	cout.unsetf(ios::left);
}

void GiftManage::showBuyer()//��ʾ���й˿���Ϣ
{
	if (buyer.size() == 0)
	{
		cout << "�˿���ϢΪ��" << endl;
		return;
	}
	//����˿���ʾ��Ϣ
	cout.setf(ios::left);
	cout << setw(15) << "����" << setw(15) << "�绰����" <<
		setw(15) << "�ǻ�Ա��" << setw(15) << "���ѽ��" << endl;
	for (int i = 0; i < buyer.size(); i++)
		cout << buyer[i] << endl;
	cout.unsetf(ios::left);
}

void GiftManage::showSaleRecords()//��ʾ�������ۼ�¼
{
	if (saleRecords.size() == 0)
	{
		cout << "���ۼ�¼Ϊ��" << endl;
		return;
	}
	//������ۼ�¼����ʾ��Ϣ
	cout.setf(ios::left);
	cout << setw(15) << "����" << setw(15) << "�绰����" << setw(15) << "��Ʒ����"
		<< setw(15) << "��Ʒ���" << setw(15) << "��Ʒ�ۼ�" << setw(15) << "ʵ���ۼ�"
		<< setw(15) << "��������" << setw(15) << "��������" << endl;
	for (int i = 0; i < saleRecords.size(); i++)
		cout << saleRecords[i] << endl;
	cout.unsetf(ios::left);
}

//������Ʒ
void GiftManage::addGift()//�����Ʒ��ֿ�
{
	string number;//��Ʒ���
	int amount;//��Ʒ����
	cout << "��������Ҫ��ӵ���Ʒ����Ʒ��ţ�" << endl;
	cin >> number;

	int idx = checkGift(number);//��ȡ��Ʒ��λ��
	if (~idx)//�����Ʒ�Ѿ�����
	{//�Ϳ���ֱ�������������������
		cout << "��������Ҫ��ӵ���Ʒ�Ĳ�Ʒ������" << endl;
		cin >> amount;
		gift[idx].setAmount(gift[idx].getAmount() + amount);
		return;
	}

	string name;//��Ʒ����
	double cost;//���۳ɱ�
	double price;//�����۸�

	cout << "��������Ҫ��ӵ���Ʒ����Ʒ���ƣ�" << endl;
	cin >> name;

	cout << "��������Ҫ��ӵ���Ʒ�Ľ��ۣ�" << endl;
	cin >> cost;

	cout << "��������Ҫ��ӵ���Ʒ���ۼۣ�" << endl;
	cin >> price;

	cout << "��������Ҫ��ӵ���Ʒ�Ĳ�Ʒ������" << endl;
	cin >> amount;

	//�����µ���Ʒ
	gift.push_back(Gift(number, name, cost, price, amount));
	//���¼������Ʒ�ŵ����ʵ�λ��
	for (int i = gift.size() - 1; i >= 1; i--)//gift���ձ���ֵ�������
		if (gift[i].getNumber() < gift[i - 1].getNumber())
			swap(gift[i], gift[i - 1]);
}

//�����˿�
int GiftManage::addBuyer(string name, string phone, double money)
{
	buyer.push_back(Buyer(name, phone));//�����µĹ˿�
	buyer[buyer.size() - 1].setMoney(money);//�޸Ĺ˿͵�����
	//���������ֵ�������
	for (int i = buyer.size() - 1; i >= 1; i--)
		if (buyer[i].getName() < buyer[i - 1].getName())
			swap(buyer[i], buyer[i - 1]);
		else return i;//���ؼ���Ĺ˿͵�λ��
	return 0;
}

//�������ۼ�¼
void GiftManage::addSaleRecords(string name, string phone, string giftName, string number,
	double cost, double price, double actualPrice, int amount)//������ۼ�¼
{
	int year = 0, month = 0, day = 0;
	//��ȡ����ʵʱʱ��
	time_t now;
	time(&now);
	tm* t = new tm;
	localtime_s(t, &now);
	year = 1900 + t-> tm_year, month = 1 + t->tm_mon, day = t->tm_mday;
	//�������ۼ�¼
	saleRecords.push_back(SaleRecords(name, phone, giftName, number, cost, price, actualPrice, amount, Date(year, month, day)));
}

void GiftManage::sellGift()//����Ʒ�۳�
{
	cout << "������Ҫ�۳�����Ʒ�ı�ţ�" << endl;
	string number;
	cin >> number;

	int idx = checkGift(number);//�����Ʒ��λ��
	if (idx == -1)
	{
		cout << "��Ʒ������" << endl;
	}
	else
	{
		cout << "������Ҫ�۳��Ĳ�Ʒ��������" << endl;
		int amount;
		cin >> amount;
		if (gift[idx].getAmount() < amount)
		{
			cout << "����ʧ�ܣ���Ʒ��治��" << endl;
			cout << "���������" << gift[idx].getAmount() << endl;
		}
		else
		{
			//ͬ���޸Ĺ˿���Ϣ�����ۼ�¼
			cout << "�����빺����Ʒ�Ĺ˿���Ϣ" << endl;
			string name;
			string phone;
			cout << "�����빺����Ʒ�Ĺ˿�����" << endl;
			cin >> name;

			cout << "�����빺����Ʒ�Ĺ˿��ֻ�����" << endl;
			cin >> phone;

			int buyerIdx = checkBuyer(phone);//��ù˿͵�λ��

			/*********���ӹ˿���Ϣ*********/
			double discount = 1;//����Ƿ��ۿ�
			if (~buyerIdx)//����˿��Ѿ�����
			{//ֱ���޸ļ۸񼴿�
				if (buyer[buyerIdx].getIsMember())
				{//��Ա�����
					discount = 0.8;//��Ա����
					//�޸Ĺ˿����ѽ��
					buyer[buyerIdx].setMoney(buyer[buyerIdx].getMoney() + amount * 0.8 * gift[idx].getPrice());
				}
				else
				{//�޸Ĺ˿����ѽ��
					buyer[buyerIdx].setMoney(buyer[buyerIdx].getMoney() + amount * gift[idx].getPrice());
				}
			}
			else
			{//�˿Ͳ����ڵĻ��������µĹ˿�
				buyerIdx = addBuyer(name, phone, amount * gift[idx].getPrice());
			}
			/*********�������ۼ�¼*********/
			//�����µ����ۼ�¼�����ѹ�֮��Ż��Ϊ��Ա
			addSaleRecords(name, phone, gift[idx].getName(), number, gift[idx].getCost(), gift[idx].getPrice(), 
				gift[idx].getPrice() * discount, amount);
			//��������
			gift[idx].setAmount(gift[idx].getAmount() - amount);
			cout << "���۳ɹ�" << endl;
		}
	}
}

void GiftManage::updateGift()//�޸���Ʒ����Ϣ
{//�޸���Ʒ��Ϣ��ʱ�򣬼�¼����ͬ���޸ģ���Ϊ��Ʒ�Ѿ�����ȥ���ۼ۵������Ϣ�����޸�
	string number;//��Ʒ���
	cout << "��������Ҫ�޸ĵ���Ʒ���" << endl;
	cin >> number;

	int idx = checkGift(number);//������Ʒλ��
	if (idx == -1)
	{
		cout << "��Ʒ������" << endl;
		return;
	}

	cout << "��������Ҫ�޸ĵ���Ʒ������Ϣ" << endl;
	string name;//��Ʒ����
	double cost;//���۳ɱ�
	double price;//�����۸�
	int amount;//��Ʒ����

	cout << "��������Ҫ�޸ĵ���Ʒ���µı��" << endl;
	cin >> number;

	cout << "��������Ҫ�޸ĵ���Ʒ���µ����ƣ�" << endl;
	cin >> name;

	cout << "��������Ҫ�޸ĵ���Ʒ���µĽ��ۣ�" << endl;
	cin >> cost;

	cout << "��������Ҫ�޸ĵ���Ʒ���µ��ۼۣ�" << endl;
	cin >> price;


	//������ж��پ��Ƕ���
	amount = gift[idx].getAmount();

	string choice;
	cout << "��Ҫ�޸Ŀ������(YES/NO)" << endl;
	cin >> choice;

	if(choice == "YES")
	{
		cout << "��������Ҫ�޸ĵ���Ʒ���µĿ������" << endl;
		cin >> amount;
	}

	gift[idx] = Gift(number, name, cost, price, amount);
	cout << "�޸ĳɹ�" << endl;
}

void GiftManage::updateBuyer()//�޸Ĺ˿͵���Ϣ
{//�޸Ĺ˿���Ϣ��ʱ����Ҫͬ������¼ͬ���޸�
	string phone;//���ߵĵ绰����

	cout << "��������Ҫ�޸ĵĹ˿͵ĵ绰����" << endl;
	cin >> phone;

	int idx = checkBuyer(phone);//���ҹ˿͵�λ��
	if (idx == -1)
	{
		cout << "�˹˿Ͳ�����" << endl;
		return;
	}

	string lastPhone = phone;//��¼һ���޸�ǰ���ֻ���

	cout << "��������Ҫ�޸ĵĹ˿͵��µ���Ϣ" << endl;
	string name;//���ߵ�����
	 
	cout << "��������Ҫ�޸ĵĹ˿͵��µ�����" << endl;
	cin >> name;

	cout << "��������Ҫ�޸ĵĹ˿͵��µ��ֻ���" << endl;
	cin >> phone;

	buyer[idx].setName(name);
	buyer[idx].setPhone(phone);

	//ͬ���޸����ۼ�¼��Ϣ
	for (int i = 0; i < saleRecords.size(); i++)
	{
		if (saleRecords[i].getPhone() == lastPhone)
		{
			saleRecords[i].setName(name);
			saleRecords[i].setPhone(phone);
		}
	}
	
	cout << "�޸ĳɹ�" << endl;
}

void GiftManage::queryGift()//��ѯ��Ʒ��Ϣ
{
	cout << "�����������Ʒ�ķ�ʽ" << endl;
	cout << "1.ͨ����Ʒ��Ų���" << endl;
	cout << "2.ͨ����Ʒ���Ʋ���" << endl;

	int choice;
	cin >> choice;
	int num = 0;//���ڼ�¼�Ƿ�鵽��Ʒ��Ϣ��
	if (choice == 1)
	{
		cout << "�����������ѯ����Ʒ���" << endl;
		string number;
		cin >> number;

		cout.setf(ios::left);
		cout << setw(15) << "��Ʒ���" << setw(15) << "��Ʒ����" << setw(15) <<
			"���۳ɱ�" << setw(15) << "�����۸�" << setw(15) << "��Ʒ����" << endl;
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
		cout << "��������Ҫ��ѯ����Ʒ����" << endl;
		string name;
		cin >> name;

		cout.setf(ios::left);
		cout << setw(15) << "��Ʒ���" << setw(15) << "��Ʒ����" << setw(15) <<
			"���۳ɱ�" << setw(15) << "�����۸�" << setw(15) << "��Ʒ����" << endl;
		
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
		cout << "�����ҵ���Ʒ������" << endl;
	}
}

void GiftManage::queryBuyer()//��ѯ�˿���Ϣ
{
	cout << "��������ҹ˿͵ķ�ʽ" << endl;
	cout << "1.ͨ����������" << endl;
	cout << "2.ͨ���ֻ��Ų���" << endl;

	int choice, num = 0;//num���ڱ���Ƿ�鵽�˿���Ϣ��
	cin >> choice;
	if (choice == 1)
	{
		cout << "��������Ҫ���ҵĹ˿�����" << endl;
		string name;
		cin >> name;

		cout.setf(ios::left);
		cout << setw(15) << "����" << setw(15) << "�绰����" <<
			setw(15) << "�ǻ�Ա��" << setw(15) << "���ѽ��" << endl;
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
		cout << "����������Ҫ���ҵĹ˿͵��ֻ���" << endl;
		string phone;
		cin >> phone;

		cout.setf(ios::left);
		cout << setw(15) << "����" << setw(15) << "�绰����" <<
			setw(15) << "�ǻ�Ա��" << setw(15) << "���ѽ��" << endl;
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
		cout << "��Ҫ���ҵĹ˿Ͳ�����" << endl;
	}
}

void GiftManage::querySaleRecords()//��ѯ���ۼ�¼
{
	cout << "������������ۼ�¼�ķ�ʽ" << endl;
	cout << "1.ͨ���˿���������" << endl;
	cout << "2.ͨ���˿��ֻ��Ų���" << endl;
	cout << "3.ͨ����Ʒ��Ų���" << endl;
	cout << "4.ͨ����Ʒ���Ʋ���" << endl;

	string name;
	string phone;
	string number;
	string giftName;
	int num = 0;//���ڼ�¼�Ƿ�鵽���ۼ�¼��

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "��������Ҫ��ѯ�Ĺ˿͵�����" << endl;
		cin >> name;
		cout.setf(ios::left);
		cout << setw(15) << "����" << setw(15) << "�绰����" << setw(15) << "��Ʒ����"
			<< setw(15) << "��Ʒ���" << setw(15) << "��Ʒ�ɱ�" << setw(15) << "��Ʒ�ۼ�" 
			<< setw(15) << "ʵ���ۼ�" << setw(15) << "��������" << setw(15) << "��������" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getName() == name)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	case 2:
		cout << "��������Ҫ��ѯ�Ĺ˿͵��ֻ�����" << endl;
		cin >> phone;
		cout.setf(ios::left);
		cout << setw(15) << "����" << setw(15) << "�绰����" << setw(15) << "��Ʒ����"
			<< setw(15) << "��Ʒ���" << setw(15) << "��Ʒ�ɱ�" << setw(15) << "��Ʒ�ۼ�"
			<< setw(15) << "ʵ���ۼ�" << setw(15) << "��������" << setw(15) << "��������" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getPhone() == phone)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	case 3:
		cout << "��������Ҫ��ѯ����Ʒ���" << endl;
		cin >> number;
		cout.setf(ios::left);
		cout << setw(15) << "����" << setw(15) << "�绰����" << setw(15) << "��Ʒ����"
			<< setw(15) << "��Ʒ���" << setw(15) << "��Ʒ�ɱ�" << setw(15) << "��Ʒ�ۼ�"
			<< setw(15) << "ʵ���ۼ�" << setw(15) << "��������" << setw(15) << "��������" << endl;
		for (int i = 0; i < saleRecords.size(); i++)
			if (saleRecords[i].getNumber() == number)
			{
				num++;
				cout << saleRecords[i] << endl;
			}
		cout.unsetf(ios::left);
		break;
	case 4:
		cout << "��������Ҫ��ѯ����Ʒ����" << endl;
		cin >> giftName;
		cout.setf(ios::left);
		cout << setw(15) << "����" << setw(15) << "�绰����" << setw(15) << "��Ʒ����"
			<< setw(15) << "��Ʒ���" << setw(15) << "��Ʒ�ɱ�" << setw(15) << "��Ʒ�ۼ�"
			<< setw(15) << "ʵ���ۼ�" << setw(15) << "��������" << setw(15) << "��������" << endl;
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
		cout << "���ۼ�¼������" << endl;
	}
}

void GiftManage::totalProfit()
{
	double total = 0;

	for (int i = 0; i < saleRecords.size(); i++)
	{
		total += (saleRecords[i].getActualPrice() - saleRecords[i].getCost()) * saleRecords[i].getAmount();
	}

	//�����λС��
	cout << "������Ϊ��" << setiosflags(ios::fixed) << setprecision(2) << total << endl;
}