/*
#include <iostream>
#include <time.h>

using namespace std;

int iArr[3] = {};
void init();
void play();
int* check(int x[]);
int main() {
//숙제 : 야구게임 만들기
//1~9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
//3개의 숫자는 * * * 의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
//사용자는 이 3개의 숫자를 맞출때까지 계속해서 3개씩 숫자를 입력한다.
//만약 맞춰야할 숫자가 7 3 8 일 경우
//사용자는 3개의 숫자를 계속 입력한다.
//-입력 : 1 2 4 를 입력했을 경우 1 2 4는 맞춰야할 숫자중 아무것도 없으므로
//Out을 출력한다.
//-입력 : 7 5 9 를 입력했을 경우 7은 맞춰야할 숫자중 있고 위치도 같으므로
//strike이다.  5 9는 없으므로 출력은 1 strike 0 ball을 출력한다.
//-입력 : 7 8 6 을 입력했을 경우 7은 1 strike, 8은 숫자는 있지만 위치가 다르므로
//ball이 된다. 따라서 출력은 1 strike 1 ball을 출력한다.
//
//이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게
//입력하면 게임이 종료된다. 만약, 입력받은 숫자 3개중 한개라도 0 이있을 경우 게임을
//종료한다.
	
	//초기 설정
	init();
	play();
	return 0;
}

//초기 설정 함수
void init() {
	int iNumber[9];

	srand((unsigned int)time(0));
	// 1~9까지의 숫자
	for (int i = 0; i < 9; ++i) {
		iNumber[i] = i + 1;
	}
	// 숫자 셔플
	int idx1, idx2, itmp;
	for (int i = 0; i < 100; ++i) {
		//랜덤 인덱스 값 
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		//swap
		itmp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = itmp;
	}
	//맞출 숫자 설정
	for (int i = 0; i < 3; ++i) {
		iArr[i] = iNumber[i];
	}
	cout << "--------------AI 번호 설정 완료 !--------------" << endl;
	cout << endl;
	cout << "\t\t설정된 번호 : * * *" << endl<<endl;
}
// 게임 시작
void play() {

	int iNum[3];
	int* iCheck;
	//사용자의 번호 입력
	while (true) {
		for (int i = 0; i < 3; ++i) {
			cout << i + 1 << " 번째 번호를 입력하세요 : ";
			cin >> iNum[i];
			//0 입력시 더이상 입력받지 않음
			if (iNum[i] == 0)
				break;
			cout << endl;
		}
		//입력된 값이 0인경우 종료
		if (iNum[0] == 0 || iNum[1] == 0 || iNum[2] == 0) {
			cout << endl << "--------------게임을 종료합니다--------------" << endl;
			break;
		}
		// 각 번호 일치 확인
		iCheck = check(iNum);
		if (iCheck[2] == 1) {
			cout << "***** OUT!! ***** " << endl << endl;
		}
		else if (iCheck[0] == 3) {
			cout << "***** 정답입니다 !!! *****" << endl << endl;
			cout << " AI의 숫자 : " << iArr[0] << " " << iArr[1] << " " << iArr[2] << " " << endl << endl;
			break;
		}
		else {
			cout << "***** " << iCheck[0] << " Strike " << iCheck[1] << " Ball !! *****" << endl << endl;
		}
	}	
}
// 번호 일치 확인 
int* check(int x[]) {
	int iStrikeCount = 0;
	int iBallCount = 0;
	int iOutCount = 0;
	
	// 모든 카운터를 반환해야 하기 때문에
	// 배열의 주소를 통해 전달.
	// 단 result의 변수가 지역변수 이기 떄문에 값(주소)이 유지되지 않음.
	// 따라서 static을 통해 정적변수로 설정하여 함수가 종료되어도
	// 값(주소)이 유지되도록 메모리에 씀.
	//실제로 check 함수에 진입할때마다 동일한 주소를 사용함을 확인할 수 있음.
	static int result[4];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (iArr[i] == x[j]) {
				if (i == j) {
					iStrikeCount++;
				}
				else {
					iBallCount++;
				}
			}
		}
	}
	if ((iStrikeCount == 0 && iBallCount == 0)) {
		iOutCount = 1;
	}
	result[0] = iStrikeCount;
	result[1] = iBallCount;
	result[2] = iOutCount;
	result[3] = '\0';

	return result;
}
*/