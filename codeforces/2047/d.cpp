#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        
        map<int, vector<int>> inds;
        for (int i = 0; i < n; i++) {
            inds[a[i]].push_back(i);
        }
            

        vector<int> mn(n);
        mn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mn[i] = min(mn[i + 1], a[i]);
        }


        int end = a[n - 1];
        map<int, int> ans;
        for (auto& [val, indices] : inds) {
            for (int i : indices) {
                if (min(end, mn[i]) < a[i]) { // gotta move it
                    ans[val + 1]++;
                    end = min(end, val + 1); // possible new minimum in the back
                } else {
                    ans[val]++;
                }
            }
        }

        
        for (auto [val, cnt] : ans) {
            while (cnt--) cout << val << " ";
        }
        cout << '\n';
    }
}




