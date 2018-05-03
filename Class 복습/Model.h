#pragma once
#include <iostream>
using std::cout;
using std::endl;

int global_id = 0;

class Model {
	//null 포인터 = nullptr
	char* data{ nullptr };			// 동적할당한 메모리의 시작번지			
	size_t size{ 0 };					// 메모리크기
	int id;
public:
	Model() : id(++global_id) {																		 	//디폴트 생성자
		cout << id << " - default constructor \t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	Model(int d) : size(d), id(++global_id) {															//인자를 받는 생성자
		this->data = new char[size];
		cout << id << " - constructor(int)\t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	Model(const Model& other) : size(other.size), id(++global_id) {										//복사생성자
		this->data = new char[other.size];
		memcpy(this->data, other.data, size);
		//memcpy(복사받는 대상, 복사하는 대상, 메모리크기)
		cout << id << " - deep copy constructor\t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	Model(Model&& other) noexcept : size(other.size), id(++global_id) {								 	//이동생성자
		data = other.data;

		//이동되는 원본은 well-known 상태로 정리
		other.size = 0;
		other.data = nullptr;
		cout << id << " - move constructor\t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	~Model() {																							//소멸자
		cout << id << " - destructor\t" << this->size << "byte \t\t" << (void*)this->data << endl;
		delete[] this->data;
	}

	Model& operator= (Model&& other) {																	//이동 할당 연산자(move assignment operator)
		if (data != nullptr)
			delete[] data;

		this->size = other.size;
		this->data = other.data;

		//이동되는 원본은 well-known 상태로 정리
		other.size = 0;
		other.data = nullptr;
		cout << id << " - move operator=\t" << this->size << "byte \t\t" << (void*)this->data << endl;

		return *this;
	}

	Model& operator= (const Model& other) {																//복사 대입 연산자
		if (this == &other)
			return *this;
		if (data != nullptr)						//이미 만들어진 객체에 대입을 하는 것 이므로, 기존의 메모리를 해제하는게 먼저다.
			delete[] data;

		this->size = other.size;
		this->data = new char[this->size];
		memcpy(this->data, other.data, size);
		cout << id << " - deep copy operator=\t" << this->size << "byte \t\t" << (void*)this->data << endl;

		return *this;
	}
};