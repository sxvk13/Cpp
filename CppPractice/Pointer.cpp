/*
	Lecture 30~32 : Pointer 
*/
/*
#include <iostream>
using namespace std;

struct _tagStudent {
	int iKor;
	int iEng;
	int imath;
	int iTotal;
	float fAvg;

};

int main() {


	// ������ : ����Ű��. �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������ ������ ������ �޸� �ּҸ� ������.
	// ��� ���� Ÿ���� ������ Ÿ���� ������ �� �ִ�. int ������ �ּҴ� int ������ ������ ������ �ؾ���.
	// �����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� ������ ���� ������ 4byte�� ������,
	// x64�϶��� 8byte�� ���´�. 
	//
	// �����ʹ� �ڱ� ������ �ƹ����ϵ� �� �� ����. �ݵ�� �ٸ� ������ �޸� �ּҸ� ������ �־��
	// ���� �� �� �ִµ� ������ �ִ� �� �޸� �ּҿ� �����ؼ� ���� ������ �� �ִ�.

	// ���� : ����Ÿ�� *������; �� ���·� ����
	//		or ����Ÿ��* ������;

	int iNumber = 100;

	// ���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�.
	// ���� �տ� &�� �ٿ��ָ� �ش� ������ �޸� �ּҰ� �ȴ�.
	// pNum�� iNumber������ �޸� �ּҸ� ������ ���� �Ѵ�. �׷��Ƿ� pNum�� �̿��ؼ� iNumber�� ����
	// ������ �� �ְ� �� ���̴�.
	int* pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum�� �̿��ؼ� iNumber�� ���� �����غ���.
	// �������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.
	// �������� ������ ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.

	cout << *pNum << endl;

	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	// �����Ϳ� �迭�� ���� : �迭���� �����ʹ�. ��, �迭�� ��ü�� �ش� �迭��
	// �޸𸮿����� ������ �ּҸ� �ǹ��Ѵ�.

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray[0] << endl;

	int* pArray = iArray;
	
	cout << pArray[2] << endl;

	// ������ ���� : +, - ������ �����Ѵ�. ++, -- �� �����ѵ� 1�� �����ϰ� �Ǹ�
	// �ܼ��� �޸� �ּҰ��� 1 �����ϴ� ���� �ƴ϶�, int �������� ��� int Ÿ���� �޸� �ּҸ�
	// ���� �Ǵµ� �޸� �ּҿ� 1�� �����ָ� 1 ������ �ƴ� ����Ű�� �ش� ������ Ÿ���� ���� Ÿ��
	// ũ�⸸ŭ �����ϰ� �ȴ�. int �������̹Ƿ� int�� ũ���� 4��ŭ ���� �����ϰ� �Ǵ°��̴�.

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;


	const char* pText = "Test String";

	// pText[0]='a';
	// pText[1]='b';
	// �� ���� �������� ���� �����ϴ� ���� �Ұ���. pText�� ��� �Ӽ�(const)�̱� ������. 

	cout << pText << endl;
	cout << (int*)pText << endl;
	

	//�׷��� �������� ����� �����ϴ� ���� ����
	pText = "abcd";

	cout << pText << endl;
	cout << (int*)pText << endl;

	//������ ���ڿ��� ���ؼ��� ������ �ּҰ��� ���
	pText = "abcd";
	cout << pText << endl;
	cout << (int*)pText << endl;

	//���� ������ ��ü���� ���ڿ��� �ٸ��ٸ� �ٸ� �ּҰ��� �Ҵ�
	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	
	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// ������ �켱���� ������ .�� ���� �ν��ϰ� �ȴ�.
	// �޸� �ּ� . �� �߸��� �����̴�. �׷��Ƿ� *pStudent�� ��ȣ�� ������ �Ŀ�
	// . �� �̿��ؼ� ����Ű�� ����� ��� ������ �����ؾ� �Ѵ�.
	
	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	// �޸� �ּ� -> �� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
	
	pStudent->iKor = 80;

	cout << tStudent.iKor << endl;

	// void : Ÿ���� ����. void�� ������ Ÿ���� Ȱ���� �� �ִ�.
	// void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ���尡��
	// ��, �������� �Ұ����ϰ� �޸� �ּҸ� ���� �����ϴ�.

	void* pVoid = &iNumber;

	cout << "iNumber Address : " << pVoid << endl;
	// *pVoid = 10; (������ �Ұ���)
	//int* pConvert = (int*)pVoid;
	//*pConvert = 10;
	// �Ǵ� *((int*)pVoid) = 9999
	//cout << "iNumber Value : " << iNumber << endl;
	//�� ���� ����ȯ�� ���־����.


	pVoid = &tStudent;
	cout << "tStudent Address : " << pVoid << endl;

	//���� ������ : *�� 2�� ���δ�. �Ϲ� ������ ������ �Ϲ� ������ �޸� �ּҸ� �����ϴ� ����
	//��� ���������ʹ� �������� �������̴�. ��, ���� �����ʹ� ������ ������ �޸� �ּҸ�
	//�����ϴ� �������̴�.

	
	int** ppNum = &pNum;

	*pNum = 3333;
	cout << "------------------------" << endl;
	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Addr : " << &iNumber << endl<<endl;
	cout << "*pNum : " << *pNum << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Addr : " << &pNum << endl<<endl;
	
	cout << "*ppNum : " << *ppNum << endl;
	cout << "**ppNum : " << **ppNum << endl;
	cout << "ppNum Value : " << ppNum << endl;
	cout << "ppNum Addr : " << &ppNum << endl;
	



	return 0;
}

*/