//----------------------------------------------------------------
//STL 2018, 1학기			3월 8일		(1주차 2일)
//
//template - 만들어진 이유?
//class 복습 - class를 사용하는 이유는?
//STL은 class를 어떻게 사용하나?
//
//void change(int&, int&);		
//void change(string&, string&);
//void change(News&, News&);
//
//change 함수를 몇개까지 만들어야 하나요?
// --> C++의 자료형은 무한하다
// 함수의 기능은 같은데 자료형만 다른경우 매번 프로그램해야하니?
//----------------------------------------------------------------
#include<string>
#include "save.h"

class Dog {
	string name;
	int age;
public:
	Dog() : name(), age() {};
	Dog(const char* n, int a) : name(n), age(a) {};
	
	string getName() const { return name; }					//const를 붙이는 이유는 일종의 보장(?) - 엉뚱한 변수를 출력하지 않도록 한다
	int getAge() const { return age; }

	friend ostream& operator<<(ostream& os, const Dog& d);
};


ostream& operator<< (ostream& os, const Dog& dog) {
	os << dog.getName() << " " << dog.getAge() << "살";
	return os;
}


template <class T>											//무한개의 자료형을 모두 받을 수 있도록 template를 이용해 함수 선언
void change(T&, T&);

void main() {

	{
		//문제 - 다음 두 자료의 값이 교환되도록 change를 선언하고 정의하라
		int a = 10, b = 20;

		change(a, b);

		cout << a << ", " << b << endl;
	}

	{
		//문제 - 다음 두 자료의 값이 교환되도록 change를 선언하고 정의하라
		string a = "world!!", b = "Hello";

		change(a, b);

		cout << a << ", " << b << endl;
	}

	{
		//문제 - 다음 두 자료의 값이 교환되도록 change를 선언하고 정의하라
		Dog a{"순실이", 4}, b{"댕댕이", 7};

		change(a, b);

		cout << a << endl;

		cout << b << endl;
	}

	save();
}
template <class T>											//무한개의 자료형을 모두 받을 수 있도록 template를 이용해 함수 선언
void change(T& a, T& b) {
	T t{ a };
	a = b;
	b = t;
}

//숙제
/*
void main() {
	Dog dog[3]{
		{"개", 3}, {"고양이", 2}, {"비둘기", 6}
	};

	//개를 나이 오름차순으로 정렬,
	//c 함수인 qsort()를 사용 = generic 함수라고 본다
	//qsort(어떤걸, 몇개인지, 한개의 크기는, 어떻게)
	qsort(dogs, 3, sizeof(Dog), 어떻게 ? ? );
}*/