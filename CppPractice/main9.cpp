/*
	21 Lecture ( Student Management Program)
*/
/*
#include <iostream>

using namespace std;

//학생 정보
#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14

//학생 최대 저장수
#define STUDENT_MAX 10

//학생 구조체
struct _tagStudent {
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];

	int iNumber, iKor, iEng, iMath, iTotal;

	float fAvg;
};

//메뉴 열거형

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUPUT,
	MENU_EXIT
};



int main() {
	
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	//배열에 추가된 개수를 저장할 변수를 만들어줌.
	int iStudentCount = 0;
	int iStdNumber = 1;
	char strSearchName[NAME_SIZE] = {};
	while (true) {
		system("cls");
		cout << "==================학생관리 프로그램==================" << endl<<endl;
		cout << "***********************메뉴**************************" << endl << endl;
		cout << "1. 학생 등록" << endl;
		cout << "2. 학생 삭제" << endl;
		cout << "3. 학생 탐색" << endl;
		cout << "4. 학생 출력" << endl;
		cout << "5. 나가기" << endl << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;
		//cin은 만약 오른쪽에 int 변수가 오면 정수를 입력해야 한다. 오른쪽에 오는 변수 
		//타입에 맞춰서 값을 입력해야 하는데 실수로 정수가 아닌 문자를 입력할 경우
		//에러가 발생한다. 그렇기 때문에 예외처리로 에러가 발생했는지를 여기에서 체크하여
		// 에러가 발생하면 cin 내부의 에러버퍼를 비워주고 cin 내부에 입력버퍼가 있는데
		//입력버퍼는 입력한 값을 저장 해놓고 그 값을 변수에 넣어주는 역할을 한다.
		//이 입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 \n을 지워준다.
		//버퍼 : 임시 저장 공간이다.
		
		//먼저 에러를 체크함.
		//cin.fail()을 했을때 입력에러가 발생했을 경우 true를 반환함.
		if (cin.fail()) {
			//애러 버퍼를 비워준다.
			cin.clear();
			//입력버퍼를 검색하여 \n을 지워준다.
			//첫번째에는 검색하고자 하는 버퍼크기를 지정한다. 넉넉하게 1024
			//바이트 정도 지정해준다. 2번째에는 찾고자 하는 문자를 넣어준다.
			//그래서 입력버퍼 처음부터 \n이 있는 곳까지 찾아서 그 부분을 모두 
			// 지워줘서 다시 입력받을수 있게 한다.
			cin.ignore(1024, '\n');
			continue;
		}
		// 나가기 메뉴 선택했을경우 반복문 탈출
		if (iMenu == MENU_EXIT)
			break;


		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "==================학생 추가==================" << endl << endl;

			//등록된 학생이 등록할 수 있는 최대치일 경우 더이상 등록이 안되게 막는다
			if (iStudentCount == STUDENT_MAX)
				break;

			//학생 정보를 추가한다. 학생정보는 이름,주소 ,전화번호
			//국어,영어, 수학 점수는 입력받고 한번 , 총점, 평균은 연산을
			//통해 계산해준다.
			// 이름을 입력받는다.
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			//cin과 cin.getline을 함께쓰면 '\n'으로 인해 에러가 발생하므로
			//입력버퍼를 \n까지 지워줌.
			cin.ignore(1024, '\n');
			
			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress,ADDRESS_SIZE);
			//cout << tStudentArr[iStudentCount].strAddress << endl;
			//cin.getline 다음에 다시 cin.getline을 사용할 때에는 문제가 되지 않으므로
			//cin.ignore를 사용하지 않음.

			cout << "전화번호 :";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);
			//cout << tStudentArr[iStudentCount].strPhoneNumber << endl;
			while (true) {
				cout << "국어 : ";
				cin >> tStudentArr[iStudentCount].iKor;
				if (tStudentArr[iStudentCount].iKor > 100 || tStudentArr[iStudentCount].iKor < 0) {
					cout << "잘못 입력하셨습니다!(사유 : 범위 초과)" << endl;
					cout << "다시 입력해 주세요." << endl;
					continue;
				}
				else {
					break;
				}
			}
				
			while (true) {
				cout << "영어 : ";
				cin >> tStudentArr[iStudentCount].iEng;
				if (tStudentArr[iStudentCount].iEng > 100 || tStudentArr[iStudentCount].iEng < 0) {
					cout << "잘못 입력하셨습니다!(사유 : 범위 초과)" << endl;
					cout << "다시 입력해 주세요." << endl;
					continue;
				}
				else {
					break;
				}
			}
				
			while (true) {
				cout << "수학 : ";
				cin >> tStudentArr[iStudentCount].iMath;
				if (tStudentArr[iStudentCount].iMath > 100 || tStudentArr[iStudentCount].iMath < 0) {
					cout << "잘못 입력하셨습니다!(사유 : 범위 초과)" << endl;
					cout << "다시 입력해 주세요." << endl;
					continue;
				}
				else {
					break;
				}
			}
			
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;
			tStudentArr[iStudentCount].iNumber = iStdNumber;
			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료 " << endl;

			break;
		case MENU_DELETE:
			system("cls");
			cout << "==================학생 삭제==================" << endl << endl;
			//char strSearchName[NAME_SIZE] = {};
			//switch 내부에 변수를 선언과 동시에 초기화 할 수 없음.
			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 : ";
			cin.getline(strSearchName, NAME_SIZE);

			//등록되어있는 학생 수만큼 반복하며 학생을 찾음.
			for (int i = 0; i < iStudentCount; ++i) {
				//학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strSearchName) == 0) {
					//찾은 학생의 인덱스가 마지막일 경우
					if (i == iStudentCount - 1) {
						//해당 인덱스를 초기화
						tStudentArr[i] = {};
						cout << "삭제되었습니다." << endl << endl;
					}
					//인덱스가 마지막이 아닌 경우
					else {
						//해당 인덱스 부터 시작하여 한칸씩 덮어 씌움
						for (int j = i; j < iStudentCount-1; ++j) {
							tStudentArr[j] = tStudentArr[j + 1];
						}
						cout << "삭제되었습니다." << endl << endl;
					}
					--iStudentCount;
					break;
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "==================학생 탐색==================" << endl << endl;
			//char strSearchName[NAME_SIZE] = {};
			//switch 내부에 변수를 선언과 동시에 초기화 할 수 없음.
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strSearchName, NAME_SIZE);

			//등록되어있는 학생 수만큼 반복하며 학생을 찾음.
			for (int i = 0; i < iStudentCount; ++i) {
				//학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strSearchName) == 0) {
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl;
					cout << "---------------------------------" << endl << endl;
					break;
				}
			}
			break;
		case MENU_OUPUT:
			system("cls");
			cout << "==================학생 출력==================" << endl << endl;
			//만약 등록된 학생이 없을 경우 
			if (iStudentCount == 0) {
				cout << "현재 등록된 학생이 없습니다!" << endl<<endl;
				break;
			}

			//등록된 학생 수만큼 반복하며 학생정보를 출력한다.
			for (int i = 0; i < iStudentCount; ++i) {
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl;
				cout << "---------------------------------"<<endl<< endl;
			}
			break;
		default:
			cout << " 메뉴를 잘못 입력하셨습니다." << endl;
			break;
		}
		system("pause");
	}

	return 0;

}
*/