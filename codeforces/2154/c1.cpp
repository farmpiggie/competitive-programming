#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
vector<int> spf(MAX);

void build_spf() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> factorize(int x) {
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    build_spf();

    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        map<int, int> mp;
        for (int x : a) {
            for (int p : factorize(x))
                mp[p]++;
        }

        int ans = 2;
        for (auto &[p, cnt] : mp) {
            if (cnt >= 2) {
                ans = 0;
                break;
            }
        }

        for (int x : a) {
            for (int p : factorize(x + 1)) {
                if (mp.count(p) && mp[p] > 0)
                    ans = min(ans, 1);
            }
        }

        cout << ans << '\n';
    }
}
