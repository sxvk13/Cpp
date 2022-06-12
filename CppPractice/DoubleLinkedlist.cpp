/*
//사용자정의 헤더파일은 ""를 사용
#include "List.h"
using namespace std;
//현재 구성되어있는 학생관리 프로그램 메인 메뉴에 정렬 기능을 추가한다.
//정렬 기준은 학번, 평균 기준으로 오름차순으로 정렬할 수 있는 기능을 만들어보자.



enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_SORT,
	MM_EXIT
};


int OutputMenu() {
	system("cls");
	cout << "1. 학생추가 " << endl;
	cout << "2. 학생삭제 " << endl;
	cout << "3. 학생탐색 " << endl;
	cout << "4. 학생출력 " << endl;
	cout << "5. 목록정렬 " << endl;
	cout << "6. 종료" << endl;

	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();
	// 입력범위 초과
	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;

}


int main() {

	//리스트 변수 생성
	LIST	tList;

	//생성된 리스트 변수에 대한 초기화 진행
	InitList(&tList);

	while (true) {
		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
		case MM_NONE:
			break;
		case MM_INSERT:
			Push_Back(&tList);
			break;
		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		case MM_SORT:
			Sort(&tList);
			break;
		}
	}

	DestroyList(&tList);

	return 0;
}
*/
