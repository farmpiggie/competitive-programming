#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), d(m), f(k);
        for (int& x : a) cin >> x;
        for (int& x : d) cin >> x;
        for (int& x : f) cin >> x;    
        
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        
        int gap = 0;
        int left = -1, right = -1;
        for (int i = 1; i < n; i++) {
            if (gap < a[i] - a[i - 1]) {
                gap = a[i] - a[i - 1];
                left = a[i - 1];
                right = a[i];
            }
        }
       

        //cout << "gap found at index " << idx << " and gap size is " << gap << '\n';

        int target = left + (right - left) / 2;
        //cout << "target number: " << target << '\n';
        int smallest_gap = INT_MAX;
        int addition = -1;
        int j = k - 1;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && d[i] + f[j] >= target) {
                j--;
            }
            int gap1 = max(abs(left - (d[i] + f[j])), abs(right - (d[i] + f[j])));
            int gap2 = INT_MAX;
            if (j + 1 < k) {
                gap2 = max(abs(left - (d[i] + f[j + 1])), abs(right - (d[i] + f[j + 1])));
            }
            if (gap1 < smallest_gap) {
                smallest_gap = gap1;
                addition = d[i] + f[j];
            }
            if (gap2 < smallest_gap) {
                smallest_gap = gap2;
                addition = d[i] + f[j + 1];
            }

        }
        //cout << "inserting number: " << addition << '\n';
        a.push_back(addition);
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            ans = max(ans, a[i] - a[i - 1]);
        }
        cout << min(ans, gap) << '\n';
    }   
}
