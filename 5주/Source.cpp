//----------------------------------------------------------------------------------------------
// Modern C++
// raw pointer(�� ������)�� ���� ����
// --> smart pointe( unique_ptr, shared_ptr )
//
//type_traits : ����Ư��(Why?)
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
//�� ������ ���ؼ� ����� �����ϴ� �Լ� f
template<class T>
T f(T a, T b) {
	//T�� ������ Ÿ���� ���� �� �ִ°Ŵ�? = is_arithmetic
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
				cout << "++n" << "�Ҵ�" << endl;
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

		v.push_back( Player("1������", 100, 30000));
		v.push_back( Player("2������", 130, 30242300));
		v.push_back( Player("3������", 102310, 31123000));
	}*/




	//*Smart Pointer*

	/*{
		unique_ptr<Model> p(new Model{ 333 });
		//unique_ptr�� �ڿ��� �����Ѵ�. (�ٸ� �����Ϳ� �ڿ� ���� �Ұ���)
		//unique_ptr<Model>q = p; //���� ��

		//���� q�� p�� ���� �޸𸮸� �������Ϸ��� p���� q�� '������ ����'�ؾ��Ѵ�.(p�� �ڿ��� q�� �Ű� �޴´�, =>p�� �ڿ��Ҵ��� ������)
		unique_ptr<Model>q( p.release() );
	}*/

	/*{
		shared_ptr<Model> p(new Model{ 333 });
		//shared_ptr�� �ڿ��� �����Ѵ�. (Ư���� ����Լ� ���� �ڿ� ���� ����) - ��뿹 DiretX12
		shared_ptr<Model>q = p;
		//�ڿ��� ����Ű�� ��� �����͸� ���־� �ڿ��� �Ҹ��ų �� �ִ�.

		//������ ���� �ڿ��� ���� Ƚ���� ���� ����Լ� .use_count()
		cout << q.use_count() << endl;

	}*/

	/*{
		// �ʴ� class�� ? = >is_class<�ڷ���>
		cout << boolalpha << is_class<Model>::value << endl;
		cout << boolalpha << is_class<int>::value << endl;

		// �ʴ� ���ϱⰡ ������ Ÿ���̴� ? = >is_arithmetic<�ڷ���>
		cout << boolalpha << is_arithmetic<Model>::value << endl;
		cout << boolalpha << is_arithmetic<int>::value << endl;

		// �ʴ� �Լ��� ? = >is_function<�Լ�()>
		cout << boolalpha << is_function<void(void)>::value << endl;
		cout << typeid(f).name() << endl;

	}*/

	// 3��, ��� �����̳ʿ� ������ �������̽�
	//	 ����, ũ��, ��ҿ� ����, �Ҵ�, ��

	// �����̳ʶ� ? - �ڷᱸ���̴�. 
	//		Cotainer is a object which contains another objects.
	// ���� �� �ִ� �ڷ��� �ڷ����� ���ƾ� �Ѵ�.(homogeneous container)
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

	cout << "�����ǰ���" << vec1.size() << endl;
	cout << "�Ҵ��� �޸�" << vec1.data();
	cout << "���� �� �ִ� ����" << vec1.capacity() << endl;

	//vec1.push_back(1);

	//cout << "�����ǰ���" << vec1.size() << endl;
	//cout << "�Ҵ��� �޸�" << vec1.data();
	//cout << "���� �� �ִ� ����" << vec1.capacity() << endl;
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

	//ó���� ����Ű�� begin�� ���� ����Ű�� end
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

	//�ڷᱸ���� �˰����� ���� ������ �� �ְ����ִ� ���� �ݺ���(iterator)
	/*{
	vector<int> v1{ 1,2,3,4,5,6,7 };
	//list<int> v1{ 1,2,3,4,5,6,7 }; �� ���� �Ǿ �ƹ� ���� ���� �� ���ư���.

	auto p = v1.begin();			// �����̳ʾ� �� ù ���Ҵ� ����ִ�?

	for (; p != v1.end(); ++p)
		cout << *p << endl;
	}*/

//1.�ҽ�.cpp�� �� �ܾ �ִ��� ����϶�
//2.���� �ڿ� �ܾ���� ó���ܾ���� ����϶�.
//3. 2�� ���� ��µ� �ܾ��� ������ ������ ����϶�(ex : vector - > rotcev)
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
		

		//auto p = v1.begin();			// �����̳ʾ� �� ù ���Ҵ� ����ִ�?

		ifstream in("Source.cpp");
		vector<string> v;

		string s;

		while (in >> s)
			v.push_back(s);

		cout << "���Ͽ��� " << v.size() << "���� �ܾ �ֽ��ϴ�" << endl;


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