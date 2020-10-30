#include<iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int bag_num = N / 5;
	int cur_weight = 5 * bag_num;

	while (cur_weight < N && cur_weight>=0) {
		if ((N - cur_weight) % 3 == 0) {
			bag_num += (N - cur_weight) / 3;
			cur_weight += (N - cur_weight);
		}
		else {
			bag_num--;
			cur_weight -= 5;
		}
	}
	if (cur_weight < 0)
		bag_num = -1;

	cout << bag_num;
	return 0;
}