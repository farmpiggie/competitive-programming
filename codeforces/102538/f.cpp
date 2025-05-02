/*
 * subtract all h_i by one. monster dies if h_i < 0
 * for each monster find smallest r_i s.t. (h_i - r_i * a) % b < a. 
 * r_i = (h_i % b) / a
 * then if we choose to kill this monster, it costs us (r_i + 1) attacks
 * and our opponent takes (h_i - r_i * a) / b.
 *
 * let x_i = (opponent moves) - (your moves) = (h_i - r_i * a) / b - (r_i + 1)
 * x_0 = 1 cause you save one move (since you start first)
 *
 * you can kill all monsters if x_0 + x_1 .... + x_i is non_negative for all 0 <= i <= n
 *
 * if we store (skip - diff), the bigger the value, the more points we would gain by skipping this particular element.
 * if we have our current value which poses less of a cost to our saved values, we can replace it.
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b; cin >> n >> a >> b;
	vector<ll> h(n);
	for (ll &x : h) {
		cin >> x;
		--x;
	}

	ll saved = 1;
	priority_queue<ll> pq;
	for (int i = 0; i < n; i++) {
		ll skip = h[i] / b + 1; // number of moves opponent needs to kill
		ll r = (h[i] % b) / a; 
		ll take = r + 1; // number of moves i need to kill
		ll opponent_take = (h[i] - (r * a)) / b; // number of moves opponent will use if i kill
		
		ll diff = opponent_take - take; // cost of taking said position (if negative, i use more moves than my opponent)

		if (saved + diff >= 0) { // we can take this item
			saved += diff;
			pq.push(skip - diff); // points saved if i skip this item
		} else if (!pq.empty() && saved + pq.top() + diff >= 0 && pq.top() > skip - diff) { // remove worst previous item, take this one instead
			saved += pq.top() + diff; // we get back savings
			pq.pop();
			pq.push(skip - diff);
		} else {
			saved += skip;
		}
	}
	cout << pq.size() << '\n';
}


