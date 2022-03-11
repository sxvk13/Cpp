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
_tagLevelUpStatus CreateLvUpstate(int iAttackMin, int iAttackMax,
	int iArmorMin, int iArmorMax, int iHPMin, int iHPMax,
	int iMPMin, int iMPMax) {
	_tagLevelUpStatus tStatus = {};
	tStatus.iAttackMin = iAttackMin;
	tStatus.iAttackMax = iAttackMax;
	tStatus.iArmorMin = iArmorMin;
	tStatus.iArmorMax = iArmorMax;
	tStatus.iHPMin = iHPMin;
	tStatus.iHPMax = iHPMax;
	tStatus.iMPMin = iMPMin;
	tStatus.iMPMax = iMPMax;

	return tStatus;
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

//레벨업에 필요한 경험치 목록을 만든다.
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

//직업별 성장치 테이블
_tagLevelUpStatus	g_tLvUpTable[JOB_END - 1] = {};


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
	if (pPlayer->bEquip[EQ_WEAPON]) {
		cout << "장착무기 : " << pPlayer->tEquip[EQ_WEAPON].strName;
	}
	else
		cout << "장작무기 : 없음";
	if (pPlayer->bEquip[EQ_ARMOR]) {
		cout << "\t장착방어구 : " << pPlayer->tEquip[EQ_ARMOR].strName << endl;
	}
	else {
		cout << "\t\t장착방어구 :없음" << endl;
	}
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


void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster) {
	//예를 들어 Min 5 Max 15 라고 가정할 경우
						// 15 - 5 +1 을 하면 11 이 되고, 11로 나눈 나머지는 0~10이 나옴.
						// 여기에 Min값인 5를 더하게 되면 5~15 사이로 값이 나오게 된다.
	int iAttackMin = pPlayer->iAttackMin;
	int iAttackMax = pPlayer->iAttackMax;

	//무기를장착하고 있을 경우 무기와 Min , Max를 더해준다
	if (pPlayer->bEquip[EQ_WEAPON]) {
		iAttackMin += pPlayer->tEquip[EQ_WEAPON].iMin;
		iAttackMax += pPlayer->tEquip[EQ_WEAPON].iMax;
	}


	int iAttack = rand() % (iAttackMax - iAttackMin + 1) +
		iAttackMin;
	int iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMin + 1) +
		pMonster->iArmorMin;
	//최소 데미지 설정
	//int iDamage = ((iAttack - iArmor)<1)?1:(iAttack-iArmor);
	int iDamage = iAttack - iArmor;
	iDamage = iDamage < 1 ? 1 : iDamage;

	//몬스터 HP를 감소 시킨다.
	pMonster->iHP -= iDamage;

	cout << pPlayer->strName << " 가 " << pMonster->strName << " 에게 "
		<< iDamage << "만큼의 피해를 입혔습니다." << endl;

	// 몬스터가 죽었을 경우를 처리
	if (pMonster->iHP <= 0) {
		cout << pMonster->strName << " 몬스터가 사망하였습니다." << endl << endl;

		pPlayer->iExp += pMonster->iExp;
		int iGold = (rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1)
			+ pMonster->iGoldMin);
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << "경험치를 획득하였습니다. " << endl;
		cout << iGold << " Gold를 획득하였습니다." << endl;


		//재 전투를 위한 몬스터 초기화
		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		//레벨업을 했는지 체크
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1]) {
			if (pPlayer->iLevel < LEVEL_MAX) {
				// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
				pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];
				//레벨을 증가시킨다.
				++pPlayer->iLevel;

				cout << "LV" << pPlayer->iLevel << "(으)로 레벨업 하였습니다." << endl;

				//능력치 상승
				//직업 인덱스를 구함.
				int iJobIndex = pPlayer->eJob - 1;

				int iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) +
					g_tLvUpTable[iJobIndex].iHPMin;
				int iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMin + 1) +
					g_tLvUpTable[iJobIndex].iMPMin;

				pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;
				pPlayer->iAttackMax += g_tLvUpTable[iJobIndex].iAttackMax;
				pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iArmorMin;
				pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iArmorMax;

				pPlayer->iHPMax += iHPUp;
				pPlayer->iMPMax += iMPUp;

				// 체력과 마나를 회복시킨다.

				pPlayer->iHP = pPlayer->iHPMax;
				pPlayer->iMP = pPlayer->iMPMax;
			}
			else {
				pPlayer->iExp = g_iLevelUpExp[pPlayer->iLevel - 1];
				cout << "레벨이 최대치 입니다." << endl;
			}
		}
		return;
	}
		// 몬스터가 살아있다면 플레이어를 공격한다.
		iAttack = rand() % (pMonster->iAttackMax - pMonster->iAttackMin + 1) +
			pMonster->iAttackMin;

		int iArmorMin = pPlayer->iArmorMin;
		int iArmorMax = pPlayer->iArmorMax;

		if (pPlayer->bEquip[EQ_ARMOR]) {
			iArmorMin += pPlayer->tEquip[EQ_ARMOR].iMin;
			iArmorMax += pPlayer->tEquip[EQ_ARMOR].iMax;
		}
		iArmor = rand() % (iArmorMax - iArmorMin + 1) +
			iArmorMin;
		//최소 데미지 설정
		//int iDamage = ((iAttack - iArmor)<1)?1:(iAttack-iArmor);
		iDamage = iAttack - iArmor;
		iDamage = iDamage < 1 ? 1 : iDamage;

		//Player의 HP를 감소 시킨다.
		pPlayer->iHP -= iDamage;

		cout << pMonster->strName << " 가 " << pPlayer->strName << " 에게 "
			<< iDamage << "만큼의 피해를 입혔습니다." << endl;

		//Player가 죽었을 경우 처리
		if (pPlayer->iHP <= 0) {
			cout << pPlayer->strName << " Player가 사망하였습니다." << endl;

			int iExp = pPlayer->iExp * 0.1f;
			int iGold = pPlayer->tInventory.iGold * 0.1f;

			pPlayer->iExp -= iExp;
			pPlayer->tInventory.iGold -= iGold;

			cout << iExp << " 의 경험치를 잃었습니다. " << endl;
			cout << iGold << " 의 Gold를 잃었습니다." << endl;

			// Player 의 사망후 부활
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}
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
			Battle(pPlayer, &tMonster);
			system("pause");
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



//맵 관련 동작 처리
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr) {
	bool	bLoop = true;
	while (bLoop) {
		int iMenu = OutPutMapMenu();

		if (MT_BACK == iMenu)
			return;
		//전투를 시작
		RunBattle(pPlayer, pMonsterArr, (MAP_TYPE)iMenu);
	}
}


int OutputStoreMenu() {
	system("cls");
	cout << "**********************상점**********************" << endl << endl;
	cout << "1.무기 " << endl;
	cout << "2.방어구 " << endl;
	cout << "3.뒤로가기 " << endl;
	cout << "선택해 주세요 : ";
	int iMenu = InputInt();
	if (iMenu == INT_MAX || iMenu <= SM_NONE || iMenu > SM_BACK)
		iMenu = SM_NONE;

	return iMenu;

}

int OutputStoreItemList(_tagInventory* pInventory, _tagItem* pStore, int iItemCount) {
	for (int i = 0; i < iItemCount; ++i) {
	cout << i+1 << ". 이름 : " << pStore[i].strName <<
		"\t종류 : "<<pStore[i].strTypeName<<endl;
	cout << "공격력 : " << pStore[i].iMin << " - " <<
		pStore[i].iMax << endl;
	cout << "판매 가격 : " << pStore[i].iPrice <<
		"\t구매 가격 : " << pStore[i].iSell << endl;
	cout << "설명 : "<< pStore[i].strDesc << endl << endl;

	}
	cout << iItemCount + 1 << " . 뒤로가기 " << endl;

	cout << "보유 금액 : " << pInventory->iGold << " Gold" << endl;
	cout << "남은 공간 : " << INVENTORY_MAX - pInventory->iItemCount << "칸" << endl;

	cout << "구입할 아이템을 선택하세요 : ";

	int iMenu = InputInt();
	if (iMenu <1 || iMenu > iItemCount + 1)
		return INT_MAX;

	return iMenu;
}

void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount,int iStoreType) {
	while (true) {
		system("cls");
		switch (iStoreType) {
		case SM_WEAPON:
			cout << "**********************무기상점**********************" << endl << endl;
			break;
		case SM_ARMOR:
			cout << "**********************방어구상점**********************" << endl << endl;
			break;
		}

		int iInput=OutputStoreItemList(pInventory, pStore, iItemCount);
		
		if (iInput == INT_MAX)
		{
			cout << "잘못 입력하였습니다." << endl;
			system("pause");
			continue;
		}
		else if (iInput == iItemCount + 1) {
			break;
		}
		// 상점 판매목록 배열의 인덱스를 구해줌.
		int iIndex = iInput - 1;
		//인벤토리가 꽉찼는지 검사.

		if (pInventory->iItemCount == INVENTORY_MAX) {
			cout << "가방이 꽉 찼습니다. " << endl;
			system("pause");
			continue;
		}
		//돈이 부족할 경우
		else if(pInventory->iGold < pStore[iIndex].iPrice){
			cout << "보유금액이 부족합니다." << endl;
			system("pause");
			continue;	
		}
		//처음에 iItemCount는 하나도 추가되어 있지 않기 때문에 0으로 
		//되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다.
		//카운트가 1이 된다. 다음번에 추가할때는 1번 인덱스에 추가가 된다.

		pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];
		++pInventory->iItemCount;

		//골드를 차감한다.
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << " 아이템을 구매하였습니다." << endl;
		system("pause");
	}
}

void RunStore(_tagInventory* pInventory, _tagItem* pWeapon,
	_tagItem* pArmor) {
	while (true) {
		switch (OutputStoreMenu()) {
		case SM_WEAPON:
			BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, SM_WEAPON);
			break;
		case SM_ARMOR:
			BuyItem(pInventory, pArmor, STORE_WEAPON_MAX, SM_ARMOR);
			break;
		case SM_BACK:
			return;
		}
	}
}

int OutputInventory(_tagPlayer* pPlayer) {
	system("cls");
	cout << "**********************가방**********************" << endl << endl;
	OutputPlayer(pPlayer);
	for (int i = 0; i < pPlayer->tInventory.iItemCount; ++i) {
		cout << i + 1 << ". 이름: " << pPlayer->tInventory.tItem[i].strName <<
			"\t 종류 : " << pPlayer->tInventory.tItem[i].strTypeName << endl;
		if (pPlayer->tInventory.tItem[i].eType == ITEM_WEAPON) {
			cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
				pPlayer->tInventory.tItem[i].iMax << endl;
		}
		else if (pPlayer->tInventory.tItem[i].eType == ITEM_ARMOR) {
			cout << "방어력 : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
				pPlayer->tInventory.tItem[i].iMax << endl;
		}
		cout << "판매 가격 : " << pPlayer->tInventory.tItem[i].iSell <<
			"\t 구매 가격 : " << pPlayer->tInventory.tItem[i].iPrice << endl;
		cout << "설명 : " << pPlayer->tInventory.tItem[i].strDesc << endl << endl;
	}
	cout << pPlayer->tInventory.iItemCount + 1 << ". 뒤로가기" << endl << endl;
	cout << "어떤 장비를 장착하시겠습니까?  :  ";
	int iMenu=InputInt();
	if (iMenu<1 || iMenu>pPlayer->tInventory.iItemCount + 1)
		return INT_MAX;
	
	return iMenu;
}

EQUIP ComputeEquipType(ITEM_TYPE eType) {
	//제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를 결정
	EQUIP eq;

	switch (eType) {
	case ITEM_WEAPON:
		eq = EQ_WEAPON;
		break;
	case ITEM_ARMOR:
		eq = EQ_ARMOR;
		break;
	
	}
	return eq;
}

void RunInventory(_tagPlayer* pPlayer) {
	while (true) {
		int iInput = OutputInventory(pPlayer);
		if (iInput == INT_MAX) {
			continue;
		}
		else if (iInput == pPlayer->tInventory.iItemCount + 1) {
			break;
		}
		//아이템 인덱스를 구해준다.
		int idx = iInput - 1;


		EQUIP eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);
		

		//아이템이 장착되어 있을경우 장착이 되어 있는 아이템과 장착할 아이템을
		//교체해 주어야 한다 Swap알고리즘을 활용한다.

		if (pPlayer->bEquip[eq] == true) {
			_tagItem tSwap = pPlayer->tEquip[eq];
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}
		//장착되어있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고
	   //인벤토리는 1칸 비워지게 된다.

		else {
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];

			for (int i = idx; i < pPlayer->tInventory.iItemCount - 1; ++i) {
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}
			--pPlayer->tInventory.iItemCount;
			//장비를 장착했기 때문에 true로 만들어준다
			pPlayer->bEquip[eq] = true;
		}
		cout << pPlayer->tEquip[eq].strName << "(을)를 장착하였습니다 ." << endl << endl;
		system("pause");
	}
}

_tagItem CreateItem(const char* pName, ITEM_TYPE eType, int iMin,
	int iMax, int iPrice, int iSell,const char* pDesc) {
	_tagItem tItem = {};
	
	strcpy_s(tItem.strName, pName);
	strcpy_s(tItem.strDesc, pDesc);

	tItem.eType = eType;
	switch (eType) {
	case ITEM_WEAPON:
		strcpy_s(tItem.strTypeName, "무기");
		break;
	case ITEM_ARMOR:
		strcpy_s(tItem.strTypeName, "방어구");
		break;

	}

	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;

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

	g_tLvUpTable[JOB_KNIGHT - 1] = CreateLvUpstate(4, 10, 8, 16, 50, 100, 10, 20);
	g_tLvUpTable[JOB_ARCHER - 1] = CreateLvUpstate(10, 15, 5, 10, 30, 60, 30, 50);
	g_tLvUpTable[JOB_WIZARD - 1] = CreateLvUpstate(15, 20, 3, 8, 20, 40, 50, 100);

	

	tStoreWeapon[WL_SWORD - 1] = CreateItem("목검",ITEM_WEAPON,5,10,
		1000,500,"나무로만든 목검");
	tStoreWeapon[WL_BOW - 1] = CreateItem("장궁", ITEM_WEAPON, 20, 40,
		7000, 3500, "짱짱한 활");
	tStoreWeapon[WL_STAFF - 1] = CreateItem("큰지팡이", ITEM_WEAPON, 90, 150,
		30000, 15000, "나무로만든 지팡이");

	tStoreArmor[AL_HEAD - 1] = CreateItem("투구",ITEM_ARMOR,  10,
		20,7000,3500,"나무로만든 투구");
	tStoreArmor[AL_BODY - 1] = CreateItem("갑옷",ITEM_ARMOR, 70,
		90, 30000, 10500, "나무로만든 갑옷");
	tStoreArmor[AL_FOOT - 1] = CreateItem("신발",ITEM_ARMOR, 5,
		10, 2000, 1000, "나무로만든 신발");

	bool	bLoop = true;
	while (bLoop) {
		switch (OuputMainMenu()) {
		case MM_MAP:
			RunMap(&tPlayer,tMonsterArr); //맵 관련 루프를 처리
			
			break;
		case MM_STORE:
			RunStore(&tPlayer.tInventory, tStoreWeapon, tStoreArmor);

			break;
		case MM_INVENTORY:
			RunInventory(&tPlayer);
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}
	return 0;
}