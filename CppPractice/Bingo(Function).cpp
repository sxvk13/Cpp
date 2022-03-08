/*
* Bingo game(Lecture Code) + AI Hard Mode + Function
* 
*/
/*
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

enum AI_MODE {

	AM_EASY = 1,
	AM_HARD = 2
};


enum LINE_NUMBER {
	//LN_Hx : Horizontal Line Number
	//LN_Vx : Verticla Line Number
	//LN_LT,RT : Left Top , Right Top Number
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};


//�Լ��� ��������� �κ����� ���� �� �ִ�.
//(����)
void SetNumber(int* pArray1,int* pArray2);

void Shuffle(int* pArray1,int* pArray2);

AI_MODE SelectAIMode();

void OutputNumber(int* pArray, int iBingo);

bool ChangeNumber(int* pArray, int iInput);

int SelectAINubmer(int* pArray, AI_MODE eMode);

int BingoCounting(int* pArray);
int BingoCountingH(int* pArray);
int BingoCountingV(int* pArray);
int BingoCountingLTD(int* pArray);
int BingoCountingRTD(int* pArray);

int main() {

	// ���� ���� �����ϱ� ���� srand
	srand((unsigned int)time(0));

	// ���� �������� ���� �迭
	int iNumber[25] = {}; //Player
	int iAINumber[25] = {}; // AI

	// �迭�� 1~25 ���� ���� ����
	SetNumber(iNumber,iAINumber);
	
	//������ ����
	Shuffle(iNumber,iAINumber);


	// ������ ���� ���� , AI�� ���� ����
	int iBingo = 0, iAIBingo = 0;
	// AI Mode ����
	AI_MODE eAiMode;


	//AI ���̵� ����
	eAiMode = SelectAIMode();

	// AI Easy ���� ���� AI�� ���ڸ�� �� *�� �ٲ��� ���� ���� ����� ����
	// �� ����� �ϳ��� �����ϰ� �ȴ�.(�����ϰ�)
	


	while (true) {
		system("cls");
		
		//Player ������ �׸���.
		cout << "==========Player BINGO BOARD==========" << endl << endl;
		OutputNumber(iNumber, iBingo);

		//AI ���̵� Ȯ��
		switch (eAiMode) {
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}

		//AI ������ ���
		cout << endl << "==========AI BINGO BOARD==========" << endl << endl;		
		OutputNumber(iAINumber, iAIBingo);

		
		
		
		//���� �¸� ����
		if (iBingo >= 5) {
			cout << "USER �¸�!" << endl;
			break;
		}
		else if (iAIBingo >= 5) {
			cout << "AI �¸�!" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ��� (0 : ����) : ";
		int iInput;
		cin >> iInput;
		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25)
			continue;

		// �ߺ��Է��� üũ�ϱ� ���� ������ �⺻������ �ߺ��Ǿ��ٶ�� �ϱ����� True �μ���.
		bool bAcc = ChangeNumber(iNumber,iInput);
		
		//bAcc������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		//�ٲ��� �������Ƿ� �ٽ� �Է¹޵��� continue ���ش�.
		if (bAcc)
			continue;

		//�ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		ChangeNumber(iAINumber, iInput);

		//AI�� ���ڸ� �����Ѵ�. AI��忡 ���缭 ���õǵ��� �Լ��� �����Ǿ��ִ�.
		iInput = SelectAINubmer(iAINumber, eAiMode);

		
		//AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.

		ChangeNumber(iNumber,iInput);

		ChangeNumber(iAINumber, iInput);


		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� ������ ó������
		//���� ī��Ʈ�� �� ���̴�. �׷��Ƿ� iBingo ������ 0 ���� �Ź� �ʱ�ȭ �ϰ�
		//���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = BingoCounting(iNumber);
		iAIBingo = BingoCounting(iAINumber);
		
	}
	return 0;
}

//(����)


void SetNumber(int* pArray1, int* pArray2) {
	for (int i = 0; i < 25; ++i) {
		pArray1[i] = pArray2[i] = i + 1;
	}
}

void Shuffle(int* pArray1, int* pArray2) {
	int iTemp, idx1, idx2;
	for (int j = 0; j < 100; ++j) {
		//User ������
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = pArray1[idx1];
		pArray1[idx1] = pArray1[idx2];
		pArray1[idx2] = iTemp;

		//AI ������
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = pArray2[idx1];
		pArray2[idx1] = pArray2[idx2];
		pArray2[idx2] = iTemp;
	}
}


AI_MODE SelectAIMode() {
	int iAiMode;
	while (true) {
		cout << "1.EASY " << endl;
		cout << "2.HARD " << endl;
		cout << "AI ��带 �����ϼ���. : ";

		cin >> iAiMode;
		if (iAiMode >= AM_EASY && iAiMode <= AM_HARD)
			break;
	}
	return (AI_MODE)iAiMode;
}


void OutputNumber(int* pArray, int iBingo) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (pArray[i * 5 + j] == INT_MAX) {
				cout << "*\t";
			}
			else {
				cout << pArray[i * 5 + j] << "\t";
			}
		}
		cout << endl << endl;
	}
	cout << "==========User Bingo Line  : " << iBingo << " ==========" << endl << endl;
}


bool ChangeNumber(int* pArray, int iInput) {
	// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ��� Ȯ��.
	for (int i = 0; i < 25; ++i) {
		if (iInput == pArray[i]) {
			//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
			// bAcc ������ false�� ������ش�.
			
			//���ڸ� *�� �����ϱ� ���� Ư�� ����INT_MAX �� ����
			pArray[i] = INT_MAX;
			//���̻� �ٸ� ���ڸ� ã�� �ʿ䰡 �����Ƿ� �ݺ��� Ż��
			return false;
		}
	}
	//������� ���� �Ǹ� return false �� ���� �ȵ� ���̹Ƿ� ���� ���ڰ�
	//���ٴ� ���̴�. ��, �ߺ��� ���ڸ� �Է��߱� ������ true�� ����
	return true;
}
int SelectAINubmer(int* pArray, AI_MODE eMode){
	

	// ���� �ȵ� ��� �迭 ����
	int iNoneSelect[25] = {};
	//���� �ȵ� ���� ������ ����
	int iNoneSelectCount = 0;


	//AI�� ������ �Ѵ�.  AI�� �����ϴ� ���� AI ��忡 ���� �޶�����.
	switch (eMode) {
		// AI Easy ���� ���� AI�� ���ڸ�� �� *�� �ٲ��� ���� ���� ����� ����
		// �� ����� �ϳ��� �����ϰ� �ȴ�.(�����ϰ�)
	case AM_EASY:
		// ���þȵ� ���ڸ���� ������ش�.
		// ���þȵ� ���� ������ ����� ���鶧 ī�������ش�.

		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i) {

			// ���� ���ڰ� *�� �ƴҰ��
			if (pArray[i] != INT_MAX) {
				//*�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
				// ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� ��������
				// �� ���þȵ� ������ �����ش�.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}
		//for���� ���������� �Ǹ� ���þȵ� ����� ���������
		// ���þȵ� ����� ������ ��������� �ȴ�.
		// ���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
		// �ε����� �����ϰ� �����ش�.
		return iNoneSelect[rand() % iNoneSelectCount];
	case AM_HARD:
		//�ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ����
		// ã�Ƽ� �� �ٿ� �ִ� ������ �ϳ��� *�� ������ش�.
		int iLine;
		int iStarCount = 0;
		int iSaveCount = 0;

		//���ζ��� �� ���� *�� ���� ������ ã�Ƴ���.
		for (int i = 0; i < 5; ++i) {
			iStarCount = 0;
			for (int j = 0; j < 5; ++j) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			//���� 5�� �̸��̾�� ���� ���� �ƴϰ� ������ ���帹��
			//������ ������ Ŀ�� ���� ���� ���� �����̹Ƿ� ������
			//��ü���ְ� ����� �� �� �� ��ü�Ѵ�.

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				//���� ������ ���� ���� ���� ������ üũ�ϴ� �κ�.
				//���ζ����� 0~4�� �ǹ̺ο���.
				iLine = i;
				iSaveCount = iStarCount;
			}
		}
		// ���� ������ ���� ���� ���� ������ �̹� �������Ƿ�,
		// ����� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
		for (int i = 0; i < 5; ++i) {
			iStarCount = 0;
			for (int j = 0; j < 5; ++j) {
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				//���� ������ ���� ���� ���� ������ üũ�ϴ� �κ�.
				//���ζ����� 5~9�� �ǹ̺ο���.
				iLine = 5 + i;
				iSaveCount = iStarCount;
			}
		}
		//���� ->������ �밢�� üũ
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}
		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}
		//������ ->���� �밢�� üũ
		iStarCount = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}
		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}
		//��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ�� �����.
		//�� �ٿ� �ִ� *�� �ƴ� ������ �ϳ��� �����ϰ� �Ѵ�.

		//�������� ���
		if (iLine <= LN_H5) {
			//�������� ��� iLine�� 0~4 ������ ���̴�.
			for (int i = 0; i < 5; ++i) {
				// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
				if (pArray[iLine * 5 + i] != INT_MAX) {
					return pArray[iLine * 5 + i];
				}
			}
		}
		//�������� ���
		else if (iLine <= LN_V5) {
			//�������� ��� iLine�� 5~9 ������ ���̴�
			for (int i = 0; i < 5; ++i) {
				//���������� ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX) {
					return  pArray[i * 5 + (iLine - 5)];
				}
			}
		}
		//������ �밢���� ���
		else if (iLine == LN_LT) {
			for (int i = 0; i < 25; i += 6) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		//������ �밢���� ���
		else if (iLine == LN_RT) {
			for (int i = 4; i <= 20; i += 4) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		break;
	}
	//�߸����� ǥ��
	return -1;
}

int BingoCounting(int* pArray) {
	int iBingo = 0;
	//������ üũ
	iBingo += BingoCountingH(pArray);
	//������ üũ
	iBingo += BingoCountingV(pArray);
	//���ʻ�� �밢�� üũ
	iBingo += BingoCountingLTD(pArray);
	//�����ʻ�� �밢�� üũ
	iBingo += BingoCountingRTD(pArray);

	return iBingo;

}
int BingoCountingH(int* pArray) {
	//���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i) {
		//������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j) {
			//���� �� ������ �����ش�.
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
			
		}
		// i for���� ���������� ���� ���� ���� ���� �� ������ �����
		//iStar1 ������ ���� �ȴ�. iStar1�� ���� 5�̸� ������
		//��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰��� �ش�.
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}
int BingoCountingV(int* pArray){
	//���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5; ++i) {
		//������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j) {
			//���� �� ������ �����ش�.
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;

		}
		// i for���� ���������� ���� ���� ���� ���� �� ������ �����
		//iStar1 ������ ���� �ȴ�. iStar1�� ���� 5�̸� ������
		//��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰��� �ش�.
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}
int BingoCountingLTD(int* pArray) {
	// ���� ��� -> ������ �ϴ� �밢�� üũ
	int iStar1 = 0,iBingo=0;
	for (int i = 0; i < 25; i += 6) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}
int BingoCountingRTD(int* pArray) {
	// ������ ��� -> ���� �ϴ� �밢�� üũ
	int iStar1 = 0, iBingo = 0;
	for (int i = 4; i < 21; i += 4) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}
*/