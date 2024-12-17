#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n,m,k;
		cin >> n >> m >> k;

	        map<ll,ll> days;
	        for (int i = 0; i < n; i++){
		        int a, b;
		        cin >> a >> b;
		        days[a] += b;
	        }

	        days[1e18] = 0;

	        ll cur_day = 1; 
	        ll cur_amt = 0;  
	        ll ans = 0;

	        stack<pll> st;
	    
	        for (auto &cur : days){
	        	while (!st.empty() && cur_day < cur.first){
	        		auto [d,x] = st.top();
	        		st.pop();

	        		if (d + k - 1 < cur_day) continue;
	        		else if (d > cur_day) cur_day = d, cur_amt = 0;

	        		if (m - cur_amt > x) cur_amt += x;
	        		else{
	        			ll nxt_day = min(cur_day + (x - m + cur_amt) / m + 1, min(d + k, cur.first));
	        			ll nx = x - (nxt_day - cur_day) * m + cur_amt;
	            			if (nx > 0) st.push({d,nx});

	           			ans += nxt_day - cur_day;
	            			cur_day = nxt_day;
	            			cur_amt = 0;
	        		} 
	        	}
	        	st.push(cur);
		}
	    
	 	cout << ans << '\n';
	}
	return 0;
}