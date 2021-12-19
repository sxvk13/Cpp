/*
#include <iostream>

using namespace std;


int main() {
	cout << "homework no.1" << endl;
	// no.1
	for (int i = 2; i < 10; ++i) {
		cout << "***구구단 " << i << " 단***" << endl;
		cout << endl;
		for (int j = 1; j < 10; ++j) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "*************************" << endl;
	}
	
	cout << endl;

	cout << "homework no.2" << endl;
	// no.2

	for (int i = 1; i < 6; ++i) {
		for (int j = 0; j < i; ++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "homework no.3" << endl;
	// no.3

	for (int i = 5; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "homework no.4" << endl;
	// no.4

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3-i;++j) {
			cout << " ";
		}
		for (int j = 0; j < i*2+1; ++j) {
			cout << "*" ;
		}
		for (int j = 0; j < 3-i; ++j) {
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	// 2단	3단	4단
	// 5단	6단	7단
	// 8단	9단	10단

	//for (int k = 0; k <3; ++k) {
	//	for (int i = 1; i < 10; ++i) {
	//		for (int j = 2 + (k * 3); j < 5 + (k * 3); ++j) {
	//			cout << j << " * " << i << " = " << j * i << "\t";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	
	//solution

	for (int i = 2; i < 11; i += 3) {
		for (int j = 1; j <= 9; ++j) {
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i +1 << " * " << j << " = " << (i+1) * j << "\t";
			cout << i +2 << " * " << j << " = " << (i+2) * j << endl;
		}

		cout << endl;
	}

	//diamond

	int iLine=7;
	int iCount = 0;
	
	for (int i = 0; i < iLine; ++i) {
		//공백 3,2,1,0,1,2,3
		//별   1,3,5,7,5,3,1
	
		iCount = i;
		// i값이 7준 기분 4,5,6 즉, 밑의 삼각형을 구성할 때만 if문에 들어가게 됨.
		if (i > iLine/2){
			iCount = iLine - 1 - i;

		}
		// i값이 0,1,2,3일 때는 iCount는 i값을 그대로 대입.
		// i값이 4,5,6일 때는 iCount는 2,1,0이 된다.
		// 즉, 최종 i값은 0,1,2,3,2,1,0 으로 들어가게 된다.
		for (int j = 0; j < iLine/2 - iCount; ++j) {
			cout << " ";
		}
		for (int j = 0; j < iCount * 2 + 1; ++j) {
			cout << "*";
		}
		cout<< endl;
	}
	return 0;
}
*/
