#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                int l = 0, r = n - 1;
                vector<char> state(n, '+');
                int uncertain = 0;
                
                string s; cin >> s;
                for (char c : s) {
                        if (c == '0') {
                                state[l] = '-';
                                l++;
                        } else if (c == '1') {
                                state[r] = '-';
                                r--;
                        } else {
                                uncertain++;
                        }
                }

                if (k == n) {
                        for (int i = 0; i < n; i++) {
                                cout << '-';
                        }
                        cout << '\n';
                        continue;
                }


                for (int i = l; i < min(n, l + uncertain); i++) {
                        if (state[i] == '+') state[i] = '?';
                }

                for (int i = r; i > max(-1, r - uncertain); i--) {
                        if (state[i] == '+') state[i] = '?';
                }

                for (char c : state) cout << c;
                cout << '\n';

        }
}




