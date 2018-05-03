//----------------------------------------------------------------------------------------------
// Modern C++
// raw pointer(생 포인터)를 쓰지 말자
// --> smart pointe( unique_ptr, shared_ptr )
//
//type_traits : 형식특집(Why?)
//
//
//----------------------------------------------------------------------------------------------

#include <iostream>
//#include <type_traits>
#include <fstream>
//#include <memory>
#include <vector>
#include <string>
//#include <list>
#include "Model.h"
using namespace std;


/*template<class T>
class up {
	T* p;
public:
	up(T* data) : p{ data } {}
	~up() {
		delete p;;
	}
};

class Player {
	string id;
	int score1;
	int score2;
public:
	Player(string s, int n1, int n2) : id(s), score1(n1), score2(n2) {

	}
};*/

/*
//두 정수를 더해서 결과를 리턴하는 함수 f
template<class T>
T f(T a, T b) {
	//T로 들어오는 타입이 더할 수 있는거니? = is_arithmetic
	if(is_arithmetic<T>::value)
		return a + b;
}*/

void f() {

}

void main() {
	/*{
		int n{ 0 };

		for (;;) {
			try {
				cout << "++n" << "할당" << endl;
			}
			catch (exception& e) {
				cout << e.what() << endl;
				break;
			}
		}
	}*/

	/*{
		//Model* p = new Model{ 333 };
		//delete p;

		unique_ptr<Model> p(new Model{ 111 });

		cout << sizeof(p) << endl;
	}*/

	/*{
		vector<Player> v;

		v.push_back( Player("1번선수", 100, 30000));
		v.push_back( Player("2번선수", 130, 30242300));
		v.push_back( Player("3번선수", 102310, 31123000));
	}*/




	//*Smart Pointer*

	/*{
		unique_ptr<Model> p(new Model{ 333 });
		//unique_ptr은 자원을 독점한다. (다른 포인터와 자원 공유 불가능)
		//unique_ptr<Model>q = p; //에러 뜸

		//만약 q가 p와 같은 메모리를 포인팅하려면 p에서 q로 '소유권 이전'해야한다.(p의 자원을 q가 옮겨 받는다, =>p는 자원할당이 없어짐)
		unique_ptr<Model>q( p.release() );
	}*/

	/*{
		shared_ptr<Model> p(new Model{ 333 });
		//shared_ptr은 자원을 공유한다. (특별한 멤버함수 없이 자원 공유 가능) - 사용예 DiretX12
		shared_ptr<Model>q = p;
		//자원을 가르키는 모든 포인터를 없애야 자원을 소멸시킬 수 있다.

		//포인팅 중인 자원의 참조 횟수를 새는 멤버함수 .use_count()
		cout << q.use_count() << endl;

	}*/

	/*{
		// 너는 class니 ? = >is_class<자료형>
		cout << boolalpha << is_class<Model>::value << endl;
		cout << boolalpha << is_class<int>::value << endl;

		// 너는 더하기가 가능한 타입이니 ? = >is_arithmetic<자료형>
		cout << boolalpha << is_arithmetic<Model>::value << endl;
		cout << boolalpha << is_arithmetic<int>::value << endl;

		// 너는 함수니 ? = >is_function<함수()>
		cout << boolalpha << is_function<void(void)>::value << endl;
		cout << typeid(f).name() << endl;

	}*/

	// 3장, 모든 컨테이너에 공통인 인터페이스
	//	 생성, 크기, 요소에 접근, 할당, 비교

	// 컨테이너란 ? - 자료구조이다. 
	//		Cotainer is a object which contains another objects.
	// 담을 수 있는 자료의 자료형은 같아야 한다.(homogeneous container)
	//
	//
	//
	//
	// 1. Sequnce Container
	//	- array
	//	- vector
	//	- deque
	//	- list
	//	- forward_list
	//
	// 2. Associative Container
	//	- set	
	//	- multiset
	//	- map
	//	- multimap
	//
	// 3. Unoredered Associative Container
	//	- unordered_set
	//	- unordered_multiset
	//	- unordered_map
	//	- unordered_multimap

	/*{
	vector<int> vec1;
	vec1.reserve(1000);
	for (int i = 0; i < 5; i++) {
	vec1.push_back(1);

	cout << "원소의갯수" << vec1.size() << endl;
	cout << "할당한 메모리" << vec1.data();
	cout << "담을 수 있는 갯수" << vec1.capacity() << endl;

	//vec1.push_back(1);

	//cout << "원소의갯수" << vec1.size() << endl;
	//cout << "할당한 메모리" << vec1.data();
	//cout << "담을 수 있는 갯수" << vec1.capacity() << endl;
	}*/


	/*{
	int a[10] { 1,2,3,4,5,6,7,8,9,10};

	vector<int> vec1;
	vector<int> vec2(&a[0], &a[10]);

	for (int d : vec2) {
		cout << d << endl;
	}

	}*/

	/*{
	int a[10]{ 1,2,3,4,5,6,7,8,9,10 };

	//처음을 가르키는 begin과 끝을 가르키는 end
	vector<int> vec1(begin(a)+1,end(a)-1);
	list <int> c(begin(vec1), end(vec1));

	for (int d : c)
			cout << d << endl;
	}*/

	/*{
		vector<int> v1{ 1,2,3,4,5,6,7 };
		cout << v1.data() << endl;
		vector<int> v2 = move(v1);

		cout << v1.size() << endl;
		cout << v2.size() << endl;
		cout << v2.data() << endl;

	}*/

	//자료구조와 알고리즘이 서로 접근할 수 있게해주는 것은 반복자(iterator)
	/*{
	vector<int> v1{ 1,2,3,4,5,6,7 };
	//list<int> v1{ 1,2,3,4,5,6,7 }; 로 변경 되어도 아무 문제 없이 잘 돌아간다.

	auto p = v1.begin();			// 컨테이너야 네 첫 원소는 어디있니?

	for (; p != v1.end(); ++p)
		cout << *p << endl;
	}*/

//1.소스.cpp에 몇 단어가 있는지 출력하라
//2.제일 뒤에 단어부터 처음단어까지 출력하라.
//3. 2와 같이 찍는데 단어의 순서를 뒤집어 출력하라(ex : vector - > rotcev)
	{
		vector<int> v1{ 1,2,3,4,5,6,7 };

		vector<int> ::iterator p1 = v1.begin();
		vector<int> ::iterator p2 = v1.end();

		vector<int> ::const_iterator p3 = v1.cbegin();
		vector<int> ::const_iterator p4 = v1.cend();

		vector<int> ::reverse_iterator p5 = v1.rbegin();
		vector<int> ::reverse_iterator p6 = v1.rend();

		vector<int> ::const_reverse_iterator p7 = v1.rbegin();
		vector<int> ::const_reverse_iterator p8 = v1.rend();

		//for (; p1 != p2; ++p1) 
		//	cout << *p1 << endl;
		//
		//
		//for (; p3 != p4; ++p3) 
		//	cout << *p3 << endl;
		//
		//
		//for (; p5 != p6; ++p5) 
		//	cout << *p5 << endl;
		//
		//
		//for (; p7 != p8; ++p7) 
		//	cout << *p7 << endl;
		

		//auto p = v1.begin();			// 컨테이너야 네 첫 원소는 어디있니?

		ifstream in("Source.cpp");
		vector<string> v;

		string s;

		while (in >> s)
			v.push_back(s);

		cout << "파일에는 " << v.size() << "개의 단어가 있습니다" << endl;


		vector<string> ::const_reverse_iterator p9 = v.rbegin();
		vector<string> ::const_reverse_iterator p0 = v.rend();

		for (; p9 != p0; ++p9)
			cout << *p9 << endl;

		for (; p9 != p0; ++p9) {
			string x = *p9;
			for (auto t = x.rbegin(); t != x.rend(); ++t)
				cout << *t;
			cout << endl;
		}
	}

}