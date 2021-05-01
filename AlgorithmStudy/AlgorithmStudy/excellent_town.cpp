#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[10001] = { false, };
int people[10001];
vector<vector<int>> map(10001);
vector<vector<int>> best(2, vector<int>(10001, 0));

void dfs(int idx) {
	if (visited[idx]) return;

	visited[idx] = true;
	best[0][idx] = 0;
	best[1][idx] = people[idx];

	for (int i = 0; i < map[idx].size(); i++) {
		int next = map[idx][i];
		if (visited[next]) continue;
		dfs(map[idx][i]);
		best[0][idx] += max(best[0][map[idx][i]],best[1][map[idx][i]]);
		best[1][idx] += best[0][map[idx][i]];
	}

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> people[i+1];

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	dfs(1);

	cout << max( best[0][1] , best[1][1]);
	return 0;
}