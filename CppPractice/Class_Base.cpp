/*
	Lecture 56 Class Base ~ Lecture 57 Constructor, Destructor
*/

#include <iostream>

using namespace std;

//int main() {
//
//	//레퍼런스 : 다른 대상을 참조하게 만들어주는 기능이다.
//	//참조를 하게 되면 그 대상에 접근하여 값을 변경할 수 있다.
//	//단, 레퍼런스는 처음 레퍼런스 변수 생성시 참조하는 대상을 지정해
//	//주어야 한다.
//	//형식은 [변수타입 &레퍼런스명 = 참조할 변수명;] 으로 한다.
//
//	int iNumber = 100;
//	int iNumber1 = 9999;
//	//iRefNum 래퍼런스 변수는 iNumber를 참조한다.
//	int& iRefNum = iNumber;
//
//	iRefNum = 1234;
//
//	iRefNum = iNumber1;
//
//	cout << iNumber << endl;
//	return 0;
//}

// 객체(Object) : 모든 사물을 의미함 c++에서 객체를 의미하는 것은 각 변수들도
// 객체로 취급할 수도 있다. 하지만 객체지향 프로그래밍을 지원하기 위해 제공되는 수단
// 은 class이다. class가 객체인 것이 아니고 class는 객체를 만들기 위한 틀이다.
// 객체지향 프로그래밍(OOP) : 객체들의 관계를 설정해주어 부품을 조립하듯이
// 객체들을 조립하여 완성된 프로그램을 만들어나가는 방식이다.

// 클래스 선언 방법 : class 클래스명 {}; 의 형태로 선언.
// 코드블럭안에 멤버변수를 넣어줄 수 있다. 단, 함수도 멤버로 만들 수 있다.

// 클래스의 4가지 속성
// 캡슐화: 클래스 안에 속하는 여러변수 혹은 함수를 하나의 클래스로 묶어주는 기능
// 은닉화: 클래스 안에 속하는 변수 혹은 함수를 내가 원하는 부분만 외부에 공개하고
// 외부에 공개하지 않을 수 있다.
//	-public: 클래스 내부와 외부에서 모두 접근 가능한 방법.
//  -protected: 클래스 외부에서는 접근이 불가능하고 자기자신 내부, 자식클래스 내부
//				에서는 접근이 가능한 방법. 
//	-private: 자기자신 내부에서만 접근이 가능하고 외부나 자식 내부에서는 접근이 불가.
// 상속성: 클래스는 클래스와 클래스간에 부모, 자식 관계를 형성할 수 있다.
// 자식 클래스는 부모클래스의 멤버를 물려받아 자신의 것처럼 사용할 수 있다.
// 단, private으로 되어있는 멤버에는 접근이 불가능하다.
// 다형성: 부모 자식관계로 상속관계가 형성되어 있는 클래스간에 서로 형변환이 가능한 성질

// 생성자와 소멸자
// 생성자 : 어떤 클래스를 이용해서 객체를 생성할때 자동으로 호출되는
// 함수이다. 객체 생성시 호출되는 함수이기 때문에 객체의 멤버변수를 초기화 할 때
// 유용하게 사용할 수 있다.
// 생성자를 만들어주지 않을 경우 내부적으로 기본 생성자가 제공이 되어서 기본 생성자
// 를 자동으로 호출해주게 된다.
// 
// 클래스명()
// {
// 
// }
// 의 형태로 선언됨.
// 
// 소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해제될 때 자동으로 호출되는
// 함수이다. 객체를 사용하고 난 뒤 마무리 작업을 해줄때 유용하게 사용할 수 있다.
// 
// ~클래스명()
// {
// 
// }
// 의 형태로 선언된다.
//

class CTracer {
	//클래스 멤버변수를 선언할때는 m_를 붙여준다.(알아서 구분되게 붙이면됨)
	char m_strName[32];

public:
	//생성자
	CTracer() {
		cout << "Tracer 생성자" << endl;
		strcpy_s(m_strName, "트레이서");
	}
	CTracer(const char* pName) {
		cout << "Name 생성자" << endl;
		strcpy_s(m_strName, pName);
	}
	//해당 생성자 방식은 선언 후 초기화 하는 방식과 같음.
	//CTracer(const char* pName, int iFlash, int iBack) {
	//	strcpy_s(m_strName, pName);
	//	m_iFlash = iFlash;
	//	m_iBack = iBack;
	//}
	
	// Initializer로 생성과 동시에 초기화 하는 방식
	CTracer(const char* pName, int iFlash, int iBack) :
		m_iBack(iBack),
		m_iFlash(iFlash) {
		cout << "Name, Flash , Back 생성자 " << endl;
		strcpy_s(m_strName, pName);
	}

	//소멸자
	~CTracer() {
		cout << "Tracer 소멸자" << endl;
	}

public: //public 키워드 아래에 있는 멤버는 모두 외부에서 접근이 가능하다.

	int m_iAttack;
	int m_iHp;
	
private:
	int m_iFlash;
private:
	int m_iBack;

public:
	void Output() {
		cout << "Tracer Output" << endl;
		cout << "Name : " << m_strName<<endl;
	}
};

int main() {

	
	//기본 생성자 호출 -> CTracer tr1;
	//매개변수를 갖고 있는 생성자 호출 
	CTracer tr1("한조");
	// 클래스의 생성과 동시에 생성자 호출

	//main()함수 안은 클래스 외부이기 때문에 public으로 설정되어 있는 멤버에만 접근 가능
	
	tr1.Output();
	
	// 소멸자 자동호출

	return 0;
}