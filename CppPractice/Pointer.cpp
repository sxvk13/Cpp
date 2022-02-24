/*
	Lecture 30~32 : Pointer 
*/
/*
#include <iostream>
using namespace std;

struct _tagStudent {
	int iKor;
	int iEng;
	int imath;
	int iTotal;
	float fAvg;

};

int main() {


	// 포인터 : 가리키다. 일반 변수는 일반적인 값을 저장하게 되지만 포인터 변수는 메모리 주소를 저장함.
	// 모든 변수 타입은 포인터 타입을 선언할 수 있다. int 변수의 주소는 int 포인터 변수에 저장을 해야함.
	// 포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86으로 개발할 때는 무조건 4byte가 나오고,
	// x64일때는 8byte가 나온다. 
	//
	// 포인터는 자기 스스로 아무런일도 할 수 없다. 반드시 다른 변수의 메모리 주소를 가지고 있어야
	// 일을 할 수 있는데 가지고 있는 그 메모리 주소에 접근해서 값을 제어할 수 있다.

	// 형태 : 변수타입 *변수명; 의 형태로 선언
	//		or 변수타입* 변수명;

	int iNumber = 100;

	// 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
	// 변수 앞에 &을 붙여주면 해당 변수의 메모리 주소가 된다.
	// pNum은 iNumber변수의 메모리 주소를 값으로 갖게 됏다. 그러므로 pNum을 이용해서 iNumber의 값을
	// 제어할 수 있게 된 것이다.
	int* pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum을 이용해서 iNumber의 값을 제어해보자.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
	// 역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.

	cout << *pNum << endl;

	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	// 포인터와 배열의 관계 : 배열명은 포인터다. 즉, 배열명 자체가 해당 배열의
	// 메모리에서의 시작점 주소를 의미한다.

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray[0] << endl;

	int* pArray = iArray;
	
	cout << pArray[2] << endl;

	// 포인터 연산 : +, - 연산을 제공한다. ++, -- 도 가능한데 1을 증가하게 되면
	// 단순히 메모리 주소값이 1 증가하는 것이 아니라, int 포인터의 경우 int 타입의 메모리 주소를
	// 갖게 되는데 메모리 주소에 1을 더해주면 1 증가가 아닌 가리키는 해당 포인터 타입의 변수 타입
	// 크기만큼 증가하게 된다. int 포인터이므로 int의 크기인 4만큼 값이 증가하게 되는것이다.

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;


	const char* pText = "Test String";

	// pText[0]='a';
	// pText[1]='b';
	// 와 같은 형식으로 값을 변경하는 것은 불가능. pText가 상수 속성(const)이기 때문임. 

	cout << pText << endl;
	cout << (int*)pText << endl;
	

	//그러나 포인터의 대상을 변경하는 것은 가능
	pText = "abcd";

	cout << pText << endl;
	cout << (int*)pText << endl;

	//동일한 문자열에 대해서는 동일한 주소값을 출력
	pText = "abcd";
	cout << pText << endl;
	cout << (int*)pText << endl;

	//앞이 같더라도 전체적인 문자열이 다르다면 다른 주소값을 할당
	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	
	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// 연산자 우선순위 때문에 .을 먼저 인식하게 된다.
	// 메모리 주소 . 은 잘못된 문법이다. 그러므로 *pStudent를 괄호로 감싸준 후에
	// . 을 이용해서 가리키는 대상의 멤버 변수에 접근해야 한다.
	
	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	// 메모리 주소 -> 을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
	
	pStudent->iKor = 80;

	cout << tStudent.iKor << endl;

	// void : 타입이 없다. void의 포인터 타입을 활용할 수 있다.
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장가능
	// 단, 역참조가 불가능하고 메모리 주소만 저장 가능하다.

	void* pVoid = &iNumber;

	cout << "iNumber Address : " << pVoid << endl;
	// *pVoid = 10; (역참조 불가능)
	//int* pConvert = (int*)pVoid;
	//*pConvert = 10;
	// 또는 *((int*)pVoid) = 9999
	//cout << "iNumber Value : " << iNumber << endl;
	//와 같이 형변환을 해주어야함.


	pVoid = &tStudent;
	cout << "tStudent Address : " << pVoid << endl;

	//이중 포인터 : *을 2개 붙인다. 일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수
	//라면 이중포인터는 포인터의 포인터이다. 즉, 이중 포인터는 포인터 변수의 메모리 주소를
	//저장하는 포인터이다.

	
	int** ppNum = &pNum;

	*pNum = 3333;
	cout << "------------------------" << endl;
	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Addr : " << &iNumber << endl<<endl;
	cout << "*pNum : " << *pNum << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Addr : " << &pNum << endl<<endl;
	
	cout << "*ppNum : " << *ppNum << endl;
	cout << "**ppNum : " << **ppNum << endl;
	cout << "ppNum Value : " << ppNum << endl;
	cout << "ppNum Addr : " << &ppNum << endl;
	



	return 0;
}

*/