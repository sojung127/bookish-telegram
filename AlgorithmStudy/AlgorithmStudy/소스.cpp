#include <iostream>
#include <sstream>

using namespace std;

void solution(int numOfOrder, string* orderArr) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	for (int i = 0; i < numOfOrder; i++) {
		string product;
		int num = orderArr[i].find('(');
		cout << num;
		for (int j = 0; j < orderArr[i].length()-1; j++) {
			if (j+1 == num) {
				int num = orderArr[i].find_last_of(')');
				string repeat;
			}
		}
		for (char& c : orderArr[i]) {
			if (c > '1' && c < '9') {
				string repeat;

			}
		}
	}
}
string repeat_string(string rp, int last) {
	if()
}
struct input_data {
	int numOfOrder;
	string* orderArr;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfOrder;

	inputData.orderArr = new string[inputData.numOfOrder];
	for (int i = 0; i < inputData.numOfOrder; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		iss >> inputData.orderArr[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfOrder, inputData.orderArr);
	return 0;
}