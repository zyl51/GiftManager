#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int year;//���
	int month;//�·�
	int day;//����

public:
	Date();
	Date(int year, int month, int day);//���캯��
	~Date();

	//�������ڵ����
	friend ostream& operator << (ostream& os, const Date& date);
};