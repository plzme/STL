// 4장. 순차 컨테이너 ( Sequence Container ) : 프로그래머가 원하는 위치에 데이터를 넣을 수 있는 컨테이너 (ex : list, array 등 ...)
//						<-> set : 프로그래머의 의도를 무시하고 스스로 위치를 정렬하는 컨테이너
//
//	array : 유일하게 컴파일시에 크기가 결정되어야 함. 안전배열(Safe Arrat)의 일종
//			=> 배열과 뭐가 다른가?
//	vector : 동적배열, 재할당동작을 이해하고 사용하자
//	deque
//	list
//	forward_list
//
//
//------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <vector>
#include "Model.h"
#include "save.h"
using namespace std;


void main() {
	/*{
		array<int, 11> v{ 333,1,3,5,7,9,2,4,6,8,10 };				// array<자료형, 개수> 
		//int v[11] { 333,1,3,5,7,9,2,4,6,8,10 }; 하지만 컨테이너가 아님(전형적인 Old Data Type)

		//int v[11] { 333,1,3,5,7,9,2,4,6,8,10 };를 아래와 같이 돌릴려면
		for (auto i = cbegin(v); i != cend(v); ++i)			//이렇게 해야함
		//for (auto i = v.cbegin(); i != v.cend(); ++i)
			cout << *i << ' ';
		cout << endl;

		//안전배열 : boundary를 check하는 배열 (안전을 위해서 속도를 희생한다.//안정성↑ 속도↓ => STL은 속도를 우선시 한다.)
		//아래와 같은 것은 돌아갈 수 없다.
		v[-1]
	}*/

	/*{
		array<int, 10> v { 1,3,5,7,9,2,4,6,8,10 };

		while (true) {
			try {
				cout << "몇 번째 값을 알려드릴까요?";
				int n;
				cin >> n;
				cout << "원하시는 값은 " << v.at(n) << "입니다." << endl;
			}
			catch (exception& e) {
				cout << "유효값 : 0 ~ " << v.size()-1 << endl;
			}
			//try&catch는 오류를 잡기는 좋지만, 조금 과한 코딩이라고 할 수 있다.
	}*/

	/*{
		int n = 1;
		for (;; ) {
			try {
				int * p = new int[100000000];
				cout << n++ << " 할당 성공" << endl;
				delete[] p;
			}
			catch (exception e) {
				cout << e.what() << endl;
				break;
			}
		}
	}*/

	/*{
		vector<int> v;
		v.reserve(1000);			//벡터의 메모리를 임의로 정해준다.


		// 재할당될 때만 화면출력되도록 하자
		int old = 0;
		for (int i = 0; i < 1000; ++i) {
			v.push_back(i);
		
			if(v.capacity() != old ){
				cout << "원소의 갯수                " << v.size() << endl;
				cout << "Free Store에 확보한 메모리 " << v.data() << endl;
				cout << "재할당없이 담을 수 있는 수 " << v.capacity() << endl;
				cout << endl;
				old = v.capacity();
			}
		}
		//한번 재할당 할때마다 메모리를 1.5배씩 늘리기 때문에 동적할당이지만 조금의 위험성이 있다.
		//(100000개를 임의로 할당해도 100001번째 데이터를 위해 150000 메모리로 재할당을 해야한다.
	}*/

	/*{
		vector<int> v;
		v.reserve(1000);

		*(v.data()) = 333;
		cout << v[0] << endl;
		//이런식으로 임의로 v의 자리에 데이터를 넣어주어도 v.size()는 0이다. => 자료구조의 특성

		for (auto i = v.begin(); i != v.end(); ++i)
			cout << *i << endl;
	}*/

	/*{
		vector<Model> v;

		//Model a { 333 };
		//v.push_back(a);					// 기존의 a라는 이름의 Model 객체를 복사해서 벡터로 가져온다.
		//v.push_back( Model { 333 })		// 이름없는 Model 객체를 생성해서 벡터로 '이동' 시킨다.
		//v.emplace_back( 333 );			// 생성자의 인자만 주면 알아서 객체를 생성해준다(이동 x)
	}*/

	{
		// qsort(v.data(), 1000, sizeof(Player), [](const void* a, const void* b) {
		// 	return ((Player*)b)->getHighscore1() - ((Player*)a)->getHighscore1();
		// });

		// sort(v.begin(), v.end(), [](const Player& a, const Player& b) {
		//	return a.getHighscore1() >  b.getHighscore1();					// < : less then operator, 오름차순용
		// });

		// 둘다 같은 generic 함수 이긴 하지만. sort는 template이 적용되어 있다.

	}
}