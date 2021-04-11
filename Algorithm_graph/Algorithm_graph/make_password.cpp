#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> character;
int l, c;
bool used[15] = { false, };
bool vowel = false;
int constant = 0;
void check(string s) {
	for (auto a : s) {
		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
			vowel = true;
		else
			constant++;
	}
	
}
void make_pass(int len, int idx, string s) {
	if (len == l) {
		check(s);
		if (vowel && constant > 1)
			cout << s << endl;
		vowel = false; constant = 0;
	}
	else {
	
		for (int i = idx; i < c; i++) {
			if (!used[i]) {
				used[i] = true;
				s.push_back(character[i]);
				make_pass(len + 1,i, s);
				s.erase(s.length() - 1);
				used[i] = false;
			}
		}

	}
}

int main() {
	cin >> l >> c;
	character.resize(c);
	for (int i = 0; i < c; i++)
		cin >> character[i];
	sort(character.begin(), character.end());

	make_pass(0, 0, "");
}
