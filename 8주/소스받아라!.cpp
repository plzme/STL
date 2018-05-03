//===================================================================================
// 18.04.24
//
//
// �����Լ� dre�� ���¸� ������ ���� �� ���� �Լ�
//
//4��. ���� �����̳� ( Sequence Container ) : ���α׷��Ӱ� ���ϴ� ��ġ�� �����͸� ���� �� �ִ� �����̳� (ex : list, array �� ...)
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
	// �����̳ʿ��� Ư�� ������ �����ϴ� ���Ҹ� ��������

	// ���� �˰��� �Լ��� ���� ������ �ϴ� �����̳��� ����Լ��� �����ȴٸ�
	// ������ ����Լ��� ����ؾ� �Ѵ�.
	/*{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		
		// v���� Ȧ���� ������.
		//auto newEnd = remove_if(v.begin(), v.end(), [](int x) {
		//	return x & 1;					// x & 1 : x�� ���� ������ ��Ʈ�� 1 �̴� = > (2��������)Ȧ�� / a % 2 == 1�� ����
		//});
		//���� ���� remove�� ���ؼ� ���Ҹ� ����� �;, �˰��� �󿡼� �ڷᱸ���� ũ�⸦ �ٲ� ���� ����. 
		//�׷��Ƿ� erase��� �ڷᱸ���� ��� �Լ��� ����� �ڷᱸ�������� ũ�⸦ �����Ѵ�.
		//v.erase(newEnd, v.end());
		// remove_if�� erase�� ��ġ�� ....
		v.erase(remove_if(v.begin(), v.end(), [](int x) {
			return x & 1;					
		}), v.end());

		for (int d : v)
			cout << d << ' ';
		cout << endl;
	}*/


	/*{
		list<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		// v���� Ȧ���� ������.
		v.remove_if( [](int x) { return x & 1; });			// ����Ʈ�� ���Ϳ� �޸� �ڽ��� ����Լ��� ����� �� �����ϰ� remove �� �� �ִ�.

		for (int d : v)
			cout << d << ' ';
		cout << endl;
	}*/

	// v�� ���Ͽ� ������ �� �ٽ� �о�� ����
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

	// ���Ͽ��� ���� ������ �����̳ʷ� �о������.
	{
		make();
		list<Player> l;

		ifstream in("����������");

		string s;
		int n;

		while (in >> s >> n)
			l.push_back(Player(s, n));

		for (auto d : l)
			d.show();
	}

}

void make() {
	ofstream out("����������");

	string name;

	for (int i = 0; i < 100000; ++i) {
		name = "����" + to_string(i);
		out << name << '\t' << i << endl;
	}
}