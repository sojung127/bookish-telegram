#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return (a[1] < b[1]);
}

vector<int> sum_vector(vector<int> a,vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		a[i] += b[i];
	}
	return a;
}

int main() {

	int n;

	scanf("%d", &n);

	vector<vector<int>> ball(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ball[i][0], &ball[i][1]);
		ball[i][2] = i;
	}

	sort(ball.begin(), ball.begin() + n, &cmp);

	vector<int> score(n, 0);
	int sum = 0;
	vector<int> sum_per_color(n + 1, 0);
	int tmp_sum = 0;
	vector<int> tmp_spc(n + 1, 0);
	int prv_size = 0;
	vector<int> prv(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int num = ball[i][2];
		int color = ball[i][0];
		int size = ball[i][1];
		if (size != prv_size) {
			sum += tmp_sum;
			sum_per_color = sum_vector(sum_per_color, tmp_spc);
			tmp_sum = 0;
			tmp_spc.assign(n + 1, 0);
			prv_size = size;
		}
		score[num] = sum - sum_per_color[color];
		tmp_sum += size;
		tmp_spc[color] += size;
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", score[i]);
	}

	return 0;
}