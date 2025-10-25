#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                string s; cin >> s;
                vector<int> pre(n + 1, 0);
                for (int i = 1; i <= n; i++) {
                        pre[i] = pre[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
                }

                if (pre[n] == 0) {
                        cout << "0\n";
                        continue;
                }

                map<int, int> mp; // mp[i] = last index with said sum
                mp[0] = 0;
                pre[0] = 0;
                int ans = n;
                for (int i = 1; i <= n; i++) {
                        // current is pre[i], we want to find a value j s.t. pre[i] - pre[j] = pre[n]
                        // therefore we look for pre[i] - pre[n] = pre[j]
                        int target = pre[i] - pre[n];
                        if (mp.find(target) != mp.end()) {
                                ans = min(ans, i - mp[target]);
                        }
                        mp[pre[i]] = i;
                }
                cout << (ans == n ? -1 : ans) << '\n';
        }
}




