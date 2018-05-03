//-----------------------------------------------------------------------------------------
// 5�� ���������̳� (associative container)
//		set		- key �������� ����
//		map		- key/value pair�� ����
//		unordered_set / unordered_map	- key�� hashing �Ͽ� ������ ���� ����
//
//		key, value : ������ ����� �Ǵ� ������
//		hasing : key�� �߰� �ɰ���.
//
//			=> ������ ����? : ���� ã�� ����
//			���� ���� ã�� �����̳� : unordered_set, ��� �ð��� �ɸ���. = �޸𸮸� ����� �ӵ��� ��´�.
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

// ǥ��������� ����Լ��� operator�� ����� �� ���� ������, �����Լ��� ¥�ش�.
// �� �ܿ��� ����Լ��� ¥�ش�.
/*bool operator< (const Model& lhs, const Model& rhs) {
	return lhs.getsize() < rhs.getsize();
}*/

void main() {
	/*{
		set<int> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		// �����ϴ� �����̳ʴ� '��ġ�� ������ ��'�� ���� ������ push_back ���� ��ġ ����� ������ �Ұ����ϴ�.
		//s.push_back( 100 );

		s.insert(-1);
	}*/


	{
		// set�� �ڽŸ��� �������� ���ҵ��� �����ϴ� �����̳��̴�.
		// ������ default <(less then) �����ڸ� ����Ѵ�.
		// POD(Plain Old Data type)�� ��� < �����ڰ� ���ǵǾ� �ִ�.
		
		// ����ڰ� ������ �ڷ����� set�� ��������
		// 1. < �����ڸ� �����ε��Ѵ�.
		// 2. ���� �� �Ҵ� �Լ���ü�� �����Ѵ�.

	}

	/*{
		//set<Model> s{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };			// �̷������� �� ���, ��ü�� ���� set�� �־��ִ°� �ȴ�.(���� ����)

		set<Model> s;												// set�� ������ ��ü�� ����� emplace�� ����� ���� ������ ���� �ʵ��� �Ѵ�.

		s.emplace(1);		s.emplace(3);		s.emplace(5);
		s.emplace(7);		s.emplace(9);		s.emplace(2);
		s.emplace(4);		s.emplace(6);		s.emplace(8);
		s.emplace(10);

		cout << "------------------------------------------------------" << endl;
		for (const Model& d : s)					// s�� ���Ҵ� key���̱� ������, ������ �״�� �������� &�� �ٿ� ������ �� ����. 
			d.show();								// �׷��Ƿ� ������ �ǵ帮�� �ʰڴٴ� const�� �ٿ��ش�.
		cout << "------------------------------------------------------" << endl;
		

		// const &�� ����ġ��, �ʿ���� ��������� ���ƾ� �Ѵٸ� �ݵ�� �ٿ��ش�.
	}*/

	// Ű���忡�� �ܾ �о� ������ �� ����϶�.
	// ver. vector
	/*{
		vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() };

		// istream_iterator<string>(cin) : Ű���忡�� string ������ �����´�. 
		// �Ʒ� �� �ؼ� : Ű���忡�� string������ �Է��� ctrl+z�Ҷ����� �޾Ƽ� v�� �־��ش�.
		//copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));
		// ������, ���ʹ� ������ ���� �� �ֱ� ������, ���� copy�� �����ʰ�, ���͸� �����Ҷ� ������
		// istream_iterator<string>(cin), istream_iterator<string>()�� �־ �ȴ�.

		sort(v.begin(), v.end());

		for (const string& d : v)
			cout << d << '\t';
		cout << endl;
	}*/

	// Ű���忡�� �ܾ �о� ������ �� ����϶�.
	// ver. set
	/*{
		set<string> s{ istream_iterator<string>(cin), istream_iterator<string>() };
		for (const string d& : s)
			cout << d << '\t';
		cout << endl;

		// ���� : �ߺ������� �����ʴ´�.

		//�׷� ��� ?
	}*/

	// Ű���忡�� �ܾ �о� ������ �� ����϶�.
	// ver. multiset
	/*{
		multiset<string> s{ istream_iterator<string>(cin), istream_iterator<string>() };
		//multiset<string, greater<string>> s{ istream_iterator<string>(cin), istream_iterator<string>() };		// �������� ����

		for (const string& d : s)
			cout << d << '\t';
		cout << endl;
	}*/


	/*{
		// map�� pair<key, value>�� ���ҷ� ���´�.
		// map<key, value, ���Ĺ��(default : less<stirng>)> m;

		// "����", 400000000
		// "Ǫ��", 200000
		// "���", 300000000
		// "��", 700000000
		map<string, int> m;

		m.insert(pair<string, int>("����", 400000000));
		m.insert(make_pair("Ǫ��", 200000));
		// map�� �����迭(associative array)ó�� ����� ���� �ִ�.
		// x["�̸�"] = 100; : �̸��� ���� 100���� �ٲ��
		m["���"] = 300000000;				// ���� ����
		m["���"] = 300000003;				// ������ �� ����				//== m.operator[]("���") = 300000003;

		for (auto& d : m)									// <= const pair<string, int>�� auto�� �ڵ����� ����ش�.
			cout << d.first << "----" << d.second << endl;
	}*/

	/*{
		// ���� v�� �� ���ĺ��� ����ü �� ���̳� �����ϴ��� ���� ����϶�

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
		// �ҽ��ѷ�.cpp�� �� ���ĺ��� ����ü �� ���̳� �����ϴ��� ���� ����϶�
		map<char, int> m;

		ifstream in("�ҽ��ѷ�.cpp");

		char c;
		while (in >> c) {
			if ( isalpha(c))
				m[c]++;
		}
		for (auto& d : m)
			cout << "[" << d.first << "] : " << d.second << endl;

		// �����Ҽ����� ���� ���� ������ ���ĺ��� ����?
		// a�� �� �� ���Դ�?
	}

}