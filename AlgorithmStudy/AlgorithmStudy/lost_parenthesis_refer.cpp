#include<iostream>
#include <string>
#include <vector>

using namespace std;
/*
���� ���� ��� ��ȣ�� ���� ��ȣ�� ���� �ĵ��� ��� ���� ������ ����.
���� �������� ���� �ִ��� ũ�� ����� �� ���� ���� ���꿡 �̿��� ���� �۾������� ����� ��.

*/
int main() {
	string str;
	cin >> str;
	int sum = 0;
	int num = 0;
	vector<int> arr;	
	for (char c : str) {
		// - �����ڸ� �����ϸ� ���ݱ����� ���������� ���� �迭�� ����.
		if (c == '-') {
			sum += num;
			arr.push_back(sum);
			num = 0;
			sum = 0;
		}
		// + �����ڸ� �����ϸ� �տ��� ó���� ���ڸ� sum�� ���Ͽ� ����.
		else if (c == '+') {
			sum += num;
			num = 0;
		}
		// �տ������� �о���̰� �����Ƿ� �տ� ���ڿ� 10�� �����ְ� �ٽ� ���� ���ڸ� ���ϴ°�.
		else {
			num *= 10;
			num += c - '0';
		}
	}

	sum += num;	//������ �ǿ����� ���� ����.
	arr.push_back(sum);

	int answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		answer -= arr[i];
	}

	cout << answer;
}