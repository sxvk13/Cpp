/*
  숫자 빙고 게임

  1~25까지의 숫자가 잇고 이 숫자를 골고루 섞어서 5 x 5로 출력한다.
  플레이어는 숫자를 입력 받는다. 1~25 사이의 숫자를 입력받아야 하며,
  0을 입력하면 게임을 종료한다.
  숫자를 입력받았으면 숫자 목록중 입력받은 숫자를 찾아서 *로 만들어 준다.
  숫자를 *로 만든 후에 빙고 줄 수를 체크한다. 5 x 5이기 때문에 가로 5줄 세로 5줄
  대각선 2줄이 나올 수 있다. 빙고줄이 몇 줄인지 체크해서 화면에 보여준다.
  5줄 이상일 경우 게임을 종료함.

*/
/*
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {
	//숫자 초기화.
	int iNum[25] = {};
	for (int i = 0; i < 25; ++i) {
		iNum[i] = i + 1;
	}
	//숫자 셔플
	srand(unsigned int(time(0)));
	//랜덤 인덱스 변수
	int idx1, idx2;
	int temp;
	for (int i = 0; i < 50; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = iNum[idx1];
		iNum[idx1] = iNum[idx2];
		iNum[idx2] = temp;
	}
	//빙고 시작점
	while (1) {
		system("cls");
		//빙고판 그리기
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				// char '*'은 int 42
				if (iNum[i * 5 + j] == 42) {
					cout << "*\t";
				}
				else {
					cout << iNum[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}
		// 현재 빙고 수 체크
		// 세로줄 체크
		int iBingoCount = 0;
		int iCorrectCount[4] = {};


		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNum[j * 5 + i] == 42) {
					iCorrectCount[0]++;
				}
			}
			if (iCorrectCount[0] == 5) {
				iBingoCount++;
			}
			iCorrectCount[0] = 0;
		}
		//가로줄 체크
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNum[i * 5 + j] == 42) {
					iCorrectCount[1]++;
				}
			}
			if (iCorrectCount[1] == 5) {
				iBingoCount++;
			}
			iCorrectCount[1] = 0;
		}
		//정방향 대각선 체크
		//증감식의 규칙이 6씩 증가함.
		//for(int i= 4;i<=20;i+=6){..} 
		for (int i = 0; i < 5; ++i) {
			if (iNum[i * 5 + i] == 42) {
					iCorrectCount[2]++;	
			}
			if (iCorrectCount[2] == 5) {
				iBingoCount++;
			}
		}

		//역방향 대각선 체크
		//증감식의 규칙이 4씩 증가함
		//for(int i= 4;i<=20;i+=4){..
		for (int i = 0; i < 5; ++i) {
			if (iNum[i * 5 + 4-i] == 42) {
				iCorrectCount[3]++;
			}
			if (iCorrectCount[3] == 5) {
				iBingoCount++;
			}
		}
		cout << endl << endl << "현재 Bingo 수 : " << iBingoCount <<" 줄"<<endl<<endl;
		
		if (iBingoCount > 4) {
			cout << "BINGO!!! 게임을 종료합니다." << endl;
			break;
		}
		
		int input;
		cout << endl << endl << "번호를 입력해 주세요 : ";
		cin >> input;

		//번호 입력 및 빙고판의 입력번호 체크
		//입력받은 값이 있을경우 해당 index의 값을 42(char '*')로 변경
		//번호를 늘리고 싶으면 변경되는 값을 42가 아닌 특정값으로 변경 후
		//해당 값을 찾아 빙고를 체크하면 됨.
		for (int i = 0; i < 25; ++i) {
			if (input == iNum[i]) {
				iNum[i] = '*';
			
			}
		}
		if (input == 0) {
			cout <<endl<< "게임을 종료합니다.";
				break;
		}
	}

	return 0;
}

*/
