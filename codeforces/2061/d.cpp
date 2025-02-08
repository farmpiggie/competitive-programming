/*
 * working backwards, it is easy to split values of b into 1+ values of a.
 * each number in b can be split exactly one way.
 * split the # greedily at each "level" and take what is needed
 * this is too slow. can we improve on this?
 *
 * divide all even numbers by 2 until a proper addition is found.
 * for odd numbers, we can do the same thing dividing by 2 until a proper addition is found, but keep track of the (+1) case
 * we can calculate whether or not a number in b can be satisfied in log(1e9) time
 *
 *
 * for each # in a, simply mark its occurrence.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m; cin >> n >> m;
                map<int, int> occ;
                for (int i = 0; i < n; i++) {
                        int x; cin >> x;
                        occ[x]++;
                }

                bool works = true;
                for (int i = 0; i < m; i++) {
                        int x; cin >> x;
                        map<int, int> mp;
                        mp[x]++;
                        while (mp.size() > 0 && mp.begin()->first > 0) {
                                for (auto &[val, cnt] : mp) {
                                        if (occ.find(val) != occ.end()) {
                                                int used = min(occ[val], cnt);
                                                cnt -= used;
                                                occ[val] -= used;
                                                if (occ[val] == 0) occ.erase(val);
                                        }
                                }
                                map<int, int> np;
                                for (auto [val, cnt] : mp) {
                                        if (cnt == 0) continue;
                                        np[val / 2] += cnt;
                                        np[val / 2 + (val & 1)] += cnt;
                                }
                                mp = np;
                        }
                        if (mp.size() > 0) works = false;
                }
                works &= ((int) occ.size() == 0);
                cout << (works ? "YES" : "NO") << '\n';
        }
}



                

