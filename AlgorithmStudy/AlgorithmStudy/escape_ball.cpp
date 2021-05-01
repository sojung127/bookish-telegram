#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct balls {
	int r_x, r_y;
	int b_x, b_y;
};

int main(void) {

	int n, m;//n:¼¼·Î , m:°¡·Î
	cin >> n >> m;

	int map[10][10];
	// 0:ºóÄ­, 1:Àå¾Ö¹°, 2: »¡°£°ø,3:ÆÄ¶õ°ø,4: Å»Ãâ ±¸¸Û

	int r_x, r_y;
	int b_x, b_y;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			char c = s.at(j);
			if (c == '#')
				map[i][j] = 1;
			if (c == '.')
				map[i][j] = 0;
			if (c == 'R') {
				r_x = j; r_y = i;
				map[i][j] = 2;
			}
			if (c == 'B') {
				b_x = j; b_y = i;
				map[i][j] = 3;
			}
			if (c == 'O')
				map[i][j] = 4;
		}
	}

	queue<balls> q;
	bool visited[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	balls now = { r_x,r_y,b_x,b_y };
	q.push(now);
	while (!q.empty()) {
		balls b = q.front();
		q.pop();
	}

	return 0;
}