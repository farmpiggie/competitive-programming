#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        set<char> unique;
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
            unique.insert(c);
        }

        if (unique.size() == 1) {
            cout << s << '\n';
            continue;
        }
        
        // otherwise switch character with least occ to char with highest occ
        
        vector<int> occs;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) occs.push_back(i);
        }

        sort(occs.begin(), occs.end(), [&](int x, int y) {
                return cnt[x] < cnt[y];
        });

        char low = occs[0] + 'a', high = occs.back() + 'a';
        
        for (char& c : s) {
            if (c == low) {
                c = high;
                break;
            }
        }
        cout << s << '\n';
    }
}

