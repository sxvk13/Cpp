/*
#include <iostream>
using namespace std;

#define NAME_SIZE			32

enum MAP_TYPE {
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_END
};
enum TOOL_MENU {
	TM_NONE,
	TM_ADD,
	TM_LOAD,
	TM_SAVE,
	TM_OUTPUT,
	TM_EXIT
};

struct _tagMonster {
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp; //사냥시 주는 경험치
	int		iLevel;
	int		iGoldMin; //최소 드랍 골드
	int		iGoldMax;// 최대 드랍 골드
};

int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		// 잘못된 입력값을 의미하는 INT_MAX 리턴 ;
		return INT_MAX;
	}
	return iInput;
}

void AddMonster(_tagMonster* pMonsterArr) {
	system("cls");
	int iMap = 0;
	while (true) {
		cout << "1.쉬움" << endl;
		cout << "2.보통" << endl;
		cout << "3.어려움" << endl;
		cout << "4.취소" << endl;
		cout << "추가할 난이도를 선택하세요 : ";
		iMap = InputInt();
		
		if (iMap == 4)
			return;
		else if (iMap < 1 || iMap>4)
			continue;
		// 1부터 시작이기 때문에 1을 감소해야 사냥터 인덱스가 됨.
		--iMap;
		break;
	}

	cin.clear();
	cin.ignore(1042, '\n');

	//몬스터 이름을 입력받음
	cout << "이름 : ";
	//문자열의 끝은 NULL이 들어가야하기 때문에 NAEM_SIZE -1을 해준다.
	cin.getline(pMonsterArr[iMap].strName, NAME_SIZE - 1);
	
	//최소 공격력 및 최대 공격력
	cout << "최소 공격력 : ";
	pMonsterArr[iMap].iAttackMin = InputInt();
	cout << "최대 공격력 : ";
	pMonsterArr[iMap].iAttackMax = InputInt();
	//최소 방어력 및 최대 방어력
	cout << "최소 방어력 : ";
	pMonsterArr[iMap].iArmorMin = InputInt();
	cout << "최대 방어력 : ";
	pMonsterArr[iMap].iArmorMax = InputInt();
	//체력
	cout << "체력 : ";
	pMonsterArr[iMap].iHP = InputInt();
	pMonsterArr[iMap].iHPMax = pMonsterArr[iMap].iHP;
	//마력
	cout << "마력 : ";
	pMonsterArr[iMap].iMP= InputInt(); 
	pMonsterArr[iMap].iMPMax = pMonsterArr[iMap].iMP;
	//최초 설정 레벨
	cout << "레벨 : ";
	pMonsterArr[iMap].iLevel= InputInt();
	//획득 경험치
	cout << "경험치 : ";
	pMonsterArr[iMap].iExp= InputInt();
	//최소 드랍골드 및 최대 드랍골드
	cout << "최소 드랍 골드 : ";
	pMonsterArr[iMap].iGoldMin= InputInt();
	cout << "최대 드랍 골드 : ";
	pMonsterArr[iMap].iGoldMax= InputInt();


	cout << "몬스터 추가 완료! " << endl;
	system("pause");
}

bool SaveMonster(_tagMonster* pMonsterArr) {
	FILE* pFile = NULL;
	fopen_s(&pFile, "Monster.mst", "wb");
	if (pFile) {
		fwrite(pMonsterArr,sizeof(_tagMonster),MT_END,pFile);
		fclose(pFile);
		return true;
	}
	return false;
}

bool LoadMonster(_tagMonster* pMonsterArr) {
	FILE* pFile = NULL;
	fopen_s(&pFile, "Monster.mst", "rb");
	if (pFile) {
		fread(pMonsterArr, sizeof(_tagMonster), MT_END, pFile);
		fclose(pFile);
		return true;
	}
	return false;
}

void OutputMonster(_tagMonster* pMonster) {
	//몬스터 정보 출력.

	cout << "=======================Monster=======================" << endl;
	cout << "이름 : " << pMonster->strName << "\t레벨 :" <<
		pMonster->iLevel << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " <<
		pMonster->iAttackMax << "\t방어력 : " << pMonster->iArmorMin << " - " <<
		pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t마력 : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "획득경험치 : " << pMonster->iExp << "\t획득골드 : " <<
		pMonster->iGoldMin << " - " << pMonster->iGoldMax << " Gold " << endl << endl << endl;

}

void Output(_tagMonster* pMonsterArr) {
	system("cls");
	for (int i = 0; i < MT_END; ++i) {
		OutputMonster(&pMonsterArr[i]);
	}
	system("pause");
}
int main() {
	
	_tagMonster tMonster[MT_END] = {};
	while (true) {
		system("cls");
		cout << "1.몬스터추가" << endl;
		cout << "2.읽어오기" << endl;
		cout << "3.저장" << endl;
		cout << "4.몬스터 출력" << endl;
		cout << "5.종료" << endl;
		cout << "메뉴를 선택하세요 : " ;
		int iMenu=InputInt();
		if (iMenu == TM_EXIT)
			break;

		switch (iMenu) {
		case TM_ADD:
			AddMonster(tMonster);
			break;
		case TM_LOAD:
			LoadMonster(tMonster);
			break;
		case TM_SAVE:
			SaveMonster(tMonster);
			break;
		case TM_OUTPUT:
			Output(tMonster);
			break;
		}
	}
	//자동 저장기능
	SaveMonster(tMonster);
	
	return 0;

}
*/