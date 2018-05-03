#pragma 
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


void save(void) {
	// main()이 있는 소스파일을 읽어
	// 하드디스크에 덧붙이기 모드로 쓴다.

	ifstream in("소스.cpp");
	ofstream out("2018 1 STL Tuseday.txt", ios::app);

	//출력파일에 시간도 기록한다.
	//auto : 자동으로 자료형을 찾아줌
	auto tp = chrono::system_clock::now();
	auto t = chrono::system_clock::to_time_t(tp);

	out << endl << endl;
	out << endl << endl;
	out << endl << endl;
	out << "----------------------------------------------------------" << endl;
	out << "저장시간 - " << ctime(&t);
	out << "----------------------------------------------------------" << endl;

	out << endl << endl;

	char c;
	while (in.get(c))
		out << c;

}
