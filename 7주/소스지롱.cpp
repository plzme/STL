//===================================================================================
// 18.04.17
//
//
// 랜덤함수 dre는 상태를 가지지 않을 수 없는 함수
//
//4장. 순차 컨테이너 ( Sequence Container ) : 프로그래머가 원하는 위치에 데이터를 넣을 수 있는 컨테이너 (ex : list, array 등 ...)
//						<-> set : 프로그래머의 의도를 무시하고 스스로 위치를 정렬하는 컨테이너
//
//	deque(양 끝이 열려있는 큐(Double ended que) - 목요일에 시작 
//	list - 화요일에 시작
//	forward_list

//===================================================================================
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <list>
#include <array>
#include <deque>
#include "save.h"
#include "Model.h"
using namespace std;

class Test {
	string id;
	int n{ 0 };
public:
	Test() = default;
	Test(string s, int n) : id(s), n(n) {}

	string getId() const { return id; }
	void show() const {
		cout << id << " : " << n << endl;
	}
	bool operator== (const Test& other) const { return id == other.id; }
};

// 클래스 객체가 아닌, 표준 입출력이 가능한 객체용 operator
/*bool operator==(const Test& lhs, const Test& rhs) {
	if (lhs.getId() == rhs.getId())
		return true;
	return false;
}*/

template<class Iter, class Val>
Iter myFind(Iter b, Iter e, Val v);

template<class Iter, class Val>
Iter myFind(Iter b, Iter e, Val v) {
	while ( b != e ){
		if (*b == v)
			return b;
		++b;
	}
	return e;
}// = algorithm의 find 함수와 같다

template<class Iter, class Call>
Iter myFindIf(Iter b, Iter e, Call l);

template<class Iter, class Call >
Iter myFindIf(Iter b, Iter e, Call l) {				//Callable Type : 호출 가능한 객체 => 람다가 함수에서 호출될 때
	while (b != e) {
		if (l(*b))
			return b;
		++b;
	}
	return e;
}// = algorithm의 find 함수와 같다

bool f(const Test& x) {
	return x.getId() == "라이브러리";
}



void main() {
	/*{
		default_random_engine dre;

		dre();			// dre() : 클래스에 함수 호출 연산자를 오버로딩한 것
						// 상태가 있다 => 부를때마다 다른 결과를 낸다.

		for (int i = 0; i < 100; ++i)
			cout << setw(20) << dre();
		cout << endl;
	}*/

	/*{
		default_random_engine dre;
		normal_distribution<> nd(0, 1.0);				// 디폴트값 : (0, 1)

		array<int, 21> a{ 0 };

		for (int i = 0; i < 10000000; ++i) {
			double val = nd(dre);
			if (-2.0 <= val && val <= 2.0) {
				val += 2.0;					//값을 0~4로 만듦
				val *= 5;					//값을 0~20으로 만듦
				a[(int)val]++;
			}
		}

		for (int i = 0; i < a.size(); ++i)
			cout << "[" << i << "] : " << a[i] << endl;
	}*/

	/*{
		default_random_engine dre;
		uniform_int_distribution<> uid(0, 9);

		array<int, 10> a{  };

		for (int i = 0; i < 100000000; ++i) {
			a[uid(dre)]++;
		}

		for (int i = 0; i < a.size(); ++i)
			cout << "[" << i << "] : " << a[i] << endl;
	}*/
	//=============================================================================================================

	//컨테이너에서 원하는 것을 찾기
	/*{
		vector<int> v{ 1,2,3,4,5 };

		// v에 3이 있는지 알고 싶다.
		// v에 6이 있는지 알고 싶다.

		//위치(3의 위치) or 진위(True of False) = 찾아라(v의 처음부터, v의 끝까지 중에서, 3이란 원소가 있는지);
		auto p = myFind(v.begin(), v.end(), 3);		// 위치
		if (p == v.end())
			cout << "발견 못함" << endl;
		else {
			cout << "앞에서 부터 " << distance(v.begin(), p) + 1 << " 위치에 있다." << endl;
		}
	}*/

	/*{
		vector<Test> v{ {"핵심", 10}, {"C++", 100}, {"표준", 30}, {"라이브러리", 20} };

		//이름이 표준인 객체를 v에서 찾아라
		// find_if 사용
		//auto p = find_if(v.begin(), v.end(), [](const Test& a) {
		//	if (a.getId() == string("표준"))
		//		return true;
		//	return false;
		//});

		//find 사용
		auto p = find(v.begin(), v.end(), Test("표준", 3045));			// find의 내부에는 '==(비교)' 가 존재한다.
		//find를 사용하려면 클래스 내부에 operator==을 선언해주어야 한다.
	}*/

	/*{
		vector<Test> v{ { "핵심", 10 },{ "C++", 100 },{ "표준", 30 },{ "라이브러리", 20 } };

		//이름이 표준인 객체를 v에서 찾아라. find를 사용해서 !
		auto p = find(v.begin(), v.end(), Test("표준", 3045));
		//조건(이름이 "C++")에 맞는 객체 v에서 찾아라.
		//auto p = find_if(v.begin(), v.end(), [](const Test& a) {
		//	if (a.getId() == string("C++"))
		//		return true;
		//	return false;
		//});
		auto q = myFindIf(v.begin(), v.end(), [](const Test& a) {
			return a.getId() == string("C++");
		});

		if (p != v.end())
			p->show();
		if (q != v.end())
			q->show();
	}*/

	/*{
		vector<Test> v{ { "핵심", 10 },{ "C++", 100 },{ "표준", 30 },{ "라이브러리", 20 } };

		auto p = myFindIf(v.begin(), v.end(), f);

		auto q = myFindIf(v.begin(), v.end(), [](const Test& a) {
			return a.getId() == string("라이브러리");
		});
		// 람다를 쓸 수 있는곳이 있다면 무조건 람다를 쓰자.(람다가 기존 함수보다 빠르다)
	}*/

	/*{
		deque<int> d;
		try {
			d.at(0) = 100;				// int& d.operator[]( int ) [] const
			cout << d.at(0);			// int d.operator[]( int )
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}*/

// list : 요소를 추가하거나 제거하여도 반복자 무효화되지 않는다,

	/*{
		vector<int> v;

		v.emplace_back( 1 );
		auto p = v.begin();
		cout << *p << endl;

		v.push_back(2);
		cout << *p << endl;
		++p;
		cout << *p << endl;
	}*/

	{
		list<int> v;

		v.emplace_back(1);
		auto p = v.begin();
		cout << *p << endl;

		v.push_back(2);
		cout << *p << endl;
		++p;
		cout << *p << endl;
	}
}