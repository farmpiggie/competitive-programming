#include <bits/stdc++.h>
using namespace std;
#define ll long long

int get_msb(int x) {
	for (int i = 30; i >= 0; i--) {
		if ((x >> i) & 1) {
			return i;
		}
	}
	return -1;
}

int get_lsb(int x) {
	for (int i = 0; i < 31; i++) {
		if ((x >> i) & 1) return i;
	}
	return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	set<int> b;
	for (int i = 0; i < 31; i++) {
		if (!(k >> i) & 1) b.insert(i); // bit is zero.
	}
	
	// mp1[i] = # of prefixes matching bits 30...i of k, where ith bit of k = 0
	// mp2[i] = same as mp[1], but flipping ith bit from 0 to 1
	// cnt[i] = # of prefixes equaling i exactly	
	map<int, int> mp1, mp2, cnt;
	// initialize variables using 0.
	//cnt[0] = 1;
	for (int i : b) {
		mp1[i] = 0;
		//cout << i << " " << mp1[i] << '\n';
       	}	       

	int cur = 0;
	ll ans = 0;
	for (int x : a) {
		cur ^= x;
		// case 1: use msb_cur and mp1
		int msb_cur = get_msb(cur);	
		//cout << "msb_cur: " << msb_cur << '\n';
		if (mp1.find(msb_cur) != mp1.end()) {
			//cout << "adding case 1: " << mp1[msb_cur] << '\n';
			ans += mp1[msb_cur];
		}

		// case 2: use prefixes > msb_cur and mp2
		for (int i = 30; i > msb_cur; i--) {
			if ((cur >> i) & 1) continue; // once we hit 1, dip.
			if (mp2.find(i) != mp2.end()) {
		//		cout << "adding case 2: " << mp2[i] << '\n';
				ans += mp2[i];
			}
		}

		// case 3: exactly equal to k
		if (cnt.find(k ^ cur) != cnt.end()) {
		//	cout << "equal to k, adding: " << cnt[k ^ cur] << '\n';	
			ans += cnt[k ^ cur];
		}

		// case 4: use entire cur
		if (cur >= k) {
			ans++;
		}
		
		// update our data sturctures
		cnt[cur]++;
		
		// update mp1 while matching prefixes of k
		// mp2 is same match but we must take the first non-match where bit_k = 0, bit_cur = 1
		for (int i = 30; i >= 0; i--) {
			int b1 = (cur >> i) & 1, b2 = (k >> i) & 1;
			if (b1 == b2) {
				if (b2 == 0) {
					mp1[i]++; // we match up to this prefix	
				}
			} else {
				if (b2 == 0 && b1 == 1) { // candidate for mp2
					mp2[i]++;
				}
				break;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}

