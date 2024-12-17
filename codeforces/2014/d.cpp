#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, d, k; cin >> n >> d >> k;
		vector<pair<int, int>> segments;
		for (int i = 0; i < k; i++) {
			int l, r; cin >> l >> r;
			segments.push_back({l, r});
		}
		sort(segments.begin(), segments.end()); // by ascending start
		vector<pair<int, int>> segments2(segments.begin(), segments.end());
		sort(segments2.begin(), segments2.end(), [](const pii& a, const pii& b) {
			return (a.second == b.second) ? a.first < b.first : a.second < b.second;
		});

		// cout << "segments\n";

		// for (pii segment : segments) cout << segment.first << " " << segment.second << '\n';
		// for (pii segment : segments2) cout << segment.first << " " << segment.second << '\n';


		int biggest = -1, smallest = k + 1;
		int big_start = 0, small_start = 0;
		// n - k + 1... n = k length stay

		// cout << "testing\n";

		vector<int> before(n + 1, 0);
		int j = 0; 
		for (int i = 1; i <= n; i++) {
			while (j < segments2.size() && segments2[j].second < i) { // going by ascending end
				j++;
			}
			before[i] = j; // number of segments that end before value i
		}
		j = segments.size() - 1;
		vector<int> after(n + 1, 0);
		for (int i = n; i >= 1; i--) {
			while (j >= 0 && segments[j].first > i) { // going by ascending start
				j--;
			}
			after[i] = segments.size() - 1 - j; // number of segments that start after value i
		}

		for (int i = 1; i <= n - d + 1; i++) { // n - d + 1 ... n is (-d + 1 ... 0 or 0 ... d - 1)
			// cout << i << " " << i + d - 1 << '\n';
			int cur = segments.size() - before[i] - after[i + d - 1];
			// cout << "cur for range: " << segments.size() << " - " << before[i] << " - " << after[i + d - 1] << '\n';
			if (cur > biggest) {
				biggest = cur;
				big_start = i;
			}
			if (cur < smallest) {
				smallest = cur;
				small_start = i;
			}
		}


		// cout << "segments\n";
		// for (pair<int, int> p : segments) {
		// 	cout << p.first << " " << p.second << '\n';
		// }
		// cout << "---\n";

		// for (int i = 1; i <= n - d + 1; i++) {
		// 	// cout << "segment: " << i << " " << i + d - 1 << '\n';
		// 	auto r = lower_bound(segments.begin(), segments.end(), make_pair(i + d, 0)); // first segment to the right
		// 	// auto l = lower_bound(segments.begin(), segments.end(), make_pair(i, -1)); // first segment with start position inside region
		// 	// cout << ending_segments[i] << " " << (r - segments.begin()) << '\n';
		// 	// int cur;
		// 	// if (l != segments.begin()) { // try going one lower
		// 	// 	--l;
		// 	// 	if (l->second >= i) { // included
		// 	// 		cur = r - l; 
		// 	// 		cout << "matches one lower\n";
		// 	// 	} else {
		// 	// 		cur = r - l - 1;
		// 	// 		cout << "does not match one lower\n";
		// 	// 	}
		// 	// } else {
		// 	// 	cur = r - l;
		// 	// 	cout << "thirdcase\n";
		// 	// }
		// 	int cur = (r - segments.begin()) - ending_segments[i] - 1;
		// 	// cout << (r - segments.begin()) << " - " << ending_segments[i] << " - 1 = " << cur << '\n';
		// 	if (cur > biggest) {
		// 		biggest = cur;
		// 		big_start = i;
		// 	}
		// 	if (cur < smallest) {
		// 		smallest = cur;
		// 		small_start = i;
		// 	}
		// 	// cout << "current value and index: " << cur << " " << index << '\n';
		// }
		cout << big_start << " " << small_start << '\n';
	}
	return 0;
}