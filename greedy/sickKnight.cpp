#include <iostream>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int stamp;

	if (n == 1)
		stamp = 1;
	else if (n == 2)
		stamp = min(4, (m + 1) / 2);
	else if (m < 7)
		stamp = min(4, m);
	else
		stamp = m - 7 + 5;

	cout << stamp;
	return 0;
}