#include <iostream>
using namespace std;

int fib(int n) {
	int fn, fn2 = 0, fn1 = 1;
	if (n < 2) fn = n;
	else {
		for (int i = 2; i <= n; i++) {
			fn = fn1 + fn2;
			fn2 = fn1;
			fn1 = fn;
		}
	}
	return fn;
}
int fib_index(int n) {
	int fn2 = 0, fn1 = 1;
	int fn=fn2+fn1;
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		int i = 1;
		while (fn < n) {
			fn = fn1 + fn2;
			fn2 = fn1;
			fn1 = fn;
			i++;
		}
		return i;

	}
}
int fib_search(int s[], int x, int size) {
	int a, i, p, q, t;
	bool done;
	int n = size-1;
	a = fib_index(n + 1);
	i = fib(a - 1);
	p = fib(a - 2);
	q = fib(a - 3);
	done = false;
	while ((i >= 1) && !done) {
		if (x > s[i]) {
			if (q == 0)
				i = 1;
			else {	// 배열의 인덱스 F(t-1)+1
				i = i - q;	t = p;
				p = q;		q = t - q;
			}
		}
		else if (x < s[i]) { // 배열의 인덱스 1부터 F[t-1]-1 까지 다시 피보나치 탐색 수행.

		}
		else {	// x==s[i]

		}

	}
}
int main()
{
	int index = fib_index(13);
	cout << index;
}