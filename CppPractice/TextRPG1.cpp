/*
* 
* TextRPG1 기본준비
* TextRPG2 직업, 인벤토리, 몬스터, 플레이어 전투
* TextRPG3,4 아이템,상점
	->	무기상점에서 판매할 아이템 목록을 만들어주고 해당 목록을 출력해줌.
	->	출력할때 앞에 번호를 부여해주고 번호를 입력받아서 해당 번호의 아이템을 구입하게 함.
	->	단, 가방이 꽉 찼거나 돈이 부족할 경우 구매하지 못하게 한다.
	->	가방을 선택하면 가방안의 아이템을 보여준다.
* TextRPG5 아이템 장착
*/
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

int main() {
	srand((unsigned int)time(0));

	//레벨업에 필요한 경험치 목록을 만든다.
	const int iLevelUpExp[LEVEL_MAX] = {4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000};

	//게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};

	//플레이어 이름을 입력받음
	cout << "이름을 입력하세요 : ";
	//문자열의 끝은 NULL이 들어가야하기 때문에 NAEM_SIZE -1을 해준다.
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

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
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;
	tPlayer.tInventory.iItemCount = 0;
	tPlayer.tInventory.tItem[INVENTORY_MAX - 1] = {};

	//위에서 직업을 선택함과 동시에 범위를 한정하였기때문에
	//해당 switch문에서 default 값을 설정해줄 필요가 없음.
	//각 직업별로 능력치가 다르기 때문에 각각의 능력치를 설정해줌.
	switch (tPlayer.eJob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 25;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;
		break;
	}
	//몬스터 생성
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//고블린 생성
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	//트롤 생성
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	//드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	// 상점에서 판매할 아이템 목록을 생성한다.

	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	//각 아이템 정보들을 설정해 준다.

	//무기상점.
	strcpy_s(tStoreWeapon[0].strName, "롱소드");
	strcpy_s(tStoreWeapon[0].strTypeName, "무기");
	strcpy_s(tStoreWeapon[0].strDesc, "큰칼입니다.");
	tStoreWeapon[0].iPrice = 3000;
	tStoreWeapon[0].iSell = 1500;
	tStoreWeapon[0].iMax = 15;
	tStoreWeapon[0].iMin = 10;
	tStoreWeapon[0].eType = (ITEM_TYPE)ITEM_WEAPON;

	strcpy_s(tStoreWeapon[1].strName, "장궁");
	strcpy_s(tStoreWeapon[1].strTypeName, "무기");
	strcpy_s(tStoreWeapon[1].strDesc, "큰활입니다.");
	tStoreWeapon[1].iPrice = 3000;
	tStoreWeapon[1].iSell = 1500;
	tStoreWeapon[1].iMax = 15;
	tStoreWeapon[1].iMin = 10;
	tStoreWeapon[1].eType = (ITEM_TYPE)ITEM_WEAPON;

	strcpy_s(tStoreWeapon[2].strName, "스태프");
	strcpy_s(tStoreWeapon[2].strTypeName, "무기");
	strcpy_s(tStoreWeapon[2].strDesc, "지팡이입니다.");
	tStoreWeapon[2].iPrice = 3000;
	tStoreWeapon[2].iSell = 1500;
	tStoreWeapon[2].iMax = 15;
	tStoreWeapon[2].iMin = 10;
	tStoreWeapon[2].eType = (ITEM_TYPE)ITEM_WEAPON;


	//방어구 상점.
	strcpy_s(tStoreArmor[0].strName, "투구");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	strcpy_s(tStoreArmor[0].strDesc, "투구입니다.");
	tStoreArmor[0].iPrice = 3000;
	tStoreArmor[0].iSell = 1500;
	tStoreArmor[0].iMax = 15;
	tStoreArmor[0].iMin = 10;
	tStoreArmor[0].eType = (ITEM_TYPE)ITEM_ARMOR;

	strcpy_s(tStoreArmor[1].strName, "갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	strcpy_s(tStoreArmor[1].strDesc, "갑옷입니다.");
	tStoreArmor[1].iPrice = 3000;
	tStoreArmor[1].iSell = 1500;
	tStoreArmor[1].iMax = 15;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].eType = (ITEM_TYPE)ITEM_ARMOR;

	strcpy_s(tStoreArmor[2].strName, "신발");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	strcpy_s(tStoreArmor[2].strDesc, "신발입니다.");
	tStoreArmor[2].iPrice = 3000;
	tStoreArmor[2].iSell = 1500;
	tStoreArmor[2].iMax = 15;
	tStoreArmor[2].iMin = 10;
	tStoreArmor[2].eType = (ITEM_TYPE)ITEM_ARMOR;


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
					cout << "이름 : " << tPlayer.strName << "\t직업 :" <<
						tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 :" <<
						tPlayer.iExp << endl;
					// 무기를 장착하고  있을 경우 공격력에 무기 공격력을 추가하여 출력.

					if (tPlayer.bEquip[EQ_WEAPON] == true) {
						cout << "공격력 : " << tPlayer.iAttackMin << " + " <<
							tPlayer.tEquip[EQ_WEAPON].iMin << " - " <<
							tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
					}
					else {

						cout << "공격력 : " << tPlayer.iAttackMin << " - " <<
							tPlayer.iAttackMax;
					}

					//방어구를 장착하고 있을 경우 방어력에 방어구 방어구 방여력방어력을 추가하여 출려

					if (tPlayer.bEquip[EQ_ARMOR] == true) {
						cout << "\t방어력 : " << tPlayer.iArmorMax << " + " <<
							tPlayer.tEquip[EQ_ARMOR].iMin << " - " <<
							tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					}
					else {

						cout << "\t방어력 : " << tPlayer.iArmorMin << " - " <<
							tPlayer.iArmorMax << endl;
					}
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t마력 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "보유 골드 : " << tPlayer.tInventory.iGold << " Gold " << endl << endl;

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
						int iAttackMin = tPlayer.iArmorMin;
						int iAttackMax = tPlayer.iAttackMax;

						//무기를장착하고 있을 경우 무기와 Min , Max를 더해준다
						if (tPlayer.bEquip[EQ_WEAPON]) {
							iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
							iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
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

						cout << tPlayer.strName << " 가 " << tMonster.strName << " 에게 "
							<< iDamage << "만큼의 피해를 입혔습니다." << endl;

						// 몬스터가 죽었을 경우를 처리
						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1)
								+ tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "경험치를 획득하였습니다. " << endl;
							cout << iGold << " Gold를 획득하였습니다." << endl;


							//재 전투를 위한 몬스터 초기화
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							//레벨업을 했는지 체크

							if (tPlayer.iExp >= iLevelUpExp[1]) {
								if (tPlayer.iLevel < LEVEL_MAX) {
									// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
									tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];
									//레벨을 증가시킨다.
									++tPlayer.iLevel;
									
									cout << tPlayer.iLevel << "레벨업 하였습니다." << endl;
								}
								else {
									tPlayer.iExp = iLevelUpExp[LEVEL_MAX-1];
									cout << "레벨이 최대치 입니다." << endl;
								}
									
							
							}

							system("pause");
							break;
						}

						// 몬스터가 살아있다면 플레이어를 공격한다.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) +
							tMonster.iAttackMin;

						int iArmorMin = tPlayer.iArmorMin;
						int iArmorMax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR]) {
							iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
							iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
						}


						iArmor = rand() % (iArmorMax - iArmorMin + 1) +
							iArmorMin;
						//최소 데미지 설정
						//int iDamage = ((iAttack - iArmor)<1)?1:(iAttack-iArmor);
						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						//Player의 HP를 감소 시킨다.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " 가 " << tPlayer.strName << " 에게 "
							<< iDamage << "만큼의 피해를 입혔습니다." << endl;

						//Player가 죽었을 경우 처리
						if (tPlayer.iHP <= 0) {
							cout << tPlayer.strName << " Player가 사망하였습니다." << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " 의 경험치를 잃었습니다. " << endl;
							cout << iGold << " 의 Gold를 잃었습니다." << endl;

							// Player 의 사망후 부활
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
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
						
						cout << "가방남은 공간 : " << INVENTORY_MAX-tPlayer.tInventory.iItemCount << "칸" << endl;

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
						if (tPlayer.tInventory.iGold < tStoreWeapon[iAction - 1].iPrice) {
							cout << endl << "구매 불가! (소지금 부족.)"  << endl << endl;
							system("pause");
							continue;
						}
						else if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {
							cout << endl << "구매 불가! (인벤토리 부족.)" << endl << endl;
							system("pause");
							continue;
						}
						else {
							switch (iAction) {
							case WL_SWORD:
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[0];
								break;
							case WL_BOW:
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[1];
								break;
							case WL_STAFF:
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[2];
								break;
							default:
								continue;
							}
						
							//골드 차감
							tPlayer.tInventory.iGold -= tStoreWeapon[iAction - 1].iPrice;
							++tPlayer.tInventory.iItemCount;
							cout << endl <<tStoreWeapon[iAction-1].strName <<" 구매 완료!" << endl << endl;

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
						
						cout << "가방남은 공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << "칸" << endl;

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
						if (tPlayer.tInventory.iGold < tStoreArmor[iAction - 1].iPrice) {
							cout << endl << "구매 불가! (소지금 부족.)" << endl;
							system("pause");
							continue;
						}
						else if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {
							cout << endl << "구매 불가! (인벤토리 부족.)" << endl;
							system("pause");
							continue;
						}
						else {
							switch (iAction) {
							case AL_HEAD:
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[0];
								break;
							case AL_BODY:
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[1];
								break;
							case AL_FOOT:
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[2];
								break;
							default:
								continue;
							}
							tPlayer.tInventory.iGold -= tStoreArmor[iAction - 1].iPrice;
							++tPlayer.tInventory.iItemCount;
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
				cout << "이름 : " << tPlayer.strName << "\t직업 :" <<
					tPlayer.strJobName << endl;
				cout << "레벨 : " << tPlayer.iLevel << "\t경험치 :" <<
					tPlayer.iExp << endl;
				// 무기를 장착하고  있을 경우 공격력에 무기 공격력을 추가하여 출력.

				if (tPlayer.bEquip[EQ_WEAPON] == true) {
					cout << "공격력 : " << tPlayer.iAttackMin << " + " <<
						tPlayer.tEquip[EQ_WEAPON].iMin << " - " <<
						tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
				}else{

					cout << "공격력 : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax;
				}
				
				//방어구를 장착하고 있을 경우 방어력에 방어구 방어구 방여력방어력을 추가하여 출려

				if (tPlayer.bEquip[EQ_ARMOR] == true) {
					cout << "\t방어력 : " << tPlayer.iArmorMax << " + " <<
						tPlayer.tEquip[EQ_ARMOR].iMin << " - " <<
						tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}
				else {

					cout << "\t방어력 : " << tPlayer.iArmorMin << " - " <<
						tPlayer.iArmorMax << endl;
				}

					
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t마력 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;


					if (tPlayer.bEquip[EQ_WEAPON]) {
						cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
					}
					else
						cout << "장작무기 : 없음";
					if (tPlayer.bEquip[EQ_ARMOR]) {
						cout << "\t장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
					}
					else {
						cout << "\t장착방어구 :없음"<<endl;
					}

					cout << "보유 골드 : " << tPlayer.tInventory.iGold << " Gold " << endl << endl << endl;


					for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i){
						cout <<i+1<< ". 이름: " << tPlayer.tInventory.tItem[i].strName <<
							"\t 종류 : "<<tPlayer.tInventory.tItem[i].strTypeName<<endl;
						if (tPlayer.tInventory.tItem[i].eType == ITEM_WEAPON) {
							cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << " - " <<
								tPlayer.tInventory.tItem[i].iMax << endl;
						}
						else if (tPlayer.tInventory.tItem[i].eType == ITEM_ARMOR) {
							cout << "방어력 : " << tPlayer.tInventory.tItem[i].iMin << " - " <<
								tPlayer.tInventory.tItem[i].iMax << endl;
						}
						cout << "판매 가격 : " << tPlayer.tInventory.tItem[i].iSell <<
							"\t 구매 가격 : " << tPlayer.tInventory.tItem[i].iPrice << endl;
						cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
					}
					cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl<<endl;
					cout << "어떤 장비를 장착하시겠습니까?  :  ";
					cin >> iMenu;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024,'\n');
						continue;
					}
					else if (iMenu<ITEM_WEAPON || iMenu>tPlayer.tInventory.iItemCount + 1) {
						cout << "잘못 선택하였습니다. " << endl;
						system("pause");
						continue;
					}
					else if (iMenu == tPlayer.tInventory.iItemCount + 1) {
						break;
					}

					//아이템 인덱스를 구해준다.
					int idx = iMenu - 1;


					//제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를 결정
					EQUIP eq;

					switch (tPlayer.tInventory.tItem[idx].eType) {
					case ITEM_WEAPON:
						eq = EQ_WEAPON;
							break;
					case ITEM_ARMOR:
						eq = EQ_ARMOR;
						break;
					}

					//아이템이 장착되어 있을경우 장착이 되어 있는 아이템과 장착할 아이템을
					//교체해 주어야 한다 Swap알고리즘을 활용한다.

					if (tPlayer.bEquip[eq] == true) {
						_tagItem tSwap = tPlayer.tEquip[eq];
						tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
						tPlayer.tInventory.tItem[idx] = tSwap;
					}
					 //장착되어있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고
					//인벤토리는 1칸 비워지게 된다.

					else{
						tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

						for (int i = idx; i < tPlayer.tInventory.iItemCount-1; ++i) {
							tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
						}
						--tPlayer.tInventory.iItemCount;
						//장비를 장착했기 때문에 true로 만들어준다
						tPlayer.bEquip[eq] = true;
					}
					cout << tPlayer.tEquip[eq].strName << "(을)를 장착하였습니다 ." << endl<<endl;
				system("pause");
				}
			break;
		default:
			continue;
		}



	}
	return 0;
}