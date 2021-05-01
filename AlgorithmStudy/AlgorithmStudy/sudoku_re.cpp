#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> prb(9, vector<int>(9, 0));

bool check(int pos) {
	int c = prb[pos / 9][pos % 9];
	for (int i = 0; i < 9; i++) {
		if (c == prb[i][pos % 9] && i != pos / 9) {
			return false;
		}
		if (c == prb[pos / 9][i] && i != pos % 9) {
			return false;
		}
	}
	for (int i = pos / 9 / 3 * 3; i < pos / 9 / 3 * 3 + 3; i++) {
		for (int j = pos % 9 / 3 * 3; j < pos % 9 / 3 * 3 + 3; j++) {
			if (i * 9 + j != pos && c == prb[i][j])
				return false;
		}
	}
	return true;
}

void sudoku(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (check(i * 9 + j))
					printf("%d ", prb[i][j]);
				else
					printf("x ");
			}
			printf("\n");
		}
		exit(0);
	}
	else {
		if (prb[cnt / 9][cnt % 9] != 0)
			sudoku(cnt + 1);
		else {
			for (int i = 1; i <= 9; i++) {
				prb[cnt / 9][cnt % 9] = i;
				if (check(cnt))
					sudoku(cnt + 1);
			}
			prb[cnt / 9][cnt % 9] = 0;
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &prb[i][j]);
		}
	}

	sudoku(0);
}


