#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	queue<int> cur;
	queue<int> next;
	bool visitied[100000] = { false, };

	cur.push(n);
	int time = 0;
	while (!cur.empty() && n != k) {
		time++;
		while (!cur.empty()) {
			n = cur.front();
			cur.pop();

			if (n - 1 == k || n + 1 == k || n * 2 == k) {
				n = k;
				break;
			}
			else {
				if (n * 2 <= 100000 && !visitied[n * 2]) {
					next.push(n * 2);
					visitied[n * 2] = true;
				}
				if (n + 1 <= 100000 && !visitied[n + 1]) {
					next.push(n + 1);
					visitied[n + 1] = true;
				}
				if (n - 1 >= 0 && !visitied[n - 1]) {
					next.push(n - 1);
					visitied[n - 1] = true;
				}

			}
		}
		
		while (!next.empty()) {
			cur.push(next.front());
			next.pop();
		}
	}
	cout << time;
	return 0;
}