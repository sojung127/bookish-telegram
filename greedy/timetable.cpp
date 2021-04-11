#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {

	int n;
	vector<pair<int, int>> info(n);
	for (int i = 0; i < n; i++) {
		cin >> info[i].first >> info[i].second;
	}

	sort(info.begin(), info.end(), compare);

	int cnt = 0;
	int end = 0;

	for (int i = 0; i < n; i++) {
		if (end <= info[i].first) {
			end = info[i].second;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}