/*
*
* 
* TextRPG Function (My Code)
*
*/
/*
#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU {
	MM_MONE,
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

void Init(_tagLevelUpStatus* tLvUpTable, _tagPlayer* tPlayer, _tagMonster* tMonsterArr, _tagItem* tStoreWeapon, _tagItem* tStoreArmor);
void InitLvUpTable(_tagLevelUpStatus* tLT, JOB eJob);
void InitPlayer(_tagPlayer* tP);
void InitMonster(_tagMonster* tMS, MAP_TYPE eMT);
void InitShop(_tagItem* tSH, const char* strName, const char* strTypeName, const char* strDesc, int iPrice, int iSell, int iMax, int iMin, ITEM_TYPE eType,int idx);
void Start(const int* iLevelUpExp, _tagLevelUpStatus* tLvUpTable, _tagPlayer* tPlayer, _tagMonster* tMonsterArr, _tagItem* tStoreWeapon, _tagItem* tStoreArmor);

int main() {
	//레벨업에 필요한 경험치 목록을 만든다.
	const int iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };
	//레벨업 별 성장치
	//JOB _END 는 4이다. 그런데 작업은 3개이므로 -1을 해주어서 배열을 각 직열별로 생성
	_tagLevelUpStatus	tLvUpTable[JOB_END - 1] = {};
	//게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};
	//몬스터 생성
	_tagMonster tMonsterArr[MT_BACK - 1] = {};
	// 상점에서 판매할 아이템 목록을 생성한다.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	//전체 초기화 
	Init(tLvUpTable, &tPlayer, tMonsterArr, tStoreWeapon, tStoreArmor);
	//게임 시작
	Start(iLevelUpExp,tLvUpTable,&tPlayer,tMonsterArr,tStoreWeapon,tStoreArmor);

	return 0;
}
void Init(_tagLevelUpStatus* tLvUpTable, _tagPlayer* tPlayer, _tagMonster* tMonsterArr, _tagItem* tStoreWeapon, _tagItem* tStoreArmor) {
	InitLvUpTable(tLvUpTable, JOB_KNIGHT);
	InitLvUpTable(tLvUpTable, JOB_ARCHER);
	InitLvUpTable(tLvUpTable, JOB_WIZARD);
	InitPlayer(tPlayer);
	InitMonster(tMonsterArr, MT_EASY);
	InitMonster(tMonsterArr, MT_NORMAL);
	InitMonster(tMonsterArr, MT_HARD);
	InitShop(tStoreWeapon, "롱소드", "무기", "큰칼입니다.", 3000, 1500, 15, 10, ITEM_WEAPON, 0);
	InitShop(tStoreWeapon, "장궁", "무기", "큰활입니다.", 3000, 1500, 15, 10, ITEM_WEAPON, 1);
	InitShop(tStoreWeapon, "스태프", "무기", "큰칼입니다.", 3000, 1500, 15, 10, ITEM_WEAPON, 2);
	InitShop(tStoreArmor, "투구", "방어구", "투구입니다.", 3000, 1500, 15, 10, ITEM_ARMOR, 0);
	InitShop(tStoreArmor, "갑옷", "방어구", "갑옷입니다.", 3000, 1500, 15, 10, ITEM_ARMOR, 1);
	InitShop(tStoreArmor, "신발", "방어구", "신발입니다.", 3000, 1500, 15, 10, ITEM_ARMOR, 2);
}
void InitLvUpTable(_tagLevelUpStatus* tLT, JOB eJob) {
	switch (eJob) {
		case JOB_KNIGHT:
			tLT[eJob - 1].iAttackMin = 4;
			tLT[eJob - 1].iAttackMax = 10;
			tLT[eJob - 1].iArmorMin = 8;
			tLT[eJob - 1].iArmorMax = 16;
			tLT[eJob - 1].iHPMin = 50;
			tLT[eJob - 1].iHPMax = 100;
			tLT[eJob - 1].iMPMin = 10;
			tLT[eJob - 1].iMPMax = 20;
			break;
		case JOB_ARCHER:
			tLT[eJob - 1].iAttackMin = 10;
			tLT[eJob - 1].iAttackMax = 15;
			tLT[eJob - 1].iArmorMin = 5;
			tLT[eJob - 1].iArmorMax = 10;
			tLT[eJob - 1].iHPMin = 30;
			tLT[eJob - 1].iHPMax = 60;
			tLT[eJob - 1].iMPMin = 30;
			tLT[eJob - 1].iMPMax = 50;
			break;
		case JOB_WIZARD:
			tLT[eJob - 1].iAttackMin = 15;
			tLT[eJob - 1].iAttackMax = 20;
			tLT[eJob - 1].iArmorMin = 3;
			tLT[eJob - 1].iArmorMax = 8;
			tLT[eJob - 1].iHPMin = 20;
			tLT[eJob - 1].iHPMax = 40;
			tLT[eJob - 1].iMPMin = 50;
			tLT[eJob - 1].iMPMax = 100;
			break;
	}
}
void InitPlayer(_tagPlayer* tP) {

	//플레이어 이름을 입력받음
	cout << "이름을 입력하세요 : ";
	//문자열의 끝은 NULL이 들어가야하기 때문에 NAEM_SIZE -1을 해준다.
	cin.getline(tP->strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1.기사" << endl;
		cout << "2.궁수" << endl;
		cout << "3.마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;
		//정수 이외의값 입력 했을때 방지
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		//직업의 범위를 벗어난 숫자를 입력했을경우
		//값을 JOB_NONE로 대입하여 다시 반복하도록 함.
		else if (iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}
	//시작시 Player의 고정적인 정보
	tP->iLevel = 1;
	tP->iExp = 0;
	tP->eJob = (JOB)iJob;
	tP->tInventory.iGold = 10000;
	tP->tInventory.iItemCount = 0;
	tP->tInventory.tItem[INVENTORY_MAX - 1] = {};

	//위에서 직업을 선택함과 동시에 범위를 한정하였기때문에
	//해당 switch문에서 default 값을 설정해줄 필요가 없음.
	//각 직업별로 능력치가 다르기 때문에 각각의 능력치를 설정해줌.
	switch (tP->eJob) {
	case JOB_KNIGHT:
		strcpy_s(tP->strJobName, "기사");
		tP->iAttackMin = 5;
		tP->iAttackMax = 10;
		tP->iArmorMin = 15;
		tP->iArmorMax = 20;
		tP->iHPMax = 500;
		tP->iHP = 500;
		tP->iMPMax = 100;
		tP->iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tP->strJobName, "궁수");
		tP->iAttackMin = 10;
		tP->iAttackMax = 15;
		tP->iArmorMin = 10;
		tP->iArmorMax = 25;
		tP->iHPMax = 400;
		tP->iHP = 400;
		tP->iMPMax = 200;
		tP->iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tP->strJobName, "마법사");
		tP->iAttackMin = 15;
		tP->iAttackMax = 20;
		tP->iArmorMin = 5;
		tP->iArmorMax = 10;
		tP->iHPMax = 300;
		tP->iHP = 300;
		tP->iMPMax = 300;
		tP->iMP = 300;
		break;
	}
}
void InitMonster(_tagMonster* tMS,MAP_TYPE eMT){
	switch (eMT) {
	case MT_EASY:
		//고블린 생성
		strcpy_s(tMS[eMT-1].strName, "고블린");
		tMS[eMT-1].iAttackMin = 20;
		tMS[eMT-1].iAttackMax = 30;
		tMS[eMT-1].iArmorMin = 2;
		tMS[eMT-1].iArmorMax = 5;
		tMS[eMT-1].iHP = 100;
		tMS[eMT-1].iHPMax = 100;
		tMS[eMT-1].iMP = 10;
		tMS[eMT-1].iMPMax = 10;
		tMS[eMT-1].iLevel = 1;
		tMS[eMT-1].iExp = 1000;
		tMS[eMT-1].iGoldMin = 500;
		tMS[eMT-1].iGoldMax = 1500;
		break;
	case MT_NORMAL:
		//트롤 생성
		strcpy_s(tMS[eMT-1].strName, "트롤");
		tMS[eMT-1].iAttackMin = 80;
		tMS[eMT-1].iAttackMax = 130;
		tMS[eMT-1].iArmorMin = 60;
		tMS[eMT-1].iArmorMax = 90;
		tMS[eMT-1].iHP = 2000;
		tMS[eMT-1].iHPMax = 2000;
		tMS[eMT-1].iMP = 100;
		tMS[eMT-1].iMPMax = 100;
		tMS[eMT-1].iLevel = 5;
		tMS[eMT-1].iExp = 7000;
		tMS[eMT-1].iGoldMin = 6000;
		tMS[eMT-1].iGoldMax = 8000;

		break;
	case MT_HARD:
		//드래곤 생성
		strcpy_s(tMS[eMT-1].strName, "드래곤");
		tMS[eMT-1].iAttackMin = 250;
		tMS[eMT-1].iAttackMax = 500;
		tMS[eMT-1].iArmorMin = 200;
		tMS[eMT-1].iArmorMax = 400;
		tMS[eMT-1].iHP = 30000;
		tMS[eMT-1].iHPMax = 30000;
		tMS[eMT-1].iMP = 20000;
		tMS[eMT-1].iMPMax = 20000;
		tMS[eMT-1].iLevel = 10;
		tMS[eMT-1].iExp = 30000;
		tMS[eMT-1].iGoldMin = 20000;
		tMS[eMT-1].iGoldMax = 50000;

		break;
	}
}
void InitShop(_tagItem* tSH,const char* strName,const char* strTypeName,const char* strDesc, int iPrice,int iSell, int iMax,int iMin, ITEM_TYPE eType,int idx) {
	strcpy_s(tSH[idx].strName, strName);
	strcpy_s(tSH[idx].strTypeName, strTypeName);
	strcpy_s(tSH[idx].strDesc, strDesc);
	tSH[idx].iPrice = iPrice;
	tSH[idx].iSell = iSell;
	tSH[idx].iMax = iMax;
	tSH[idx].iMin = iMin;
	tSH[idx].eType = eType;
}
void Start(const int* iLevelUpExp, _tagLevelUpStatus* tLvUpTable, _tagPlayer* tPlayer, _tagMonster* tMonsterArr, _tagItem* tStoreWeapon, _tagItem* tStoreArmor) {
	srand((unsigned int)time(0));
	while (true) {
		system("cls");
		cout << "**********************로비**********************" << endl << endl;
		cout << "1. 맵 " << endl;
		cout << "2. 상점 " << endl;
		cout << "3. 가방 " << endl;
		cout << "4. 종료 " << endl;
		cout << "메뉴를 선택해 주세요 :";
		int iMenu, iAction;
		cin >> iMenu;
		// iMenu 변수에 정수가아닌 문자가 들어갔을경우에
		// cin의 버퍼를 비워주기 위함.
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == MM_EXIT) {
			break;
		}
		switch (iMenu) {
		case MM_MAP:
			while (true) {
				system("cls");
				cout << "**********************맵**********************" << endl << endl;
				cout << "1.쉬움 " << endl;
				cout << "2.보통 " << endl;
				cout << "3.어려움 " << endl;
				cout << "4.뒤로가기 " << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				//이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로
				//이 while문을 빠져나간다.
				if (iMenu == MT_BACK)
					break;

				// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
				// 그렇게 해서 해당 맵의 몬스터를 생성해준다.

				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true) {
					system("cls");
					switch (iMenu) {
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
					// 플레이어 정보를 출력한다.
					cout << "=======================Player=======================" << endl;
					cout << "이름 : " << tPlayer->strName << "\t직업 :" <<
						tPlayer->strJobName << endl;
					cout << "레벨 : " << tPlayer->iLevel << "\t경험치 :" <<
						tPlayer->iExp << " / " << iLevelUpExp[tPlayer->iLevel - 1] << endl;
					// 무기를 장착하고  있을 경우 공격력에 무기 공격력을 추가하여 출력.

					if (tPlayer->bEquip[EQ_WEAPON] == true) {
						cout << "공격력 : " << tPlayer->iAttackMin << " + " <<
							tPlayer->tEquip[EQ_WEAPON].iMin << " - " <<
							tPlayer->iAttackMax << " + " << tPlayer->tEquip[EQ_WEAPON].iMax;
					}
					else {

						cout << "공격력 : " << tPlayer->iAttackMin << " - " <<
							tPlayer->iAttackMax;
					}

					//방어구를 장착하고 있을 경우 방어력에 방어구 방어구 방여력방어력을 추가하여 출려

					if (tPlayer->bEquip[EQ_ARMOR] == true) {
						cout << "\t방어력 : " << tPlayer->iArmorMax << " + " <<
							tPlayer->tEquip[EQ_ARMOR].iMin << " - " <<
							tPlayer->iArmorMax << " + " << tPlayer->tEquip[EQ_ARMOR].iMax << endl;
					}
					else {

						cout << "\t방어력 : " << tPlayer->iArmorMin << " - " <<
							tPlayer->iArmorMax << endl;
					}
					cout << "체력 : " << tPlayer->iHP << " / " << tPlayer->iHPMax <<
						"\t마력 : " << tPlayer->iMP << " / " << tPlayer->iMPMax << endl;
					cout << "보유 골드 : " << tPlayer->tInventory.iGold << " Gold " << endl << endl;

					//몬스터 정보 출력.

					cout << "=======================Monster=======================" << endl;
					cout << "이름 : " << tMonster.strName << "\t레벨 :" <<
						tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin << " - " <<
						tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t마력 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "획득경험치 : " << tMonster.iExp << "\t획득골드 : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << " Gold " << endl << endl << endl;



					cout << "1.공격" << endl;
					cout << "2.도망가기" << endl;
					cout << "선택해주세요 : ";

					cin >> iAction;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iAction == BATTLE_BACK) {
						break;
					}

					cout << endl << endl;
					switch (iAction) {
					case BATTLE_ATTACK:
					{
						//예를 들어 Min 5 Max 15 라고 가정할 경우
						// 15 - 5 +1 을 하면 11 이 되고, 11로 나눈 나머지는 0~10이 나옴.
						// 여기에 Min값인 5를 더하게 되면 5~15 사이로 값이 나오게 된다.
						int iAttackMin = tPlayer->iArmorMin;
						int iAttackMax = tPlayer->iAttackMax;

						//무기를장착하고 있을 경우 무기와 Min , Max를 더해준다
						if (tPlayer->bEquip[EQ_WEAPON]) {
							iAttackMin += tPlayer->tEquip[EQ_WEAPON].iMin;
							iAttackMax += tPlayer->tEquip[EQ_WEAPON].iMax;
						}


						int iAttack = rand() % (iAttackMax - iAttackMin + 1) +
							iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) +
							tMonster.iArmorMin;
						//최소 데미지 설정
						//int iDamage = ((iAttack - iArmor)<1)?1:(iAttack-iArmor);
						int iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//몬스터 HP를 감소 시킨다.
						tMonster.iHP -= iDamage;

						cout << tPlayer->strName << " 가 " << tMonster.strName << " 에게 "
							<< iDamage << "만큼의 피해를 입혔습니다." << endl;

						// 몬스터가 죽었을 경우를 처리
						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl << endl;

							tPlayer->iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1)
								+ tMonster.iGoldMin);
							tPlayer->tInventory.iGold += iGold;

							cout << tMonster.iExp << "경험치를 획득하였습니다. " << endl;
							cout << iGold << " Gold를 획득하였습니다." << endl;


							//재 전투를 위한 몬스터 초기화
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							//레벨업을 했는지 체크

							if (tPlayer->iExp >= iLevelUpExp[tPlayer->iLevel - 1]) {
								if (tPlayer->iLevel < LEVEL_MAX) {
									// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
									tPlayer->iExp -= iLevelUpExp[tPlayer->iLevel - 1];
									//레벨을 증가시킨다.
									++tPlayer->iLevel;

									cout << "LV" << tPlayer->iLevel << "(으)로 레벨업 하였습니다." << endl;

									//능력치 상승
									//직업 인덱스를 구함.
									int iJobIndex = tPlayer->eJob - 1;

									int iHPUp = rand() % (tLvUpTable[iJobIndex].iHPMax - tLvUpTable[iJobIndex].iHPMin + 1) +
										tLvUpTable[iJobIndex].iHPMin;
									int iMPUp = rand() % (tLvUpTable[iJobIndex].iMPMax - tLvUpTable[iJobIndex].iMPMin + 1) +
										tLvUpTable[iJobIndex].iMPMin;

									tPlayer->iAttackMin += tLvUpTable[iJobIndex].iAttackMin;
									tPlayer->iAttackMax += tLvUpTable[iJobIndex].iAttackMax;
									tPlayer->iArmorMin += tLvUpTable[iJobIndex].iArmorMin;
									tPlayer->iArmorMax += tLvUpTable[iJobIndex].iArmorMax;

									tPlayer->iHPMax += iHPUp;
									tPlayer->iMPMax += iMPUp;

									// 체력과 마나를 회복시킨다.

									tPlayer->iHP = tPlayer->iHPMax;
									tPlayer->iMP = tPlayer->iMPMax;


								}
								else {
									tPlayer->iExp = iLevelUpExp[tPlayer->iLevel - 1];
									cout << "레벨이 최대치 입니다." << endl;
								}


							}

							system("pause");
							break;
						}

						// 몬스터가 살아있다면 플레이어를 공격한다.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) +
							tMonster.iAttackMin;

						int iArmorMin = tPlayer->iArmorMin;
						int iArmorMax = tPlayer->iArmorMax;

						if (tPlayer->bEquip[EQ_ARMOR]) {
							iArmorMin += tPlayer->tEquip[EQ_ARMOR].iMin;
							iArmorMax += tPlayer->tEquip[EQ_ARMOR].iMax;
						}


						iArmor = rand() % (iArmorMax - iArmorMin + 1) +
							iArmorMin;
						//최소 데미지 설정
						//int iDamage = ((iAttack - iArmor)<1)?1:(iAttack-iArmor);
						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//Player의 HP를 감소 시킨다.
						tPlayer->iHP -= iDamage;

						cout << tMonster.strName << " 가 " << tPlayer->strName << " 에게 "
							<< iDamage << "만큼의 피해를 입혔습니다." << endl;

						//Player가 죽었을 경우 처리
						if (tPlayer->iHP <= 0) {
							cout << tPlayer->strName << " Player가 사망하였습니다." << endl;

							int iExp = tPlayer->iExp * 0.1f;
							int iGold = tPlayer->tInventory.iGold * 0.1f;

							tPlayer->iExp -= iExp;
							tPlayer->tInventory.iGold -= iGold;

							cout << iExp << " 의 경험치를 잃었습니다. " << endl;
							cout << iGold << " 의 Gold를 잃었습니다." << endl;

							// Player 의 사망후 부활
							tPlayer->iHP = tPlayer->iHPMax;
							tPlayer->iMP = tPlayer->iMPMax;
						}
						system("pause");
						break;
					}

					break;
					}



				}
			}
			break;
		case MM_STORE:
			while (true) {
				system("cls");
				cout << "**********************상점**********************" << endl << endl;
				cout << "1.무기 " << endl;
				cout << "2.방어구 " << endl;
				cout << "3.뒤로가기 " << endl;
				cout << "선택해 주세요 : ";

				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == SM_BACK) {
					break;
				}

				switch (iMenu) {
				case SM_WEAPON:
					while (true) {
						system("cls");
						//판매 목록을 보여준다.
						cout << "**********************무기상점**********************" << endl << endl;
						cout << WL_SWORD << ". " << tStoreWeapon[0].strName << endl;
						cout << WL_BOW << ". " << tStoreWeapon[1].strName << endl;
						cout << WL_STAFF << ". " << tStoreWeapon[2].strName << endl;
						cout << WL_BACK << ". " << "뒤로가기" << endl << endl;

						cout << "가방남은 공간 : " << INVENTORY_MAX - tPlayer->tInventory.iItemCount << "칸" << endl;

						cout << "선택해 주세요 : ";

						cin >> iAction;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iAction == WL_BACK)
							break;


						//현재 Player의 소지 금액이 아이템의 가격보다 작을경우 구입불가
						//현재 Player의 인벤토리가 꽉 찼을 경우 구입 불가
						if (tPlayer->tInventory.iGold < tStoreWeapon[iAction - 1].iPrice) {
							cout << endl << "구매 불가! (소지금 부족.)" << endl << endl;
							system("pause");
							continue;
						}
						else if (tPlayer->tInventory.iItemCount == INVENTORY_MAX) {
							cout << endl << "구매 불가! (인벤토리 부족.)" << endl << endl;
							system("pause");
							continue;
						}
						else {
							switch (iAction) {
							case WL_SWORD:
								tPlayer->tInventory.tItem[tPlayer->tInventory.iItemCount] = tStoreWeapon[0];
								break;
							case WL_BOW:
								tPlayer->tInventory.tItem[tPlayer->tInventory.iItemCount] = tStoreWeapon[1];
								break;
							case WL_STAFF:
								tPlayer->tInventory.tItem[tPlayer->tInventory.iItemCount] = tStoreWeapon[2];
								break;
							default:
								continue;
							}

							//골드 차감
							tPlayer->tInventory.iGold -= tStoreWeapon[iAction - 1].iPrice;
							++tPlayer->tInventory.iItemCount;
							cout << endl << tStoreWeapon[iAction - 1].strName << " 구매 완료!" << endl << endl;

							system("pause");
						}

					}
					break;
				case SM_ARMOR:
					while (true) {
						system("cls");
						cout << "**********************방어구상점**********************" << endl << endl;
						cout << AL_HEAD << ". " << tStoreArmor[0].strName << endl;
						cout << AL_BODY << ". " << tStoreArmor[1].strName << endl;
						cout << AL_FOOT << ". " << tStoreArmor[2].strName << endl;
						cout << AL_BACK << ". " << "뒤로가기" << endl << endl;

						cout << "가방남은 공간 : " << INVENTORY_MAX - tPlayer->tInventory.iItemCount << "칸" << endl;

						cout << "선택해 주세요 : ";

						cin >> iAction;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iAction == AL_BACK)
							break;
						//현재 Player의 소지 금액이 아이템의 가격보다 작을경우 구입불가
						//현재 Player의 인벤토리가 꽉 찼을 경우 구입 불가
						if (tPlayer->tInventory.iGold < tStoreArmor[iAction - 1].iPrice) {
							cout << endl << "구매 불가! (소지금 부족.)" << endl;
							system("pause");
							continue;
						}
						else if (tPlayer->tInventory.iItemCount == INVENTORY_MAX) {
							cout << endl << "구매 불가! (인벤토리 부족.)" << endl;
							system("pause");
							continue;
						}
						else {
							switch (iAction) {
							case AL_HEAD:
								tPlayer->tInventory.tItem[tPlayer->tInventory.iItemCount] = tStoreArmor[0];
								break;
							case AL_BODY:
								tPlayer->tInventory.tItem[tPlayer->tInventory.iItemCount] = tStoreArmor[1];
								break;
							case AL_FOOT:
								tPlayer->tInventory.tItem[tPlayer->tInventory.iItemCount] = tStoreArmor[2];
								break;
							default:
								continue;
							}
							tPlayer->tInventory.iGold -= tStoreArmor[iAction - 1].iPrice;
							++tPlayer->tInventory.iItemCount;
							cout << endl << tStoreArmor[iAction - 1].strName << " 구매 완료!" << endl << endl;
							system("pause");
						}

					}
					break;
				default:
					break;
				}
			}
			break;
		case MM_INVENTORY:
			while (true) {
				system("cls");
				cout << "**********************가방**********************" << endl << endl;
				cout << "[ 정보 ] " << endl << endl;
				cout << "이름 : " << tPlayer->strName << "\t직업 :" <<
					tPlayer->strJobName << endl;
				cout << "레벨 : " << tPlayer->iLevel << "\t경험치 :" <<
					tPlayer->iExp << " / " << iLevelUpExp[tPlayer->iLevel - 1] << endl;
				// 무기를 장착하고  있을 경우 공격력에 무기 공격력을 추가하여 출력.

				if (tPlayer->bEquip[EQ_WEAPON] == true) {
					cout << "공격력 : " << tPlayer->iAttackMin << " + " <<
						tPlayer->tEquip[EQ_WEAPON].iMin << " - " <<
						tPlayer->iAttackMax << " + " << tPlayer->tEquip[EQ_WEAPON].iMax;
				}
				else {

					cout << "공격력 : " << tPlayer->iAttackMin << " - " <<
						tPlayer->iAttackMax;
				}

				//방어구를 장착하고 있을 경우 방어력에 방어구 방어구 방여력방어력을 추가하여 출려

				if (tPlayer->bEquip[EQ_ARMOR] == true) {
					cout << "\t방어력 : " << tPlayer->iArmorMax << " + " <<
						tPlayer->tEquip[EQ_ARMOR].iMin << " - " <<
						tPlayer->iArmorMax << " + " << tPlayer->tEquip[EQ_ARMOR].iMax << endl;
				}
				else {

					cout << "\t방어력 : " << tPlayer->iArmorMin << " - " <<
						tPlayer->iArmorMax << endl;
				}


				cout << "체력 : " << tPlayer->iHP << " / " << tPlayer->iHPMax <<
					"\t마력 : " << tPlayer->iMP << " / " << tPlayer->iMPMax << endl;


				if (tPlayer->bEquip[EQ_WEAPON]) {
					cout << "장착무기 : " << tPlayer->tEquip[EQ_WEAPON].strName;
				}
				else
					cout << "장작무기 : 없음";
				if (tPlayer->bEquip[EQ_ARMOR]) {
					cout << "\t장착방어구 : " << tPlayer->tEquip[EQ_ARMOR].strName << endl;
				}
				else {
					cout << "\t장착방어구 :없음" << endl;
				}

				cout << "보유 골드 : " << tPlayer->tInventory.iGold << " Gold " << endl << endl << endl;


				for (int i = 0; i < tPlayer->tInventory.iItemCount; ++i) {
					cout << i + 1 << ". 이름: " << tPlayer->tInventory.tItem[i].strName <<
						"\t 종류 : " << tPlayer->tInventory.tItem[i].strTypeName << endl;
					if (tPlayer->tInventory.tItem[i].eType == ITEM_WEAPON) {
						cout << "공격력 : " << tPlayer->tInventory.tItem[i].iMin << " - " <<
							tPlayer->tInventory.tItem[i].iMax << endl;
					}
					else if (tPlayer->tInventory.tItem[i].eType == ITEM_ARMOR) {
						cout << "방어력 : " << tPlayer->tInventory.tItem[i].iMin << " - " <<
							tPlayer->tInventory.tItem[i].iMax << endl;
					}
					cout << "판매 가격 : " << tPlayer->tInventory.tItem[i].iSell <<
						"\t 구매 가격 : " << tPlayer->tInventory.tItem[i].iPrice << endl;
					cout << "설명 : " << tPlayer->tInventory.tItem[i].strDesc << endl << endl;
				}
				cout << tPlayer->tInventory.iItemCount + 1 << ". 뒤로가기" << endl << endl;
				cout << "어떤 장비를 장착하시겠습니까?  :  ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu<ITEM_WEAPON || iMenu>tPlayer->tInventory.iItemCount + 1) {
					cout << "잘못 선택하였습니다. " << endl;
					system("pause");
					continue;
				}
				else if (iMenu == tPlayer->tInventory.iItemCount + 1) {
					break;
				}

				//아이템 인덱스를 구해준다.
				int idx = iMenu - 1;


				//제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를 결정
				EQUIP eq;

				switch (tPlayer->tInventory.tItem[idx].eType) {
				case ITEM_WEAPON:
					eq = EQ_WEAPON;
					break;
				case ITEM_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				//아이템이 장착되어 있을경우 장착이 되어 있는 아이템과 장착할 아이템을
				//교체해 주어야 한다 Swap알고리즘을 활용한다.

				if (tPlayer->bEquip[eq] == true) {
					_tagItem tSwap = tPlayer->tEquip[eq];
					tPlayer->tEquip[eq] = tPlayer->tInventory.tItem[idx];
					tPlayer->tInventory.tItem[idx] = tSwap;
				}
				//장착되어있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고
			   //인벤토리는 1칸 비워지게 된다.

				else {
					tPlayer->tEquip[eq] = tPlayer->tInventory.tItem[idx];

					for (int i = idx; i < tPlayer->tInventory.iItemCount - 1; ++i) {
						tPlayer->tInventory.tItem[i] = tPlayer->tInventory.tItem[i + 1];
					}
					--tPlayer->tInventory.iItemCount;
					//장비를 장착했기 때문에 true로 만들어준다
					tPlayer->bEquip[eq] = true;
				}
				cout << tPlayer->tEquip[eq].strName << "(을)를 장착하였습니다 ." << endl << endl;
				system("pause");
			}
			break;
		default:
			continue;
		}



	}
}
*/