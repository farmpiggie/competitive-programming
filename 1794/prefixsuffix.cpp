#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string a1 = "", a2 = ""; // strings of length 1
	string b1 = "", b2 = ""; // strings of length n - 1
	for (int i = 0; i < 2 * n - 2; i++) {
		string s; cin >> s;
		if (s.length() == 1) {
			if (a1 == "") a1 = s;
			else a2 = s;
		} 
		if (s.length() == n - 1) {
			if (b1 == "") b1 = s;
			else b2 = s;
		}
	}

	if (n == 1) { cout << "YES" << endl; return;} 

	string res = "", res2 = "";
	string actual = "";
	res = a1 + b1; res2 = a2 + b2;
	if (res == res2) actual = res;
	res = a1 + b1; res2 = b2 + a2;
	if (res == res2) actual = res;
	res = a2 + b1; res2 = a1 + b2;
	if (res == res2) actual = res;
	res = a2 + b1; res2 = b2 + a1;
	if (res == res2) actual = res;
	res = b1 + a2; res2 = b2 + a1;
	if (res == res2) actual = res;
	res = b1 + a2; res2 = a1 + b2;
	if (res == res2) actual = res;
	res = b1 + a1; res2 = b2 + a2;
	if (res == res2) actual = res;
	res = b1 + a1; res2 = a2 + b2;
	if (res == res2) actual = res;
	

	for (int i = 0; i < n / 2; i++) {
		if (actual[i] != actual[n - i - 1]) { cout << "NO" << endl; return; }
	}
	cout << "YES" << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}