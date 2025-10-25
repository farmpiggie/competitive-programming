#include <bits/stdc++.h>
using namespace std;

struct pt {
        int x, y, ind;
};

#define pii pair<int, int>
#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<pt> x_sorted, y_sorted;
                for (int i = 0; i < n; i++) {
                        int x, y; cin >> x >> y;
                        x_sorted.push_back({x, y, i + 1});
                        y_sorted.push_back({x, y, i + 1});
                }
                sort(x_sorted.begin(), x_sorted.end(), [](pt a, pt b) { return a.x < b.x; });
                sort(y_sorted.begin(), y_sorted.end(), [](pt a, pt b) { return a.y < b.y; });

                // split xs
                ll x_ans = 0;
                vector<int> ans1;
                vector<pt> lft(x_sorted.begin(), x_sorted.begin() + n / 2), rht(x_sorted.begin() + n / 2, x_sorted.end());
                sort(lft.begin(), lft.end(), [](pt a, pt b) { return a.y < b.y; });
                sort(rht.begin(), rht.end(), [](pt a, pt b) { return a.y > b.y; });
                for (int i = 0; i < n / 2; i++) {
                        ans1.push_back(lft[i].ind);
                        ans1.push_back(rht[i].ind);
                        x_ans += abs(lft[i].x - rht[i].x) + abs(lft[i].y - rht[i].y);
                }

                // split ys
                ll y_ans = 0;
                vector<int> ans2;
                vector<pt> down(y_sorted.begin(), y_sorted.begin() + n / 2), up(y_sorted.begin() + n / 2, y_sorted.end());
                sort(down.begin(), down.end(), [](pt a, pt b) { return a.x < b.x; });
                sort(up.begin(), up.end(), [](pt a, pt b) { return a.x > b.x; });
                for (int i = 0; i < n / 2; i++) {
                        ans2.push_back(down[i].ind);
                        ans2.push_back(up[i].ind);
                        y_ans += abs(down[i].x - up[i].x) + abs(down[i].y - up[i].y);
                }

                if (x_ans > y_ans) {
                        for (int i = 0; i < n; i += 2) {
                                cout << ans1[i] << " " << ans1[i + 1] << '\n';
                        }
                } else {
                        for (int i = 0; i < n; i += 2) {
                                cout << ans2[i] << " " << ans2[i + 1] << '\n';
                        }
                }
        }
}


               






