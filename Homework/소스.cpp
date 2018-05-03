//-----------------------------------------------------------
//
//
//qsort - 자료형에 관계없이 정렬하는 함수
//		qsort는 메모리가 붙어있는 경우에만 정렬해준다.
//		[], array, vector, deque, ..... 
// 개를 여러마리 만들어서 정렬하자
// 정렬할 자료는 다른 곳에 존재할 것이다.
//
// 개의 나이를 만드는데 rand() 함수를 쓰지말자 - (C++에 더 좋은 방법이 있다)
// 1. 랜덤한 수를 만들어 주는 몇 가지 엔진이 있다.
// 2. 확률 분포에 따른 랜덤값을 만들 수 있다.

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

	string getName() const { return name; }					//const를 붙이는 이유는 일종의 보장(?) - 엉뚱한 변수를 출력하지 않도록 한다
	int getAge() const { return age; }

	void setAge(int n) {age = n;}

	friend ostream& operator<<(ostream& os, const Dog& d);
};


ostream& operator<< (ostream& os, const Dog& dog) {
	os << dog.getName() << " " << dog.getAge() << "살";
	return os;
}


int compare(const void*, const void*);
int f(const void*, const void*);

Dog dogs[1000000];

void main() {

	/*int a[10] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};		

	//정수를 오름차순으로 정렬
	//C의 방식 : qsort(a, 10, sizeof(int), f);

	//C++의 방식 : 한줄에 다 때려 넣는다.(함수까지 !) - 람다 함수
	qsort(a, 10, sizeof(int), [](const void* a, const void* b) { return *static_cast<const int*>(a) - *static_cast<const int*>(b); });
	
	for (int d : a)
		cout << d << " ";
	cout << endl;*/
	/*Dog dogs[3]{
		{ "개", 3 },{ "고양이", 2 },{ "비둘기", 6 }
	};


	//개를 나이 오름차순으로 정렬,
	//c 함수인 qsort()를 사용 = generic 함수라고 본다
	//qsort(어떤걸, 몇개인지, 한개의 크기는, 어떻게(람다사용))
	qsort(dogs, 3, sizeof(Dog), [](const void* a, const void* b) { 
		return static_cast<const Dog*>(a)->getAge() - static_cast<const Dog*>(b)->getAge();
	});

	for (Dog d : dogs)
		cout << d << endl;


	//개를 이름 오름차순으로 정렬
	qsort(dogs, 3, sizeof(Dog), [](const void* a, const void* b) {
		if (static_cast<const Dog*>(a)->getName() < static_cast<const Dog*>(b)->getName()) return -1;
		else if (static_cast<const Dog*>(a)->getName() == static_cast<const Dog*>(b)->getName()) return 0;
		else return 1;
	});									//string 자료형은 - 같은 연산은 되지 않지만, if 나 <, > 를 이용해서 연산 비슷하게 할 수 있다.

	for (Dog& d : dogs)
		cout << d << endl;*/

	//개 100000마리는 왜 돌아가지 않을까 => 지역변수의 한계, 전역변수로 바꾸면 잘 돌아간다.

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

int compare(const void *A, const void  *B){							//void 포인터 : 받는 인자가 무엇인지 알 수 없다.

	Dog* ptrA = (Dog*)A;

	Dog* ptrB = (Dog*)B;

	if (ptrA->getAge() < ptrB->getAge()) return -1;

	else if (ptrA->getAge() == ptrB->getAge()) return 0;

	else return 1;

}


int f(const void* A, const void* B) {

	return *(int*)A - *(int*)B;					//오름차순 간략화 
}