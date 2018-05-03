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
	cout << "f ���" << endl;

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


	// Ű���忡�� �ԷµǴ� ������ �о� ��հ��� ���϶�
	/*
	{
		vector<int> v;
		copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

		int sum = 0;
		for (int d : v)
			sum += d;

		//�Է��� ���� ctrl + z

		cout << "��հ��� " << (double)sum / v.size() << endl;
	}
	*/

	// Ű���忡�� �ܾ �Է¹޾� �����Ѵ�.
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
		vector<Model> v;							//Dynamic memory�� ���� (physical continuous memory)

		Model a(111);
		Model b(222);

		//���� : ��ü�� ����, �Ҹ�, ���縦 �����غ���.
		v.push_back(a);
		v.push_back(b);
	}*/

	// �Լ� f�� Model�� ��������.
	// �Լ� f�� ȭ�鿡 "f ȣ��"�̶�� ����� ��, ������ ���ڸ� �����Ѵ�.
	// �����ϰ� ������ ����.

	/*{
		Model id(1234);

		Model c_id = f(id);
	}*/

	/*{
		// stack�� �̿��ϴ°� ��������, �Լ� ȣ�� ����, ���ϰ�

		// ���������� ���������� �޸� ���̴� ����.
		vector<Model> v;							

		Model a{ 100 };
		Model b{ 200 };


		//cout << "���ÿ� ������ v �� ���� : " << &v << endl;
		//cout << "���ÿ� ������ a �� ���� : " << &a << endl;
		//���� ���ϸ� �ּҰ� �� 16���� ���̰� ���� => 12�� �ƴ϶� 16�� ������, ��ǻ�Ͱ� �ּҸ� ¦���� ���߱� ���� ���Ƿ� 4����Ʈ�� �о�°� : �����


		cout << "============" << endl;
		v.push_back(a);
		cout << "============" << endl;
		v.push_back(b);
	}*/

	{
		// ����� �ڿ�(Resource)�� �Ҵ��ϴ� Ŭ������ ����ٸ�
		// Ŭ�����ȿ� �ڿ��� ����Ű�� �����Ͱ� �ݵ�� ����� �����Ŵ�.

		// class Res {
		//		Resource* p;
		// }

		// Ŭ������ �̷��� ����ִ� �� ������ �����Ϸ��� ���� �Լ����� �˾Ƽ� �����.
		// class Test {
				// Resource *p
		//		public:
		//		Test() = default;				//RAII idiom
		//		~Test() = default;				
		//		Test(const Test&) = default;	
		//		Test& operator=(const Test&) = default;
		//	};
		
		// ����� �� �Լ� 4�� �߿� �ϳ��� ���α׷����ߴٸ�,
		// �������� �ݵ�� ���α׷��� �ؾ߸� �Ѵ�.
	}
	
	{
		// ���⿡ ���ؼ� ����� ���θ� ���������� �ʴ� ���α׷��Ӷ��
		// �̵������ڿ� �̵��Ҵ翬���ڵ� ���α׷����Ͽ��� ���� �� �� �� �����Ŵ�.

		// auto�� �� �� ������ auto�� ����, ���� �Լ��� �� �� ������ ���� �Լ��� ���
		// ���� ��� for ������ ���� �� ������ ������, ���� i < 1000 ���� �ڵ���������
		
		vector<Model> v;

		v.push_back(Model{ 111 });
		v.push_back(Model{ 222 });

		vector<Model> v2(move(v));

	}
	
	cout << "======================== Main End ========================" << endl;
}


