#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXN 100005

ll t, n, ans[MAXN];
pll a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll b; cin >> b;
		a[i].first = b;
		a[i].second = i;
	}
	sort(a, a + n); 
	ll sum = a[0].first;
	int evaluated = 0;
	
	for (int i = 1; i < n; i++) {
		if (sum < a[i].first) {
			// cout << sum << ' ' << a[i].first << '\n';
			for (int j = evaluated; j < i; j++) {
				ans[a[j].second] = (i - 1);
			}
			evaluated = i; // i isnt evaluated yet
		} 
		sum += a[i].first;
		
	}
	for (int j = evaluated; j < n; j++) {
		ans[a[j].second] = (n - 1);
	}


	for (int i = 0; i < n; i++) {
		cout << ans[i] << " "; 
	}
	cout << '\n';


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}