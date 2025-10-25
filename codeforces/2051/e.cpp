#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
        set<int> costs; 
        vector<array<int, 2>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({a[i] + 1, 0}); // good -> bad
            arr.push_back({b[i] + 1, 1}); // bad -> no sell
            costs.insert(a[i]);
            costs.insert(b[i]);
        }
        sort(arr.begin(), arr.end());
        int j = 0, active = n, bad = 0;
        ll best = 0;
        for (int cost : costs) {
            while (j < 2 * n && arr[j][0] <= cost) {
                if (arr[j][1] == 0) bad++;
                else {
                    bad--;
                    active--;
                }
                j++;
            }
            if (bad <= k) best = max(best, 1ll * cost * active); 
        }
        cout << best << '\n';
    }
    return 0;
}
