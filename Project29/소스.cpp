#include <iostream>
using namespace std;

int big(int a, int b)
{
	if (a > b) return a;
	else if (a < b) return b;
	else return -1;
}

int big(int a[], int size)  // �Լ� �ߺ�����
{
	int max;
	max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (max < a[i]) max = a[i];
	}

	return max;
}

int sum(int a, int b) // �Լ� �ߺ�����
{
	return a + b;
}

int sum(int a)
{
	int sum = 0;
	for (int i = 0; i <= a; i++)
	{
		sum += i;
	}
	return sum;
}

class MyVector
{
	int* p;
	int size;
public:
	MyVector(int n = 100)
	{
		p = new int[n];
		size = 100;

	}
	~MyVector() { delete []p; }

};

class Person
{
public:
	int money;
	int addMoney(int a) { money += a; }

	static int sharedMoney;
	static int addSharedMoney(int a) { sharedMoney += a; }

	int showMoney() { return money + sharedMoney; }   //  static �Լ��� ��ü ���������� �����ؾ��ϴµ� money�� ���������ʱ⿡ �����߻�

};
int Person::sharedMoney = 10;

class Circle
{
	int radius;
	static int numOfCircle;
public:
	Circle(int r = 1) { radius = r; numOfCircle++; }
	~Circle() { numOfCircle--; }
	
	static int getNum() { return numOfCircle; }
};
int Circle::numOfCircle = 0;

int main()
{
	int a[5] = { 1,9,-2,-5,6 };
	cout << big(2, 3) << endl;
	cout << big(a, 5) << endl;

	cout << sum(3, 5) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;

	MyVector* v1, *v2;
	v1 = new MyVector();
	v2 = new MyVector(10);

	delete v1, v2;

	Person::sharedMoney = 100;  // ��ü �������� static ���� ���ٰ���
	Person han;
	han.money = 100;
	han.sharedMoney = 200;

	Circle* cir = new Circle[10];
	cout << "������ ���� ���� : " << Circle::getNum() << endl;
	delete []cir;
	cout << "������ ���� ���� : " << Circle::getNum() << endl;
	Circle q;
	cout << "������ ���� ���� : " << Circle::getNum() << endl;
	Circle w;
	cout << "������ ���� ���� : " << Circle::getNum() << endl;
}