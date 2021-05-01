#include <iostream>

using namespace std;




int main() {

	int c,r,k;
	c = r = k = 0;
	cin >> c >> r;
	cin >> k;
	int org_c, org_r, org_k;
	org_c = c;
	org_r = r;
	org_k = k;
	int x, y;
	x = y = 1;

	if (k > c* r)
		cout << "0";
	else {
		int i;
		c--;
		for (i = 1; k >= 0; i++) {
			if (i%2==1 ) {
				if (k - r <= 0) break;
				k -= r; r--; x++;
			}
			if (i % 2 == 0 ) {
				if (k - c <= 0) break;
				k -= c; c--; y++;
			}
		}

		int ans_x, ans_y;
		// 구역의 마지막 칸의 위치를 구함
		if (x % 2 == 1) 
			ans_x=  x / 2 + 1;
		else
			ans_x= org_c - x / 2 + 1;
		if (y % 2 == 1)
			ans_y= org_r - y / 2;
		else
			ans_y= y / 2;

		// k가 몇번째 구역에 있었는지에 따라 마지막 칸의 위치에 k값을 이용해서 k의 위치를 구함.
		if (i % 4 == 1) {
			ans_y -= r-k;
		}
		else if (i % 4 == 2) {
			ans_x -= c-k;
		}
		else if (i % 4 == 3) {
			ans_y += r-k;
		}
		else {
			ans_x += c - k;
		}
		cout << ans_x << " " << ans_y;
	}
}