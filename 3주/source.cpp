//-----------------------------------------------------------
// STL 2018. 1학기
//
// 2장 Utilites
// 클래스 복습 - 
// 1-move() 17쪽
// 2-forward - 18쪽 (perfect forwarding으로 googling
//1과 2를 지원하기 위해 c++!!에사 && 키워드가 도입되었다.
//
//swap() - 19쪽
//pair/tuple - 21쪽
//
//
//
//
//
// Modern C++
// raw pointer(생 포인터)를 쓰지 말자
// --> smart pointe( unique_ptr, shared_ptr )
//-----------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
using namespace std;

/*
void main() {
	
	//측정 시작
	auto begin = chrono::high_resolution_clock::now();									//초 정밀 측정(나노초 측정)

	//측정 할 코드를 이곳에
	//this_thread::sleep_for(3.3s);			//Sleep()을 대신하는 sleep_for


	//측정 끝
	auto elapsedTime = chrono::high_resolution_clock::now() - begin;

	//결과시간 출력
	cout << chrono::duration<double>(elapsedTime).count() << "초 경과" << endl;						//측정한 시간을 초단위로 단위를 바꾼다.

}
*/


// min, max, minmax
/*
class Dog {
	int x;
public:
	Dog(int n) : x(n) {}

	int getX() const { return x; }

	//operator int() const { return x; }
	friend ostream& operator<<(ostream& os, const Dog& d) {
		os << d.getX();
		return os;
	}
};*/

/*
//Test는 정수를 인자로 호출하면 자기 정수값*인자를 하는 클래스라고 해보자
class Test {
	int n;
public:
	explicit Test(int n): n(n){}
	void operator()(int x) {
		n = n*x;
	}

	operator int(){
		return n;
	}
};*/

void main() {
	
	/*{
		//제일 작은 값을 찾아주는 min

		cout << min(Dog(3), Dog(5), [](const Dog& a, const Dog& b) {
			return a.getX() < b.getX();
		}) << endl;
	}*/


	/*
	{
	//제일 작은 값과 제일 큰 값을 찾아주는 minmax

	//auto p = minmax({ 1,2,3,4,5,6,7 });
	pair<int, int> p = minmax({ 1,2,3,4,5,6,7 });

	cout << p.first << ", " << p.second << endl;
	}
	*/

	/*{

		// 함수가 상태를 갖는다?
		// 함수란 뭘까? - 호출할 수 있는 그 무엇, (함수, 람다, 멤버함수, 함수객체 ...)
		// Callable Objects (호출가능객체)

		auto x = []() { cout << "나는 람다야." << endl; };					//함수뒤에 오는 () 는 함수 호출 연산자
		cout << typeid(x).name() << endl;

		//함수 이름은 함수의 시작번지를 의미한다.
	}*/
	{
		int *p = new int[1000000];

		// 시공의 차이

		delete[] p;
	}
}
