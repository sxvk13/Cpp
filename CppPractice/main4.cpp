/*

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	// do while ��
	// ���� : do {..}while(���ǽ�) �� ����
	// while���� ó�� ���Ժ��� ���ǽ��� üũ������ do while�� ó�� �ѹ��� ������ ����
	// �� �Ŀ� ���ǽ��� üũ�ؼ� true�� ��� �����ϴ� �ݺ���

	int iNumber = 0;

	do {
		cout << iNumber << endl;
	} while (iNumber > 0);

	
	//�迭
	//�������� ������ �ѹ��� �������� �� �ִ� ���
	//���� : ����Ÿ�� �迭��[����] �� ���·� ����
	//Ư¡ : ���ӵ� �޸� ���� ������ �Ҵ��.
	//		-�迭�� �ε����� �̿��ؼ� ���ϴ� �κп� �����Ͽ� ���� ����.
	//		-�ε����� 0���� ����-1 ������. (10�̶�� 0~9���� �� 10���� �ε���)
	//		-�迭 �Ӹ� �ƴ϶� �Ϲ� �����鵵 ������ �ϰ� ���� �ʱ�ȭ ���� ������
	//			������ ���� ��.
	
	//int iArray[10]; -> int type ���� 10 �� -> 4byte(int�� ũ��) * 10 = 40byte 
	//int iArray[10] = {1,2,3,4,5,6,7,8,9,10 }; -> ����� ���ÿ� �ʱ�ȭ
	//int iArray[10] = {1,2,3,4,5} -> 0~4 �������� 1~5�� �ʱ�ȭ �ϰ� �������� 0���� �ʱ�ȭ
	int iArray[10] = {};// ����ִ� �߰�ȣ�� ������ ��� ��� �ε����� 0���� �ʱ�ȭ

	iArray[1] = 1234;
	for (int i = 0; i < 10; ++i) {
		cout << iArray[i] << endl;
	}

	// �迭 ������ 2�� �����ϸ� 2���� �迭, 3������ �ϸ� 3���� �迭 n�� �����ϸ� n���� �迭�� �ȴ�.
	// 2���� �迭�� ������ ���� �� * ���� �� ��ŭ ó���� �ȴ�
	int iArray2[10][10] = { {1,2,3},{4,5,6} }; // ����� ���ÿ� �ʱ�ȭ 10 * 10 ���� �迭 ���� 

	//2���� �迭�� ��� ��ø�ݺ����� ����ؼ� ���

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << iArray2[i][j] << "\t";
		}
		cout << endl;
	 }
	


	system("cls");
	//Lotto Program

	int iLotto[45] = {};
	int iRn;
	srand((unsigned int) time(0));;
	int i = 0;

	for(int i=0;i<45;++i){
		iLotto[i]= i+ 1;	
	}

	while(true){
		if (i == 6)
			break;

		iRn = rand() % 45 + 1;
		for (int j = 0; j < 45; ++j) {
			if ((iLotto[j] != 0) && (iRn == iLotto[j])) {
				cout << iLotto[j] << " ";
				iLotto[j] = 0;
				++i;
				break;
			}
		}
	}
	cout << endl;
	system("cls");
	cout << endl;


	//Ǯ��

	//1~45������ ���ڸ� ���ʴ�� �־���.

	for (int i = 0; i < 45; i++) {
		iLotto[i] = i + 1;
	}
	//Swap �˰���
	//int iNum1 =1, iNum2=2,  iNum3;
	//iNum3=iNum1;
	//iNum1=iNum2;
	//iNUM2=iNum3;


	//Shuffle - TCG���ӿ��� ���� ���
	//Shuffle�� Swap�˰����� ���
	int iTemp, idx1, idx2;
	//100������ ���� ������.
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 45; //0~44 ��° ��ġ�� ����
		idx2 = rand() % 45; 

		//��ġ ����
		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}	
	for (int i = 0; i < 6; i++) {
		cout << iLotto[i]<<" " ;
	}
	cout << "���ʽ� ��ȣ : " << iLotto[6];
	return 0;
}

*/