/*
	21 Lecture ( Student Management Program)
*/

#include <iostream>

using namespace std;

//�л� ����
#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14

//�л� �ִ� �����
#define STUDENT_MAX 10

//�л� ����ü
struct _tagStudent {
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];

	int iNumber, iKor, iEng, iMath, iTotal;

	float fAvg;
};

//�޴� ������

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUPUT,
	MENU_EXIT
};



int main() {
	
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	//�迭�� �߰��� ������ ������ ������ �������.
	int iStudentCount = 0;
	int iStdNumber = 1;
	while (true) {
		system("cls");
		cout << "==================�л����� ���α׷�==================" << endl<<endl;
		cout << "***********************�޴�**************************" << endl << endl;
		cout << "1. �л� ���" << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� Ž��" << endl;
		cout << "4. �л� ���" << endl;
		cout << "5. ������" << endl << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		cin >> iMenu;
		//cin�� ���� �����ʿ� int ������ ���� ������ �Է��ؾ� �Ѵ�. �����ʿ� ���� ���� 
		//Ÿ�Կ� ���缭 ���� �Է��ؾ� �ϴµ� �Ǽ��� ������ �ƴ� ���ڸ� �Է��� ���
		//������ �߻��Ѵ�. �׷��� ������ ����ó���� ������ �߻��ߴ����� ���⿡�� üũ�Ͽ�
		// ������ �߻��ϸ� cin ������ �������۸� ����ְ� cin ���ο� �Է¹��۰� �ִµ�
		//�Է¹��۴� �Է��� ���� ���� �س��� �� ���� ������ �־��ִ� ������ �Ѵ�.
		//�� �Է¹��ۿ� \n�� ���������Ƿ� ���۸� ��ȸ�Ͽ� \n�� �����ش�.
		//���� : �ӽ� ���� �����̴�.
		
		//���� ������ üũ��.
		//cin.fail()�� ������ �Է¿����� �߻����� ��� true�� ��ȯ��.
		if (cin.fail()) {
			//�ַ� ���۸� ����ش�.
			cin.clear();
			//�Է¹��۸� �˻��Ͽ� \n�� �����ش�.
			//ù��°���� �˻��ϰ��� �ϴ� ����ũ�⸦ �����Ѵ�. �˳��ϰ� 1024
			//����Ʈ ���� �������ش�. 2��°���� ã���� �ϴ� ���ڸ� �־��ش�.
			//�׷��� �Է¹��� ó������ \n�� �ִ� ������ ã�Ƽ� �� �κ��� ��� 
			// �����༭ �ٽ� �Է¹����� �ְ� �Ѵ�.
			cin.ignore(1024, '\n');
			continue;
		}
		// ������ �޴� ����������� �ݺ��� Ż��
		if (iMenu == MENU_EXIT)
			break;


		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "==================�л� �߰�==================" << endl << endl;

			//��ϵ� �л��� ����� �� �ִ� �ִ�ġ�� ��� ���̻� ����� �ȵǰ� ���´�
			if (iStudentCount == STUDENT_MAX)
				break;

			//�л� ������ �߰��Ѵ�. �л������� �̸�,�ּ� ,��ȭ��ȣ
			//����,����, ���� ������ �Է¹ް� �ѹ� , ����, ����� ������
			//���� ������ش�.
			// �̸��� �Է¹޴´�.
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;

			//cin�� cin.getline�� �Բ����� '\n'���� ���� ������ �߻��ϹǷ�
			//�Է¹��۸� \n���� ������.
			cin.ignore(1024, '\n');
			
			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress,ADDRESS_SIZE);
			//cout << tStudentArr[iStudentCount].strAddress << endl;
			//cin.getline ������ �ٽ� cin.getline�� ����� ������ ������ ���� �����Ƿ�
			//cin.ignore�� ������� ����.

			cout << "��ȭ��ȣ :";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);
			//cout << tStudentArr[iStudentCount].strPhoneNumber << endl;
			while (true) {
				cout << "���� : ";
				cin >> tStudentArr[iStudentCount].iKor;
				if (tStudentArr[iStudentCount].iKor > 100 || tStudentArr[iStudentCount].iKor < 0) {
					cout << "�߸� �Է��ϼ̽��ϴ�!(���� : ���� �ʰ�)" << endl;
					cout << "�ٽ� �Է��� �ּ���." << endl;
					continue;
				}
				else {
					break;
				}
			}
				
			while (true) {
				cout << "���� : ";
				cin >> tStudentArr[iStudentCount].iEng;
				if (tStudentArr[iStudentCount].iEng > 100 || tStudentArr[iStudentCount].iEng < 0) {
					cout << "�߸� �Է��ϼ̽��ϴ�!(���� : ���� �ʰ�)" << endl;
					cout << "�ٽ� �Է��� �ּ���." << endl;
					continue;
				}
				else {
					break;
				}
			}
				
			while (true) {
				cout << "���� : ";
				cin >> tStudentArr[iStudentCount].iMath;
				if (tStudentArr[iStudentCount].iMath > 100 || tStudentArr[iStudentCount].iMath < 0) {
					cout << "�߸� �Է��ϼ̽��ϴ�!(���� : ���� �ʰ�)" << endl;
					cout << "�ٽ� �Է��� �ּ���." << endl;
					continue;
				}
				else {
					break;
				}
			}
			
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;
			tStudentArr[iStudentCount].iNumber = iStdNumber;
			++iStdNumber;
			++iStudentCount;

			cout << "�л� �߰� �Ϸ� " << endl;

			break;
		case MENU_DELETE:
				
			break;
		case MENU_SEARCH:
			break;
		case MENU_OUPUT:
			system("cls");
			cout << "==================�л� ���==================" << endl << endl;
			//���� ��ϵ� �л��� ���� ��� 
			if (iStudentCount == 0) {
				cout << "���� ��ϵ� �л��� �����ϴ�!" << endl<<endl;
				break;
			}

			//��ϵ� �л� ����ŭ �ݺ��ϸ� �л������� ����Ѵ�.
			for (int i = 0; i < iStudentCount; ++i) {
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl;
				cout << "---------------------------------"<<endl<< endl;
			}
			break;
		default:
			cout << " �޴��� �߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		system("pause");
	}

	return 0;

}