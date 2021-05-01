#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
queue<tuple<int, int, int>> q;
bool visited[201][201][201] = { false, };

int main() {

	int Ab, Bb, Cb;
	cin >> Ab >> Bb >> Cb;

	tuple<int, int, int> s(0, 0, Cb);
	q.push(s);

	vector<int> ans;
	int a, b, c;
	while (!q.empty()) {
		s = q.front();
		q.pop();
		tie(a, b, c) = s;
		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;
		if (a == 0) 
			ans.push_back(c);

		if (a != 0) {
			if (a > Cb) q.push({ a - (Cb-c), b, Cb }); else if (a + c > Cb) q.push({ (Cb - c - a) * (-1),b,Cb }); else q.push({ 0,b,a + c });
			if (a > Bb) q.push({ a - (Bb-b),Bb,c }); else if (a + b > Bb) q.push({ a + b - Bb,Bb,c }); else q.push({ 0,a + b,c });
		}
		if (b != 0) {
			if (b > Ab) q.push({ Ab,b - Ab+a,c }); else if (a + b > Ab) q.push({ Ab,a + b - Ab,c }); else q.push({ a + b,0,c });
			if (b > Cb) q.push({ a,b - Cb+c,Cb }); else if (b + c > Cb) q.push({ a,b + c - Cb,Cb }); else q.push({ a,0,b + c });
		}
		if (c != 0) {
			if (c > Ab) q.push({ Ab,b,c - Ab+a }); else if (a + c > Ab) q.push({ Ab,b,c + a - Ab }); else q.push({ a + c,b,0 });
			if (c > Bb) q.push({ a,Bb,c - Bb+b }); else if (c + b > Bb) q.push({ a,Bb,c + b - Bb }); else q.push({ a,b + c,0 });
		}
		
	}
	sort(ans.begin(), ans.end());
	for (auto answer : ans) {
		cout << answer << " ";
	}

	return 0;
}