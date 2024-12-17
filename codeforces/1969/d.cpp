// obv1: given a subset of items, bob chooses the k most expensive
// obv2: if we know the kth most expensive element alice picks in terms of bob's price called j, then:
// we pick cheapest (K - 1) elements where b_i > b_j
// we take all i where a_i < b_i and b_i <= b_j
// 
// solve: sort by ascending b, then ascending a
//
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second
#define ll long long

ll sum(int l, int r, vector<ll>& cost) {
	return cost[r] - (l == 0 ? 0 : cost[l - 1]);
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;

		vector<pii> arr;
		
		for (int i = 0; i < n; i++) arr.push_back({b[i], a[i]});
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		priority_queue<int> pq;
		vector<ll> cost(n, 0);
		if (arr[n - 1].f > arr[n - 1].s) cost[n - 1] = arr[n - 1].f - arr[n - 1].s;
		for (int i = n - 2; i >= 0; i--) {
			cost[i] = cost[i + 1] + max(0, arr[i].f - arr[i].s);
		}
		
		if (k == 0) {
			cout << cost[0] << '\n';
			continue;
		}
		
		ll asum = 0;
		ll profit = 0;
		for (int i = 0; i < k; i++) {
			pq.push(arr[i].s);
			asum += arr[i].s;
		}

		for (int i = k; i < n; i++) {
			profit = max(profit, cost[i] - asum);
			if (arr[i].s < pq.top()) { // replace more expensive element
				asum -= (pq.top() - arr[i].s);
				pq.pop();
				pq.push(arr[i].s);
			}
		}
		cout << profit << '\n';


	
	}
	return 0;
}
