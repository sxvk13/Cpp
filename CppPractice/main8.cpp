/*
20 Lecture (Structure and String Function)
*/

#include <iostream>

using namespace std;

//사이즈는 변수가아닌 상수로 정해줘야 유지보수에 용이하기에 
//define 매크로를 사용하여 상수로 지정
#define NAME_SIZE 32 
#define NO_SIZE 9

// 구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능이다.
// 사용자정의 변수 타입이다.
// 형태 : struct 구조체명 {} : 의 형태로 구성된다.
// 배열과 구조체의 공통점 
//	1. 데이터의 집합.
//  2. 구조체 멤버들은 연속된 메모리 블럭에 할당된다.

struct _tagStudent {
	
	char strName[NAME_SIZE];
	char strNo[NO_SIZE];
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};



int main() {
	//={}으로 초기화 해주지 않으면 쓰레기값이 들어가있음.
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {}; // 52byte *100  =5200byte

	//구조체 멤버에 접근할때는 " . " 을 이용해서 접근하게 된다.

	tStudent.iKor = 100;

	//tStudent.strName = "asdkfasfsd";(불가능)
	// 문자열을 배열에 넣어줄 때에는 단순 대입으로는 불가능하다.
	// strcpy_s 라는 함수를 이용해서 문자열을 복사해 주어야한다.
	// strcpy_s 함수는 오른쪽에 있는 문자열을 왼쪽으로 복사해줌.
	//strcpy_s(tStudent.strName, "가나다라 asdf");

	// 문자열의 끝은 항상 0(NULL)로 끝나야 함. 
	// 따라서 각 배열 요소에 값을 넣어주게 되면 그 값은 출력되나,
	// ex) tStudent.strName[0]= 'a';tStudent.strName[1]= 'b'; 
	// 넣어주지 않은 부분은 문자열의 끝을 인식할 수 없기 때문에 쓰레기값으로 출력이 된다.
	// 각 배열 요소에 값을 넣어 정상적으로 출력하기 위해서는
	// 마지막 요소에 0(NULL)을 넣어주면 된다.
	// ex) tStudent.strName[2]= 0;
	//strcpy_s 함수는 마지막에 자동으로 0을 삽입한다.
	strcpy_s(tStudent.strName, "가나다라 asdf");
	strcpy_s(tStudent.strNo, "20150979");

	//strcat_s 함수는 문자열을 붙여주는 기능이다.
	//오른족에 있는 문자열을 왼쪽에 붙여준다. strName에는 위에서
	//가나다라 asdf 를 저장해 두었기 때문에 이 뒤에 오른쪽 문자열을 붙여서 만들어준다.
	strcat_s(tStudent.strName, " 문자열 붙이기");

	//strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환하고 
	//다른경우 0이 아닌 값을 반환한다.
	strcpy_s(tStudent.strName, "홍길동");

	cout << "비교할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;
	if (strcmp(tStudent.strName, strName) == 0) {
		cout << " 학생을 찾았습니다. " << endl;
	}
	else {
		cout << "찾는 학생이 없습니다. " << endl;
	}


	//strlen 함수는 인자의 길이를 구해준다.
	cout << "이름길이 : " << strlen(tStudent.strName) << endl;
	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.strNo << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	return 0;
}