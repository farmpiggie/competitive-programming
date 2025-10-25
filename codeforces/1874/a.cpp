#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	map<ll, int> first, second;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		first[a]++;
	}

	for (int i = 0; i < m; i++) {
		ll a; cin >> a;
		second[a]++;
	}

	if (k == 0) {
		ll sum = 0;
		for (const pair<ll, int>& p : first) sum += (p.first * p.second);
		cout << sum << endl;
		return;
	}


	// find smallest in first and swap for biggest in second
	auto it = first.begin();
	auto it2 = --second.end();
	if (it->first < it2->first) {
		first[it2->first]++;
		second[it->first]++;
		first[it->first]--;
		second[it2->first]--;
		if (first[it->first] == 0) first.erase(it);
		if (second[it2->first] == 0) second.erase(it2);
	}

	// recompute for k = 1

	if (k == 1) {
		ll sum = 0;
		for (const pair<ll, int>& p : first) sum += (p.first * p.second);
		cout << sum << endl;
		return;
	}

	// find smallest in second an swap for biggest in first
	it = second.begin();
	it2 = --first.end();
	if (it->first < it2->first) {
		second[it2->first]++;
		first[it->first]++;
		second[it->first]--;
		first[it2->first]--;
		if (second[it->first] == 0) second.erase(it);
		if (first[it2->first] == 0) first.erase(it2);
	}

	if (k == 2) {
		ll sum = 0;
		for (const pair<ll, int>& p : first) sum += (p.first * p.second);
		cout << sum << endl;
		return;
	}

	// smallest val should always be in first, biggest value should always be in second

	ll firstSum = 0, secondSum = 0;
	for (const pair<ll, int>& p : first) {
		firstSum += (p.first * p.second);
	}
	for (const pair<ll, int>& p : second) {
		secondSum += (p.first * p.second);
	}
	int smallest = first.begin()->first, biggest = second.rbegin()->first;
	firstSum -= smallest;
	secondSum -= biggest;

	if (k % 2 == 0) {
		cout << firstSum + smallest << endl;
	} else {
		cout << firstSum + biggest << endl;
	}

}

int main() {
	int t; cin >> t;
	while (t--) solve();

	return 0;
}