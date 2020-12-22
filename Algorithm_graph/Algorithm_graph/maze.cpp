#include<iostream>
#include<cstdio>
#include <vector>
#include<string>
#include <cmath>
#include <queue>

using namespace std;

int minimum = 1000000;
int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;
void DFS(int x, int y, int step);

int main() {
	scanf("%d %d", &n, &m);
	map.resize(n, vector<int>(m));
	visited.assign(n, vector<bool>(m,false));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = stoi(s.substr(j, 1));
		}

	}
	DFS(0, 0, 1);
	cout << minimum;
}
//1011101110111011101110111
//1110111011101110111011101
void DFS(int x, int y, int step) {
	if ((x == (n - 1)) && (y == (m - 1))) {
		if (step < minimum)
			minimum = step;
	}
	else {
		pair<int, int> u = make_pair(0, 0);
		visited[0][0] = true;
		queue<pair<int, int>> q;
		q.push(u);
		while (!q.empty()) {
			u = q.front();
			visited[u.first][u.second] = true;
			q.pop();



			if (x > 0 && map[x - 1][y] == 1 && !visited[x - 1][y]) {
				q.push(make_pair(x - 1, y));
			}
			if (y > 0 && map[x][y - 1] == 1 && !visited[x][y - 1]) {
				q.push(make_pair(x - 1, y));
			}
			if (x < n - 1 && map[x + 1][y] == 1 && !visited[x + 1][y]) {
				q.push(make_pair(x - 1, y));
			}
			if (y < m - 1 && map[x][y + 1] == 1 && !visited[x][y + 1]) {
				q.push(make_pair(x - 1, y));
			}
		}



		if (x > 0 && map[x - 1][y] == 1 && !visited[x - 1][y]) {
			visited[x-1][y] = true;
			DFS(x - 1, y, step + 1);
			visited[x-1][y] = false;
		}
		if (y > 0 && map[x][y - 1] == 1 && !visited[x][y - 1]) {
			visited[x][y-1] = true;
			DFS(x, y - 1, step + 1);
			visited[x][y-1] = false;
		}
		if (x < n - 1 && map[x + 1][y] == 1 && !visited[x+1][y]) {
			visited[x+1][y] = true;
			DFS(x + 1, y, step + 1);
			visited[x+1][y] = false;
		}
		if (y < m - 1 && map[x][y + 1] == 1 && !visited[x][y + 1]) {
			visited[x][y+1] = true;
			DFS(x, y + 1, step + 1);
			visited[x][y+1] = false;
		}
	}
}