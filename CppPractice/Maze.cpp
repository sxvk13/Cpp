/*
* Lecture 38 Maze Game
*/


#include <iostream>
#include <conio.h>

using namespace std;

// 0 : 벽  ,	1 : 길 ,	2 : 시작점 ,	3 : 도착점 ,	4: 폭탄설치

struct _tagPoint
{
	int x;
	int y;
};

// typdef :타입 재정의
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21],PPOINT pPlyaerPos, PPOINT pStartPos,PPOINT pEndPos) {
	
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlyaerPos = *pStartPos;

	strcpy_s(Maze[0],	"21100000000000000000");
	strcpy_s(Maze[1],	"00111111111100000000");
	strcpy_s(Maze[2],	"00100010000111111100");
	strcpy_s(Maze[3],	"01100010000000000100");
	strcpy_s(Maze[4],	"01000111100000111100");
	strcpy_s(Maze[5],	"01001100001111100000");
	strcpy_s(Maze[6],	"01100000001000000000");
	strcpy_s(Maze[7],	"00100000001111111000");
	strcpy_s(Maze[8],	"01111000000000001000");
	strcpy_s(Maze[9],	"00001000000000001000");
	strcpy_s(Maze[10],	"00001000000111111000");
	strcpy_s(Maze[11],	"00001111000100001000");
	strcpy_s(Maze[12],	"01100001100100001000");
	strcpy_s(Maze[13],	"00111111000111111000");
	strcpy_s(Maze[14],	"00001000000000001000");
	strcpy_s(Maze[15],	"00111111111110001110");
	strcpy_s(Maze[16],	"01100000100010001000");
	strcpy_s(Maze[17],	"01000011111010001110");
	strcpy_s(Maze[18],	"00000010001000000010");
	strcpy_s(Maze[19],	"00000000000000000013");
}

void Output(char Maze[21][21],PPOINT pPlayerPos) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			if (Maze[i][j] == '4')
				cout << "♨";
			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "☆";
			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";
			else if (Maze[i][j] == '3')
				cout << "◎";
		}
		cout << endl;
	}
}
void MoveUp(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y - 1 >= 0)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0'&& Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
		{
			--pPlayerPos->y;
		}
	}
}
void MoveDown(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y + 1 < 20)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0'&& Maze[pPlayerPos->y + 1][pPlayerPos->x] !='4' )
		{
			++pPlayerPos->y;
		}
	}
}
void MoveRight(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 < 20)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0'&& Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
		{
			++pPlayerPos->x;
		}
	}
}
void MoveLeft(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0'&&Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
		{
			--pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos,char cInput) {

	switch (cInput) {
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);

		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}
//포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다.

void CreateBomb(char Maze[21][21], const PPOINT pPlayer,
PPOINT pBombArr,int* pBombCount) {

	if (*pBombCount == 5)
		return;

	for (int i = 0; i < *pBombCount; ++i) {
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
			return;
	}
	// 시작점에서는 폭탄 설치 불가
	if (pPlayer->y == 0 && pPlayer->x == 0)
		return;
	else {
		pBombArr[*pBombCount]= *pPlayer;
		++(*pBombCount);
		Maze[pPlayer->y][pPlayer->x] = '4';
	}
}

void Fire(char Maze[21][21], const PPOINT pPlayer,PPOINT pBombArr, int* pBombCount) {
	for (int i = 0; i < *pBombCount; ++i) {
		

		//플레이어가 폭탄에 맞았을 경우 시작점으로 되돌림.
		if (pPlayer->y == pBombArr[i].y && pPlayer->x == pBombArr[i].x ||
			pPlayer->y == pBombArr[i].y-1 && pPlayer->x == pBombArr[i].x ||
			pPlayer->y == pBombArr[i].y+1 && pPlayer->x == pBombArr[i].x || 
			pPlayer->y == pBombArr[i].y && pPlayer->x == pBombArr[i].x-1 || 
			pPlayer->y == pBombArr[i].y && pPlayer->x == pBombArr[i].x+1) {
			pPlayer->y = 0;
			pPlayer->x = 0;
		}

		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
		
		if(pBombArr[i].y-1>=0 && Maze[pBombArr[i].y-1][pBombArr[i].x] !='2')
			Maze[pBombArr[i].y-1][pBombArr[i].x] = '1';
		if(pBombArr[i].y+1<20 && Maze[pBombArr[i].y + 1][pBombArr[i].x] != '2')
			Maze[pBombArr[i].y+1][pBombArr[i].x] = '1';
		if(pBombArr[i].x+1<20 && Maze[pBombArr[i].y][pBombArr[i].x + 1] != '2')
			Maze[pBombArr[i].y][pBombArr[i].x+1] = '1';
		if(pBombArr[i].x-1>=0 && Maze[pBombArr[i].y][pBombArr[i].x - 1] != '2')
			Maze[pBombArr[i].y][pBombArr[i].x-1] = '1';

	}
	*pBombCount = 0;
}
int main() {
	
	// 20 x 20 미로를 만들어준다.
	// 마지막에 NULL문자가 들어가기 위해 21,21 크기의 배열
	char	strMaze[21][21] = {};

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 0;

	POINT tBombPos[5];

	//미로 설정
	SetMaze(strMaze,&tPlayerPos,&tStartPos,&tEndPos);
	while (true) {
		system("cls");
		//미로 출력
		Output(strMaze,&tPlayerPos);
		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) {
			cout << endl << "도착하였습니다!" << endl;
			break;
		}
		cout << endl << "t : 폭탄설치 u : 폭탄 터뜨리기 " << endl;
		cout << endl << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료   >>>  ";
		char cInput=_getch();
		if (cInput == 'q' || cInput == 'Q')
			break;
		else if (cInput == 't' || cInput == 'T') {
			CreateBomb(strMaze, &tPlayerPos,tBombPos,&iBombCount);
		}
		else if (cInput == 'u' || cInput == 'U') {
			Fire(strMaze,&tPlayerPos,tBombPos,&iBombCount);
		}
		else {
		MovePlayer(strMaze, &tPlayerPos,cInput);

		}
		


	}


	return 0;
}