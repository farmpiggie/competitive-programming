#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                map<int, int> mp;
                for (int i = 0; i < n; i++) {
                        int x; cin >> x;
                        mp[x]++;
                }
                bool works = true;
                while (mp.size() > 0) {
                        //cout << "size: " << mp.size() << '\n';
                        auto cur = mp.begin();
                        int x = cur->first, cnt = cur->second;
                        //cout << "cnt: " << cnt << '\n';
                        if (cnt == 1) {
                                works = false;
                                break;
                        }
                        cnt -= 2;
                        if (cnt > 0) mp[x + 1] += cnt;
                        //cout << "size before erase: " << mp.size() << '\n';
                        mp.erase(mp.begin());
                        //cout << "size after erase: " << mp.size() << '\n';
                }

                cout << (works ? "YES" : "NO") << '\n';
        }
}
