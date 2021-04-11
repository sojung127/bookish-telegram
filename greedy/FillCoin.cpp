#include <iostream>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int coin[10];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int cnt = 0;
	int key = 1;

	while (k>0 && key<n) {
		if(k%coin[key]!=0)
			cnt += k%coin[key]/coin[key-1];
		k = k / coin[key] * coin[key];
		key++;
	}
	if (k > 0) {
		cnt += k/ coin[key - 1];
	}


	cout << cnt;

	return 0;
}