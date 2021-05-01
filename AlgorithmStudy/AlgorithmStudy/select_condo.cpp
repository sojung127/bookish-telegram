#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dist_cmp(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}
bool money_cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

void print_vector(vector<int> input) {
	
		for (int j = 0; j < 5; j++) {
			cout << input[j] << " ";
		}
		cout << endl;

}

int main() {

	int n;
	cin >> n;

	vector<vector<int>> input(n, vector<int>(5, 0));

	for (int i = 0; i < n; i++) {
		int d, c;
		cin >> d >> c;
		input[i][0] = i;
		input[i][1] = d;
		input[i][2] = c;
	}

	vector<vector<int>> sorted(n, vector<int>(5));;
	vector<vector<int>> sorted_dist(n, vector<int>(5));;
	copy(input.begin(), input.end(), sorted.begin());
	copy(input.begin(), input.end(), sorted_dist.begin());

	//거리순 정렬
	sort(sorted_dist.begin(), sorted_dist.end(), dist_cmp);
	for (int i = 0; i < n; i++) {
		int k = sorted_dist[i][0];
		input[k][3] = i;
	}

	//비용순 정렬
	sort(sorted.begin(), sorted.end(), money_cmp);
	for (int i = 0; i < n; i++) {
		int k = sorted[i][0];
		input[k][4] = i;
	}

	int cnt = 0;
	bool can = true;
	for (int i = 0; i < n; i++) { // 후보가 i일때
		can = true;
		for (int j = 0; j < input[i][4]; j++) { 
			// i보다 비용이 작은 콘도들은 거리가 더 멀ek
			int k = sorted[j][0]; // 비용순으로 탐색
			if (input[k][3] <= input[i][3]) {
				can = false;
				break;
			}
		}
		for (int j = 0; j < input[i][3];j++) {
			// i보다 거리가 가까운 콘도들은 비용이 더 크다
			int k = sorted_dist[j][0];
			if (input[k][4] <= input[i][4]) {
				can = false;
				break;
			}
		}
		if (can) cnt++;
	}

	cout << cnt;
	return 0;
}