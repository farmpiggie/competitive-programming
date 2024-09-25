#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
			
		bool works = true;	
		for (int i = 1; i < n - 1; i++) {
			if (a[i - 1] < 0) {
				works = false;
				break;	
			}
			a[i] -= 2 * a[i - 1];
			a[i + 1] -= a[i - 1];
			a[i - 1] = 0; 
		}	
				
		works &= (a[n - 1] == 0 && a[n - 2] == 0);		

		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
}
