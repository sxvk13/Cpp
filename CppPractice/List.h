/*
//#pragma once : 이 헤더파일을 딱 1번만 포함시키겠다는 의미.
#pragma once


#include <iostream>

using namespace std;

enum OUTPUT_TYPE {
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE
};

enum SORT_TYPE {
	ST_NONE,
	ST_NO,
	ST_AVERAGE
};
enum SORT_OPTION {
	SO_NONE,
	SO_ASC,
	SO_DESC
};
// 헤더파일에는 보통 함수 선언부분을 만들어준다.
#define NAME_SIZE 32

//학생의 정보를 가지고 있는 구조체 
typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;

}STUDENT, * PSTUDENT;

//노드 구조체
typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, * PNODE;

//링크드 리스트 구조체
typedef struct _tagList {

	//pBegin 과 pEnd 는 명시적으로 처음과 끝을 의미하도록 만든다.
	//실제 데이터를 저장하는 노드는 아니다.
	//실제 데이터를 저장하는 노드는 pBegin 과 pEnd 사이에 존재하게 만들어준다.
	PNODE	pBegin;
	PNODE	pEnd;
	int		iSize;
}LIST, * PLIST;


//헤더파일에 선언과 정의를 전부 구현할 경우에 중복오류가 발생할 수 있으므로
//정의 부분에 static을 붙여줘야 안전함.

static int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

static void InputString(char* pString, int iSize) {

	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);

}

void InitList(PLIST pList);
//void ClearList(PLIST pList);
void DestroyList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void Output(PLIST pList);
void OutputStudent(const PSTUDENT pStudent);
void Search(PLIST pList);
void Delete(PLIST pList);
void Sort(PLIST pList);
*/
