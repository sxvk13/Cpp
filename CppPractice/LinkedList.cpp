/*
#include <iostream>
using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

#define NAME_SIZE 32
#define STUDENT_MAX 10
typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;

}STUDENT, *PSTUDENT;


// 링크드리스트 : 자료구조의 한 종류이다. 자료구조란 데이터를 관리하는 방법을 말한다.
// 링크드리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 제공한다.
// 링크드리스트는 데이터를 저장하기 위한 노드라는 것이 존재한다. 각 노드의 특징은
// 다음 노드를 알 수 있게 된다. ( 다음 노드의 메모리 주소를 저장한다는 의미)
// 리스트는 선형구조로 되어있으므로 배열처럼 특정 요소에 바로 접근이 불가능하다.
// 무조건 앞에서부터 차례대로 타고 들어가야 한다.
// 노드를 새로 추가할 때는 노드를 생성하고 마지막 노드에 연결만 해주면 되기 때문에
// 개수의 제한이 없다.

// 리스트 노드를 만든다.
typedef struct _tagNode {
	STUDENT		tStudent;
	_tagNode*	pNext;
}NODE, *PNODE;

//리스트 구조체를 만들어 준다.
typedef struct _tagList {
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;

}LIST, *PLIST;

void InitList(PLIST pList) {
	//포인터는 가급적이면 초기화 할때 NULL(0) 으로 초기화 해두고 쓰는것이 좋다.
	//왜냐하면 0은 false, 0이 아닌 모든수는 true이기 때문에 쓰레기값 조차 true이다.

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

void InputString(char* pString, int iSize) {
	
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);

}

int OutputMenu() {
	system("cls");
	cout << "1. 학생추가 " << endl;
	cout << "2. 학생삭제 " << endl;
	cout << "3. 학생탐색 " << endl;
	cout << "4. 학생출력 " << endl;
	cout << "5. 종료" << endl;

	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();
	// 입력범위 초과
	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
	
}

void Insert(PLIST pList) {
	system("cls");
	cout << "=========== 학생 추가 =============" << endl;

	STUDENT		tStudent = {};
	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "학번 : ";
	tStudent.iNumber = InputInt();
	cout << "국어 : ";
	tStudent.iKor = InputInt();
	cout << "영어 : ";
	tStudent.iEng = InputInt();
	cout << "수학 : ";
	tStudent.iMath = InputInt();
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = (float)tStudent.iTotal / 3;
	cout << "합계 : "<< tStudent.iTotal<<endl;
	cout << "평균 : "<< tStudent.fAvg<<endl ;

	//추가할 리스트 노드를 생성한다.
	PNODE	pNode = new NODE;
	
	// 현재 추가하는 노드는 가장 마지막에 추가될 것이기 때문에 다음 노드가 존재하지 않음.
	// 그래서 다음 노드는 NULL로 초기화하고 정보는 위에서 입력받은 학생정보를 준다.
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;


	if (pList->pBegin == NULL) {
		pList->pBegin = pNode;	
	}
	else {
		pList->pEnd->pNext = pNode;
	}
	pList->pEnd = pNode;
	++pList->iSize;

	system("pause");
}

void ClearList(PLIST pList) {
	PNODE pNode = pList->pBegin;

	while (pNode != NULL) {
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;;
}


//const 포인터이기 때문에 가리키는 대상의 값을 변경할 수 없다.
void OutputStudent(const PSTUDENT pStudent) {
	cout << "이름 : " << pStudent->strName << endl;
	cout << "학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << endl;
	cout << "영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "합계 : " << pStudent->iTotal << endl;
	cout << "평균 : " << pStudent->fAvg << endl;
	cout << "---------------------------------------------------" << endl;
}


void Output(PLIST pList) {
	system("cls");
	cout << "===================== 학생 출력 ======================" << endl;
	PNODE	pNode = pList->pBegin;

	while (pNode != NULL) {
		
		OutputStudent(&pNode->tStudent);

		pNode = pNode->pNext;
	}

	cout << "학생 수 : " << pList->iSize << endl;

	system("pause");
}
void Search(PLIST pList) {
	system("cls");
	cout << "===================== 학생 탐색 ======================" << endl;
	cout << "탐색할 학생의 이름을 입력해 주세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName,NAME_SIZE);
	PNODE	pNode = pList->pBegin;
	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "찾을 학생이 없습니다." << endl;
	system("pause");
}

void Delete(PLIST pList) {
	system("cls");
	cout << "===================== 학생 삭제 ======================" << endl;
	cout << "삭제할 학생의 이름을 입력해 주세요 : ";
	char	strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);
	PNODE pNode = pList->pBegin;
	PNODE pPrev= NULL;
	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			//지울 노드의 다음 노드를 얻어옴.
			PNODE pNext = pNode->pNext;
			//만약 이전 노드가 NULL이라면 제일 처음 노드를 지운다는 의미.
			if (pPrev == NULL) {
				delete pNode;
				pList->pBegin = pNext;
				if (pNext == NULL)
					pList->pEnd = NULL;
			}
			//이전 노드가 있을 경우에는 이전 노드의 다음을 지운 노드의 다음노드로 연결.
			else {
				delete pNode;
				pPrev->pNext = pNext;
				if (pNext == NULL)
					pList->pEnd = pPrev;
			}
			
			cout << "삭제 완료!" << endl;
			--pList->iSize;
			system("pause");
			return;
		}
		//해당학생이 아니라면 현재 학생이 이전 학생이 된다.
		pPrev = pNode;
		pNode = pNode->pNext;

	}
	cout << "삭제할 학생이 없습니다." << endl;
	system("pause");
}

int main() {

	LIST	tList;
	InitList(&tList);
	
	while (true) {
		int iMenu = OutputMenu();
		
		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
		case MM_NONE:
			break;
		case MM_INSERT:
			Insert(&tList);
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
		}
	}
	ClearList(&tList);
	return 0;

}
*/
