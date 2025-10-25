#include <bits/stdc++.h>
using namespace std;

struct entry {
    int gold, silver, bronze;

    string name;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<entry> entries;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        string s; getline(cin, s);
        s = s.substr(1);
        entries.push_back({a, b, c, s});
    }
    auto cmp = [](entry& a, entry& b) {
        if (a.gold == b.gold) {
            if (a.silver == b.silver) {
                return a.bronze > b.bronze;
            } else return a.silver > b.silver;
        } else return a.gold > b.gold;
    };
    sort(entries.begin(), entries.end(), cmp);
    cout << entries[0].name << endl;
    return 0;
}