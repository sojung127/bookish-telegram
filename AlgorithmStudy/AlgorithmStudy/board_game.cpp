#include <iostream>
#include <algorithm>

using namespace std;

int N, K, M;
int card[1001];
int map[501][501];
int ans;
int dp[1002][502];

int dfs(int cur_card, int cur_town) {

	if (cur_card == N + 1) {
		return 0;
	}
	if (dp[cur_card][cur_town] != -1) return dp[cur_card][cur_town];
	dp[cur_card][cur_town] = 0;

	int cur_color = card[cur_card];
	for (int i = 1; i <= M; i++) {
		if (map[cur_town][i] == cur_color) {
			dp[cur_card][cur_town] = max(dp[cur_card][cur_town], dfs(cur_card + 1, i) + 10);

		}
		else if (map[cur_town][i] != 0) {
			dp[cur_card][cur_town] = max(dp[cur_card][cur_town], dfs(cur_card + 1, i));
		}
	}
	return dp[cur_card][cur_town];

}
int main() {

	cin >> N;
	char color;
	for (int i = 1; i <= N; i++) {
		cin >> color;
		if (color == 'R') card[i] = 1;
		if (color == 'G') card[i] = 2;
		if (color == 'B') card[i] = 3;
	}
	cin >> M >> K;
	int to, from;
	for (int i = 0; i < K; i++) {
		cin >> to >> from >> color;
		if (color == 'R') map[to][from] = map[from][to] = 1;
		if (color == 'G') map[to][from] = map[from][to] = 2;
		if (color == 'B') map[to][from] = map[from][to] = 3;
	}
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			dp[i][j] = -1;
		}
	}
	dfs(1, 1);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (ans < dp[i][j]) {
				ans = dp[i][j];
			}
		}
	}

	cout << ans;

}