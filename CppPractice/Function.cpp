#include <iostream>

using namespace std;

// 함수 : 기능을 만들어 줌.
// 일종의 사용할 수 있는 부품을 만들어 준다고 볼 수 있다.
// 특정 상황에 동작하는 코드 집합을 만들어 내는 것이다.
//	
// 형태: 반환타입 함수명(인자) {} 의 형태로 구성이 된다.
// 반환타입 : 이 함수가 기능을 수행하고 기능의 결과를 반환 해야 할 경우 지정한다.
// 정수를 반환할 때는 정수타입, 실수를 반환할 때는 실수 타입을 지정한다.
// 함수명 : 함수의 이름을 의미한다. 함수명은 가급적이면 이 함수가 하는 역할을
//	정확하게 표시해 주는 것이 코드 가독성에 좋다
// 인자 : 해당 함수를 사용할 때 넘겨줄 값이 있을경우 인자를 활용한다. 인자는 있을수도 없을수도 있다.

// 해당 함수를 호출하면 코드블럭 안의 코드가 동작이 된다.

int Sum(int a, int b) {
	

	//return 키워드를 이용해서 이 함수의 반환타입에 맞는 값을 반환해야한다.

	return a + b;
}

// 함수는 단순히 만들어 놓기만 해서는 아무런 동작도 하지 않는다. 함수의 기능을
// 동작시키기 위해서는 반드시 main 함수 안에서 해당 함수를 호출해 주어야 한다.

void OutputText() {
	cout << "OutputText Function!" << endl;
 }
void OutputNumber(int iNumber) {
	cout << "Number : " << iNumber << endl;
}

void ChangeNumber(int iNumber) {
	iNumber = 9999;
}



int main() {
	
	// 함수를 호출할때는 함수명(인자로 넘겨줄 값); 의 형태로 호출을 하게 된다.
	// 아래처럼 호출하면 a에 10, b에 20이 전달되어 두 값을 더한 30이 반환됨.

	cout << Sum(10, 20) << endl;
	cout << Sum(102, 304) << endl;

	OutputText();
	OutputNumber(1234);
	

	return 0;

}