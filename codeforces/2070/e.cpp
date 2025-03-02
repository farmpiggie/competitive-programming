/*
 * binary string (wraps around)
 * first player move: remove two adjacent 0s
 * second player move: at least one char removed is 1. (10, 01, 11)
 * player who cannot make a valid move loses.
 *
 * how to determine who wins on a binary string?
 * first player can win if len(string) < 2 or second player runs out of ones.
 * second player wins all other times.
 *
 * strategy for second player seems to be: try and remove 01 or 10 until there are no zeros left, then pick 11.
 * strategy for first player: remove any 00. doesn't really matter.
 *
 *
 * for player one, the max turns they can get is: sum(x/3) for all x = group sizes, add 1 if there is a group size y s.t. y % 3 == 2. call this sumOne.
 * for player two, the max turns they can get is: min(# 1s, sum(# 0s - sumOne))
 *
 * player one wins if sumOne > min(1s, sum(0s - sumOne)), otherwise player two wins
 * player one wins is n0 >= 3 * n1 + 2 // player one removes two zeros, then player two and one go back and forth
 * player one also wins if n0 = 3 * n1 - 1. // player one takes two zeros, player two is left with 1 one.
 *
 * we can check if n0 >= 3 * n1 + 2 by making all 0 -> 1, 1 -> -3. then check if sum(array) >= 2.
 * how to check second part? we look for subarray of value -1.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e6;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; string s; cin >> n >> s;
	vector<int> cnt(MAXN, 0);
	int cur = 3 * n;
	cnt[cur] = 1;
	ll sum = 0; // stores current sum of all prefix sums - 2.
	ll ans = 0;	
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cur++;
			if (cur - 2 >= 0) sum += cnt[cur - 2];
		} else {
			for (int i = 0; i < 3; i++) {
				if (cur - 2 >= 0) sum -= cnt[cur - 2];
				cur--;
			}
		}
		ans += sum + cnt[cur + 1];
		cnt[cur]++;
	}
	cout << ans << '\n';
}
		

