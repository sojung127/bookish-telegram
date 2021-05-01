#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[11][11];

int TSP(int visited,int cnt);
int n, k;
int cache[11][1 << 10];

int main() {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	// 플로이드 와샬
	int d[11][11][11];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			d[0][i][j] = map[i][j];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[k][i][j] = d[k - 1][i][j] < (d[k - 1][i][k] + d[k - 1][k][j]) ? d[k - 1][i][j] : (d[k - 1][i][k] + d[k - 1][k][j]);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			cout << d[n][i][j]<<" ";
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			map[i][j] = d[n][i + 1][j + 1];
	}

	// 외판원 순회 -비트마스킹
	cout << TSP(1 << k, k);
	return 0;
}

int TSP(int visited,int cnt) {
	if (visited == (1<<n)-1 ) {
		return 0;
	}
	int& ret = cache[cnt][visited];
	if (ret != 0)	return ret;
	ret = 1000*10+1;

	for (int next = 0; next < n; next++) {
		if (visited & (1 << next)) continue;
		//if (map[cnt][next] == 0)	continue;
		ret = min(ret, TSP( visited | (1 << next),next) + map[cnt][next]);
	}
	return ret;
}