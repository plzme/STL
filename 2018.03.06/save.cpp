

//1��
/*class Animal {
public:
	virtual void move() = 0;			//virtual(���� �Լ�)�� ���̴� ������ �޸𸮸� �Ҹ��ؼ� �������� ��������̴�. ���� = 0�� �ٴ� ���� �Ϲ� �������� ��ü�� ������ �� ���� �ȴ�.
										//��, �������̽��� �����ϴ� �����̴�.(�ڽ� Ŭ������ ��ü�� �����ϱ� ���ؼ��� �ݵ�� �θ��� �����Լ��� �ڽ� Ŭ�������� �����ؾ� �Ѵ�)
};

class Dog : public Animal {
public:
	virtual void move() { cout << "���� �޸���" << endl; }
};

class Bird : public Animal {
public:
	virtual void move() { cout << "���� ����" << endl; }
};

void main() {
	//��ĳ����(����, ���� �ʴ� �����̴�?), ������ �����͸� �̿��� ����� �����߸� �������� ����ȴ�.
	Animal* d = new Dog;						
	Animal* b = new Bird;

	d->move();
	b->move();
}*/

//2��
/*
struct�� ���°�� : ��������� ���� public�� ���
class�� ���� ��� : ��������� private�� �ʿ��� ���
*/


//3��
/*void main() {
	int *num = new int{ 100 };			//���� �Ҵ�� ���ÿ� num�� 100�̶�� �ʱⰪ�� �ִ´�

	*num = 200;

	delete num;							//�����Ҵ� �� num�� �����.
}*/


//4~5��
/*void change(const int& x, const int& y) {				//main���� �Ѱ��ִ� x�� y�� ���� �ƴ�, &(���۷���)���� �Ѱ� �޾ƾ� ���������� �۵��� �� �ִ�.
	int temp = x;										//Call by value�� �ƴ� Call by reference�� �Ǿ����
	x = y;												//const : �б⸸�ض�, &(���۷���) : ������������
	y = temp;
}

void main() {
	int x = 5, y = 10;
	change(x, y);
	cout << x << " " << y << endl;
}*/

//6��
//������ �ٸ� x��y, a��b�� ���� change�Լ��� ��ȯ��Ű����, change�Լ��� ��� �������� ���� �� �ִ� template�� ����Ͽ� ���ڸ� �޾ƾ� �Ѵ�.
/*template <class T>
void change(T& x, T& y) {				
	T temp = x;										
	x = y;												
	y = temp;
}

void main() {
	int x = 5, y = 10;
	change(x, y);

	char a = 5, b = 10;
	change(x, y);

	cout << x << " " << y << endl;
}*/

