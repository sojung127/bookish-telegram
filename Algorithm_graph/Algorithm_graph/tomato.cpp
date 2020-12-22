#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int m, n, h;	// m: 상자의 가로칸 수, n: 세로칸, h: 높이 
	scanf("%d %d %d", &m, &n, &h);

	vector<int> box(h * m * n);

	queue<int> grown;
	queue<int> tobe;

	int input;
	for (int height = 0; height < h; height++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				scanf("%d", &input);
				box[height * (m * n) + y * m + x] = input;
				if (input == 1) {
					grown.push(height * (m * n) + y * m + x);
				}
			}
		}
	}
	
	int day = 0;

	while (!grown.empty()) {
		while (!grown.empty()) {
			int tomato = grown.front();
			grown.pop();

			if ((tomato + m * n < h * m * n) && box[tomato + (m * n)] == 0) {
				box[tomato + m * n] = 1;
				tobe.push(tomato + m * n);
			}
			if ((tomato - (m * n) >= 0) && box[tomato - (m* n)] == 0) {
				box[tomato - (m * n)] = 1;
				tobe.push(tomato - (m * n));
			}
			if (tomato % m != 0 && box[tomato - 1] == 0) {
				box[tomato - 1] = 1;
				tobe.push(tomato - 1);
			}
			if ((tomato + 1) % m != 0 && box[tomato + 1] == 0) {
				box[tomato + 1] = 1;
				tobe.push(tomato + 1);
			}
			if ((tomato % (m * n)) >= m && box[tomato - m] == 0) {
				box[tomato - m] = 1;
				tobe.push(tomato - m);
			}
			if (((tomato / m) + 1) % n != 0 && box[tomato + m] == 0) {
				box[tomato + m] = 1;
				tobe.push(tomato + m);
			}
		}

		grown = tobe;
		while (!tobe.empty()) tobe.pop();
		day++;
	}

	if (find(box.begin(), box.end(), 0) == box.end())
		cout << day;
	else
		cout << -1;

	return 0;
}