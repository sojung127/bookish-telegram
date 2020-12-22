#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> video;

string makeTree(int x, int y, int size) {
	if (size == 1) 
		return to_string(video[x][y]);

	string answer;
	bool clear = true;
	for (int i = x; i < x + size && clear; i++) {
		for (int j = y; j < y + size; j++) {
			if (video[x][y] != video[i][j]) {
				clear = false;
				break;
			}
		}
	}

	if (!clear) {
		answer = "(";
		answer += makeTree(x, y, size / 2);
		answer += makeTree(x, y + size / 2, size / 2);
		answer += makeTree(x + size / 2, y, size / 2);
		answer += makeTree(x + size / 2, y + size / 2, size / 2);
		answer += ")";
	}
	else {
		answer = to_string(video[x][y]);
	}
	return answer;
}

int main() {

	int n;
	scanf("%d", &n);

	video.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			video[i][j] = stoi(input.substr(j, 1));
		}
	}
	cout << "input end\n";

	cout << makeTree(0, 0, n);
	return 0;
}