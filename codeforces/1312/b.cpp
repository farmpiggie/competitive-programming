#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int T, N;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<int> arr;
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		for (int val : arr) {
			cout << val << ' ';
		}
		cout << endl;
	}
	return 0;
}