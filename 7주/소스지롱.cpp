//===================================================================================
// 18.04.17
//
//
// �����Լ� dre�� ���¸� ������ ���� �� ���� �Լ�
//
//4��. ���� �����̳� ( Sequence Container ) : ���α׷��Ӱ� ���ϴ� ��ġ�� �����͸� ���� �� �ִ� �����̳� (ex : list, array �� ...)
//						<-> set : ���α׷����� �ǵ��� �����ϰ� ������ ��ġ�� �����ϴ� �����̳�
//
//	deque(�� ���� �����ִ� ť(Double ended que) - ����Ͽ� ���� 
//	list - ȭ���Ͽ� ����
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

// Ŭ���� ��ü�� �ƴ�, ǥ�� ������� ������ ��ü�� operator
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
}// = algorithm�� find �Լ��� ����

template<class Iter, class Call>
Iter myFindIf(Iter b, Iter e, Call l);

template<class Iter, class Call >
Iter myFindIf(Iter b, Iter e, Call l) {				//Callable Type : ȣ�� ������ ��ü => ���ٰ� �Լ����� ȣ��� ��
	while (b != e) {
		if (l(*b))
			return b;
		++b;
	}
	return e;
}// = algorithm�� find �Լ��� ����

bool f(const Test& x) {
	return x.getId() == "���̺귯��";
}



void main() {
	/*{
		default_random_engine dre;

		dre();			// dre() : Ŭ������ �Լ� ȣ�� �����ڸ� �����ε��� ��
						// ���°� �ִ� => �θ������� �ٸ� ����� ����.

		for (int i = 0; i < 100; ++i)
			cout << setw(20) << dre();
		cout << endl;
	}*/

	/*{
		default_random_engine dre;
		normal_distribution<> nd(0, 1.0);				// ����Ʈ�� : (0, 1)

		array<int, 21> a{ 0 };

		for (int i = 0; i < 10000000; ++i) {
			double val = nd(dre);
			if (-2.0 <= val && val <= 2.0) {
				val += 2.0;					//���� 0~4�� ����
				val *= 5;					//���� 0~20���� ����
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

	//�����̳ʿ��� ���ϴ� ���� ã��
	/*{
		vector<int> v{ 1,2,3,4,5 };

		// v�� 3�� �ִ��� �˰� �ʹ�.
		// v�� 6�� �ִ��� �˰� �ʹ�.

		//��ġ(3�� ��ġ) or ����(True of False) = ã�ƶ�(v�� ó������, v�� ������ �߿���, 3�̶� ���Ұ� �ִ���);
		auto p = myFind(v.begin(), v.end(), 3);		// ��ġ
		if (p == v.end())
			cout << "�߰� ����" << endl;
		else {
			cout << "�տ��� ���� " << distance(v.begin(), p) + 1 << " ��ġ�� �ִ�." << endl;
		}
	}*/

	/*{
		vector<Test> v{ {"�ٽ�", 10}, {"C++", 100}, {"ǥ��", 30}, {"���̺귯��", 20} };

		//�̸��� ǥ���� ��ü�� v���� ã�ƶ�
		// find_if ���
		//auto p = find_if(v.begin(), v.end(), [](const Test& a) {
		//	if (a.getId() == string("ǥ��"))
		//		return true;
		//	return false;
		//});

		//find ���
		auto p = find(v.begin(), v.end(), Test("ǥ��", 3045));			// find�� ���ο��� '==(��)' �� �����Ѵ�.
		//find�� ����Ϸ��� Ŭ���� ���ο� operator==�� �������־�� �Ѵ�.
	}*/

	/*{
		vector<Test> v{ { "�ٽ�", 10 },{ "C++", 100 },{ "ǥ��", 30 },{ "���̺귯��", 20 } };

		//�̸��� ǥ���� ��ü�� v���� ã�ƶ�. find�� ����ؼ� !
		auto p = find(v.begin(), v.end(), Test("ǥ��", 3045));
		//����(�̸��� "C++")�� �´� ��ü v���� ã�ƶ�.
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
		vector<Test> v{ { "�ٽ�", 10 },{ "C++", 100 },{ "ǥ��", 30 },{ "���̺귯��", 20 } };

		auto p = myFindIf(v.begin(), v.end(), f);

		auto q = myFindIf(v.begin(), v.end(), [](const Test& a) {
			return a.getId() == string("���̺귯��");
		});
		// ���ٸ� �� �� �ִ°��� �ִٸ� ������ ���ٸ� ����.(���ٰ� ���� �Լ����� ������)
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

// list : ��Ҹ� �߰��ϰų� �����Ͽ��� �ݺ��� ��ȿȭ���� �ʴ´�,

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