#include <bits/stdc++.h>
using namespace std;
int T, M, N;
int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N;
		cout << ((M % N == 0) ? "YES" : "NO") << endl;
	}
	return 0;
}