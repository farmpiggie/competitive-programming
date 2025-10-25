#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
        int me = a[0]; // kevin rating
        int good = 0;
        vector<int> bad;
        
        sort(a.begin(), a.end()); // sort ratings of other contestants
        for (int x : b) {
            // i can beat or no one can beat
            if (me >= x || x > a[n - 1]) good++;
            else { // someone not me can beat it. see how many.
                int idx = lower_bound(a.begin(), a.end(), x) - a.begin(); // first index >= x
                int beat = (n - idx); 
                bad.push_back(beat);
            }
        }
        sort(bad.begin(), bad.end()); // sort based on how many can beat
        
        for (int k = 1; k <= m; k++) {
            int sz = k; // m, m/2, etc.
            int used = m / k * k;
            ll ans = m / k;

            int numbad = max(0, used - good); 
            for (int i = numbad - 1; i >= 0; i -= k) {
                ans += bad[i];
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
