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
// ���ڿ��� ���������� ���ϴ°� ���� 
// ������ ���ϴ°��� ������ ������ ������
// ���������� ����
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

//�������� �ʿ��� ����ġ ����� �����.
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
	int		iExp; //���� ����ġ
	int		iLevel;
	_tagItem	tEquip[EQ_MAX]; // ������ ������ ����
	bool		bEquip[EQ_MAX]; // �ش� ���� ������ ���� ����
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
	int		iExp; //��ɽ� �ִ� ����ġ
	int		iLevel;
	int		iGoldMin; //�ּ� ��� ���
	int		iGoldMax;// �ִ� ��� ���
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

//���� �Է��� �޴´�. �Է� �������� ó���� �ְ� INT_MAX�� �����ϸ�
//�Է� �����̴�.
int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		// �߸��� �Է°��� �ǹ��ϴ� INT_MAX ���� ;
		return INT_MAX;
	}
	return iInput;
}
//���� �޴��� ȭ�鿡 �����ְ� �Է¹��� �޴��� ��ȯ�Ѵ�.
//�Է� ������ ��� Ȥ�� �߸��� ��ȣ�� ��� MM_NONE�� ��ȯ.
int OuputMainMenu() {
	system("cls");
	cout << "**********************�κ�**********************" << endl << endl;
	cout << "1. �� " << endl;
	cout << "2. ���� " << endl;
	cout << "3. ���� " << endl;
	cout << "4. ���� " << endl;
	cout << "�޴��� ������ �ּ��� :";
	int iMenu = InputInt();
	if (iMenu == INT_MAX || iMenu <=MM_NONE||iMenu >MM_EXIT)
		return MM_NONE;

	return iMenu;
}

_tagMonster CreateMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin,
	int iArmorMax, int iHP, int iHPMax, int iMP, int iMPMAX, int iLevel, int iExp, int iGoldMin, int iGoleMax) {

	//���� ����
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
	//������ ������ ������
	pMonsterArr[MT_EASY - 1] = CreateMonster("���", 20, 30, 2, 5, 100, 100, 10,
		10, 1, 1000, 500, 1500);
	pMonsterArr[MT_NORMAL - 1] = CreateMonster("Ʈ��", 80, 130, 60, 90, 2000,
		2000, 100, 100, 5, 7000, 6000, 8000);
	pMonsterArr[MT_HARD - 1] = CreateMonster("�巡��", 250, 500, 200, 400,
		30000, 30000, 20000, 20000, 10, 30000, 20000, 50000);
}
void OutputBattleTag(MAP_TYPE eMenu) {
	switch (eMenu) {
	case MT_EASY:
		cout << "**********************����**********************" << endl << endl;
		break;
	case MT_NORMAL:
		cout << "**********************����**********************" << endl << endl;
		break;
	case MT_HARD:
		cout << "**********************�����**********************" << endl << endl;
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer) {
	
	// �÷��̾� ������ ����Ѵ�.
	cout << "=======================Player=======================" << endl;
	cout << "�̸� : " << pPlayer->strName << "\t���� :" <<
		pPlayer->strJobName << endl;
	cout << "���� : " << pPlayer->iLevel << "\t����ġ :" <<
		pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
	// ���⸦ �����ϰ�  ���� ��� ���ݷ¿� ���� ���ݷ��� �߰��Ͽ� ���.

	if (pPlayer->bEquip[EQ_WEAPON] == true) {
		cout << "���ݷ� : " << pPlayer->iAttackMin << " + " <<
			pPlayer->tEquip[EQ_WEAPON].iMin << " - " <<
			pPlayer->iAttackMax << " + " << pPlayer->tEquip[EQ_WEAPON].iMax;
	}
	else {

		cout << "���ݷ� : " << pPlayer->iAttackMin << " - " <<
			pPlayer->iAttackMax;
	}

	//���� �����ϰ� ���� ��� ���¿� �� �� �濩�¹����� �߰��Ͽ� ���

	if (pPlayer->bEquip[EQ_ARMOR] == true) {
		cout << "\t���� : " << pPlayer->iArmorMax << " + " <<
			pPlayer->tEquip[EQ_ARMOR].iMin << " - " <<
			pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	}
	else {

		cout << "\t���� : " << pPlayer->iArmorMin << " - " <<
			pPlayer->iArmorMax << endl;
	}
	cout << "ü�� : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t���� : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
	cout << "���� ��� : " << pPlayer->tInventory.iGold << " Gold " << endl << endl;

}

void OutputMonster(_tagMonster* pMonster) {
	//���� ���� ���.

	cout << "=======================Monster=======================" << endl;
	cout << "�̸� : " << pMonster->strName << "\t���� :" <<
		pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " <<
		pMonster->iAttackMax << "\t���� : " << pMonster->iArmorMin << " - " <<
		pMonster->iArmorMax << endl;
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t���� : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ���� : " <<
		pMonster->iGoldMin << " - " << pMonster->iGoldMax << " Gold " << endl << endl << endl;

}

int OutputBattleMenu() {

	cout << "1.����" << endl;
	cout << "2.��������" << endl;
	cout << "�������ּ��� : ";

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
		//�÷��̾� ���
		OutputPlayer(pPlayer);
		//���� ���
		OutputMonster(&tMonster);
		switch (OutputBattleMenu()) {
		case BATTLE_ATTACK:
			break;
		case BATTLE_BACK:
			return;
		}

	}
}

//�� �޴��� ȭ�鿡 �����ְ� �Է¹��� �޴��� ��ȯ�Ѵ�.
//�Է� ������ ��� Ȥ�� �߸��� ��ȣ�� ��� MT_NONE�� ��ȯ.
int OutPutMapMenu() {
	system("cls");
	cout << "**********************��**********************" << endl << endl;
	cout << "1.���� " << endl;
	cout << "2.���� " << endl;
	cout << "3.����� " << endl;
	cout << "4.�ڷΰ��� " << endl;
	cout << "���� �����ϼ��� : ";
	int iMenu = InputInt();
	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MT_NONE;
	
	return iMenu;
}
//�� ���� ���� ó��
void RunMap(_tagPlayer* pPlayer,_tagMonster* pMonsterArr) {
	bool	bLoop = true;
	while (bLoop) {
		int iMenu = OutPutMapMenu(); 
			
		if (MT_BACK == iMenu)
			return;
		//������ ����
		RunBattle(pPlayer, pMonsterArr, (MAP_TYPE)iMenu);
	}
}


int SelectJob() {
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1.���" << endl;
		cout << "2.�ü�" << endl;
		cout << "3.������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = InputInt();
		//������ ������ ��� ���ڸ� �Է��������
		//���� JOB_NONE�� �����Ͽ� �ٽ� �ݺ��ϵ��� ��.
		if(iJob==INT_MAX|| iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}
	return iJob;
}



void SetPlayer(_tagPlayer* pPlayer) {
	//�÷��̾� �̸��� �Է¹���
	cout << "�̸��� �Է��ϼ��� : ";
	//���ڿ��� ���� NULL�� �����ϱ� ������ NAEM_SIZE -1�� ���ش�.
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
	//���۽� Player�� �������� ����
	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;
	pPlayer->tInventory.iItemCount = 0;
	pPlayer->tInventory.tItem[INVENTORY_MAX - 1] = {};


	//������ ������ �����԰� ���ÿ� ������ �����Ͽ��⶧����
	//�ش� switch������ default ���� �������� �ʿ䰡 ����.
	//�� �������� �ɷ�ġ�� �ٸ��� ������ ������ �ɷ�ġ�� ��������.
	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "���");
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
		strcpy_s(pPlayer->strJobName, "�ü�");
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
		strcpy_s(pPlayer->strJobName, "������");
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
	//�������.
	strcpy_s(pStoreWeapon[0].strName, "�ռҵ�");
	strcpy_s(pStoreWeapon[0].strTypeName, "����");
	strcpy_s(pStoreWeapon[0].strDesc, "ūĮ�Դϴ�.");
	pStoreWeapon[0].iPrice = 3000;
	pStoreWeapon[0].iSell = 1500;
	pStoreWeapon[0].iMax = 15;
	pStoreWeapon[0].iMin = 10;
	pStoreWeapon[0].eType = (ITEM_TYPE)ITEM_WEAPON;

	strcpy_s(pStoreWeapon[1].strName, "���");
	strcpy_s(pStoreWeapon[1].strTypeName, "����");
	strcpy_s(pStoreWeapon[1].strDesc, "ūȰ�Դϴ�.");
	pStoreWeapon[1].iPrice = 3000;
	pStoreWeapon[1].iSell = 1500;
	pStoreWeapon[1].iMax = 15;
	pStoreWeapon[1].iMin = 10;
	pStoreWeapon[1].eType = (ITEM_TYPE)ITEM_WEAPON;

	strcpy_s(pStoreWeapon[2].strName, "������");
	strcpy_s(pStoreWeapon[2].strTypeName, "����");
	strcpy_s(pStoreWeapon[2].strDesc, "�������Դϴ�.");
	pStoreWeapon[2].iPrice = 3000;
	pStoreWeapon[2].iSell = 1500;
	pStoreWeapon[2].iMax = 15;
	pStoreWeapon[2].iMin = 10;
	pStoreWeapon[2].eType = (ITEM_TYPE)ITEM_WEAPON;

}
void SetArmor(_tagItem* pStoreArmor) {
	//�� ����.
	strcpy_s(pStoreArmor[0].strName, "����");
	strcpy_s(pStoreArmor[0].strTypeName, "��");
	strcpy_s(pStoreArmor[0].strDesc, "�����Դϴ�.");
	pStoreArmor[0].iPrice = 3000;
	pStoreArmor[0].iSell = 1500;
	pStoreArmor[0].iMax = 15;
	pStoreArmor[0].iMin = 10;
	pStoreArmor[0].eType = (ITEM_TYPE)ITEM_ARMOR;

	strcpy_s(pStoreArmor[1].strName, "����");
	strcpy_s(pStoreArmor[1].strTypeName, "��");
	strcpy_s(pStoreArmor[1].strDesc, "�����Դϴ�.");
	pStoreArmor[1].iPrice = 3000;
	pStoreArmor[1].iSell = 1500;
	pStoreArmor[1].iMax = 15;
	pStoreArmor[1].iMin = 10;
	pStoreArmor[1].eType = (ITEM_TYPE)ITEM_ARMOR;

	strcpy_s(pStoreArmor[2].strName, "�Ź�");
	strcpy_s(pStoreArmor[2].strTypeName, "��");
	strcpy_s(pStoreArmor[2].strDesc, "�Ź��Դϴ�.");
	pStoreArmor[2].iPrice = 3000;
	pStoreArmor[2].iSell = 1500;
	pStoreArmor[2].iMax = 15;
	pStoreArmor[2].iMin = 10;
	pStoreArmor[2].eType = (ITEM_TYPE)ITEM_ARMOR;
}

int main(){
	srand((unsigned int)time(0));
	
	//������ ������ �� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer tPlayer = {};

	_tagMonster tMonsterArr[MT_BACK - 1] = {};
	// �������� �Ǹ��� ������ ����� �����Ѵ�.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	//�÷��̾��� ������ ������
	SetPlayer(&tPlayer);
	//������ ������ ������
	SetMonster(tMonsterArr);
	//������ ������ ������
	SetWeapon(tStoreWeapon);
	SetArmor(tStoreArmor);



	bool	bLoop = true;
	while (bLoop) {
		switch (OuputMainMenu()) {
		case MM_MAP:
			RunMap(&tPlayer,tMonsterArr); //�� ���� ������ ó��
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