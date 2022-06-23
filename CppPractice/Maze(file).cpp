/*
* Lecture 52 Maze Game [File]
* SetMaze 함수내 미로를 그릴때 파일을 읽어와 미로를 그리게 설정
*/
/*
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

// 0 : 벽  ,		1 : 길 ,				2 : 시작점 ,		3 : 도착점 ,	4 : 폭탄설치
// 5 : 파워아이템 ,	6 : 벽밀기 아이템 ,		7 : 투명아이템 ,	8 : 웜홀

// 벽을 깨면 일정 확률로 아이템이 나온다.
// 아이템 종류 : 폭탄 반경 1칸 증가, 벽밀기 아이템, 투명아이템(벽통과)
// 3종류가 랜덤하게 등장한다. 등장하지 않을 수도 있다.

// 아이템을 먹게되면 해당 아이템 효과를 부여받게 된다.

// 벽을 깨면 랜덤하게 웜홀을 만든다. 웜홀에 들어가게되면 다른 웜홀의 위치로 이동
// 한다. 웜홀은 맵 중간마다 몇개씩 만들어 본다. 웜홀이 1개일 경우 다른곳으로 이동하지
// 않는다.

struct _tagPoint
{
	int x;
	int y;
};

// typdef :타입 재정의
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer {
	_tagPoint	tPos;
	bool		bWallPush;
	bool		bPushOnOff;
	bool		bTransparency;
	int			iBombPower;
}PLAYER, * PPLAYER;

void SetMaze(char Maze[21][21],PPLAYER pPlayer, PPOINT pStartPos,PPOINT pEndPos) {


	// MazeList.txt 파일을 읽어와서 미로 목록을 만든다.
	// **주의 : 파일의 마지막에는 개행이 입력되어있어야 마지막에 구분가능.


	FILE* pFile = NULL;

	fopen_s(&pFile, "MazeList.txt", "rt");

	char** pMazeList = NULL; 

	if (pFile) {
		char cCount;
		//MazeList에서 가장 먼저 읽어야 하는 것은 
		//맵의 갯수이므로 하나를 읽어옴.
		fread(&cCount, 1, 1, pFile);
		//메모장에 쓰여있는 맵의 갯수는 char형으로 읽히기 때문에 실질적인
		//정수로 바꿔주어야 함. 따라서 atoi()를 사용하여 해당 문자를
		//정수형으로 바꿔줌.

		int iMazeCount = atoi(&cCount);

		fread(&cCount, 1, 1, pFile);

		//char* 타입을 동적배열로 맵의 갯수만큼 할당.
		pMazeList = new char* [iMazeCount];

		for (int i = 0; i < iMazeCount; ++i) {
			// 파일명의 길이를 알아오기 위한 변수
			int iNameCount = 0;

			// 현재 미로의 파일 이름을 저장할 배열을 256개로 넉넉하게
			// 미리 할당.
			pMazeList[i] = new char[256];

			while (true) {
				fread(&cCount, 1, 1, pFile);
				if (cCount != '\n') {
					pMazeList[i][iNameCount] = cCount;
					++iNameCount;
				}
				else {
					break;
				}
			}
			//파일 이름을 모두 읽었다면 문자열의 마지막에 0을 넣어 문자열의 끝을 알려줌.
			pMazeList[i][iNameCount] = 0;

		}
		fclose(pFile);

		//읽을 파일 목록이 만들어 졌으므로 각 파일중 하나를 선택해서 미로를 읽어와서 설정.
		for (int i = 0; i < iMazeCount; ++i) {
			cout << i + 1 << ".: " << pMazeList[i] << endl;
		}


		cout << "미로를 선택하세요 : ";
		int iSelect;
		cin >> iSelect;

		//선택한 미로 파일을 읽는다.
		fopen_s(&pFile, pMazeList[iSelect - 1], "rt");
		
		if (pFile) {
			//미로의 세로 줄 수만큼 반복하며 각 줄 별로 읽어온다.

			for (int i = 0; i < 20; ++i) {
				fread(Maze[i], 1, 20, pFile);
				
				//현재 줄의 미로를 검사하여 시작점, 혹은 도착점이 있는지 판단.
				for (int j = 0; j < 20; ++j) {
					//시작점
					if (Maze[i][j] == '2') {
						pStartPos->x = j;
						pStartPos->y = i;
						
						pPlayer->tPos = *pStartPos;
					}
					//도착점
					else if (Maze[i][j] == '3') {
						pEndPos->x = j;
						pEndPos->y = i;
					}
				}

				//개행문자를 읽어온다.
				fread(&cCount, 1, 1, pFile);
			}
			
			fclose(pFile);
		}

	}


}

void Output(char Maze[21][21],PPLAYER pPlayer) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			if (Maze[i][j] == '4')
				cout << "♨";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "☆";
			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";
			else if (Maze[i][j] == '3')
				cout << "◎";
			else if (Maze[i][j] == '5')
				cout << "▲";
			else if (Maze[i][j] == '6')
				cout << "▷";
			else if (Maze[i][j] == '7')
				cout << "＃";
		}
		cout << endl;
	}
	cout << "폭탄파워 : " << pPlayer->iBombPower <<endl;

	//가지고 있는 아이템 표시
	cout << "벽통과 : ";
	if (pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";
	cout << "벽밀기 : ";
	if (pPlayer->bWallPush) {
		cout << "가능 / ";

		if (pPlayer->bPushOnOff)
			cout << "ON" << endl;
		else
			cout << "OFF" << endl;

	}
	else
		cout << "불가능 / OFF"<<endl;

}

bool AddItem(char cItemType,PPLAYER pPlayer) {
	if (cItemType == '5') {
		//폭탄파워 증가 최대 5
		if(pPlayer->iBombPower<5)
		++pPlayer->iBombPower;
		return true;
	}
	else if (cItemType == '6') {
		pPlayer->bWallPush = true;
		pPlayer->bPushOnOff = true;
		return true;
	}
	else if (cItemType == '7') {
		pPlayer->bTransparency = true;
		return true;
	}
	return false;
}

void MoveUp(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y - 1 >= 0)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}
		// 벽 밀기가 가능하고 바로 윗칸이 벽일경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0') {
			//벽 밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff ) {
				//위의 위칸이 0보다 크거나 같은경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y - 2 >= 0) {
					//위의 위칸이 길이어야 밀기가 가능. 따라서 길인지 체크
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.y;

					}
					//길일 경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1') {
						//위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						//위칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1';
						//플레이어 이동.
						--pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.y;
			}
			//벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.y;
		}
		//벽일 경우
		//유령화 상태
		else if (pPlayer->bTransparency) {
			--pPlayer->tPos.y;
		}
		//위치가 아이템일 경우11
		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x],pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}
void MoveDown(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.y + 1 < 20)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] !='4' )
		{
			++pPlayer->tPos.y;
		}
		// 벽 밀기가 가능하고 바로 아래칸이 벽일경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0') {
			//벽 밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff) {
				//아래의 아래칸이 0보다 크거나 같은경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y + 2 <20) {
					//아래의 아래칸이 길이어야 밀기가 가능. 따라서 길인지 체크
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.y;

					}
					//길일 경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1') {
						//아래의 아래칸을 벽으로 하고
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						//아래칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1';
						//플레이어 이동.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.y;
			}
			//벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.y;
		}

		//벽일 경우
		//유령화 상태
		else if (pPlayer->bTransparency) {
			++pPlayer->tPos.y;
		}
		//위치가 아이템일 경우
		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}
void MoveRight(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x + 1 < 20)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}
		// 벽 밀기가 가능하고 바로 오른쪽칸이 벽일경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x+1] == '0') {
			//벽 밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff) {
				//오른쪽의 오른쪽칸이 0보다 크거나 같은경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x + 2 < 20) {
					//오른쪽의 오른쪽칸이 길이어야 밀기가 가능. 따라서 길인지 체크
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x +2] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.x;

					}
					//길일 경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x+2] == '1') {
						//오른쪽의 오른쪽칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x+2] = '0';
						//오른쪽칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y][pPlayer->tPos.x+1] = '1';
						//플레이어 이동.
						++pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.x;
			}
			//벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.x;
		}


		//벽일 경우
		//유령화 상태
		else if (pPlayer->bTransparency) {
			++pPlayer->tPos.x;
		}
		//위치가 아이템일 경우
		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}
void MoveLeft(char Maze[21][21], PPLAYER pPlayer) {
	if (pPlayer->tPos.x - 1 >= 0)
	{
		//벽 또는 폭탄인지 체크
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0'
			&&Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}

		// 벽 밀기가 가능하고 바로 왼쪽칸이 벽일경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0') {
			//벽 밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff) {
				//왼쪽의 왼쪽칸이 0보다 크거나 같은경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x - 2 >= 0) {
					//왼쪽의 왼쪽칸이 길이어야 밀기가 가능. 따라서 길인지 체크
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.x;

					}
					//길일 경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1') {
						//왼쪽의 왼쪽칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						//왼쪽칸은 벽이었는데 길로 만들어준다.
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1';
						//플레이어 이동.
						--pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.x;
			}
			//벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.x;
		}

		//벽일 경우
		//유령화 상태
		else if (pPlayer->bTransparency) {
			--pPlayer->tPos.x;
		}
		//위치가 아이템일 경우
		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MovePlayer(char Maze[21][21], PPLAYER pPlayer,char cInput) {

	switch (cInput) {
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);

		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;
	}
}
//포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다.

void CreateBomb(char Maze[21][21], const PPLAYER pPlayer,
PPOINT pBombArr,int* pBombCount) {
	//폭탄 설치수가 5개 이상 설치 불가
	if (*pBombCount == 5)
		return;
	// 현위치가 시작점일 경우 폭탄 설치 불가
	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '2')
		return;
	// 벽일경우 설치 불가
	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; ++i) {
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
			return;
	}
		pBombArr[*pBombCount]= pPlayer->tPos;
		++(*pBombCount);
		Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Fire(char Maze[21][21],const PPLAYER pPlayer,PPOINT pBombArr, int* pBombCount,PPOINT pStartPos) {
	for (int i = 0; i < *pBombCount; ++i) {

		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
		for (int j = 1; j <=pPlayer->iBombPower; ++j) {
			if (pBombArr[i].y - j >= 0 && Maze[pBombArr[i].y - j][pBombArr[i].x] != '2')
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0') {
					//아이템 드랍 확률을 구함.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						}
						else if (iPercent < 70) {
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';
						}
						else{
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
						}
					}
					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
				}

			if (pBombArr[i].y + j < 20 && Maze[pBombArr[i].y + j][pBombArr[i].x] != '2')
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0') {
					//아이템 드랍 확률을 구함.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						}
						else if (iPercent < 70) {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';
						}
						else {
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
						}
					}
					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}

			if (pBombArr[i].x + j < 20 && Maze[pBombArr[i].y][pBombArr[i].x + j] != '2')
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0') {
					//아이템 드랍 확률을 구함.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
						}
						else if (iPercent <70) {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';
						}
						else {
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
						}
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

			if (pBombArr[i].x - j >= 0 && Maze[pBombArr[i].y][pBombArr[i].x - j] != '2')
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0') {
					//아이템 드랍 확률을 구함.
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 40) {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						}
						else if (iPercent < 70) {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';
						}
						else {
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
						}
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
				}
		}
		for (int j = 1; j <= pPlayer->iBombPower; ++j) {
			//플레이어가 폭탄에 맞았을 경우 시작점으로 되돌림.
			if (pPlayer->tPos.y == pBombArr[i].y && pPlayer->tPos.x == pBombArr[i].x ||
				pPlayer->tPos.y == pBombArr[i].y - j && pPlayer->tPos.x == pBombArr[i].x ||
				pPlayer->tPos.y == pBombArr[i].y + j && pPlayer->tPos.x == pBombArr[i].x ||
				pPlayer->tPos.y == pBombArr[i].y && pPlayer->tPos.x == pBombArr[i].x - j ||
				pPlayer->tPos.y == pBombArr[i].y && pPlayer->tPos.x == pBombArr[i].x + j) {
				pPlayer->tPos = *pStartPos;
			}
		}
	}
	*pBombCount = 0;
}
int main() {

	srand((unsigned int)time(0));

	// 20 x 20 미로를 만들어준다.
	// 마지막에 NULL문자가 들어가기 위해 21,21 크기의 배열
	char	strMaze[21][21] = {};

	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;

	POINT tBombPos[5];

	//미로 설정
	SetMaze(strMaze,&tPlayer,&tStartPos,&tEndPos);
	while (true) {
		system("cls");
		//미로 출력
		Output(strMaze,&tPlayer);
		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y) {
			cout << endl << "도착하였습니다!" << endl;
			break;
		}
		cout << endl << "t : 폭탄설치 u : 폭탄 터뜨리기 i : 벽밀기 ON/OFF" << endl;
		cout << endl << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료   >>>  ";
		char cInput=_getch();
		if (cInput == 'q' || cInput == 'Q')
			break;
		else if (cInput == 't' || cInput == 'T') {
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		}
		else if (cInput == 'u' || cInput == 'U') {
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount,&tStartPos);
		}
		else if (cInput == 'i' || cInput == 'I') {
			if (tPlayer.bWallPush) {
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
			}
		}
		else {
		MovePlayer(strMaze, &tPlayer,cInput);

		}



	}


	return 0;
}
*/
