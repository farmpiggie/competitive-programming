#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            mp[b[i]].push_back(i);
        }
        bool works = true;
        for (auto &[x, cnt] : mp) {
            if ((int)cnt.size() % x != 0) {
                works = false;
                break;
            }
        }

        if (!works) {
            cout << "-1\n";
            continue;
        }

        vector<int> a(n);
        int unique = 1;
        for (auto &[x, cnt] : mp) {
            for (int i = 0; i < cnt.size(); i += x) {
                for (int j = i; j < i + x; j++) {
                    a[cnt[j]] = unique;
                }
                unique++;
            }
        }

        for (int x : a)
            cout << x << ' ';
        cout << '\n';
    }
}