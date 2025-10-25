#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<int> a(n);
                map<int, int> mp;
                ll sum = 0;
                for (int i = 0; i < n; i++) {
                        int x; cin >> x;
                        sum += x;
                        mp[x]++;
                }
                int mx = (--mp.end())->first;
                mp[mx]--;
                mp[mx - 1]++;
                if (mp[mx] == 0) {
                        mp.erase(mx);
                }

                mx = (--mp.end())->first;
                int mn = mp.begin()->first;

                if (mx - mn > k) {
                        cout << "Jerry\n";
                } else {
                        cout << ((sum & 1) ? "Tom" : "Jerry") << '\n';
                }
        }
}
