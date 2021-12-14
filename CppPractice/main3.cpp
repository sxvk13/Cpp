///*
#include <iostream>
#include <time.h>

using namespace std;

// 열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능.
// enum 열거체명 {} 의 형태로 구성됨.
// 열거체명을 이용해서 열거체 타입의 변수를 선언도 가능하다.
// 즉, 열거체 자체가 사용자정의 변수 타입이 될 수도 있다.
// 열거체는 숫자에 이름을 붙여주는 기능이다.


enum NUM
{
	NUM_0, //아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여됨.
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
	// switch 문 : 분기문의 한 종류이며
	// if문이 조건을 체크하는 분기문이라면 switch 문은 값이 뭔지를 체크하는 분기문.
	// 즉, switch문은 비교를 할 수 없음.
	// 형태 : switch(값을 체크할 변수){}의 형태. 코드블럭 안에는 case~break 구문이 들어감.
	// case 상수 : 의 형태로 처리가 되고 변수값이 무엇인지에 따라서 case 뒤에 오는 상수를 비교.
	// break가 없으면 아래내용이 연달아서 출력됨.

	// 난수 발생
//srand((unsigned int)time(0));
//
//cout << rand() << endl;
//cout << rand() << endl;
//
//cout << ((rand() % 100) + (rand() * 0.001)) << endl;
//cout << (rand() % 10000 * 0.01f) << endl;
//
//// 업그레이드 수치
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
//		//강화 확률을 구함.
//		float fPercent = rand() % 10000 / 100.f;
//
//		//강화 확률 : 업그레이드가 0~3 :  100% 성공 , 4~6 : 40% ,7~9 :10%,
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
	//			cout << "더 이상 강화할 수 없습니다 ! " << endl;
	//			break;
	//		}
	//		
	//		iNum[iUpgrade - 1] += 1;
	//		iCount++;
	//	}
	//}
	//cout << "15강까지 걸린 횟수 : " << iCount << endl;
	//cout << "15강까지 소모한 돈 : " << iMoney << endl;
	//for (int i = 0; i < 15; i++) {
	//	cout << "강화 " << i + 1 << "단계 일때 시도 횟수 : " << iNum[i] << endl;
	//}

//	int iNumber;
//	
//	cout << "숫자 입력 : ";
//	cin >> iNumber;
//	
//	switch (iNumber) {
//	case 1: // iNumber 값이 무엇인지에 따라서 실행되는 case 구문이 결정된다.
//		cout << "입력한 숫자는 1 입니다. " << endl;
//		break;
//	case 2: 
//		cout << "입력한 숫자는 2 입니다. " << endl;
//		break;
//	case 3:
//		cout << "입력한 숫자는 3 입니다. " << endl;
//		break;
//	case NUM_4:
//		cout << "입력한 숫자는 4 입니다. " << endl;
//		break;
//	
//	default: // case로 지정되어 있지 않은 숫자가 들어올 경우 실행됨.
//		cout << "그 외의 숫자입니다. " << endl;
//		break;
//	}
	

	// 열거체 타입의 변수를 선언. 열거체 타입의 변수는 무조건 4byte를 차지함.
	NUM eNum = (NUM)10;

	// sizeof(타입 or 변수) 를 하게 되면 해당 타입 혹은 변수의 메모리 크기를 구해줌.

	cout << sizeof(NUM) << endl;
	//typeid(타입 or 변수).name()을 하게 되면 typeid 안에 들어간 타입 혹은 변수의
	//타입을 문자열로 반환해줌.

	cout << typeid(eNum).name() << endl;
	cout << eNum << endl;


	// 반목문 : 특정 작업을 반복해서 수행해주는 기능.
	// 종류 : for, while, do while 3종류가 존재함.
	// while(조건식) {}의 형태로 구성.
	// while문은 조건식을 체크해서 true 일 경우 코드블럭 안의 코드가 동작되고 다시
	// 조건식을 체크한다. 조건식이 false 가 되면 while문을 빠져나오게 됨.
	// 반복문 안에서 break를 만나게 되면 해당 반복문을 빠져나옴.

//	iNumber = 0;
//	while (iNumber < 10) {
//		cout << iNumber << endl;
//		++iNumber;
//		if (iNumber == 4) {
//			break;
//		}
//	}

	// 화면을 깨끗히 지워준다.
	system("cls");


	//난수 테이블 생성

	srand((unsigned int)time(0));

	int iPlayer;
	int iAI;

	while (false) {
		cout << "1.가위 " << endl;
		cout << "2.바위 "<<endl;
		cout << "3.보 " << endl;
		cout << "4.종료 " << endl;
		cout << "메뉴를 선택하세요. : ";
		cin >> iPlayer;

		if (iPlayer <SRP_S || iPlayer>SRP_END) {
			cout << "잘못된 값을 입력하였습니다." << endl;
			//일시정지
			system("pause");
			continue;
		}
		else if (iPlayer == SRP_END) {
			break;
		}
		// AI 선택

		iAI = rand() % SRP_P + SRP_S;

		switch (iAI) {
		case SRP_S:
			cout << "AI : 가위 " << endl;
			break;
		case SRP_R:
			cout << "AI : 바위 " << endl;
			break;
		case SRP_P:
			cout << "AI : 보 " << endl;
			break;
		}
		// 결과비교

		int iWin = iPlayer - iAI; //가위바위보 규칙
		switch (iWin) {
		case 0:
			cout << "비겼습니다!" << endl;
			break;
		case 1:
		case -2:
			cout << "이겼습니다!" << endl;
			break;
		default :
			cout << "졌습니다!" << endl;
			break;
		}
		
	}

	// for문 : 반복문의 한 종류
	// 형태 : for(초기값 ; 조건식; 증감식){} 의 형태로 구성
	// 조건식이 true이면 코드블럭의 코드가 동작함.
	//무한루프를 돌릴때는 for(;;){}을 해주면 무한으로 돌아감.
	//for문에서 초기값은 처음 for 문에 진입할 때 딱 1번만 동작함. 그 후에 조건식을
	//체크하고 조건식이 true이면 코드블력의 코드가 동작된 후, 증감식을 처리함.
	// 그후 다시 조건을 체크하고 true면 동작되고 증감->조건->증감->조건의 순서로 처리.
	// 조건이 false  되거나 break를 만나면 for문을 빠져나감.


	// 초기값 : i=0 , 조건식 :i <10, 증감식 :++i
	// 먼저 for문에 진입하면서 초기값이 실행되므로 i를 0으로 초기화함.
	// 그 후 i<10을 체크해서 0일 때는 true가 나와 i값을 출력.
	// 그 후 증감식 처리 하여 ++을 하면 0에서 1이 되고 조건을 체크.
	// 1은 10보다 작으므로 true가 나오고 1출력 ++해서 2가 되고 조건 true
	// 2출력 3, 4,5,...9까지는 조건이 true라서 9를 출력하고
	// ++이 되어 10이 되고 10<10을 하면 조건이 false이므로 반복문을 빠져나옴.
	int i = 0;
	for (i = 0; i < 10; ++i) {
		cout << i << endl;
	}

	cout << i << endl;




	return 0;
}
//*/