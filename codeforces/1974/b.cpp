#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                string s; cin >> s;

                set<char> unique;
                for (char c : s) unique.insert(c);
                vector<char> a;
                for (char c : unique) a.push_back(c);

                map<char, char> translate;
                for (int i = 0; i <= a.size() / 2; i++) {
                        translate[a[i]] = a[a.size() - 1 - i];
                        translate[a[a.size() - 1 - i]] = a[i];
                }

                for (char &c : s) {
                        c = translate[c];
                }
                cout << s << '\n';
        }
}
