//----------------------------------------------------------------
//STL 2018, 1�б�			3�� 8��		(1���� 2��)
//
//template - ������� ����?
//class ���� - class�� ����ϴ� ������?
//STL�� class�� ��� ����ϳ�?
//
//void change(int&, int&);		
//void change(string&, string&);
//void change(News&, News&);
//
//change �Լ��� ����� ������ �ϳ���?
// --> C++�� �ڷ����� �����ϴ�
// �Լ��� ����� ������ �ڷ����� �ٸ���� �Ź� ���α׷��ؾ��ϴ�?
//----------------------------------------------------------------
#include<string>
#include "save.h"

class Dog {
	string name;
	int age;
public:
	Dog() : name(), age() {};
	Dog(const char* n, int a) : name(n), age(a) {};
	
	string getName() const { return name; }					//const�� ���̴� ������ ������ ����(?) - ������ ������ ������� �ʵ��� �Ѵ�
	int getAge() const { return age; }

	friend ostream& operator<<(ostream& os, const Dog& d);
};


ostream& operator<< (ostream& os, const Dog& dog) {
	os << dog.getName() << " " << dog.getAge() << "��";
	return os;
}


template <class T>											//���Ѱ��� �ڷ����� ��� ���� �� �ֵ��� template�� �̿��� �Լ� ����
void change(T&, T&);

void main() {

	{
		//���� - ���� �� �ڷ��� ���� ��ȯ�ǵ��� change�� �����ϰ� �����϶�
		int a = 10, b = 20;

		change(a, b);

		cout << a << ", " << b << endl;
	}

	{
		//���� - ���� �� �ڷ��� ���� ��ȯ�ǵ��� change�� �����ϰ� �����϶�
		string a = "world!!", b = "Hello";

		change(a, b);

		cout << a << ", " << b << endl;
	}

	{
		//���� - ���� �� �ڷ��� ���� ��ȯ�ǵ��� change�� �����ϰ� �����϶�
		Dog a{"������", 4}, b{"�����", 7};

		change(a, b);

		cout << a << endl;

		cout << b << endl;
	}

	save();
}
template <class T>											//���Ѱ��� �ڷ����� ��� ���� �� �ֵ��� template�� �̿��� �Լ� ����
void change(T& a, T& b) {
	T t{ a };
	a = b;
	b = t;
}

//����
/*
void main() {
	Dog dog[3]{
		{"��", 3}, {"�����", 2}, {"��ѱ�", 6}
	};

	//���� ���� ������������ ����,
	//c �Լ��� qsort()�� ��� = generic �Լ���� ����
	//qsort(���, �����, �Ѱ��� ũ���, ���)
	qsort(dogs, 3, sizeof(Dog), ��� ? ? );
}*/