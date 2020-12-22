#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

	int k, n;
	scanf("%d %d", &k, &n);
	vector<int> line(k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &line[i]);
	}

	long long len = 0;
	for (auto a : line)
		len += a;

	// 
	long left = 1;
	long right = *max_element(line.begin(), line.end());
	int max = 0;
	while (left <= right) {
		int cnt = 0;
		long long mid = (left + right) / 2;
		for (auto a : line) {
			cnt += a / mid;
		}
		if (cnt >= n) {
			if (max < mid)
				max = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << max;
	return 0;
}