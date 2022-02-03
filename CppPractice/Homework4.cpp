/*
 관리프로그램 만들기
 도서 대여 프로그램 만들기.
 1.책 등록 
 2.책 대여 
 3.책 반납
 4.책 목록
 5.종료 
 
 책 구조체는 이름, 대여금액, 책번호, 대여여부가 팔요함.
 책 목록을 선택하면 책 정보를 출력해 준다.

 My Source
 */
/*
#include <iostream>

using namespace std;

#define BOOK_NAME 32
#define BOOK_MAX 10

struct _tagBook {
	char strBookName[BOOK_NAME];
	int iBookPrice;
	int iBookNo;
	bool bBookCheck;
};

enum BookMenu {
	MENU_ENROLL=1,
	MENU_BOOKING,
	MENU_RETURN,
	MENU_PRINT,
	MENU_EXIT
};

int main() {
	_tagBook tBookArr[BOOK_MAX] = {};
	int iBookCount = 0;
	int iBookNumber = 1;
	char strBook[BOOK_NAME] = {};

	while (true) {
		system("cls");
		cout << "=========도서 대여 프로그램=========" << endl << endl;
		cout << "1.책 등록 " << endl;
		cout << "2.책 대여 " << endl;
		cout << "3.책 반납 " << endl; 
		cout << "4.책 목록 " << endl; 
		cout << "5.종료 " << endl << endl;
		cout << "메뉴를 선택해 주세요 : ";
		int iSelectMenu;
		cin >> iSelectMenu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iSelectMenu == MENU_EXIT)
			break;
		switch (iSelectMenu) {
		case MENU_ENROLL:
			system("cls");
			cout << "=========도서 등록=========" << endl << endl;
			if (iBookCount == BOOK_MAX){
				cout << "도서가 최대치 입니다." << endl;
				break;
			}
			cout << "도서명 : ";
			cin>>tBookArr[iBookCount].strBookName;
			tBookArr[iBookCount].iBookNo = iBookNumber;
			cout << "대여가격 : ";
			cin>> tBookArr[iBookCount].iBookPrice;
			tBookArr[iBookCount].bBookCheck = true;
			cout << endl << "도서 등록완료! " << endl;
			cout << "---------------------------------" << endl << endl;
			++iBookCount;
			++iBookNumber;
			break;
		case MENU_BOOKING:
			system("cls");
			cout << "=========도서 대여=========" << endl << endl;
			cin.ignore(1024, '\n');
			cout << "대여할 도서명을 입력해 주세요 : ";
			cin.getline(strBook, BOOK_NAME);
			for (int i = 0; i < iBookCount; ++i) {
				if (strcmp(tBookArr[i].strBookName,strBook)==0) {
					if (tBookArr[i].bBookCheck) {
						cout <<endl << "대출 완료! " << endl << endl;
						tBookArr[i].bBookCheck = false;
						break;
					}
					else {
						cout << endl << "대출 실패! (대여중인 도서)" << endl << endl;
						break;
					}
				}
			}
			break;
		case MENU_RETURN:
			system("cls");
			cout << "=========도서 반납=========" << endl << endl;
			cin.ignore(1024, '\n');
			cout << "반납할 도서명을 입력해 주세요 : ";
			cin.getline(strBook, BOOK_NAME);
			for (int i = 0; i < iBookCount; ++i) {
				if (strcmp(tBookArr[i].strBookName, strBook) == 0) {
					if (tBookArr[i].bBookCheck) {
						cout << endl << "반납 실패! (대여중이지 않은 도서) " << endl << endl;
						break;
					}
					else {
						cout << endl << "반납 성공! " << endl << endl;
						tBookArr[i].bBookCheck = true;
						break;
					}
				}
			}
			break;
		case MENU_PRINT:
			system("cls");
			cout << "=========도서 목록=========" << endl << endl;
			if (iBookCount == 0) {
				cout << "등록된 책이 없습니다." << endl << endl;
				break;
			}
			for (int i = 0; i < iBookCount; ++i) {
				cout << "도서명 : " << tBookArr[i].strBookName << endl;
				cout << "도서번호 : " << tBookArr[i].iBookNo << endl;
				cout << "대여가격 : " << tBookArr[i].iBookPrice << endl;
				if(tBookArr[i].bBookCheck)
					cout << "대여여부 : 가능" << endl;
				else
					cout << "대여여부 : 불가능" << endl;

				cout << "---------------------------------" << endl << endl;
			}
			break;
		default:
			cout << "잘못 입력하셨습니다. 초기화면으로 돌아갑니다.";
			system("pause");
			continue;
		}
		system("pause");
	}

	return 0;
}
*/