#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
vector<pair<int, int>> path;
void move(int a, int b) {
	cnt++;
	path.push_back(make_pair(a, b));
}
void hanoi(int n,int a, int b, int c) {		//n개의 원반을 a에서 b를 거쳐 c로 이동.
	if (n == 1) {
		move(a, c);
	}

	else {
		hanoi(n - 1, a, c, b);	// 위의 n-1개를 a에서 b로 옮겨둠
		move(a, c);				// 가장 밑의 큰 원판을 c로 옮김
		hanoi(n - 1, b, a, c);	// 다시 b로 옮겨둔 n-1개의 원판을 c로 옮김.
	}
	
}

int main() {

	int n;
	cin >> n;

	hanoi(n, 1, 2, 3);
	cout << cnt << endl;
	for (auto p : path) {
		cout << p.first << " " << p.second << endl;
	}
}