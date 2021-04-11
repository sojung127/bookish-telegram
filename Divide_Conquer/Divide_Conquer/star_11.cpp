#include <cstdio>	
#include <iostream>	
#include <vector>
#include <string>

using namespace std;

vector<string> str;
int n;

void draw(int floor) {
	if (floor == 1) {
		str[0] = "*";
		str[1] = "* *";
		str[2] = "*****";
	}
	else {
		draw(floor / 2);
		for (int i = (floor / 2) * 3; i < floor * 3; i++) {
			str[i] += str[i - (floor / 2) * 3];
			string tmp;
			tmp.assign(floor * 3 - 1 - (i - (floor / 2) * 3) * 2, ' ');
			str[i] += tmp;
			str[i] += str[i - (floor / 2) * 3];
		}
	}
}

int main() {

	scanf("%d", &n);

	int floor = n / 3;
	str.resize(n);

	draw(floor);

	string white = "";
	for (int i = 1; i <= n; i++) {
		white += " ";
	}
	for (int i = n; i > 0; i--) {
		//printf("%s%s\n",white.substr(0,i-1).c_str(),str[n-i].c_str());
		for (int j = 1; j < i; j++) cout << " ";
		for (auto c : str[n - i])
			cout << c;
		for (int j = str[n - 1].length(); j > (i + str[n - i].length()); j--) cout << " ";
		cout << ";";
		cout << endl;
	}


}