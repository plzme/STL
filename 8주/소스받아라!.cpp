//===================================================================================
// 18.04.24
//
//
// 랜덤함수 dre는 상태를 가지지 않을 수 없는 함수
//
//4장. 순차 컨테이너 ( Sequence Container ) : 프로그래머가 원하는 위치에 데이터를 넣을 수 있는 컨테이너 (ex : list, array 등 ...)
//
//	list 
//	forward_list

//===================================================================================
#include <iostream>
#include <fstream>
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

void make();

class Player {
	string id;
	int n;
public:
	Player(string s, int n) : id(s), n(n) {};

	void show() const {
		cout << id << "-------" << n << endl;
	}
};

void main() {
	// 컨테이너에서 특정 조건을 만족하는 원소를 지워보자

	// 전역 알고리즘 함수와 같은 동작을 하는 컨테이너의 멤버함수가 제공된다면
	// 무조건 멤버함수를 사용해야 한다.
	/*{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		
		// v에서 홀수를 지워라.
		//auto newEnd = remove_if(v.begin(), v.end(), [](int x) {
		//	return x & 1;					// x & 1 : x의 가장 오른쪽 비트가 1 이다 = > (2진수에서)홀수 / a % 2 == 1도 가능
		//});
		//위와 같이 remove를 통해서 원소를 지우고 싶어도, 알고리즘 상에서 자료구조의 크기를 바꿀 수는 없다. 
		//그러므로 erase라는 자료구조의 멤버 함수를 사용해 자료구조내에서 크기를 조절한다.
		//v.erase(newEnd, v.end());
		// remove_if와 erase를 합치면 ....
		v.erase(remove_if(v.begin(), v.end(), [](int x) {
			return x & 1;					
		}), v.end());

		for (int d : v)
			cout << d << ' ';
		cout << endl;
	}*/


	/*{
		list<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		// v에서 홀수를 지워라.
		v.remove_if( [](int x) { return x & 1; });			// 리스트는 벡터와 달리 자신의 멤버함수를 사용해 더 간단하게 remove 할 수 있다.

		for (int d : v)
			cout << d << ' ';
		cout << endl;
	}*/

	// v를 파일에 저장한 후 다시 읽어와 보자
	/*{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		ofstream out("SavingTest", ios::binary);
		for (int d : v)
			out.write((char*)&d, sizeof(int));
		//out.write((char*)v.data(), sizeof(int)*v.size());
	}*/

	/*{
		vector<int> v;
		v.resize(10);

		ifstream in("SavingTest", ios::binary);
		in.read((char*)v.data(), 40);

	}*/


	/*{
		list<int> l;

		ifstream in("SavingTest", ios::binary);

		int n;
		for (int i = 0; i < 10; ++i) {
			in.read((char*)&n, sizeof(int));
			l.push_back(n);
		}

		for (int d : l)
			cout << d << ' ';
		cout << endl;
	}*/

	// 파일에서 선수 정보를 컨테이너로 읽어오세요.
	{
		make();
		list<Player> l;

		ifstream in("선수데이터");

		string s;
		int n;

		while (in >> s >> n)
			l.push_back(Player(s, n));

		for (auto d : l)
			d.show();
	}

}

void make() {
	ofstream out("선수데이터");

	string name;

	for (int i = 0; i < 100000; ++i) {
		name = "선수" + to_string(i);
		out << name << '\t' << i << endl;
	}
}