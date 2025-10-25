#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                bool works = true;
                vector<int> ans(n, -1);

                for (int i = 1; i < n; i++) {
                        if (a[i] - a[i - 1] == 1) { // 0 to 0
                                if (ans[i - 1] == 1) {
                                        works = false;
                                        break;
                                }
                                ans[i - 1] = 0;
                                ans[i] = 0;
                        } else if (a[i] - a[i - 1] == -1) { // 1 to 1
                                if (ans[i - 1] == 0) {
                                        works = false;
                                        break;
                                }
                                ans[i - 1] = 1;
                                ans[i] = 1;
                        } else if (a[i] == a[i - 1]) { // flip 
                                if (ans[i - 1] != -1) {
                                        ans[i] = 1 - ans[i - 1]; // flip
                                } // otherwise keep both as -1
                        } else { 
                                works = false;
                                break;
                        }
                }
                if (!works) {
                        cout << "0\n";
                        continue;
                }
                // all the same, reflectable
                if (ans[n - 1] == -1) {
                        vector<int> c(n), d(n);
                        for (int i = 0; i < n; i++) {
                                if (i % 2 == 0) c[i] = 0;
                                else c[i] = 1;
                        }
                        for (int i = 0; i < n; i++) {
                                if (i % 2 == 1) d[i] = 0;
                                else d[i] = 1;
                        }
                        vector<int> pre_zeros_c(n), suf_ones_c(n);
                        vector<int> pre_zeros_d(n), suf_ones_d(n);
                        for (int i = 0; i < n; i++) {
                                pre_zeros_c[i] = (c[i] == 0);
                                if (i) pre_zeros_c[i] += pre_zeros_c[i - 1];
                                pre_zeros_d[i] = (d[i] == 0);
                                if (i) pre_zeros_d[i] += pre_zeros_d[i - 1];
                        }
                        for (int i = n - 1; i >= 0; i--) {
                                suf_ones_c[i] = (c[i] == 1);
                                if (i != n - 1) suf_ones_c[i] += suf_ones_c[i + 1];
                                suf_ones_d[i] = (d[i] == 1);
                                if (i != n - 1) suf_ones_d[i] += suf_ones_d[i + 1];
                        }

                        map<int, int> mp;
                        set<int> values_c, values_d;
                        for (int i = 0; i < n; i++) {
                                int cur = 1;
                                cur += (i - 1 >= 0 ? pre_zeros_c[i - 1] : 0);
                                cur += (i + 1 < n ? suf_ones_c[i + 1] : 0);
                                values_c.insert(cur);
                                cur = 1;
                                cur += (i - 1 >= 0 ? pre_zeros_d[i - 1] : 0);
                                cur += (i + 1 < n ? suf_ones_d[i + 1] : 0);
                                values_d.insert(cur);
                        }
                        if ((int) values_c.size() == 1) {
                                mp[*values_c.begin()]++;
                        }
                        if ((int) values_d.size() == 1) {
                                mp[*values_d.begin()]++;
                        }

                        cout << mp[a[n - 1]] << '\n';
                        continue;
                }
                for (int i = n - 2; i >= 0; i--) {
                        if (ans[i] == -1) {
                                if (ans[i + 1] == 0) { 
                                        if (a[i + 1] - a[i] == 1) { // 0 to 0
                                                ans[i] = 0;
                                        } else if (a[i + 1] == a[i]) { // flip
                                                ans[i] = 1;
                                        } else {
                                                works = false;
                                                break;
                                        }
                                } else { // a[i] = 1;
                                        if (a[i + 1] - a[i] == -1) { // 1 to 1
                                                ans[i] = 1;
                                        } else if (a[i + 1] == a[i]) {
                                                ans[i] = 0;
                                        } else {
                                                works = false;
                                                break;
                                        }
                                }
                        }
                }
                int sum = 0;
                for (int i = 0; i < n - 1; i++) {
                        if (ans[i] == 0) sum++;
                }
                works &= (sum + 1 == a[n - 1]);
                cout << (works ? 1 : 0) << '\n';
        }
}






                

                        

