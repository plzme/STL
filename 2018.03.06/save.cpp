

//1번
/*class Animal {
public:
	virtual void move() = 0;			//virtual(가상 함수)을 붙이는 이유는 메모리를 소모해서 다형성을 얻기위함이다. 또한 = 0이 붙는 순간 일반 선언으로 객체를 생성할 수 없게 된다.
										//즉, 인터페이스를 강제하는 역할이다.(자식 클래스의 객체를 선언하기 위해서는 반드시 부모의 가상함수를 자식 클래스에서 선언해야 한다)
};

class Dog : public Animal {
public:
	virtual void move() { cout << "개가 달린다" << endl; }
};

class Bird : public Animal {
public:
	virtual void move() { cout << "새가 난다" << endl; }
};

void main() {
	//업캐스팅(개야, 새야 너는 동물이니?), 조상의 포인터를 이용해 명령을 내려야만 다형성이 적용된다.
	Animal* d = new Dog;						
	Animal* b = new Bird;

	d->move();
	b->move();
}*/

//2번
/*
struct를 쓰는경우 : 멤버변수가 전부 public인 경우
class를 쓰는 경우 : 멤버변수에 private가 필요한 경우
*/


//3번
/*void main() {
	int *num = new int{ 100 };			//동적 할당과 동시에 num에 100이라는 초기값을 넣는다

	*num = 200;

	delete num;							//동적할당 된 num을 지운다.
}*/


//4~5번
/*void change(const int& x, const int& y) {				//main에서 넘겨주는 x와 y의 값이 아닌, &(레퍼런스)값을 넘겨 받아야 정상적으로 작동할 수 있다.
	int temp = x;										//Call by value가 아닌 Call by reference가 되어야함
	x = y;												//const : 읽기만해라, &(레퍼런스) : 복사하지마라
	y = temp;
}

void main() {
	int x = 5, y = 10;
	change(x, y);
	cout << x << " " << y << endl;
}*/

//6번
//형식이 다른 x와y, a와b를 같은 change함수로 변환시키려면, change함수를 모든 변수형을 받을 수 있는 template을 사용하여 인자를 받아야 한다.
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

