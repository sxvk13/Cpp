///*
#include <iostream>
#include <time.h>

using namespace std;

// ����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �ִ� ���.
// enum ����ü�� {} �� ���·� ������.
// ����ü���� �̿��ؼ� ����ü Ÿ���� ������ ���� �����ϴ�.
// ��, ����ü ��ü�� ��������� ���� Ÿ���� �� ���� �ִ�.
// ����ü�� ���ڿ� �̸��� �ٿ��ִ� ����̴�.


enum NUM
{
	NUM_0, //�ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� ���� �ο���.
	NUM_1,
	NUM_2,
	NUM_3
};

#define NUM_4 4

enum SRP {
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};


int main() {
	// switch �� : �б⹮�� �� �����̸�
	// if���� ������ üũ�ϴ� �б⹮�̶�� switch ���� ���� ������ üũ�ϴ� �б⹮.
	// ��, switch���� �񱳸� �� �� ����.
	// ���� : switch(���� üũ�� ����){}�� ����. �ڵ�� �ȿ��� case~break ������ ��.
	// case ��� : �� ���·� ó���� �ǰ� �������� ���������� ���� case �ڿ� ���� ����� ��.
	// break�� ������ �Ʒ������� ���޾Ƽ� ��µ�.

	// ���� �߻�
//srand((unsigned int)time(0));
//
//cout << rand() << endl;
//cout << rand() << endl;
//
//cout << ((rand() % 100) + (rand() * 0.001)) << endl;
//cout << (rand() % 10000 * 0.01f) << endl;
//
//// ���׷��̵� ��ġ
//int iUpgrade = 0;
//int iNum[15] = { 0 };
//int iCount = 0;
//int iMoney = 0;
//
//while (true) {
//	if (iUpgrade == 15) {
//		break;
//	}
//	else {
//		//��ȭ Ȯ���� ����.
//		float fPercent = rand() % 10000 / 100.f;
//
//		//��ȭ Ȯ�� : ���׷��̵尡 0~3 :  100% ���� , 4~6 : 40% ,7~9 :10%,
//		//10~ 13 : 1%, 14~15 :0.01%
//		cout << "Percent : " << fPercent << endl;
//		
//		switch (iUpgrade) {
//		case 0:
//		case 1:
//		case 2:
//			iUpgrade++;
//			iMoney += 30000;
//			break;
//		case 3:
//			iUpgrade++;
//			iMoney += 60000;
//			break;
//		case 4:
//			if (fPercent < 40.f) {
//				iUpgrade++;
//			}
//				iMoney += 68000;
//			break;
//		case 5:
//			if (fPercent < 40.f) {
//				iUpgrade++;
//			}
//				iMoney += 76000;
//			break;
//		case 6:
//			if (fPercent < 40.f) {
//				iUpgrade++;
//			}
//				iMoney += 84000;
//			break;
//		case 7:
//			if (fPercent < 10.f) {
//				iUpgrade++;
//			}
//				iMoney += 92000;
//			break;
//		case 8:
//			if (fPercent < 10.f) {
//				iUpgrade++;
//			}
//				iMoney += 100000;
//			break;
//		case 9:
//			if (fPercent < 10.f) {
//				iUpgrade++;
	//			}
	//				iMoney += 108000;
	//			break;
	//		case 10:
	//			if (fPercent < 1.f) {
	//				iUpgrade++;
	//			}
	//				iMoney += 116000;
	//			break;
	//		case 11:
	//			if (fPercent < 1.f) {
	//				iUpgrade++;
	//			}
	//				iMoney += 124000;
	//			break;
	//		case 12:
	//			if (fPercent < 1.f) {
	//				iUpgrade++;
	//			}
	//				iMoney += 132000;
	//			break;
	//		case 13:
	//			if (fPercent < 1.f) {
	//				iUpgrade++;
	//			}
	//				iMoney += 140000;
	//			break;
	//		case 14:
	//			if (fPercent < 0.01f) {
	//				iUpgrade++;
	//			}
	//				iMoney += 148000;
	//			break;
	//		default:
	//			cout << "�� �̻� ��ȭ�� �� �����ϴ� ! " << endl;
	//			break;
	//		}
	//		
	//		iNum[iUpgrade - 1] += 1;
	//		iCount++;
	//	}
	//}
	//cout << "15������ �ɸ� Ƚ�� : " << iCount << endl;
	//cout << "15������ �Ҹ��� �� : " << iMoney << endl;
	//for (int i = 0; i < 15; i++) {
	//	cout << "��ȭ " << i + 1 << "�ܰ� �϶� �õ� Ƚ�� : " << iNum[i] << endl;
	//}

//	int iNumber;
//	
//	cout << "���� �Է� : ";
//	cin >> iNumber;
//	
//	switch (iNumber) {
//	case 1: // iNumber ���� ���������� ���� ����Ǵ� case ������ �����ȴ�.
//		cout << "�Է��� ���ڴ� 1 �Դϴ�. " << endl;
//		break;
//	case 2: 
//		cout << "�Է��� ���ڴ� 2 �Դϴ�. " << endl;
//		break;
//	case 3:
//		cout << "�Է��� ���ڴ� 3 �Դϴ�. " << endl;
//		break;
//	case NUM_4:
//		cout << "�Է��� ���ڴ� 4 �Դϴ�. " << endl;
//		break;
//	
//	default: // case�� �����Ǿ� ���� ���� ���ڰ� ���� ��� �����.
//		cout << "�� ���� �����Դϴ�. " << endl;
//		break;
//	}
	

	// ����ü Ÿ���� ������ ����. ����ü Ÿ���� ������ ������ 4byte�� ������.
	NUM eNum = (NUM)10;

	// sizeof(Ÿ�� or ����) �� �ϰ� �Ǹ� �ش� Ÿ�� Ȥ�� ������ �޸� ũ�⸦ ������.

	cout << sizeof(NUM) << endl;
	//typeid(Ÿ�� or ����).name()�� �ϰ� �Ǹ� typeid �ȿ� �� Ÿ�� Ȥ�� ������
	//Ÿ���� ���ڿ��� ��ȯ����.

	cout << typeid(eNum).name() << endl;
	cout << eNum << endl;


	// �ݸ� : Ư�� �۾��� �ݺ��ؼ� �������ִ� ���.
	// ���� : for, while, do while 3������ ������.
	// while(���ǽ�) {}�� ���·� ����.
	// while���� ���ǽ��� üũ�ؼ� true �� ��� �ڵ�� ���� �ڵ尡 ���۵ǰ� �ٽ�
	// ���ǽ��� üũ�Ѵ�. ���ǽ��� false �� �Ǹ� while���� ���������� ��.
	// �ݺ��� �ȿ��� break�� ������ �Ǹ� �ش� �ݺ����� ��������.

//	iNumber = 0;
//	while (iNumber < 10) {
//		cout << iNumber << endl;
//		++iNumber;
//		if (iNumber == 4) {
//			break;
//		}
//	}

	// ȭ���� ������ �����ش�.
	system("cls");


	//���� ���̺� ����

	srand((unsigned int)time(0));

	int iPlayer;
	int iAI;

	while (false) {
		cout << "1.���� " << endl;
		cout << "2.���� "<<endl;
		cout << "3.�� " << endl;
		cout << "4.���� " << endl;
		cout << "�޴��� �����ϼ���. : ";
		cin >> iPlayer;

		if (iPlayer <SRP_S || iPlayer>SRP_END) {
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			//�Ͻ�����
			system("pause");
			continue;
		}
		else if (iPlayer == SRP_END) {
			break;
		}
		// AI ����

		iAI = rand() % SRP_P + SRP_S;

		switch (iAI) {
		case SRP_S:
			cout << "AI : ���� " << endl;
			break;
		case SRP_R:
			cout << "AI : ���� " << endl;
			break;
		case SRP_P:
			cout << "AI : �� " << endl;
			break;
		}
		// �����

		int iWin = iPlayer - iAI; //���������� ��Ģ
		switch (iWin) {
		case 0:
			cout << "�����ϴ�!" << endl;
			break;
		case 1:
		case -2:
			cout << "�̰���ϴ�!" << endl;
			break;
		default :
			cout << "�����ϴ�!" << endl;
			break;
		}
		
	}

	// for�� : �ݺ����� �� ����
	// ���� : for(�ʱⰪ ; ���ǽ�; ������){} �� ���·� ����
	// ���ǽ��� true�̸� �ڵ���� �ڵ尡 ������.
	//���ѷ����� �������� for(;;){}�� ���ָ� �������� ���ư�.
	//for������ �ʱⰪ�� ó�� for ���� ������ �� �� 1���� ������. �� �Ŀ� ���ǽ���
	//üũ�ϰ� ���ǽ��� true�̸� �ڵ����� �ڵ尡 ���۵� ��, �������� ó����.
	// ���� �ٽ� ������ üũ�ϰ� true�� ���۵ǰ� ����->����->����->������ ������ ó��.
	// ������ false  �ǰų� break�� ������ for���� ��������.


	// �ʱⰪ : i=0 , ���ǽ� :i <10, ������ :++i
	// ���� for���� �����ϸ鼭 �ʱⰪ�� ����ǹǷ� i�� 0���� �ʱ�ȭ��.
	// �� �� i<10�� üũ�ؼ� 0�� ���� true�� ���� i���� ���.
	// �� �� ������ ó�� �Ͽ� ++�� �ϸ� 0���� 1�� �ǰ� ������ üũ.
	// 1�� 10���� �����Ƿ� true�� ������ 1��� ++�ؼ� 2�� �ǰ� ���� true
	// 2��� 3, 4,5,...9������ ������ true�� 9�� ����ϰ�
	// ++�� �Ǿ� 10�� �ǰ� 10<10�� �ϸ� ������ false�̹Ƿ� �ݺ����� ��������.
	int i = 0;
	for (i = 0; i < 10; ++i) {
		cout << i << endl;
	}

	cout << i << endl;




	return 0;
}
//*/