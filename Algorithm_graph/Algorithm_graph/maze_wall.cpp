#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

int main() {

	int n, m;
	cin >> m>>n;
	vector<vector<int>> map(n+1, vector<int>(m+1,0));
	vector<vector<bool>> visited(n , vector<bool>(m , false));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = stoi(s.substr(j , 1));
		}
	}

	int block = 0;
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; //x,y 와 cnt를 저장
	pair<int, int> v ;
	q.push({ 0,{0,0} });
	visited[0][0] = true;
	while (!q.empty()) {
		v = q.top().second;
		int x = v.first; int y = v.second;
		
		int cnt = q.top().first;
		q.pop();

		if (x == n-1 && y== m-1) {
			block = cnt;
			break;
		}

		if (x > 0 && !visited[x - 1][y]) {
			q.push({ map[x - 1][y] == 0 ? cnt : cnt + 1, {x - 1,y} });
			visited[x-1][y] = true;
		}
		if (x < n-1 && !visited[x + 1][y]) {
			visited[x+1][y] = true;
			q.push({ map[x + 1][y] == 0 ? cnt : cnt + 1 ,{x + 1, y} });
		}
		if (y > 0 && !visited[x][y - 1]) {
			visited[x][y-1] = true;
			q.push({ map[x][y - 1] == 0 ? cnt : cnt + 1,{x, y - 1} });
		}
		if (y < m-1 && !visited[x][y + 1]) {
			visited[x][y+1] = true;
			q.push({ map[x][y + 1] == 0 ? cnt : cnt + 1,{x, y + 1} });
		}
	}

	cout << block;

		

	return 0;
}