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

#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
using namespace std;

class Dog {
	string name;
	int age;
public:
	Dog() : name(), age() { }						//== d.init()
	Dog(const char* n, int a) : name(n), age(a) {};

	string getName() const { return name; }					//const�� ���̴� ������ ������ ����(?) - ������ ������ ������� �ʵ��� �Ѵ�
	int getAge() const { return age; }

	void setAge(int n) {age = n;}

	friend ostream& operator<<(ostream& os, const Dog& d);
};


ostream& operator<< (ostream& os, const Dog& dog) {
	os << dog.getName() << " " << dog.getAge() << "��";
	return os;
}


int compare(const void*, const void*);
int f(const void*, const void*);

Dog dogs[1000000];

void main() {

	/*int a[10] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};		

	//������ ������������ ����
	//C�� ��� : qsort(a, 10, sizeof(int), f);

	//C++�� ��� : ���ٿ� �� ���� �ִ´�.(�Լ����� !) - ���� �Լ�
	qsort(a, 10, sizeof(int), [](const void* a, const void* b) { return *static_cast<const int*>(a) - *static_cast<const int*>(b); });
	
	for (int d : a)
		cout << d << " ";
	cout << endl;*/
	/*Dog dogs[3]{
		{ "��", 3 },{ "�����", 2 },{ "��ѱ�", 6 }
	};


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
		cout << d << endl;*/

	//�� 100000������ �� ���ư��� ������ => ���������� �Ѱ�, ���������� �ٲٸ� �� ���ư���.

	default_random_engine dre;
	uniform_int_distribution<> uid(0, 100);

	for (Dog& d : dogs)
		d.setAge(uid(dre));
	/*
	qsort(dogs, 100000000, sizeof(Dog), [](const void* a, const void* b) {
		return static_cast<const Dog*>(a)->getAge() - static_cast<const Dog*>(b)->getAge();
	});
	*/
	for (Dog& d : dogs)
		cout << d << endl;
}

int compare(const void *A, const void  *B){							//void ������ : �޴� ���ڰ� �������� �� �� ����.

	Dog* ptrA = (Dog*)A;

	Dog* ptrB = (Dog*)B;

	if (ptrA->getAge() < ptrB->getAge()) return -1;

	else if (ptrA->getAge() == ptrB->getAge()) return 0;

	else return 1;

}


int f(const void* A, const void* B) {

	return *(int*)A - *(int*)B;					//�������� ����ȭ 
}