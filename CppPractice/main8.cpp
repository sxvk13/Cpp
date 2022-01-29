/*
20 Lecture (Structure and String Function)
*/

#include <iostream>

using namespace std;

//������� �������ƴ� ����� ������� ���������� �����ϱ⿡ 
//define ��ũ�θ� ����Ͽ� ����� ����
#define NAME_SIZE 32 
#define NO_SIZE 9

// ����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
// ��������� ���� Ÿ���̴�.
// ���� : struct ����ü�� {} : �� ���·� �����ȴ�.
// �迭�� ����ü�� ������ 
//	1. �������� ����.
//  2. ����ü ������� ���ӵ� �޸� ���� �Ҵ�ȴ�.

struct _tagStudent {
	
	char strName[NAME_SIZE];
	char strNo[NO_SIZE];
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};



int main() {
	//={}���� �ʱ�ȭ ������ ������ �����Ⱚ�� ������.
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {}; // 52byte *100  =5200byte

	//����ü ����� �����Ҷ��� " . " �� �̿��ؼ� �����ϰ� �ȴ�.

	tStudent.iKor = 100;

	//tStudent.strName = "asdkfasfsd";(�Ұ���)
	// ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־���Ѵ�.
	// strcpy_s �Լ��� �����ʿ� �ִ� ���ڿ��� �������� ��������.
	//strcpy_s(tStudent.strName, "�����ٶ� asdf");

	// ���ڿ��� ���� �׻� 0(NULL)�� ������ ��. 
	// ���� �� �迭 ��ҿ� ���� �־��ְ� �Ǹ� �� ���� ��µǳ�,
	// ex) tStudent.strName[0]= 'a';tStudent.strName[1]= 'b'; 
	// �־����� ���� �κ��� ���ڿ��� ���� �ν��� �� ���� ������ �����Ⱚ���� ����� �ȴ�.
	// �� �迭 ��ҿ� ���� �־� ���������� ����ϱ� ���ؼ���
	// ������ ��ҿ� 0(NULL)�� �־��ָ� �ȴ�.
	// ex) tStudent.strName[2]= 0;
	//strcpy_s �Լ��� �������� �ڵ����� 0�� �����Ѵ�.
	strcpy_s(tStudent.strName, "�����ٶ� asdf");
	strcpy_s(tStudent.strNo, "20150979");

	//strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	//�������� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�. strName���� ������
	//�����ٶ� asdf �� ������ �ξ��� ������ �� �ڿ� ������ ���ڿ��� �ٿ��� ������ش�.
	strcat_s(tStudent.strName, " ���ڿ� ���̱�");

	//strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ� 
	//�ٸ���� 0�� �ƴ� ���� ��ȯ�Ѵ�.
	strcpy_s(tStudent.strName, "ȫ�浿");

	cout << "���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;
	if (strcmp(tStudent.strName, strName) == 0) {
		cout << " �л��� ã�ҽ��ϴ�. " << endl;
	}
	else {
		cout << "ã�� �л��� �����ϴ�. " << endl;
	}


	//strlen �Լ��� ������ ���̸� �����ش�.
	cout << "�̸����� : " << strlen(tStudent.strName) << endl;
	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.strNo << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}