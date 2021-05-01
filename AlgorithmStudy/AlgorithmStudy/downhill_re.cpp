#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> step;
int cnt;
int n, m;

int dfs(int r, int c) {
	if (r == n - 1 && c == m - 1) {
		return 1;
	}
	else if (step[r][c] != -1) {
		return step[r][c];
	}
	else {
		int cur = map[r][c];
		step[r][c] = 0;
		if (r > 0 && map[r - 1][c] < cur) 
			step[r][c] += dfs(r - 1, c);
		if (c > 0 && map[r][c - 1] < cur)
			step[r][c] += dfs(r, c - 1);
		if (r < n - 1 && map[r + 1][c] < cur)
			step[r][c] += dfs(r + 1, c);
		if (c < m - 1 && map[r][c + 1] < cur)
			step[r][c] += dfs(r, c + 1);
		return step[r][c];
	}
}

int main() {
	
	cin >> n >> m;

	map.resize(n, vector<int>(m));
	step.resize(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0);


	return 0;
}