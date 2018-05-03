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
	string getName() const { return name; }					//const를 붙이는 이유는 일종의 보장(?) - 엉뚱한 변수를 출력하지 않도록 한다
	int getAge() const { return age; }

	void setName(char* n) { name = n; }
	void setAge(int a) { age = a; }

	friend ostream& operator<<(ostream& os, const Dog& d);
};


ostream& operator<< (ostream& os, const Dog& d) {
	os << d.getAge() << "살";
	return os;
}


int compare(const void*, const void*);
int f(const void*, const void*);

#define dog_size 10000000
void main() {

	//int a[10] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};

	//정수를 오름차순으로 정렬
	//C의 방식 : qsort(a, 10, sizeof(int), f);

	//C++의 방식 : 한줄에 다 때려 넣는다.(함수까지 !) - 람다 함수
	//qsort(a, 10, sizeof(int), [](const void* a, const void* b) { return *static_cast<const int*>(a) - *static_cast<const int*>(b); });

	//for (int d : a)
	//cout << d << " ";
	//cout << endl;
	//Dog dogs[3]{
	//{ "개", 3 },{ "고양이", 2 },{ "비둘기", 6 }
	//};


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
	cout << d << endl;

	//개 100000마리는 왜 돌아가지 않을까 => 지역변수의 메모리 한계, 전역변수로 바꾸면 잘 돌아간다.

	//개 1000만 마리를 동적으로 할당하여 나이오름차순으로 정렬하라
	//앞에서 100개만 출력해서 정렬된결과를 확인

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

int compare(const void *A, const void  *B) {							//void 포인터 : 받는 인자가 무엇인지 알 수 없다.

	Dog* ptrA = (Dog*)A;

	Dog* ptrB = (Dog*)B;

	if (ptrA->getAge() < ptrB->getAge()) return -1;

	else if (ptrA->getAge() == ptrB->getAge()) return 0;

	else return 1;

}


int f(const void* A, const void* B) {

	return *(int*)A - *(int*)B;					//오름차순 간략화 
}




//*.exe를 실행 시키는 순간, 실행파일이 메모리(stack,1mb 고정)에 올려진다.
//지역 변수로 Dog 10만마리를 불러올 경우 stack의 용량인 1mb를 넘을 수 없지만
//전역 변수로 불러올 경우 약 21억의 Data만큼 불러올 수 있다.


*/

//=========================================================================================

// 숙제
// 파일에 자료를 읽고 써서 연습해보자
// 파일을 열 때 text mode와 binary mode를 선택할 수 있다. - 차이점을 알아서 공부하자


// 정수 1000개가 파일에 저장되어 있다.
// 읽어와서 정렬 후 출력하라.

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
	ofstream out("정수 1000개.txt",ios::binary);

	// 메모리의 내용을 그대로 기록하는 것이 맞다
	out.write((const char* )n, 1000 * sizeof(int));*/

/*	ifstream in("정수 1000개.txt", ios::binary);

	int n[1000];

	in.read((char*)n, sizeof(int) * 1000);

	sort(begin(n), end(n), [](int a, int b) {
		return a > b;
	});

	for (int d : n)
		cout << d << "\t";
	cout << endl;*/
//}

// main()이 있는 source 파일을 앞에서 200글자만 읽어서
// 알파벳 오름차순으로 정렬 후 화면에 출력하라.

void main() {
	ifstream in("소스.cpp",ios::binary);
	if (!in) {
		cout << "파일을 열수 없습니다" << endl;
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


