/*
 * n 0s, m 1s
 * balance = (difference in 0s and 1s)
 * create string s.t. max balance over all substrings is EXACTLY K
 *
 * can we not greedily just do:
 * assume n > m and n - m <= k, n >= k.
 *
 * k 0s
 * 1 and 0 alternate. (n - k to be exact)
 * end up with extra 1s, which is fine (sinc ethis is <= k anyway).
 * profit??
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, k; cin >> n >> m >> k;
                bool flip = false;
                if (n < m) {
                        swap(n, m);
                        flip = true;
                }
                
                if (n - m > k || n < k) {
                        cout << "-1\n";
                        continue;
                }

                string s = "";
                for (int i = 0; i < k; i++) {
                        s += '0';
                }
                for (int i = 0; i < n - k; i++) {
                        s += "10";
                }
                m -= (n - k);
                for (int i = 0; i < m; i++) {
                        s += '1';
                }
                
                if (flip) {
                        for (char &c : s) {
                                c = (c == '0' ? '1' : '0');
                        }
                }

                cout << s << '\n';
        }
}

