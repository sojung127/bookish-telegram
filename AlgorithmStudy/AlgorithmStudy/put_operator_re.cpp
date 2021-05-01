#include <iostream>	
#include <vector>

using namespace std;

vector<int> number(11);
int n;
// 연산 결과는 중간 연산을 포함하여 최대 10억, 최소 -10억의 결과가 나온다.
int max_val = -1000000000;	
int min_val = 1000000000;

void dfs(int val, int cnt, int plus, int minus, int mul, int div) {
	if (cnt == n - 1) {
		if (max_val < val)
			max_val = val;
		if (min_val > val)
			min_val = val;
	}
	else {
		if (plus > 0)
			dfs(val + number[cnt + 1], cnt + 1, plus - 1,minus, mul, div);
		if (minus > 0)
			dfs(val - number[cnt + 1], cnt+1,plus, minus - 1, mul, div);
		if (mul > 0)
			dfs(val * number[cnt + 1], cnt + 1, plus, minus, mul - 1, div);
		if (div > 0)
			dfs(val / number[cnt + 1], cnt + 1, plus, minus, mul, div-1);
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> number[i];
	int op[4] = { 0, };
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	dfs(number[0], 0, op[0], op[1], op[2], op[3]);
	cout << max_val << endl << min_val;
	return 0;
}