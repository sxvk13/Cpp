/*
	TexptRPG (Function ) Lecture Code
*/
#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};
enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};
// 문자열을 직접적으로 비교하는것 보다 
// 정수를 비교하는것이 빠르기 때문에 직업을
// 열거형으로 정의
enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};
enum ITEM_TYPE {
	ITEM_NONE,
	ITEM_WEAPON,
	ITEM_ARMOR,
	ITEM_BACK
};
enum WEAPON_LIST {
	WL_NONE,
	WL_SWORD,
	WL_BOW,
	WL_STAFF,
	WL_BACK
};
enum ARMOR_LIST {
	AL_NONE,
	AL_HEAD,
	AL_BODY,
	AL_FOOT,
	AL_BACK
};
enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};
enum EQUIP {
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};

#define NAME_SIZE			32
#define ITEM_DESC_LENGTH	512
#define INVENTORY_MAX		20
#define STORE_WEAPON_MAX	3
#define STORE_ARMOR_MAX		3
#define LEVEL_MAX			10

//레벨업에 필요한 경험치 목록을 만든다.
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };


struct _tagItem {
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory {
	_tagItem	tItem[INVENTORY_MAX];
	int		iItemCount;
	int		iGold;
};

struct _tagPlayer {
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp; //현재 경험치
	int		iLevel;
	_tagItem	tEquip[EQ_MAX]; // 장착한 아이템 종류
	bool		bEquip[EQ_MAX]; // 해당 종류 아이템 장착 여부
	_tagInventory	tInventory;
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

struct _tagLevelUpStatus {
	int	iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;
};

//숫자 입력을 받는다. 입력 오류까지 처리해 주고 INT_MAX를 리턴하면
//입력 오류이다.
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
//메인 메뉴를 화면에 보여주고 입력받은 메뉴를 반환한다.
//입력 오류일 경우 혹은 잘못된 번호일 경우 MM_NONE를 반환.
int OuputMainMenu() {
	system("cls");
	cout << "**********************로비**********************" << endl << endl;
	cout << "1. 맵 " << endl;
	cout << "2. 상점 " << endl;
	cout << "3. 가방 " << endl;
	cout << "4. 종료 " << endl;
	cout << "메뉴를 선택해 주세요 :";
	int iMenu = InputInt();
	if (iMenu == INT_MAX || iMenu <=MM_NONE||iMenu >MM_EXIT)
		return MM_NONE;

	return iMenu;
}

_tagMonster CreateMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin,
	int iArmorMax, int iHP, int iHPMax, int iMP, int iMPMAX, int iLevel, int iExp, int iGoldMin, int iGoleMax) {

	//몬스터 생성
	_tagMonster tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHPMax;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMPMAX;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoleMax;

	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr) {
	//몬스터의 정보를 정의함
	pMonsterArr[MT_EASY - 1] = CreateMonster("고블린", 20, 30, 2, 5, 100, 100, 10,
		10, 1, 1000, 500, 1500);
	pMonsterArr[MT_NORMAL - 1] = CreateMonster("트롤", 80, 130, 60, 90, 2000,
		2000, 100, 100, 5, 7000, 6000, 8000);
	pMonsterArr[MT_HARD - 1] = CreateMonster("드래곤", 250, 500, 200, 400,
		30000, 30000, 20000, 20000, 10, 30000, 20000, 50000);
}
void OutputBattleTag(MAP_TYPE eMenu) {
	switch (eMenu) {
	case MT_EASY:
		cout << "**********************쉬움**********************" << endl << endl;
		break;
	case MT_NORMAL:
		cout << "**********************보통**********************" << endl << endl;
		break;
	case MT_HARD:
		cout << "**********************어려움**********************" << endl << endl;
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer) {
	
	// 플레이어 정보를 출력한다.
	cout << "=======================Player=======================" << endl;
	cout << "이름 : " << pPlayer->strName << "\t직업 :" <<
		pPlayer->strJobName << endl;
	cout << "레벨 : " << pPlayer->iLevel << "\t경험치 :" <<
		pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
	// 무기를 장착하고  있을 경우 공격력에 무기 공격력을 추가하여 출력.

	if (pPlayer->bEquip[EQ_WEAPON] == true) {
		cout << "공격력 : " << pPlayer->iAttackMin << " + " <<
			pPlayer->tEquip[EQ_WEAPON].iMin << " - " <<
			pPlayer->iAttackMax << " + " << pPlayer->tEquip[EQ_WEAPON].iMax;
	}
	else {

		cout << "공격력 : " << pPlayer->iAttackMin << " - " <<
			pPlayer->iAttackMax;
	}

	//방어구를 장착하고 있을 경우 방어력에 방어구 방어구 방여력방어력을 추가하여 출려

	if (pPlayer->bEquip[EQ_ARMOR] == true) {
		cout << "\t방어력 : " << pPlayer->iArmorMax << " + " <<
			pPlayer->tEquip[EQ_ARMOR].iMin << " - " <<
			pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	}
	else {

		cout << "\t방어력 : " << pPlayer->iArmorMin << " - " <<
			pPlayer->iArmorMax << endl;
	}
	cout << "체력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t마력 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
	cout << "보유 골드 : " << pPlayer->tInventory.iGold << " Gold " << endl << endl;

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

int OutputBattleMenu() {

	cout << "1.공격" << endl;
	cout << "2.도망가기" << endl;
	cout << "선택해주세요 : ";

	int iAction = InputInt();

	if (iAction == INT_MAX || iAction <= BATTLE_NONE || iAction > BATTLE_BACK)
		return BATTLE_NONE;
	
	return iAction;
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, MAP_TYPE eMenu) {
	_tagMonster tMonster = pMonsterArr[eMenu - 1];

	while (true) {
		system("cls");
		OutputBattleTag(eMenu);
		//플레이어 출력
		OutputPlayer(pPlayer);
		//몬스터 출력
		OutputMonster(&tMonster);
		switch (OutputBattleMenu()) {
		case BATTLE_ATTACK:
			break;
		case BATTLE_BACK:
			return;
		}

	}
}

//맵 메뉴를 화면에 보여주고 입력받은 메뉴를 반환한다.
//입력 오류일 경우 혹은 잘못된 번호일 경우 MT_NONE를 반환.
int OutPutMapMenu() {
	system("cls");
	cout << "**********************맵**********************" << endl << endl;
	cout << "1.쉬움 " << endl;
	cout << "2.보통 " << endl;
	cout << "3.어려움 " << endl;
	cout << "4.뒤로가기 " << endl;
	cout << "맵을 선택하세요 : ";
	int iMenu = InputInt();
	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MT_NONE;
	
	return iMenu;
}
//맵 관련 동작 처리
void RunMap(_tagPlayer* pPlayer,_tagMonster* pMonsterArr) {
	bool	bLoop = true;
	while (bLoop) {
		int iMenu = OutPutMapMenu(); 
			
		if (MT_BACK == iMenu)
			return;
		//전투를 시작
		RunBattle(pPlayer, pMonsterArr, (MAP_TYPE)iMenu);
	}
}


int SelectJob() {
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1.기사" << endl;
		cout << "2.궁수" << endl;
		cout << "3.마법사" << endl;
		cout << "직업을 선택하세요 : ";
		iJob = InputInt();
		//직업의 범위를 벗어난 숫자를 입력했을경우
		//값을 JOB_NONE로 대입하여 다시 반복하도록 함.
		if(iJob==INT_MAX|| iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}
	return iJob;
}



void SetPlayer(_tagPlayer* pPlayer) {
	//플레이어 이름을 입력받음
	cout << "이름을 입력하세요 : ";
	//문자열의 끝은 NULL이 들어가야하기 때문에 NAEM_SIZE -1을 해준다.
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
	//시작시 Player의 고정적인 정보
	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;
	pPlayer->tInventory.iItemCount = 0;
	pPlayer->tInventory.tItem[INVENTORY_MAX - 1] = {};


	//위에서 직업을 선택함과 동시에 범위를 한정하였기때문에
	//해당 switch문에서 default 값을 설정해줄 필요가 없음.
	//각 직업별로 능력치가 다르기 때문에 각각의 능력치를 설정해줌.
	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "기사");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMPMax = 100;
		pPlayer->iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "궁수");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 25;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMPMax = 200;
		pPlayer->iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "마법사");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMPMax = 300;
		pPlayer->iMP = 300;
		break;
	}
}

void SetWeapon(_tagItem* pStoreWeapon) {
	//무기상점.
	strcpy_s(pStoreWeapon[0].strName, "롱소드");
	strcpy_s(pStoreWeapon[0].strTypeName, "무기");
	strcpy_s(pStoreWeapon[0].strDesc, "큰칼입니다.");
	pStoreWeapon[0].iPrice = 3000;
	pStoreWeapon[0].iSell = 1500;
	pStoreWeapon[0].iMax = 15;
	pStoreWeapon[0].iMin = 10;
	pStoreWeapon[0].eType = (ITEM_TYPE)ITEM_WEAPON;

	strcpy_s(pStoreWeapon[1].strName, "장궁");
	strcpy_s(pStoreWeapon[1].strTypeName, "무기");
	strcpy_s(pStoreWeapon[1].strDesc, "큰활입니다.");
	pStoreWeapon[1].iPrice = 3000;
	pStoreWeapon[1].iSell = 1500;
	pStoreWeapon[1].iMax = 15;
	pStoreWeapon[1].iMin = 10;
	pStoreWeapon[1].eType = (ITEM_TYPE)ITEM_WEAPON;

	strcpy_s(pStoreWeapon[2].strName, "스태프");
	strcpy_s(pStoreWeapon[2].strTypeName, "무기");
	strcpy_s(pStoreWeapon[2].strDesc, "지팡이입니다.");
	pStoreWeapon[2].iPrice = 3000;
	pStoreWeapon[2].iSell = 1500;
	pStoreWeapon[2].iMax = 15;
	pStoreWeapon[2].iMin = 10;
	pStoreWeapon[2].eType = (ITEM_TYPE)ITEM_WEAPON;

}
void SetArmor(_tagItem* pStoreArmor) {
	//방어구 상점.
	strcpy_s(pStoreArmor[0].strName, "투구");
	strcpy_s(pStoreArmor[0].strTypeName, "방어구");
	strcpy_s(pStoreArmor[0].strDesc, "투구입니다.");
	pStoreArmor[0].iPrice = 3000;
	pStoreArmor[0].iSell = 1500;
	pStoreArmor[0].iMax = 15;
	pStoreArmor[0].iMin = 10;
	pStoreArmor[0].eType = (ITEM_TYPE)ITEM_ARMOR;

	strcpy_s(pStoreArmor[1].strName, "갑옷");
	strcpy_s(pStoreArmor[1].strTypeName, "방어구");
	strcpy_s(pStoreArmor[1].strDesc, "갑옷입니다.");
	pStoreArmor[1].iPrice = 3000;
	pStoreArmor[1].iSell = 1500;
	pStoreArmor[1].iMax = 15;
	pStoreArmor[1].iMin = 10;
	pStoreArmor[1].eType = (ITEM_TYPE)ITEM_ARMOR;

	strcpy_s(pStoreArmor[2].strName, "신발");
	strcpy_s(pStoreArmor[2].strTypeName, "방어구");
	strcpy_s(pStoreArmor[2].strDesc, "신발입니다.");
	pStoreArmor[2].iPrice = 3000;
	pStoreArmor[2].iSell = 1500;
	pStoreArmor[2].iMax = 15;
	pStoreArmor[2].iMin = 10;
	pStoreArmor[2].eType = (ITEM_TYPE)ITEM_ARMOR;
}

int main(){
	srand((unsigned int)time(0));
	
	//게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};

	_tagMonster tMonsterArr[MT_BACK - 1] = {};
	// 상점에서 판매할 아이템 목록을 생성한다.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	//플레이어의 정보를 정의함
	SetPlayer(&tPlayer);
	//몬스터의 정보를 정의함
	SetMonster(tMonsterArr);
	//아이템 정보를 정의함
	SetWeapon(tStoreWeapon);
	SetArmor(tStoreArmor);



	bool	bLoop = true;
	while (bLoop) {
		switch (OuputMainMenu()) {
		case MM_MAP:
			RunMap(&tPlayer,tMonsterArr); //맵 관련 루프를 처리
			break;
		case MM_STORE:
			bLoop = true;
			break;
		case MM_INVENTORY:
			bLoop = true;
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}
	return 0;
}