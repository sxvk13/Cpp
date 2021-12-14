﻿/*
// #include : Header File을 포함시키는 기능임.
// <iostream> : 표준 I/O 에 대한 Header File

// 실행 과정 : 컴파일 -> 빌드 -> 실행
// 컴파일 : 고수준언어(c언어,c++등...) -> 저수준언어(기계어)로 변환해 주는 작업.

#include <iostream>

using namespace std;

//C++의 시작점. main 함수는 반드시 있어야 함.
int main(){
	//C++ 표준 기능의 대부분은 std라는 namespace 안에 존재함.
	//이름이 겹치는 것을 방지해 주기 위함.
	// cout : 콘솔창에 출력해주는 기능. 
	// " "(큰따옴표) 안에 있는 문자들을 화면에 출력함.
	// 문자여러개를 출력하기 위해서는 반드시 ""안에 넣어야 함. (문자열)
	//endl : 개행 기능.
	// 코드는 보편적으로 오른쪽 -> 왼쪽 

	std::cout << "Test Output" << std::endl;

	cout << "std namespace 사용 " << endl;
	

	*****************************************
		변수 : 변하는 수. 즉, 값이 바뀔 수 있다.
		
		false:0
		true :0이 아닌 모든 수 

		종류	|	용량	|	데이터	|	표현범위		|	unsigned	|
		cahr	|	1byte	|	문자	|	-128~127		|	0~255		|
		bool	|	1byte	|	참/거짓	|	true/false		|	true/false	|
		short	|	2byte	|	정수	|	-32768~32767	|	0~65535		|
		int		|	4byte	|	정수	|	약-22억~21억	|	0~약 43억	|
		float	|	4byte	|	실수	|	
		double	|	8byte	|	실수	|

	*****************************************

	//[변수 타입] [변수이름]
	//변수 이름 : 언더바(_) 외에 특수 기호는 올 수 없음. (숫자 불가능)
	// 목적에 맞는 이름을 부여하는 것이 좋음.
	// ' = ' :대입연산자.
	int Number = 10;

	cout << "After Number is : " << Number << endl<<endl;

	Number = 20;

	cout << "Before Number is :"<< Number << endl;

	//float 변수에는 'f' 를 붙여준다.
	float fNumber = 3.14f;

	***********************************************
		사칙연산자 : +, -, *, /, %(나머지 연산자);
		관계연산자 : 값 : 값을 연산하여 참/거짓으로 결과를 반환
			- 종류 : >, >=, <, <=, ==, !=
		논리연산자 : 참 / 거짓 대 참 / 거짓을 연산하여 참/거짓으로 반환함.
			- 종류 : AND(&&), OR(||), NOT(!)
			**AND -> 둘 다 참
			**OR -> 둘중 하나만 참이어도 참.
			**NOT -> 논리값을 반대로.	
			
		진수 : 2진수, 8진수, 10진수, 16진수,
			* 2진수 : 0~1로 값 표현
			* 8진수 : 0~7로 값 표현
			* 16진수 : 0~F로 값 표현  (0~9 :숫자 , 10~15 : a~f)
			**진수들은 서로 다른 진수로 변환이 가능함.
		비트단위 논리연산자 : 2진수 단위의 연산을 진행함. 값 : 값 으로 연산하여 값을 반환.
			-종류 : AND(&), OR(|), NOT(~), XOR(^)
			***XOR -> 서로 같으면 거짓, 서로 다르면 참
	*************************************************

	cout << "10 < 20 = " << (10 < 20) << endl;

//	cout << "숫자를 입력하세요 : ";
//	cin >> Number;
//	cout << (10 <= Number && Number <= 20) << endl;


	cout << "40 & 35 = " << (40 & 35) << endl;
	cout << "40 | 35 = " << (40 | 35) << endl;
	cout << "~40 & 35 = " << (~40 & 35) << endl;
	cout << "40 ^ 35 = " << (40 ^ 35) << endl;

	return 0;
}
*/