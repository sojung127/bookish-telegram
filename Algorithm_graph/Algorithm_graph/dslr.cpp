#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	int a, b;
	vector<string> answer;
	bool visited[10000] = { false, };
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		// d는 2배, s는 n-1, l은 왼편으로 회전, r은 오른편으로 회전
		queue<pair<string, short>> q;
		q.push({ "", a });
		string ans = "";
		while (!q.empty()) {
			string str = q.front().first;
			int k = q.front().second;
			q.pop();

			int d, s, l, r;

			d = k * 2 % 10000;
			s = k - 1 == 0 ? 9999 : k - 1;
			l = k % 1000 * 10 + k / 1000;
			r = k / 10 + (k % 10 * 1000);

			if (d == b) {
				ans = str + "D";
				break;
			}
			else if (s == b) {
				ans = str + "S";
				break;
			}
			else if (l == b) {
				ans = str + "L";
				break;
			}
			else if (r == b) {
				ans = str + "R";
				break;
			}
			else {
				if (!visited[d]) {
					visited[d] = true;
					q.push({ str + "D", d });
				}if (!visited[s]) {
					visited[s] = true;
					q.push({ str + "S", s });
				}if (!visited[l]) {
					visited[l] = true;
					q.push({ str + "L", l });
				}if (!visited[r]) {
					visited[r] = true;
					q.push({ str + "R", r });
				}
			}


		}
		answer.push_back(ans);
		while (!q.empty()) q.pop();
	}

	for (auto ans : answer)
		cout << ans << endl;

	return 0;
}