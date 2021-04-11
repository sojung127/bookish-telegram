#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
vector<pair<int, int>> path;
void move(int a, int b) {
	cnt++;
	path.push_back(make_pair(a, b));
}
void hanoi(int n,int a, int b, int c) {		//n���� ������ a���� b�� ���� c�� �̵�.
	if (n == 1) {
		move(a, c);
	}

	else {
		hanoi(n - 1, a, c, b);	// ���� n-1���� a���� b�� �Űܵ�
		move(a, c);				// ���� ���� ū ������ c�� �ű�
		hanoi(n - 1, b, a, c);	// �ٽ� b�� �Űܵ� n-1���� ������ c�� �ű�.
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