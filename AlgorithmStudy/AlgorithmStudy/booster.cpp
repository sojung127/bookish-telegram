#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double distance(int x1, int x2, int y1, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {

	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> checkpoint;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		checkpoint.push_back(make_pair(x,y));
	}

	int cur_x, cur_y;
	int des_x, des_y;
	for (int test_case = 0; test_case < q; test_case++) {
		int A, B, hp;
		cin >> A >> B >> hp;
		cur_x = checkpoint[A - 1].first;
		cur_y = checkpoint[A - 1].second;
		des_x = checkpoint[B - 1].first;
		des_y = checkpoint[B - 1].second;

		bool reach = false;
		int dir_x, dir_y;
		dir_x = des_x - cur_x;
		dir_y = des_y - cur_y;
		double dis = distance(cur_x, des_x, cur_y, des_y);
		// �湮���� üũ �迭 �ʿ�
		while (!(cur_x == des_x && cur_y == des_y) || !reach) {
			int tmpX, tmpY;
			int bestX, bestY;
			double tmpDis=0;
			for (int i = 0; i < n; i++) {
				if (i != A - 1) {
					tmpX = checkpoint[i].first; tmpY = checkpoint[i].second;
					tmpDis = distance(cur_x, tmpX, cur_y, tmpY);
					// �ν��ͷ� �� �� �ִ°�
					if ((tmpX == cur_x || tmpY == cur_y)) {

						continue;
					}
					// �ɾ �� �ִ°�
					else if(tmpDis<dis && tmpDis<hp){

					}
				}
			}

		}

	}

	return 0;
}