#include <iostream>

using namespace std;

int dirX[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dirY[9] = { 0,-1,-1,0,1,1,1,0,-1 };


int result;
void dfs(int sharkAte,int sharkX,int sharkY,int shark_dir,int dir[],int pos[][2],int map[][4]) {
	result = result < sharkAte ? sharkAte : result;
	for (int i = 1; i <= 16; i++) {
		if (dir[i] == 0) continue;
		int cnt = 0;
		int toX = pos[i][0] + dirX[dir[i]];
		int toY = pos[i][1] + dirY[dir[i]];
		while (toX < 0 || toX >= 4 || toY < 0 || toY >= 4 || (toX == sharkX && toY == sharkY)) {
			if (cnt == 8) break;
			dir[i] = (dir[i]==8)?1:dir[i]+1;
			toX = pos[i][0] + dirX[dir[i]];
			toY = pos[i][1] + dirY[dir[i]];
			cnt++;
		}
		if (cnt < 8) {
			int toIndex = map[toY][toX];
			pos[toIndex][0] = pos[i][0];
			pos[toIndex][1] = pos[i][1];
			map[pos[i][1]][pos[i][0]] = toIndex;
			pos[i][0] = toX;	pos[i][1] = toY;
			map[toY][toX] = i;
		}
	}


	int y = sharkY;
	int x = sharkX;

	for (int move = 1; move <= 3; move++) {
		int tempdir[17];
		int temppos[17][2];
		for (int i = 0; i < 17; i++) {
			tempdir[i] = dir[i];
			temppos[i][0] = pos[i][0];
			temppos[i][1] = pos[i][1];
		}
		int tempmap[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tempmap[i][j] = map[i][j];
			}
		}

		int nextY = y + dirY[shark_dir] * move;
		int nextX = x + dirX[shark_dir] * move;
		if (nextY < 0 || nextY >= 4 || nextX < 0 || nextX >= 4) { continue; }

		if (tempmap[nextY][nextX] == 0) { continue; }

		sharkY = nextY;
		sharkX = nextX;

		int score = tempmap[nextY][nextX];
		tempmap[nextY][nextX] = 0;
		shark_dir = tempdir[score];
		tempdir[score] = 0;

		dfs(sharkAte + score, sharkX, sharkY, shark_dir, tempdir, temppos, tempmap);
	}


	
	
}
int main() {

	
	int dir[17];
	int pos[17][2];
	int map[4][4];
	int a, b;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> a >> b;
			dir[a] = b;
			pos[a][1] = i - 1;
			pos[a][0] = j - 1;
			map[i - 1][j - 1] = a;
		}
	}
	int sharkAte;
	int sharkX, sharkY;
	int shark_dir;
	sharkAte = map[0][0];
	map[0][0] = 0;
	sharkX = 0; sharkY = 0;
	shark_dir = dir[sharkAte];
	dir[sharkAte] = 0;

	result = 0;
	dfs(sharkAte, sharkX, sharkY, shark_dir, dir, pos, map);

	cout << result;

	return 0;
}