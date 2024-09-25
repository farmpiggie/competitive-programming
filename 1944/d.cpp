#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second
#define ll long long

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return res;
}

vector<pii> list_palindromes(vector<int> a) {
	vector<pii> ans;
	int l, r;
	for (int i = 0; i < a.size(); i++) {
		if (i % 2 == 0 && a[i] > 1) { // centered on #
			r = i / 2 + a[i] / 2 - 1;
			l = i / 2 - (a[i] / 2);
			ans.push_back({l, r});
		} else if (i % 2 == 1) {
			r = i / 2 + (a[i] / 2 - 1);
			l = i / 2 - (a[i] / 2 - 1);
			ans.push_back({l, r});
		}
	}
	return ans;
}


void run() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<int> res = manacher(s);

	vector<int> diff1(n + 1), diff2(n + 1);
	diff1[n - 1] = n;
	for (int i = n - 2; i >= 0; i--) {
		diff1[i] = (s[i] == s[i + 1]) ? diff1[i + 1] : i + 1;
	}

	diff2[n - 1] = n;
	diff2[n - 2] = n;
	for (int i = n - 3; i >= 0; i--) {
		diff2[i] = (s[i] == s[i + 2]) ? diff2[i + 2] : i + 2;
	}
	
	// cout << "palindromes\n";
	// for (pii& p : list_palindromes(res)) cout << p.f << " " << p.s << '\n';
	// cout << "---\n";
	// for (int num : res) cout << num << " ";
	// cout << "\n\n";

	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		int mid, len;
		ll ans = 0;
		// cout << "l, r: " << l << " " << r << '\n';
		if ((r - l + 1) % 2 == 0) { // #
			mid = (l + r + 1) / 2;
			len = (res[2 * mid] - 1);
			// if (r - l + 1 == 12) {
			// 	cout << "mid, len: " << mid << " " << len << '\n';
			// }
		} else { // not a #
			// cout << mid << " " << len << '\n';
			mid = (l + r) / 2;
			len = res[2 * mid + 1] - 1;
		}
		// cout << len << '\n';

		ll range = r - l + 1;
		if (len >= (r - l + 1)) {
			// cout << "is palindrome! \n";
			range--;
		}
		if (diff1[l] <= r) {
			ans += (range/2) * ((range/2) + 1);
			// cout << "evens summed up to: " << ans << '\n';
		}
		if (diff2[l] <= r || diff2[l + 1] <= r) {
			ans += ((range - 1) / 2 * ((range - 1) / 2 + 1)) + ((range - 1) / 2);
			// ans += (range/2 + (range%2)) * (range/2 + (range%2));
			// ans --;

			// cout << "odds summed up to: " << (range / 2 + (range % 2)) * (range / 2 + (range % 2)) - 1 << '\n';
		}
		cout << ans << '\n';
	}
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
}