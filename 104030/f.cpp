#include <bits/stdc++.h>
using namespace std;

class HashedString {

  private:

    // change M and B if you want

    static const long long M = 1e9 + 9;

    static const long long B = 9973;


    // pow[i] contains B^i % M

    static vector<long long> pow;


    // p_hash[i] is the hash of the first i characters of the given string

    vector<long long> p_hash;


  public:

    HashedString(const string &s) : p_hash(s.size() + 1) {

        while (pow.size() <= s.size()) { pow.push_back((pow.back() * B) % M); }


        p_hash[0] = 0;

        for (int i = 0; i < s.size(); i++) {

            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;

        }

    }


    long long get_hash(int start, int end) {

        long long raw_val = (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));

        return (raw_val % M + M) % M;

    }

};

vector<long long> HashedString::pow = {1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<string>> a(n, vector<string>(n));
    for (auto& x : a) for (string& y : x) cin >> y;

    if (n == 2) {
        HashedString x(a[0][1]), y(a[1][0]);
        int cnt = 0;
        int idx = -1;
        for (int len = 1; len < min(a[0][1].length(), a[1][0].length()); len++) {
//            cout << "len: " << len << endl;
            if (x.get_hash(0, len - 1) == y.get_hash(a[1][0].length() - len, a[1][0].length() - 1) && x.get_hash(len, a[0][1].length() - 1) == y.get_hash(0, a[1][0].length() - len - 1)) {
                cnt++;
                idx = len;
            }
        }
        if (idx == -1) {
            cout << "NONE\n";
        } else if (cnt == 1) {
            cout << "UNIQUE\n";
            cout << a[0][1].substr(0, idx) << '\n' << a[0][1].substr(idx) << '\n';
        } else {
            cout << "MANY\n";
        }

    } else {
        // len(s[i]) = (len(s[i][j]) + len(s[i][k]) - len(s[j][k])) / 2;
        vector<string> ans(n);
        vector<int> lens(n);
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            int len = (a[i][j].length() + a[i][k].length() - a[j][k].length()) / 2;
            lens[i] = len;
            ans[i] = a[i][j].substr(0, len);
        }
        
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (ans[i] + ans[j] != a[i][j]) {
                    works = false;
                    break;
                }
            }
        }
        
        for (int i = 0; i < n; i++) if (lens[i] == 0) works = false;
        
        if (works) {
            cout << "UNIQUE\n";
            for (int i = 0; i < n; i++) cout << ans[i] << '\n';
        } else {
            cout << "NONE\n";
        }

    }

    
    return 0;
}
