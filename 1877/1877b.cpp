#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

static bool cmp(const pii& a, const pii& b) {
	if (a.first < b.first) return true;
	else if (b.first > a.first) return false;
	else return a.second > b.second;
}

void solve() {
	int n, p; cin >> n >> p;
	long long ans = (long long) n * p;

	// sort all residents
	vector<int> amount(n), cost(n);
	for (int i = 0; i < n; i++) {
		cin >> amount[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	vector<pii> residents;
	for (int i = 0; i < n; i++) {
		residents.push_back({cost[i], amount[i]});
	}

	sort(residents.begin(), residents.end(), cmp);

	// binary search on start
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;

		long long runningCost = p * mid;
		list<pii> arr;
		arr.push_back({residents[0].first, residents[0].second});
		for (int i = 1; i < mid; i++) {
			pii back = arr.back();
			if (back.first < residents[i].first) {
				arr.push_back({residents[i].first, residents[i].second});
			} else {
				arr.pop_back();
				back.second += residents[i].second;
				arr.push_back(back);
			}
		}


		for (int i = mid; i < n; i++) {
			pii p = arr.front();
			runningCost += p.first;
			--p.second;

			// add new 
			pii back = arr.back();
			if (back.first < residents[i].first) {
				arr.push_back({residents[i].first, residents[i].second});
			} else {
				arr.pop_back();
				back.second += residents[i].second;
				arr.push_back(back);
			}

			// pop front
			arr.pop_front();
			if (p.second != 0) arr.push_front(p);

		}

		if (runningCost < ans) {
			hi = mid - 1;
			ans = runningCost;
		} else {
			lo = mid + 1;
		}
	}

	cout << ans << '\n';

}

int main() {
	int t; cin >> t;
	while (t--) solve();

	return 0;
}