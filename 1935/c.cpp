#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define a second
#define b first

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;
        vector<pii> tasks;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            tasks.push_back({y, x});
        }
        sort(tasks.begin(), tasks.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            int sum1 = 0;
            int small = tasks[i].b;
            int total = 0;
            for (int j = i; j < n; j++) {
                mp[tasks[j].a]++;
                sum1 += tasks[j].a;
                total++;
                while (sum1 > (l - (tasks[j].b - small)) && mp.size() > 0) {
                    sum1 -= ((--mp.end())->first);
                    (--mp.end())->second--;
                    total--;
                    if ((--mp.end())->second == 0) mp.erase(--mp.end());
                }
                ans = max(ans, total);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}