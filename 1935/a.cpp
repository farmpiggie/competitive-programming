#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string rev_s = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            rev_s = rev_s + s[i];
        }
        if (s <= rev_s) {
            cout << s << '\n';
        } else {
            cout << rev_s + s << '\n';
        }
    }
    return 0;
}