//-----------------------------------------------------------------------------------------
// 5장 연관컨테이너 (associative container)
//		set		- key 기준으로 정렬
//		map		- key/value pair를 저장
//		unordered_set / unordered_map	- key를 hashing 하여 저장할 곳을 선택
//
//		key, value : 정렬의 대상이 되는 데이터
//		hasing : key를 잘개 쪼갠다.
//
//			=> 정렬의 목적? : 빨리 찾기 위함
//			가장 빨리 찾는 컨테이너 : unordered_set, 상수 시간이 걸린다. = 메모리를 희생해 속도를 얻는다.
//-----------------------------------------------------------------------------------------

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <functional>
#include <map>
#include <fstream>
#include "Model.h"
#include "save.h"
using namespace std;

// 표준입출력은 멤버함수로 operator를 사용할 수 없기 때문에, 전역함수로 짜준다.
// 그 외에는 멤버함수로 짜준다.
/*bool operator< (const Model& lhs, const Model& rhs) {
	return lhs.getsize() < rhs.getsize();
}*/

void main() {
	/*{
		set<int> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		// 정렬하는 컨테이너는 '위치를 지정할 일'이 없기 때문에 push_back 같은 위치 기반의 삽입이 불가능하다.
		//s.push_back( 100 );

		s.insert(-1);
	}*/


	{
		// set은 자신만의 기준으로 원소들을 정렬하는 컨테이너이다.
		// 정렬은 default <(less then) 연산자를 사용한다.
		// POD(Plain Old Data type)는 모두 < 연산자가 정의되어 있다.
		
		// 사용자가 정의한 자료형을 set에 넣으려면
		// 1. < 연산자를 오버로딩한다.
		// 2. 비교할 수 았는 함수객체를 지정한다.

	}

	/*{
		//set<Model> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };			// 이런식으로 쓸 경우, 객체를 만들어서 set에 넣어주는게 된다.(복사 생성)

		set<Model> s;												// set이 스스로 객체를 만드는 emplace를 사용해 복사 생성을 하지 않도록 한다.

		s.emplace(1);		s.emplace(3);		s.emplace(5);
		s.emplace(7);		s.emplace(9);		s.emplace(2);
		s.emplace(4);		s.emplace(6);		s.emplace(8);
		s.emplace(10);

		cout << "------------------------------------------------------" << endl;
		for (const Model& d : s)					// s의 원소는 key값이기 때문에, 원본을 그대로 가져오는 &를 붙여 가져올 수 없다. 
			d.show();								// 그러므로 원본은 건드리지 않겠다는 const를 붙여준다.
		cout << "------------------------------------------------------" << endl;
		

		// const &는 지나치고, 필요없는 복사생성을 막아야 한다면 반드시 붙여준다.
	}*/

	// 키보드에서 단어를 읽어 정렬한 후 출력하라.
	// ver. vector
	/*{
		vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() };

		// istream_iterator<string>(cin) : 키보드에서 string 단위로 가져온다. 
		// 아래 줄 해석 : 키보드에서 string단위로 입력을 ctrl+z할때까지 받아서 v에 넣어준다.
		//copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));
		// 하지만, 벡터는 범위를 받을 수 있기 때문에, 굳이 copy를 쓰지않고, 벡터를 생성할때 범위로
		// istream_iterator<string>(cin), istream_iterator<string>()를 주어도 된다.

		sort(v.begin(), v.end());

		for (const string& d : v)
			cout << d << '\t';
		cout << endl;
	}*/

	// 키보드에서 단어를 읽어 정렬한 후 출력하라.
	// ver. set
	/*{
		set<string> s{ istream_iterator<string>(cin), istream_iterator<string>() };
		for (const string d& : s)
			cout << d << '\t';
		cout << endl;

		// 단점 : 중복저장이 되지않는다.

		//그럼 어떻게 ?
	}*/

	// 키보드에서 단어를 읽어 정렬한 후 출력하라.
	// ver. multiset
	/*{
		multiset<string> s{ istream_iterator<string>(cin), istream_iterator<string>() };
		//multiset<string, greater<string>> s{ istream_iterator<string>(cin), istream_iterator<string>() };		// 내림차순 정렬

		for (const string& d : s)
			cout << d << '\t';
		cout << endl;
	}*/


	/*{
		// map은 pair<key, value>를 원소로 갖는다.
		// map<key, value, 정렬방법(default : less<stirng>)> m;

		// "루피", 400000000
		// "푸딩", 200000
		// "상디", 300000000
		// "빅맘", 700000000
		map<string, int> m;

		m.insert(pair<string, int>("루피", 400000000));
		m.insert(make_pair("푸딩", 200000));
		// map은 연관배열(associative array)처럼 사용할 수도 있다.
		// x["이름"] = 100; : 이름의 값을 100으로 바꿔라
		m["상디"] = 300000000;				// 원소 생성
		m["상디"] = 300000003;				// 원소의 값 수정				//== m.operator[]("상디") = 300000003;

		for (auto& d : m)									// <= const pair<string, int>를 auto로 자동으로 잡아준다.
			cout << d.first << "----" << d.second << endl;
	}*/

	/*{
		// 벡터 v에 각 알파벳이 도대체 몇 번이나 출현하는지 세서 출력하라

		vector<char> v(100000);

		default_random_engine dre;
		uniform_int_distribution<> ui('a', 'z');

		for (char& d : v)						
			d = ui(dre);

		map<char, int> m;

		for (char d : v)
			m[d]++;

		for (auto& d : m)
			cout << "[" << d.first << "] : " << d.second << endl;
	}*/

	{
		// 소스뿌려.cpp에 각 알파벳이 도대체 몇 번이나 출현하는지 세서 출력하라
		map<char, int> m;

		ifstream in("소스뿌려.cpp");

		char c;
		while (in >> c) {
			if ( isalpha(c))
				m[c]++;
		}
		for (auto& d : m)
			cout << "[" << d.first << "] : " << d.second << endl;

		// 영문소설에서 가장 많이 나오는 알파벳은 뭘까?
		// a는 몇 번 나왔니?
	}

}