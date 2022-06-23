/*
#include <iostream>

using namespace std;

void Test(int** pp) {
	*pp = new int;
}

int main() {
	//int* p =NULL;

	//p = new int ;
	//Test(&p);

	FILE* pFile = NULL;

	//fopen_s의 1번 인자 : 파일의 이중포인터.
	//fopen_s는 call by address <=> fopen 은 call by value 방식
	
	//fopen_s의 2번 인자 : 파일경로이다. 파일이 생성되는 기준 경로는 현재 프로젝트가 있는
	//폴더 기준이다. 만약 실행파일로 실행했을 경우에는 해당 exe 파일이 있는 경로를 기준.
	
	//fopen_s의 3번 인자 : 파일 모드이다. 모드는 크게 2가지로 구분된다.
	//파일 읽기, 쓰기, 접근이 있고 파일 형태, 텍스트파일, 바이너리파일
	//2가지 모드가 있어서 합쳐서 사용한다.
	//r : 읽기,  w : 쓰기, a : 접근			t : 텍스트파일, b : 바이너리 파일
	//======================== 파일 쓰기 ========================
	//fopen_s(&pFile,"hot.txt","wt");
	//
	//
	//
	//if (pFile != NULL) {
	//
	//	// fwrite, fread 2개의 함수가 제공된다.
	//	// fputs, fgets 도 제공됨.

	//	char* pText = new char();
	//	//fwrite의 1번째 인자 : 저장하고자 하는 값의 메모리 주소를 넣어줌.
	//	//fwrite의 2번째 인자 : 저장하고자 하는 값의 변수타입의 메모리 크기를 넣어줌.
	//	//fwrite의 3번째 인자 : 저장하고자 하는 값의 개수를 넣어줌.
	//	//fwrite의 4번째 인자 : 저장할 파일의 스트림을 넣어줌.
	//	
	//	cout << "파일에 작성할 내용을 입력해 주세요." << endl;
	//	
	//	cin >> pText;

	//	fwrite(pText,1,strlen(pText),pFile);

	//	fclose(pFile);

	//	cout << "파일 만들기 성공" << endl;
	//}
	//========================================================================
	//======================== 파일 읽기 ========================
	
	fopen_s(&pFile, "hot.txt", "rt");
	if (pFile) {
		char strText[10] = {};
		cout << "파일에 저장된 내용 : ";
		fread(strText, 1, 10, pFile);
		cout << strText << endl;

		cout << "파일 불러오기 성공" << endl;
	}


	return 0;
}
*/