/*
* Homework3 (Bingo game)(Lecture Code) + AI Easy Mode
*/
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

enum AI_MODE {
	AM_EASY,
	AM_HARD
};

int main() {
	// 랜덤 값을 생성하기 위한 srand 
	srand((unsigned int)time(0));

	// 빙고 숫자판을 위한 배열
	int iNumber[25] = {}; //Player
	int iAINumber[25] = {}; // AI

	// 배열에 1~25 까지 숫자 생성
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = iAINumber[i] = i + 1;
	}

	//빙고판 셔플 
	int iTemp, idx1, idx2;
	for (int j = 0; j < 100; ++j) {
		//User 빙고판
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

		//AI 빙고판
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	// 유저의 빙고 개수 , AI의 빙고 개수
	// input 변수 ,Ai의 Input 카운트
	int iBingo = 0, iAiBingo = 0;

	int iAiMode;
	//AI 난이도 선택

	while (true) {
		cout << "1.EASY " << endl;
		cout << "2.HARD " << endl;
		cout << "AI 모드를 선택하세요. : ";

		cin >> iAiMode;
		if (iAiMode >= AM_EASY && iAiMode <= AM_HARD)
			break;
	}
	// AI Easy 모드는 현재 AI의 숫자목록 중 *로 바뀌지 않은 숫자 목록을 만들어서
	// 그 목록중 하나를 선택하게 된다.(랜덤하게)
	// 선택 안된 목록 배열 생성
	int iNoneSelect[25] = {};
	//선택 안된 숫자 개수를 저장
	int iNoneSelectCount = 0;


	while (true) {
		system("cls");
		//Player 빙고판 그리기.
		cout << "==========Player BINGO BOARD==========" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}
			}
			cout << endl << endl;
		}
		cout << "==========User Bingo Line  : " << iBingo << " ==========" << endl << endl;
		//AI 빙고판 출력
		cout << endl << "==========AI BINGO BOARD==========" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iAINumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iAINumber[i * 5 + j] << "\t";
				}
			}
			cout << endl << endl;
		}
		cout << "==========AI Bingo Line : " << iAiBingo << " ==========" << endl << endl;


		//게임 승리 조건
		if (iBingo >= 5) {
			cout << "USER 승리!" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "AI 승리!" << endl;
			break;
		}

		cout << "숫자를 입력하세요 (0 : 종료) : ";
		int iInput;
		cin >> iInput;
		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25)
			continue;

		// 중복입력을 체크하기 위한 변수로 기본적으로 중복되었다라고 하기위해 True 로설정.
		bool bAcc = true;
		// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지 확인.
		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {
				//숫자를 찾았을 경우 중복된 숫자가 아니므로
				// bAcc 변수를 false로 만들어준다.
				bAcc = false;
				//숫자를 *로 변경하기 위해 특수 값인INT_MAX 로 변경
				iNumber[i] = INT_MAX;
				//더이상 다른 숫자를 찾을 필요가 없으므로 반복문 탈출
				break;
			}
		}
		//bAcc변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 
		//바꾸지 못했으므로 다시 입력받도록 continue 해준다.
		if (bAcc)
			continue;

		//중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iInput == iAINumber[i]) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		
		//빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때마다 처음부터
		//새로 카운트를 할 것이다. 그러므로 iBingo 변수를 0 으로 매번 초기화 하고
		//새롭게 줄 수를 구해주도록 한다.
		iBingo = 0;
	}
		return 0;
}

