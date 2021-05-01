#include <iostream>
#include <string>

using namespace std;


int ddpp[1000001] = { -1, };

int main() {

	string s;

	cin >> s;

	int slen = s.length();

	s.insert(0, "_");
	
	for (int x = 1; x <= slen / 2; x++) {
		int cnt = 1;
		string xs = s.substr(1, x);
		int key = x+1;
		while (xs == s.substr(key, x)) {
			key += x;
			cnt++;
			if (key > slen - x) break;
		}
		if(cnt!=1) key -= 1;
		ddpp[key] = ddpp[key] < cnt ? cnt : ddpp[key];
	}

	for (int i = 1; i <= slen; i++) {
		if (true) {
			cout << i << " " << ddpp[i] << endl;
		}
	}

	return 0;
}