#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                string s; cin >> s;
                bool works = false;
                for (int i = 1; i < s.size(); i++) {
                        if (s[i - 1] == s[i]) {
                                works = true;
                                break;
                        }
                }
                cout << (works ? 1 : (int) s.size()) << '\n';
        }
}
