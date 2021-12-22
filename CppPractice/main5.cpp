#include <iostream>
#include <time.h>


using namespace std;


int main() {

	srand((signed int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i) {
		iNumber[i] = i + 1;
	}

	//가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을
	//사용할건데, INT_MAX라는 값을 사용할 것이다. INT_MAX는 이미 정의되어있는 값으로
	//int로 표현할 수 있는 최대값이다.

	iNumber[24] = INT_MAX;

	// 마지막 칸 공백을 제외하고 1~24까지의 숫자만 섞어준다. 즉 인덱스는 0~23번
	//인덱스까지만 섞어준다.

	int idx1, idx2, iTemp;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	//for (int i = 0; i < 25; ++i) {
	//	if (i % 5 == 0)
	//		cout << endl<<endl;
	//	cout << iNumber[i] << "\t";
	//}
	//cout << endl;
	while (true) {
		system("cls");
		// i for문이 세로줄을 의미
		for (int i = 0; i < 5; ++i) {
			// j for문이 가로줄을 의미
			for (int j = 0; j < 5; ++j) {
				//1차원 배열을 2차원 배열처럼사용
				// 줄번호 * 가로개수 + 칸번호
				// 공백(INT_MAX)을 '*'로 표시
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";

				}
			}
			cout << endl << endl;
		}
		cout << "w : 위  s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 " << endl;
		char key;
		int pos=0;
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == INT_MAX) {
				pos = i;
			}
		}
		cin >> key;
		iTemp = iNumber[pos];
		switch (key) {
		case 'w':
			if (pos >= 5) {
				iNumber[pos] = iNumber[pos - 5];
				iNumber[pos - 5] = iTemp;
			}
			break;
		case 's':
			if (pos <= 19) {
				iNumber[pos] = iNumber[pos + 5];
				iNumber[pos + 5] = iTemp;
			}
			break;
		case 'a':
			if (pos > 0) {
				iNumber[pos] = iNumber[pos-1];
				iNumber[pos - 1] = iTemp;
			}
			break;
		case 'd':
			if (pos < 24) {
				iNumber[pos] = iNumber[pos + 1];
				iNumber[pos + 1] = iTemp;
			}
			break;
		case 'q':
			cout << "게임을 종료합니다."<<endl;
			exit(0);
		default:
			cout<<"잘못된 키 입력입니다."<<endl;
		}
	}
	

	return 0;
}