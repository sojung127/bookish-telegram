#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;
	list<string> exp;

	string number;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			number.push_back(str[i]);
		else {
			string s;
			s += str[i];
			exp.push_back(number);
			exp.push_back(s);
			number.clear();
		}
	}
	exp.push_back(number);

	bool isParenthesis = false;
	for (list<string>::iterator iter = exp.begin(); iter != exp.end(); iter++) {
		if (!isParenthesis) {
			if (*iter == "+") {
				iter--;
				exp.insert(iter, "(");
				iter++; iter++;
				isParenthesis = true;
			}
		}
		else {
			if (*iter == "-") {
				exp.insert(iter, "-");
				isParenthesis = false;
			}
		}
		
	}
	if (isParenthesis) {
		exp.push_back(")");
	}

	// 중위계산식을 후위계산식으로 교체
	list<string>::iterator iter;
	vector<string> exp_postfix;
	stack<string> trans;
	for (string s : exp) {
		if (s == "(") {
			trans.push(s);
		}
		else if (s == ")") {
			string p = trans.top();
			trans.pop();
			while (p != ")") {
				exp_postfix.push_back(p);
				p = trans.top();
				trans.pop();
			}

		}
		else {

			exp_postfix.push_back(s);
		}
	}

	for (string s : exp_postfix)
		cout << s;



	return 0;
}