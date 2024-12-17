/*
even + even = even, odd + odd = even
basically find some even, odd # when added together has some divisors.
let's say it is divisible by 3.

basically find some x, y <= n s.t. (x + y) % 3 == 0
try 1, 2. or (1, 5). 

// odd + even = odd
// make some odd # that is not prime.
// smallest odd that isnt prime is 9.
// 5 4 = 9

[odds] 1 5 [even]
[odds] 

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n < 5) {
			cout << "-1\n";
			continue;
		}
		for (int i = 1; i <= n; i += 2) {
			if (i == 5) continue;
			cout << i << " ";
		}
		cout << "5 4 ";
		for (int i = 2; i <= n; i += 2) {
			if (i == 4) continue;
			cout << i << " ";
		}
		cout << '\n';

	}
	return 0;
}
