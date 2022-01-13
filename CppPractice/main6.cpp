/*
* Homework3 (Bingo game) + AI Easy Mode
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
	int iUserNum[25] = {};
	int iAiNum[25] = {};


	//각 숫자판 배열에 숫자 생성
	for (int i = 0; i < 25; ++i) {
		iUserNum[i] = iAiNum[i] = i + 1;
	}

	//빙고판 셔플 및 AI 입력 값 미리 생성
	int iTemp, idx1, idx2;
	for (int i = 0; i <2; ++i) {
		switch (i) {
		case 0:
			//User 빙고판
			for (int j = 0; j < 100; ++j) {
				idx1 = rand() % 25;
				idx2 = rand() % 25;
				iTemp = iUserNum[idx1];
				iUserNum[idx1] = iUserNum[idx2];
				iUserNum[idx2] = iTemp;
			}
			break;
		case 1:
			//AI 빙고판
			for (int j = 0; j < 100; ++j) {
				idx1 = rand() % 25;
				idx2 = rand() % 25;
				iTemp = iAiNum[idx1];
				iAiNum[idx1] = iAiNum[idx2];
				iAiNum[idx2] = iTemp;
			}
			break;
		}
	}
	
	// 유저의 빙고 개수 , AI의 빙고 개수
	// input 변수 ,Ai의 Input 카운트
	int iUserBingo = 0, iAiBingo = 0;
	int Number=0;
	//AI 난이도 선택

	while (true) {
		cout << "1.EASY " << endl;
		cout << "2.HARD " << endl;
		cout << "AI 모드를 선택하세요. : ";
		int iAiMode;
		cin >> iAiMode;
		if (iAiMode >= AM_EASY && iAiMode <= AM_HARD)
			break;
	}
	// AI Easy 모드는 현재 AI의 숫자목록 중 *로 바뀌지 않은 숫자 목록을 만들어서
	// 그 목록중 하나를 선택하게 된다.(랜덤하게)
	// 선택 안된 목록 배열 생성
	int iNoneSelect[25] = {};
	//선택 안된 숫자 개수를 저장
	int iNoneSelectCount = 25;

	while (true) {
		system("cls");
		//빙고판 그리기.
		cout << "==========USER BINGO BOARD==========" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iUserNum[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iUserNum[i * 5 + j] << "\t";
				}
			}
			cout << endl << endl;
		}
		cout <<"==========User Bingo Line  : "<<iUserBingo<<" =========="<< endl << endl;

		cout << endl << "==========AI BINGO BOARD==========" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iAiNum[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iAiNum[i * 5 + j] << "\t";
				}
			}
			cout << endl << endl;
		}
		cout << "==========AI Bingo Line : " << iUserBingo <<" =========="<< endl << endl;


		//게임 승리 조건
		if (iUserBingo >= 5) {
			cout << "USER 승리!" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "AI 승리!" << endl;
			break;
		}


		//USER가 맞출 번호 입력 
		//0 입력시 게임이 종료
		cout << endl<<"번호를 입력하세요 (0입력시 종료) :  ";
		cin >> Number;		
		if (Number == 0) {
			cout <<endl << "게임을 종료합니다!" << endl << endl;
			break;
		}
		//입력한 값이 1~25일때(정상범위)
		else if (Number > 0 || Number < 26) {
			//입력한 값과 빙고판 비교
			//AI의 입력 값에 따른 빙고판 숫자 체크
			for (int i = 0; i < 25; ++i) {
				//일치하면 해당 index의 값을 INT_MAX 로 변경
				if (iUserNum[i] == Number) {
					iUserNum[i] = INT_MAX;
				}
				if (iAiNum[i] == Number) {
					iAiNum[i] = INT_MAX;
				}
			}
		}
	}

	return 0;
}
