#pragma 
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


void save(void) {
	// main()�� �ִ� �ҽ������� �о�
	// �ϵ��ũ�� �����̱� ���� ����.

	ifstream in("�ҽ�.cpp");
	ofstream out("2018 1 STL Tuseday.txt", ios::app);

	//������Ͽ� �ð��� ����Ѵ�.
	//auto : �ڵ����� �ڷ����� ã����
	auto tp = chrono::system_clock::now();
	auto t = chrono::system_clock::to_time_t(tp);

	out << endl << endl;
	out << endl << endl;
	out << endl << endl;
	out << "----------------------------------------------------------" << endl;
	out << "����ð� - " << ctime(&t);
	out << "----------------------------------------------------------" << endl;

	out << endl << endl;

	char c;
	while (in.get(c))
		out << c;

}
