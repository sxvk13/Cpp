/*
	실제 구현부
*/
/*
#include "List.h"

//학생 출력함수
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
void Search(PLIST pList)
{
	system("cls");
	cout << "=========== 학생 탐색 =============" << endl;

	cout << "탐색할 이름을 입력하세요 : ";

	char strName[NAME_SIZE] = {};
	
	InputString(strName,NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd) {
		if (strcmp(strName, pNode->tStudent.strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "해당 학생을 찾을 수 없습니다." << endl;
	system("pause");
}
void Delete(PLIST pList)
{
	system("cls");
	cout << "=========== 학생 삭제 =============" << endl;
	cout << "삭제할 이름을 입력하세요 : ";

	char strName[NAME_SIZE] = {};

	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
		
			//현재 지울노드의 이전노드의 다음은 현재 지울 노드로 되어있음.
			//지울 노드는 지워져야 하기 때문에 이전노드의 다음노드를
			//지울 노드의 다음 노드로 주고
			//다음 노드의 이전은 현재 노드의 이전 노드로 준다.
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << "학생을 삭제하였습니다." << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "해당 학생을 찾을 수 없습니다." << endl;
	system("pause");
}
void Sort(PLIST pList)
{
	int iMenu;

	system("cls");
	cout << "=========== 목록 정렬 =============" << endl;
	cout << "1. 학번정렬" << endl;
	cout << "2. 평균정렬" << endl;
	cout << "정렬 기준을 선택하세요 : ";
	iMenu = InputInt();
	if (iMenu <= ST_NONE || iMenu > ST_AVERAGE) {
		cout << "잘못 입력하셨습니다.";
		system("pause");
		return;
	}
	cout << endl;
	cout << "1. 오름차순" << endl;
	cout << "2. 내림차순" << endl;
	cout << "정렬 방식을 선택하세요 : ";
	int iOption = InputInt();
	if (iMenu <= SO_NONE || iMenu > SO_DESC) {
		cout << "잘못 입력하셨습니다.";
		system("pause");
		return;
	}

	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = NULL;


	// First는 End의 이전 노드와 같아지게 되면 더이상 비교할 노드가 없으므로
	// 종료한다.
	while (pFirst != pList->pEnd->pPrev) {
		//Second 는 무조건 First 노드 다음노드무터 검사
		pSecond = pFirst->pNext;
		//Second는 End 이전까지 반복해야 하므로 End가 아닐동안만 반복
		while (pSecond != pList->pEnd) {
			bool bSwap = false;

			switch (iMenu) {
			case ST_NO:
				switch (iOption) {
				case SO_ASC:
					if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber) {
						bSwap = true;
					}
					break;
				case SO_DESC:
					if (pFirst->tStudent.iNumber < pSecond->tStudent.iNumber) {
						bSwap = true;
					}
					break;
				}
				break;
			case ST_AVERAGE:
				switch (iOption) {
				case SO_ASC:
					if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg) {
						bSwap = true;
					}
					break;
				case SO_DESC:
					if (pFirst->tStudent.fAvg < pSecond->tStudent.fAvg) {
						bSwap = true;
					}
					break;
				}
				break;
			}
			//bool변수 bSwap이 true일 경우 두 노드를 바꿔야 함.
			if (bSwap) {
				//바꿀 노드의 기존 앞,뒤 노드(pPrev,pNext)를 저장

				//기존 pFirst의 이전 노드
				//기존 pFirst의 다음 노드
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;

				//기존 pSecond의 이전 노드
				//기존 pSecond의 다음 노드
				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;


				//위에서 두 노드가 서로 바꼈으므로 연결되어있던 pNext와 pPrev도 바꿔
				//주어야 한다. 그래서 pFirstPrev 노드의 다음노드로 바뀐 pFirst를 지정
				//하고 바뀐 pFirst의 이전 노드를 pFirstPrev노드를 지정해 준다.
				//다음 노드들도 마찬가지로 교체해 주어야한다.

				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;
				//*********두 노드가 붙어있을 경우와 붙어있지 않은 경우의 처리가 중요
				//바꾸려는 두 노드가 붙어있지 않은 경우
				if (pSecond != pFirstNext) {

					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;
				}
				//붙어 있는경우
				else {
					pSecond->pNext = pFirst;
					pFirst->pPrev = pSecond;
				}

				pSecondNext->pPrev = pFirst;
				pFirst->pNext = pSecondNext;

				//두 노드를 바꿔줌.
				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;
			}
			pSecond = pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}

	cout << "정렬을 완료하였습니다. " << endl;
	system("pause");
}
//리스트 구조체 초기화 함수
void InitList(PLIST pList) {
	pList->iSize = 0;
	//리스트의 pBegin과 pEnd의 메모리를 동적할당
	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	// 시작노드의 다음노드는 마지막 노드이다.
	pList->pBegin->pNext = pList->pEnd;

	// 마지막노드의 이전노드는 시작 노드이다.
	pList->pEnd->pPrev = pList->pBegin;

	// 마지막 노드의 다음 노드는 없으므로 NULL로 해준다.
	pList->pEnd->pNext = NULL;

	// 시작 노드의 이전 노드는 없으므로 NULL로 해준다.
	pList->pBegin->pPrev = NULL;

}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	
	while (pNode != NULL) {
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;

}

void Push_Back(PLIST pList)
{
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
	cout << "합계 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	//추가할 리스트 노드를 생성한다.
	PNODE	pNode = new NODE;
	pNode->tStudent = tStudent;


	//새로 추가되는 노드는 pEnd노드의 이전노드와 pEnd노드 사이에 추가해야함.
	//그래서 pEnd의 pPrev노드를 구해놓음.
	PNODE pPrev = pList->pEnd->pPrev;

	//pEnd 노드 이전 노드의 다음으로 추가할 노드를 지정.
	pPrev->pNext = pNode;
	//추가할 노드의 이전 노드로 pEnd의 이전 노드를 지정
	pNode->pPrev = pPrev;

	//새로 추가할 노드의 다음 노드를 pEnd에 연결
	pNode->pNext = pList->pEnd;
	//pEnd노드의 이전 노드로 새로 추가할 노드를 지정
	pList->pEnd->pPrev = pNode;

	++pList->iSize;

	system("pause");
}

void Push_Front(PLIST pList)
{
}

void Output(PLIST pList)
{
	int iMenu;
	while (true) {

		system("cls");
		cout << "===================== 학생 출력 ======================" << endl;
		cout << "1. 정방향 출력" << endl;
		cout << "2. 역방향 출력" << endl;
		cout << "메뉴를 선택하세요 : ";
		iMenu = InputInt();
		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
			break;
	}
	PNODE	pNode=NULL;
	switch (iMenu) {
	case OT_OUTPUT:
		//추가되는 노드들은 pBegin과 pEnd 사이에 배치됨.
		//따라서 pBegin의 다음 노드를 얻어옴.
		pNode = pList->pBegin->pNext;

		//마지막으로 추가된 노드는 pEnd의 이전까지 이므로
		//노드가 pEnd와 일치할 경우에 반복문 종료.
		while (pNode != pList->pEnd) {

			OutputStudent(&pNode->tStudent);

			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		
		//역방향으로 출력을 할때는 pEnd의 이전 노드를 얻어와 계속 이전노드로 진행.
		//따라서 pBegin과 일치할 경우 반복문 종료.
		pNode = pList->pEnd->pPrev;

		while (pNode != pList->pBegin) {

			OutputStudent(&pNode->tStudent);

			pNode = pNode->pPrev;
		}
		break;
	}

	cout << "학생 수 : " << pList->iSize << endl;

	system("pause");
}

*/
