// 4��. ���� �����̳� ( Sequence Container ) : ���α׷��Ӱ� ���ϴ� ��ġ�� �����͸� ���� �� �ִ� �����̳� (ex : list, array �� ...)
//						<-> set : ���α׷����� �ǵ��� �����ϰ� ������ ��ġ�� �����ϴ� �����̳�
//
//	array : �����ϰ� �����Ͻÿ� ũ�Ⱑ �����Ǿ�� ��. �����迭(Safe Arrat)�� ����
//			=> �迭�� ���� �ٸ���?
//	vector : �����迭, ���Ҵ絿���� �����ϰ� �������
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
		array<int, 11> v{ 333,1,3,5,7,9,2,4,6,8,10 };				// array<�ڷ���, ����> 
		//int v[11] { 333,1,3,5,7,9,2,4,6,8,10 }; ������ �����̳ʰ� �ƴ�(�������� Old Data Type)

		//int v[11] { 333,1,3,5,7,9,2,4,6,8,10 };�� �Ʒ��� ���� ��������
		for (auto i = cbegin(v); i != cend(v); ++i)			//�̷��� �ؾ���
		//for (auto i = v.cbegin(); i != v.cend(); ++i)
			cout << *i << ' ';
		cout << endl;

		//�����迭 : boundary�� check�ϴ� �迭 (������ ���ؼ� �ӵ��� ����Ѵ�.//�������� �ӵ��� => STL�� �ӵ��� �켱�� �Ѵ�.)
		//�Ʒ��� ���� ���� ���ư� �� ����.
		v[-1]
	}*/

	/*{
		array<int, 10> v { 1,3,5,7,9,2,4,6,8,10 };

		while (true) {
			try {
				cout << "�� ��° ���� �˷��帱���?";
				int n;
				cin >> n;
				cout << "���Ͻô� ���� " << v.at(n) << "�Դϴ�." << endl;
			}
			catch (exception& e) {
				cout << "��ȿ�� : 0 ~ " << v.size()-1 << endl;
			}
			//try&catch�� ������ ���� ������, ���� ���� �ڵ��̶�� �� �� �ִ�.
	}*/

	/*{
		int n = 1;
		for (;; ) {
			try {
				int * p = new int[100000000];
				cout << n++ << " �Ҵ� ����" << endl;
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
		v.reserve(1000);			//������ �޸𸮸� ���Ƿ� �����ش�.


		// ���Ҵ�� ���� ȭ����µǵ��� ����
		int old = 0;
		for (int i = 0; i < 1000; ++i) {
			v.push_back(i);
		
			if(v.capacity() != old ){
				cout << "������ ����                " << v.size() << endl;
				cout << "Free Store�� Ȯ���� �޸� " << v.data() << endl;
				cout << "���Ҵ���� ���� �� �ִ� �� " << v.capacity() << endl;
				cout << endl;
				old = v.capacity();
			}
		}
		//�ѹ� ���Ҵ� �Ҷ����� �޸𸮸� 1.5�辿 �ø��� ������ �����Ҵ������� ������ ���輺�� �ִ�.
		//(100000���� ���Ƿ� �Ҵ��ص� 100001��° �����͸� ���� 150000 �޸𸮷� ���Ҵ��� �ؾ��Ѵ�.
	}*/

	/*{
		vector<int> v;
		v.reserve(1000);

		*(v.data()) = 333;
		cout << v[0] << endl;
		//�̷������� ���Ƿ� v�� �ڸ��� �����͸� �־��־ v.size()�� 0�̴�. => �ڷᱸ���� Ư��

		for (auto i = v.begin(); i != v.end(); ++i)
			cout << *i << endl;
	}*/

	/*{
		vector<Model> v;

		//Model a { 333 };
		//v.push_back(a);					// ������ a��� �̸��� Model ��ü�� �����ؼ� ���ͷ� �����´�.
		//v.push_back( Model { 333 })		// �̸����� Model ��ü�� �����ؼ� ���ͷ� '�̵�' ��Ų��.
		//v.emplace_back( 333 );			// �������� ���ڸ� �ָ� �˾Ƽ� ��ü�� �������ش�(�̵� x)
	}*/

	{
		// qsort(v.data(), 1000, sizeof(Player), [](const void* a, const void* b) {
		// 	return ((Player*)b)->getHighscore1() - ((Player*)a)->getHighscore1();
		// });

		// sort(v.begin(), v.end(), [](const Player& a, const Player& b) {
		//	return a.getHighscore1() >  b.getHighscore1();					// < : less then operator, ����������
		// });

		// �Ѵ� ���� generic �Լ� �̱� ������. sort�� template�� ����Ǿ� �ִ�.

	}
}