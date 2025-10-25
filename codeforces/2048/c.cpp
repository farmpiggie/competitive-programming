#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = (int) s.length();
        vector<string> options;
        int leading = 0;
        for (char c : s) {
            if (c == '1') leading++;
            else break;
        }
        if (leading == n) {
            cout << "1 " << n << " " << n << " " << n << '\n';
            continue;
        }
        // i can try this many substrings starting at said position
        for (int i = 0; i < leading; i++) {
            string t = s.substr(i, n - leading);
            string ns = s;
            int m = (int) t.length();
            for (int i = leading; i < n; i++) {
                int tb = t[i - leading] - '0', nb = ns[i] - '0';
                if (tb ^ nb == 1) ns[i] = '1';
                else ns[i] = '0';
            }
            options.push_back(ns);
        }

        int best = -1;
        string mx = "";
        for (int i = 0; i < n; i++) mx += '0';
        for (int i = 0; i < options.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (options[i][j] > mx[j]) {
                    best = i;
                    mx = options[i];
                    break;
                } else if (mx[j] > options[i][j]) {
                    break;
                }
            }
        }
        cout << "1 " << n << " " << best + 1 << " " << best + n - leading << '\n';
    }
    return 0;
}
