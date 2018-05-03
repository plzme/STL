#pragma once
#include <iostream>
using std::cout;
using std::endl;

int global_id = 0;

class Model {
	//null ������ = nullptr
	char* data{ nullptr };			// �����Ҵ��� �޸��� ���۹���			
	size_t size{ 0 };					// �޸�ũ��
	int id;
public:
	Model() : id(++global_id) {																		 	//����Ʈ ������
		cout << id << " - default constructor \t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	Model(int d) : size(d), id(++global_id) {															//���ڸ� �޴� ������
		this->data = new char[size];
		cout << id << " - constructor(int)\t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	Model(const Model& other) : size(other.size), id(++global_id) {										//���������
		this->data = new char[other.size];
		memcpy(this->data, other.data, size);
		//memcpy(����޴� ���, �����ϴ� ���, �޸�ũ��)
		cout << id << " - deep copy constructor\t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	Model(Model&& other) noexcept : size(other.size), id(++global_id) {								 	//�̵�������
		data = other.data;

		//�̵��Ǵ� ������ well-known ���·� ����
		other.size = 0;
		other.data = nullptr;
		cout << id << " - move constructor\t" << this->size << "byte \t\t" << (void*)this->data << endl;
	}

	~Model() {																							//�Ҹ���
		cout << id << " - destructor\t" << this->size << "byte \t\t" << (void*)this->data << endl;
		delete[] this->data;
	}

	Model& operator= (Model&& other) {																	//�̵� �Ҵ� ������(move assignment operator)
		if (data != nullptr)
			delete[] data;

		this->size = other.size;
		this->data = other.data;

		//�̵��Ǵ� ������ well-known ���·� ����
		other.size = 0;
		other.data = nullptr;
		cout << id << " - move operator=\t" << this->size << "byte \t\t" << (void*)this->data << endl;

		return *this;
	}

	Model& operator= (const Model& other) {																//���� ���� ������
		if (this == &other)
			return *this;
		if (data != nullptr)						//�̹� ������� ��ü�� ������ �ϴ� �� �̹Ƿ�, ������ �޸𸮸� �����ϴ°� ������.
			delete[] data;

		this->size = other.size;
		this->data = new char[this->size];
		memcpy(this->data, other.data, size);
		cout << id << " - deep copy operator=\t" << this->size << "byte \t\t" << (void*)this->data << endl;

		return *this;
	}
};