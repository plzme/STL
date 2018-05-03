#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include"Model.h"
using namespace std;

int global_id = 0;


Model f(const Model&);


Model f(const Model& other) {
	cout << "f 출력" << endl;

	return other;
}

void main() {
	cout << "======================== Main Start ========================" << endl;
	/*
	Model a;
	Model b{ 1000 };
	Model c = b;

	a = c;				//a.operator=(c)
	*/


	// 키보드에서 입력되는 정수를 읽어 평균값을 구하라
	/*
	{
		vector<int> v;
		copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

		int sum = 0;
		for (int d : v)
			sum += d;

		//입력의 끝은 ctrl + z

		cout << "평균값은 " << (double)sum / v.size() << endl;
	}
	*/

	// 키보드에서 단어를 입력받아 정렬한다.
	/*
	{
		vector<string> v;
		copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));

		sort(begin(v), end(v));
		for (const string& d : v)
			cout << d << endl;
	}
	*/
	
	/*{
		vector<Model> v;							//Dynamic memory의 일종 (physical continuous memory)

		Model a(111);
		Model b(222);

		//숙제 : 객체의 생성, 소멸, 복사를 관찰해보자.
		v.push_back(a);
		v.push_back(b);
	}*/

	// 함수 f에 Model을 전달하자.
	// 함수 f는 화면에 "f 호출"이라고 출력한 후, 전달한 인자를 리턴한다.
	// 실행하고 관찰해 보자.

	/*{
		Model id(1234);

		Model c_id = f(id);
	}*/

	/*{
		// stack을 이용하는것 지역변수, 함수 호출 변수, 리턴값

		// 전역변수와 지역변수의 메모리 차이는 없다.
		vector<Model> v;							

		Model a{ 100 };
		Model b{ 200 };


		//cout << "스택에 생성된 v 의 번지 : " << &v << endl;
		//cout << "스택에 생성된 a 의 번지 : " << &a << endl;
		//둘을 비교하면 주소가 약 16정도 차이가 난다 => 12가 아니라 16인 이유는, 컴퓨터가 주소를 짝수로 맞추기 위해 임의로 4바이트를 밀어내는것 : 얼라인


		cout << "============" << endl;
		v.push_back(a);
		cout << "============" << endl;
		v.push_back(b);
	}*/

	{
		// 당신이 자원(Resource)을 할당하는 클래스를 만든다면
		// 클래스안에 자원을 가리키는 포인터가 반드시 멤버로 있을거다.

		// class Res {
		//		Resource* p;
		// }

		// 클래스는 이렇게 비어있는 듯 보여도 컴파일러가 다음 함수들을 알아서 만든다.
		// class Test {
				// Resource *p
		//		public:
		//		Test() = default;				//RAII idiom
		//		~Test() = default;				
		//		Test(const Test&) = default;	
		//		Test& operator=(const Test&) = default;
		//	};
		
		// 당신이 이 함수 4개 중에 하나라도 프로그래밍했다면,
		// 나머지도 반드시 프로그래밍 해야만 한다.
	}
	
	{
		// 여기에 더해서 당신이 공부를 게을리하지 않는 프로그래머라면
		// 이동생성자와 이동할당연산자도 프로그래밍하여야 함을 잘 알 수 있을거다.

		// auto를 쓸 수 있으면 auto를 쓰고, 람다 함수를 쓸 수 있으면 람다 함수를 써라
		// 범위 기반 for 루프를 돌릴 수 있으면 돌려라, 굳이 i < 1000 같은 코딩하지말고
		
		vector<Model> v;

		v.push_back(Model{ 111 });
		v.push_back(Model{ 222 });

		vector<Model> v2(move(v));

	}
	
	cout << "======================== Main End ========================" << endl;
}


