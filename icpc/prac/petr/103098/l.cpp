/*
 * there is 1 way to make a 1x3.
 * there is 2 ways to make a 2x3 (not overcounting two 1x3s)
 * but to not overcount 2x3 + 1x3, we will only count when the planks are horizontal for 3x3
 * which is 4 + 1 = 5 ways.
 *
 * ans[1] = 1;
 * ans[2] = 3;
 * ans[3] = 10; // 5 + 1 + 4
 *
 * dp[i] = dp[i - 3] * 5 + dp[i - 2] * 2 + dp[i - 1] * 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

