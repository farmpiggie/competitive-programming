/*
 * group all subarrays into positive and negative #s
 * [pos] [neg] [pos] [neg]
 *
 * optimal answer is either:
 * max(all pos groups, all neg groups)
 * or we pick two groups, one pos one neg
 * but the pos groups must be to the left of the neg group.
 *
 * like [pos] [neg] pos neg
 * or [pos] neg pos [neg]
 * or pos neg [pos] [neg]
 *
 * answer: you can actually take [a bunch of positive] and [a bunch of negatives] like this
 *
 * [pos] neg [pos][neg] pos [neg]
 *
 * so for each neg, keep track of all pos groups we have seen before.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		
		ll cur = abs(a[0]);
		int sign = (a[0] > 0); // true is positive, false is negative
		vector<pair<ll, int>> segments;
		for (int i = 1; i < n; i++) {
			if (a[i] > 0 == sign) {
				cur += abs(a[i]);
			} else {
				segments.push_back({cur, sign});
				sign = 1 - sign;
				cur = abs(a[i]);
			}
		}
		segments.push_back({cur, sign});


		vector<ll> pos(segments.size(), 0), neg(segments.size(), 0);

		for (int i = 0; i < segments.size(); i++) {
			pos[i] = (i ? pos[i - 1] : 0);
			neg[i] = (i ? neg[i - 1] : 0);
			if (segments[i].second) { // positive
				pos[i] += segments[i].first;
			} else {
				neg[i] += segments[i].first;
			}
		}

		auto sum = [&](int l, int r, vector<ll>& a) -> ll {
			if (l > r) return 0;
			else return a[r] - (l ? a[l - 1] : 0);
		};

		ll ans = max(pos.back(), neg.back());

		for (int i = 0; i < segments.size() - 1; i++) {
			ans = max(ans, sum(0, i, pos) + sum(i + 1, segments.size() - 1, neg));
		}


		cout << ans << '\n';
	}
}


