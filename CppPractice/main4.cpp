/*

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	// do while 문
	// 형태 : do {..}while(조건식) 의 형태
	// while뭉는 처음 진입부터 조건식을 체크하지만 do while은 처음 한번은 무조건 동작
	// 그 후에 조건식을 체크해서 true일 경우 동작하는 반복문

	int iNumber = 0;

	do {
		cout << iNumber << endl;
	} while (iNumber > 0);

	
	//배열
	//여러개의 변수를 한번에 생성해줄 수 있는 기능
	//형태 : 변수타입 배열명[개수] 의 형태로 선언
	//특징 : 연속된 메모리 블럭에 공간이 할당됨.
	//		-배열은 인덱스를 이용해서 원하는 부분에 접근하여 값을 지정.
	//		-인덱스는 0부터 개수-1 까지임. (10이라면 0~9까지 총 10개의 인덱스)
	//		-배열 뿐만 아니라 일반 변수들도 선언을 하고 값을 초기화 하지 않으면
	//			쓰레기 값이 들어감.
	
	//int iArray[10]; -> int type 변수 10 개 -> 4byte(int형 크기) * 10 = 40byte 
	//int iArray[10] = {1,2,3,4,5,6,7,8,9,10 }; -> 선언과 동시에 초기화
	//int iArray[10] = {1,2,3,4,5} -> 0~4 번까지는 1~5로 초기화 하고 나머지는 0으로 초기화
	int iArray[10] = {};// 비어있는 중괄호를 대입할 경우 모든 인덱스를 0으로 초기화

	iArray[1] = 1234;
	for (int i = 0; i < 10; ++i) {
		cout << iArray[i] << endl;
	}

	// 배열 개수를 2개 지정하면 2차원 배열, 3개지정 하면 3차원 배열 n개 지정하면 n차원 배열이 된다.
	// 2차원 배열의 개수는 앞의 수 * 뒤의 수 만큼 처리가 된다
	int iArray2[10][10] = { {1,2,3},{4,5,6} }; // 선언과 동시에 초기화 10 * 10 개의 배열 생성 

	//2차원 배열의 경우 중첩반복문을 사용해서 출력

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << iArray2[i][j] << "\t";
		}
		cout << endl;
	 }
	


	system("cls");
	//Lotto Program

	int iLotto[45] = {};
	int iRn;
	srand((unsigned int) time(0));;
	int i = 0;

	for(int i=0;i<45;++i){
		iLotto[i]= i+ 1;	
	}

	while(true){
		if (i == 6)
			break;

		iRn = rand() % 45 + 1;
		for (int j = 0; j < 45; ++j) {
			if ((iLotto[j] != 0) && (iRn == iLotto[j])) {
				cout << iLotto[j] << " ";
				iLotto[j] = 0;
				++i;
				break;
			}
		}
	}
	cout << endl;
	system("cls");
	cout << endl;


	//풀이

	//1~45까지의 숫자를 차례대로 넣어줌.

	for (int i = 0; i < 45; i++) {
		iLotto[i] = i + 1;
	}
	//Swap 알고리즘
	//int iNum1 =1, iNum2=2,  iNum3;
	//iNum3=iNum1;
	//iNum1=iNum2;
	//iNUM2=iNum3;


	//Shuffle - TCG게임에서 많이 사용
	//Shuffle은 Swap알고리즘을 사용
	int iTemp, idx1, idx2;
	//100번정도 골고루 섞어줌.
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 45; //0~44 번째 위치를 얻음
		idx2 = rand() % 45; 

		//위치 변경
		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}	
	for (int i = 0; i < 6; i++) {
		cout << iLotto[i]<<" " ;
	}
	cout << "보너스 번호 : " << iLotto[6];
	return 0;
}

*/