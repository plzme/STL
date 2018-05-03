//-----------------------------------------------------------
//
//
//qsort - �ڷ����� ������� �����ϴ� �Լ�
//		qsort�� �޸𸮰� �پ��ִ� ��쿡�� �������ش�.
//		[], array, vector, deque, ..... 
// ���� �������� ���� ��������
// ������ �ڷ�� �ٸ� ���� ������ ���̴�.
//
// ���� ���̸� ����µ� rand() �Լ��� �������� - (C++�� �� ���� ����� �ִ�)
// 1. ������ ���� ����� �ִ� �� ���� ������ �ִ�.
// 2. Ȯ�� ������ ���� �������� ���� �� �ִ�.

//-----------------------------------------------------------

/*
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <random>
#include "save.h"
using namespace std;

class Dog {
	string name;
	int age;
public:
	Dog() : name(), age() {	}					//== d.init()
	Dog(const char* n, int a) : name(n), age(a) {}

	~Dog() {
	}
	string getName() const { return name; }					//const�� ���̴� ������ ������ ����(?) - ������ ������ ������� �ʵ��� �Ѵ�
	int getAge() const { return age; }

	void setName(char* n) { name = n; }
	void setAge(int a) { age = a; }

	friend ostream& operator<<(ostream& os, const Dog& d);
};


ostream& operator<< (ostream& os, const Dog& d) {
	os << d.getAge() << "��";
	return os;
}


int compare(const void*, const void*);
int f(const void*, const void*);

#define dog_size 10000000
void main() {

	//int a[10] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};

	//������ ������������ ����
	//C�� ��� : qsort(a, 10, sizeof(int), f);

	//C++�� ��� : ���ٿ� �� ���� �ִ´�.(�Լ����� !) - ���� �Լ�
	//qsort(a, 10, sizeof(int), [](const void* a, const void* b) { return *static_cast<const int*>(a) - *static_cast<const int*>(b); });

	//for (int d : a)
	//cout << d << " ";
	//cout << endl;
	//Dog dogs[3]{
	//{ "��", 3 },{ "�����", 2 },{ "��ѱ�", 6 }
	//};


	//���� ���� ������������ ����,
	//c �Լ��� qsort()�� ��� = generic �Լ���� ����
	//qsort(���, �����, �Ѱ��� ũ���, ���(���ٻ��))
	qsort(dogs, 3, sizeof(Dog), [](const void* a, const void* b) {
	return static_cast<const Dog*>(a)->getAge() - static_cast<const Dog*>(b)->getAge();
	});

	for (Dog d : dogs)
	cout << d << endl;


	//���� �̸� ������������ ����
	qsort(dogs, 3, sizeof(Dog), [](const void* a, const void* b) {
	if (static_cast<const Dog*>(a)->getName() < static_cast<const Dog*>(b)->getName()) return -1;
	else if (static_cast<const Dog*>(a)->getName() == static_cast<const Dog*>(b)->getName()) return 0;
	else return 1;
	});									//string �ڷ����� - ���� ������ ���� ������, if �� <, > �� �̿��ؼ� ���� ����ϰ� �� �� �ִ�.

	for (Dog& d : dogs)
	cout << d << endl;

	//�� 100000������ �� ���ư��� ������ => ���������� �޸� �Ѱ�, ���������� �ٲٸ� �� ���ư���.

	//�� 1000�� ������ �������� �Ҵ��Ͽ� ���̿����������� �����϶�
	//�տ��� 100���� ����ؼ� ���ĵȰ���� Ȯ��

	Dog *dogs = new Dog[dog_size];

	default_random_engine dre;
	uniform_int_distribution<> uid;

	for (int i = 0; i < dog_size; ++i)
		dogs[i].setAge(uid(dre));
	
	qsort(dogs, 10000000, sizeof(Dog), [](const void* a, const void* b) {
	return static_cast<const Dog*>(a)->getAge() - static_cast<const Dog*>(b)->getAge();
	});
	
	for (int i = 0; i < 100; ++i)
		cout << dogs[i] << endl;

	delete[] dogs;
}

int compare(const void *A, const void  *B) {							//void ������ : �޴� ���ڰ� �������� �� �� ����.

	Dog* ptrA = (Dog*)A;

	Dog* ptrB = (Dog*)B;

	if (ptrA->getAge() < ptrB->getAge()) return -1;

	else if (ptrA->getAge() == ptrB->getAge()) return 0;

	else return 1;

}


int f(const void* A, const void* B) {

	return *(int*)A - *(int*)B;					//�������� ����ȭ 
}




//*.exe�� ���� ��Ű�� ����, ���������� �޸�(stack,1mb ����)�� �÷�����.
//���� ������ Dog 10�������� �ҷ��� ��� stack�� �뷮�� 1mb�� ���� �� ������
//���� ������ �ҷ��� ��� �� 21���� Data��ŭ �ҷ��� �� �ִ�.


*/

//=========================================================================================

// ����
// ���Ͽ� �ڷḦ �а� �Ἥ �����غ���
// ������ �� �� text mode�� binary mode�� ������ �� �ִ�. - �������� �˾Ƽ� ��������


// ���� 1000���� ���Ͽ� ����Ǿ� �ִ�.
// �о�ͼ� ���� �� ����϶�.

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

//void main() {

	/*default_random_engine dre;
	uniform_int_distribution<> uid(0, 10000);
	//dre.seed(2014184028);

	int n[1000];
	for (int i = 0; i < 1000; ++i)
		n[i] = uid(dre);
	ofstream out("���� 1000��.txt",ios::binary);

	// �޸��� ������ �״�� ����ϴ� ���� �´�
	out.write((const char* )n, 1000 * sizeof(int));*/

/*	ifstream in("���� 1000��.txt", ios::binary);

	int n[1000];

	in.read((char*)n, sizeof(int) * 1000);

	sort(begin(n), end(n), [](int a, int b) {
		return a > b;
	});

	for (int d : n)
		cout << d << "\t";
	cout << endl;*/
//}

// main()�� �ִ� source ������ �տ��� 200���ڸ� �о
// ���ĺ� ������������ ���� �� ȭ�鿡 ����϶�.

void main() {
	ifstream in("�ҽ�.cpp",ios::binary);
	if (!in) {
		cout << "������ ���� �����ϴ�" << endl;
		return;
	}

	char d[200];
	in.read(d, 200);

	qsort(d, 200, 1, [](const void* a, const void* b){
	return *(char*)a - *(char*)b;
	});


	for (int i = 0; i < 200; ++i)
		cout << d[i];
}


