//-----------------------------------------------------------
// STL 2018. 1�б�
//
// 2�� Utilites
// Ŭ���� ���� - 
// 1-move() 17��
// 2-forward - 18�� (perfect forwarding���� googling
//1�� 2�� �����ϱ� ���� c++!!���� && Ű���尡 ���ԵǾ���.
//
//swap() - 19��
//pair/tuple - 21��
//
//
//
//
//
// Modern C++
// raw pointer(�� ������)�� ���� ����
// --> smart pointe( unique_ptr, shared_ptr )
//-----------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
using namespace std;

/*
void main() {
	
	//���� ����
	auto begin = chrono::high_resolution_clock::now();									//�� ���� ����(������ ����)

	//���� �� �ڵ带 �̰���
	//this_thread::sleep_for(3.3s);			//Sleep()�� ����ϴ� sleep_for


	//���� ��
	auto elapsedTime = chrono::high_resolution_clock::now() - begin;

	//����ð� ���
	cout << chrono::duration<double>(elapsedTime).count() << "�� ���" << endl;						//������ �ð��� �ʴ����� ������ �ٲ۴�.

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
//Test�� ������ ���ڷ� ȣ���ϸ� �ڱ� ������*���ڸ� �ϴ� Ŭ������� �غ���
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
		//���� ���� ���� ã���ִ� min

		cout << min(Dog(3), Dog(5), [](const Dog& a, const Dog& b) {
			return a.getX() < b.getX();
		}) << endl;
	}*/


	/*
	{
	//���� ���� ���� ���� ū ���� ã���ִ� minmax

	//auto p = minmax({ 1,2,3,4,5,6,7 });
	pair<int, int> p = minmax({ 1,2,3,4,5,6,7 });

	cout << p.first << ", " << p.second << endl;
	}
	*/

	/*{

		// �Լ��� ���¸� ���´�?
		// �Լ��� ����? - ȣ���� �� �ִ� �� ����, (�Լ�, ����, ����Լ�, �Լ���ü ...)
		// Callable Objects (ȣ�Ⱑ�ɰ�ü)

		auto x = []() { cout << "���� ���پ�." << endl; };					//�Լ��ڿ� ���� () �� �Լ� ȣ�� ������
		cout << typeid(x).name() << endl;

		//�Լ� �̸��� �Լ��� ���۹����� �ǹ��Ѵ�.
	}*/
	{
		int *p = new int[1000000];

		// �ð��� ����

		delete[] p;
	}
}
