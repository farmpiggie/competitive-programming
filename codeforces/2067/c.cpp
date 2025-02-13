#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool good(ll x) {
        while (x > 0) {
                int d = x % 10;
                if (d == 7) return true;
                x /= 10;
        }
        return false;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                string s; cin >> s;
                int n = (int) s.length();
                ll cur = s[n - 1] - '0';

                int ans;
                if (s[n - 1] - '0' < 7) ans = s[n - 1] - '0' + 3;
                else ans = s[n - 1] - '7';
                int len = 1;

                vector<ll> nines(12, 0);
                nines[1] = 9;
                for (int i = 2; i < 12; i++) {
                        nines[i] = nines[i - 1] * 10 + 9;
                }
                
                        
                for (int i = n - 2; i >= 0; i--) {
                        int digit = s[i] - '0';

                        int addition = 1;
                        for (int j = 0; j < (n - 1) - i; j++) {
                                addition *= 10;
                        }
                        addition *= digit;
                        cur += addition;
                        len++;

                        int cnt = 0;
                        ll temp = cur;
                        while (!good(temp)) {
                                temp += nines[len - 1];
                                cnt++;
                        }

                        ans = min(ans, cnt);

                        temp = cur, cnt = 0;
                        while (!good(temp)) {
                                temp += nines[len];
                                cnt++;
                        }

                        ans = min(ans, cnt);
                }
                ll temp = cur; // whole number
                int cnt = 0;
                while (!good(temp)) {
                        temp += nines[len + 1];
                        cnt++;
                }
                ans = min(ans, cnt);

                cout << ans << '\n';
        }
}

                        
