#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> ans;
	vector<int> positives, negatives;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == 0) ans.push_back(num);
		else if (num < 0) negatives.push_back(num);
		else positives.push_back(num);
	}

	if (ans.size() == n) {
		cout << "No\n";
		return;
	}
	int i = 0, j = 0;
	long long psum = 0;
	while (i < positives.size() || j < negatives.size()) {
		if (psum <= 0) {
			ans.push_back(positives[i]);
			psum += positives[i];
			i++;
		} else {
			ans.push_back(negatives[j]);
			psum += negatives[j];
			j++;
		}
	}
	cout << "Yes\n";
	for (int num : ans) {
		cout << num << " ";
	}
	cout << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}