#include<iostream>
#include <string>
#include <vector>

using namespace std;
/*
덧셈 식을 모두 괄호로 묶고 괄호로 묶인 식들을 모두 빼는 식으로 진행.
덧셈 연산으로 값을 최대한 크게 만들고 그 값을 뺄셈 연산에 이용해 값이 작아지도록 만드는 것.

*/
int main() {
	string str;
	cin >> str;
	int sum = 0;
	int num = 0;
	vector<int> arr;	
	for (char c : str) {
		// - 연산자를 마주하면 지금까지의 덧셈연산의 값을 배열에 저장.
		if (c == '-') {
			sum += num;
			arr.push_back(sum);
			num = 0;
			sum = 0;
		}
		// + 연산자를 마주하면 앞에서 처리한 숫자를 sum에 합하여 저장.
		else if (c == '+') {
			sum += num;
			num = 0;
		}
		// 앞에서부터 읽어들이고 있으므로 앞에 숫자에 10을 곱해주고 다시 현재 숫자를 더하는것.
		else {
			num *= 10;
			num += c - '0';
		}
	}

	sum += num;	//마지막 피연산자 값을 더함.
	arr.push_back(sum);

	int answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		answer -= arr[i];
	}

	cout << answer;
}