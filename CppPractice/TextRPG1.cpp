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
	JOB_WIZARD
};

#define NAME_SIZE 32

struct _tagPlayer {
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJOB;
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

	while (true) {
		system("cls");
		cout << "**********************로비**********************" << endl << endl;
		cout << "1. 맵 " << endl;
		cout << "2. 상점 " << endl;
		cout << "3. 가방 " << endl;
		cout << "4. 종료 " << endl;
		cout << "메뉴를 선택해 주세요 :";
		int iMenu;
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
			while(true) {
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

			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하셨습니다." << endl;
			break;
		}



	}
	return 0;
}