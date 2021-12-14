/*
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	// 상수 :  변하지 않는 수. 값을 한번 지정해놓으면 바꿀 수 없다.
	// 상수는 선언과 동시에 값을 지정해 둬야 함.

	const int iAttack = 0x00000001;		//			1
	const int iArmor = 0x00000002;		//		   10
	const int iHP = 0x00000004;			//		  100
	const int iMP = 0x00000008;			//		 1000
	const int iCritical = 0x00000010;	//		10000


	// 공격,체력,크리티컬 버프 할당
	//			 001 | 100 | 10000 =  10101
	int iBuf = iAttack | iHP | iCritical;

	//연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
	
	// 10101 ^ 00100 = 10001 = 17;
	iBuf ^= iHP;
	// 10001 ^ 00100 = 10101 = 21;
	iBuf ^= iHP;
	
	// XOR 연산을 이용해서 스위치 기능을 구현할 수 있음.


	// 10101 & 00001 = 1;
	cout << "Attack : "<<(iBuf & iAttack) << endl;
	
	// 10101 & 00010 = 0;
	cout << "Armor : " << (iBuf & iArmor) << endl;

	// 10101 & 00100 = 4;
	cout << "HP : " << (iBuf & iHP) << endl;
	
	// 10101 & 01000 =  0;
	cout << "MP : " << (iBuf & iMP) << endl;
	
	// 10101 & 10000 = 16;
	cout << "Critical : " << (iBuf & iCritical) << endl;
	


		//*********************************************************
		//쉬프트 연산자 : <<, >> 값 대 값을 연산하여 값으로 나오게 된다.
		//이 연산자 또한 이진수 단위의 연산을 하게 된다.
		//20 << 2 = 80	->	20*(2^2)
		//20 << 3 = 160	->	20*(2^3)
		//20 << 4 = 320	->	20*(2^4)
		
		//우측쉬프트 연산은 빠른 나누기 역할(정수 대 정수의 나눔. 소수점 버림)

		//20 >> 2 = 5	->	20/(2^2)
		//20 >> 3 = 2 ->	20/(2^3)
		//*********************************************************
	
	
	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;
	// iNumber에는 187이 들어가있다. 이 값을 좌측쉬프트로 16비트 연산하면
	// 상위 16비트에 값이 들어가게 됨.
	iNumber <<= 16;

	// 하위 16비트를 채운다.

	iNumber |= iLow;

	//High 값을 출력한다.

	cout << "iHigh : " << iHigh << endl;
	cout << "iNumber High bit : " << (iNumber >> 16) << endl;
	cout << "iLow : " << iLow << endl;
	cout << "iNumber Low bit : " << (iNumber & 0x0000ffff) << endl;

	//증감연산자 : ++ ,-- 가 있음 1증가, 1감소
	iNumber = 10;

	//전치
	++iNumber;

	//후치
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl; 


	//******************
	  //분기문에는 크게 2가지 종류가 있다. if문, switch 문이 존재한다.
	  //if문 : 조건을 체크해주는 기능이다.
	  //형태 : if(조건식){ ... };
	  //if문은 조건식이 true가 될 경우 코드블럭 안의 코드가 동작된다.
	  //false일 경우에는 동작되지 않는다.
	  //if문 아래에 들어갈 코드가 1줄일 경우 {}(코드블럭)을 생략할 수 있다.
	//***************
	if (true) {
		cout << "if문 조건이 true 입니다." << endl;
	}

	// 버프가 있는지 확인한다.

	if ((iBuf & iAttack) != 0) {
		cout << "Attack 버프가 있습니다. " << endl;
	}
	if ((iBuf & iArmor) != 0)
		cout << "Armor 버프가 있습니다. " << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP 버프가 있습니다." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP 버프가 있습니다." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;
	
	//****************
	//	else : if문과 반드시 같이 사용이 되어야 한다.
	//	if문 조건이 false일 경우 else가 있다면 else구문 안의 코드가 동작된다.

	//	else if: if문과 반드시 같이 사용이 되어야한다.
	//	if문 아래 와야 하고 else 보다는 위에 있어야 한다.
	//	else if는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을 체크한다.
	//	else if는 몇개든 사용이 가능하다.
	//************

	if (false) {
		cout << "if문 조건이 true 입니다." << endl;
	}
	else {
		cout << "if문 조건이 false 입니다." << endl;
	}

//	cout << "숫자를 입력하세요 : ";
	//cin >> iNumber;
//	if (10 <= iNumber && iNumber <= 20)
//		cout << "10~20 사이의 숫자입니다." << endl;
//	else if (21 <= iNumber && iNumber <= 30)
//		cout << "20~30 사이의 숫자입니다." << endl;
//	else if (31 <= iNumber && iNumber <= 40)
//		cout << "30~40 사이의 숫자입니다." << endl;
//	else
//		cout << "그 외의 숫자입니다." << endl;


	// 난수 발생
	srand((unsigned int)time(0));

	cout << rand() << endl;
	cout << rand() << endl;
	
	cout << ((rand() %100) + (rand()* 0.001)) << endl;
	cout << (rand() % 10000 * 0.01f) << endl;

	// 업그레이드 수치
	int iUpgrade = 0;
	int iNum[15] = { 0 };
	int iCount = 0;

	while (true) {
		if (iUpgrade == 15) {
			break;
		}else{
			//강화 확률을 구함.
			float fPercent = rand() % 10000 / 100.f;

			//강화 확률 : 업그레이드가 0~3 :  100% 성공 , 4~6 : 40% ,7~9 :10%,
			//10~ 13 : 1%, 14~15 :0.01%
			cout << "Percent : " << fPercent << endl;

			if (iUpgrade <= 3) {
				iUpgrade++;
			}
			else if (iUpgrade > 3 && iUpgrade < 7) {
				if (fPercent < 40.f) {
					iUpgrade++;
				}
			}
			else if (iUpgrade > 6 && iUpgrade < 10) {
				if (fPercent < 10.f) {
					iUpgrade++;
				}
				else {
				//	iUpgrade -= (rand() % 3)+1;
				}
			}
			else if (iUpgrade > 9 && iUpgrade < 14) {
				if (fPercent < 1.f) {
					iUpgrade++;
				}
				else {
					//iUpgrade -= (rand() % iUpgrade) + 1;
				}
			}
			else if (iUpgrade > 13) {
				if (fPercent < 0.01f)
					iUpgrade++;
				else{
					//iUpgrade -= (rand() % iUpgrade) + 1;
				}
			}
			else {
				cout << "더 이상 강화할 수 없습니다." << endl;
			}
			iNum[iUpgrade - 1] += 1;
			iCount++;
		}
	}
	cout << "15강까지 걸린 횟수 : " << iCount << endl;
	for (int i = 0; i < 15; i++) {
		cout << "강화 " << i + 1 << "단계 일때 시도 횟수 : " << iNum[i] << endl;
	}
	return 0;

}

*/