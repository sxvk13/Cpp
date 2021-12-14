/*
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	// ��� :  ������ �ʴ� ��. ���� �ѹ� �����س����� �ٲ� �� ����.
	// ����� ����� ���ÿ� ���� ������ �־� ��.

	const int iAttack = 0x00000001;		//			1
	const int iArmor = 0x00000002;		//		   10
	const int iHP = 0x00000004;			//		  100
	const int iMP = 0x00000008;			//		 1000
	const int iCritical = 0x00000010;	//		10000


	// ����,ü��,ũ��Ƽ�� ���� �Ҵ�
	//			 001 | 100 | 10000 =  10101
	int iBuf = iAttack | iHP | iCritical;

	//������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.
	
	// 10101 ^ 00100 = 10001 = 17;
	iBuf ^= iHP;
	// 10001 ^ 00100 = 10101 = 21;
	iBuf ^= iHP;
	
	// XOR ������ �̿��ؼ� ����ġ ����� ������ �� ����.


	// 10101 & 00001 = 1;
	cout << "Attack : "<<(iBuf & iAttack) << endl;
	
	// 10101 & 00010 = 0;
	cout << "Armor : " << (iBuf & iArmor) << endl;

	// 10101 & 00100 = 4;
	cout << "HP : " << (iBuf & iHP) << endl;
	
	// 10101 & 01000 =  0;
	cout << "MP : " << (iBuf & iMP) << endl;
	
	// 10101 & 10000 = 16;
	cout << "Critical : " << (iBuf & iCritical) << endl;
	


		//*********************************************************
		//����Ʈ ������ : <<, >> �� �� ���� �����Ͽ� ������ ������ �ȴ�.
		//�� ������ ���� ������ ������ ������ �ϰ� �ȴ�.
		//20 << 2 = 80	->	20*(2^2)
		//20 << 3 = 160	->	20*(2^3)
		//20 << 4 = 320	->	20*(2^4)
		
		//��������Ʈ ������ ���� ������ ����(���� �� ������ ����. �Ҽ��� ����)

		//20 >> 2 = 5	->	20/(2^2)
		//20 >> 3 = 2 ->	20/(2^3)
		//*********************************************************
	
	
	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;
	// iNumber���� 187�� ���ִ�. �� ���� ��������Ʈ�� 16��Ʈ �����ϸ�
	// ���� 16��Ʈ�� ���� ���� ��.
	iNumber <<= 16;

	// ���� 16��Ʈ�� ä���.

	iNumber |= iLow;

	//High ���� ����Ѵ�.

	cout << "iHigh : " << iHigh << endl;
	cout << "iNumber High bit : " << (iNumber >> 16) << endl;
	cout << "iLow : " << iLow << endl;
	cout << "iNumber Low bit : " << (iNumber & 0x0000ffff) << endl;

	//���������� : ++ ,-- �� ���� 1����, 1����
	iNumber = 10;

	//��ġ
	++iNumber;

	//��ġ
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl; 


	//******************
	  //�б⹮���� ũ�� 2���� ������ �ִ�. if��, switch ���� �����Ѵ�.
	  //if�� : ������ üũ���ִ� ����̴�.
	  //���� : if(���ǽ�){ ... };
	  //if���� ���ǽ��� true�� �� ��� �ڵ�� ���� �ڵ尡 ���۵ȴ�.
	  //false�� ��쿡�� ���۵��� �ʴ´�.
	  //if�� �Ʒ��� �� �ڵ尡 1���� ��� {}(�ڵ��)�� ������ �� �ִ�.
	//***************
	if (true) {
		cout << "if�� ������ true �Դϴ�." << endl;
	}

	// ������ �ִ��� Ȯ���Ѵ�.

	if ((iBuf & iAttack) != 0) {
		cout << "Attack ������ �ֽ��ϴ�. " << endl;
	}
	if ((iBuf & iArmor) != 0)
		cout << "Armor ������ �ֽ��ϴ�. " << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical ������ �ֽ��ϴ�." << endl;
	
	//****************
	//	else : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	//	if�� ������ false�� ��� else�� �ִٸ� else���� ���� �ڵ尡 ���۵ȴ�.

	//	else if: if���� �ݵ�� ���� ����� �Ǿ���Ѵ�.
	//	if�� �Ʒ� �;� �ϰ� else ���ٴ� ���� �־�� �Ѵ�.
	//	else if�� �ڽ��� ���� �ִ� ���ǽ��� false�� ��� ���� else if�� ���ǽ��� üũ�Ѵ�.
	//	else if�� ��� ����� �����ϴ�.
	//************

	if (false) {
		cout << "if�� ������ true �Դϴ�." << endl;
	}
	else {
		cout << "if�� ������ false �Դϴ�." << endl;
	}

//	cout << "���ڸ� �Է��ϼ��� : ";
	//cin >> iNumber;
//	if (10 <= iNumber && iNumber <= 20)
//		cout << "10~20 ������ �����Դϴ�." << endl;
//	else if (21 <= iNumber && iNumber <= 30)
//		cout << "20~30 ������ �����Դϴ�." << endl;
//	else if (31 <= iNumber && iNumber <= 40)
//		cout << "30~40 ������ �����Դϴ�." << endl;
//	else
//		cout << "�� ���� �����Դϴ�." << endl;


	// ���� �߻�
	srand((unsigned int)time(0));

	cout << rand() << endl;
	cout << rand() << endl;
	
	cout << ((rand() %100) + (rand()* 0.001)) << endl;
	cout << (rand() % 10000 * 0.01f) << endl;

	// ���׷��̵� ��ġ
	int iUpgrade = 0;
	int iNum[15] = { 0 };
	int iCount = 0;

	while (true) {
		if (iUpgrade == 15) {
			break;
		}else{
			//��ȭ Ȯ���� ����.
			float fPercent = rand() % 10000 / 100.f;

			//��ȭ Ȯ�� : ���׷��̵尡 0~3 :  100% ���� , 4~6 : 40% ,7~9 :10%,
			//10~ 13 : 1%, 14~15 :0.01%
			cout << "Percent : " << fPercent << endl;

			if (iUpgrade <= 3) {
				iUpgrade++;
			}
			else if (iUpgrade > 3 && iUpgrade < 7) {
				if (fPercent < 40.f) {
					iUpgrade++;
				}
			}
			else if (iUpgrade > 6 && iUpgrade < 10) {
				if (fPercent < 10.f) {
					iUpgrade++;
				}
				else {
				//	iUpgrade -= (rand() % 3)+1;
				}
			}
			else if (iUpgrade > 9 && iUpgrade < 14) {
				if (fPercent < 1.f) {
					iUpgrade++;
				}
				else {
					//iUpgrade -= (rand() % iUpgrade) + 1;
				}
			}
			else if (iUpgrade > 13) {
				if (fPercent < 0.01f)
					iUpgrade++;
				else{
					//iUpgrade -= (rand() % iUpgrade) + 1;
				}
			}
			else {
				cout << "�� �̻� ��ȭ�� �� �����ϴ�." << endl;
			}
			iNum[iUpgrade - 1] += 1;
			iCount++;
		}
	}
	cout << "15������ �ɸ� Ƚ�� : " << iCount << endl;
	for (int i = 0; i < 15; i++) {
		cout << "��ȭ " << i + 1 << "�ܰ� �϶� �õ� Ƚ�� : " << iNum[i] << endl;
	}
	return 0;

}

*/