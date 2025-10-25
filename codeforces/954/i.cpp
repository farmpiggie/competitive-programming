#include <bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> par, sz;

	dsu(int n) {
		par = vector<int>(n + 1);
		sz = vector<int>(n + 1);

		for (int i = 0; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int a) {
		if (a == par[a]) return a;
		else return par[a] = find(par[a]);
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
	}
};

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void run() {
    string s, t; cin >> s >> t;

    int n = (int) s.length(), m = (int) t.length();

    vector<int> a(n), b(m);

    vector<vector<vector<bool>>> cnt(n - m + 1, vector<vector<bool>>(6, vector<bool>(6, 0)));

    for (char i = 'a'; i <= 'f'; i++) {
        for (char j = 'a'; j <= 'f'; j++) {
            if (i == j) continue;

            for (int k = 0; k < n; k++) {
                a[k] = (s[k] == i);
            }
            for (int k = m - 1; k >= 0; k--) {
                b[k] = (t[m - 1 - k] == j);
            }

            vector<int> res = multiply(a, b);
            for (int k = 0; k < (n - m + 1); k++) {
                cnt[k][i - 'a'][j - 'a'] = (res[k + m-1] > 0);
            }
        }
    }

    for (int l = 0; l < (n - m + 1); l++) {
        int diff = 0;
        dsu uf(6);
        for (char i = 0; i < 6; i++) {
            for (char j = i + 1; j < 6; j++) {
                if (cnt[l][i][j] > 0 || cnt[l][j][i] > 0) {
                    uf.merge(i, j);
                }
            }
        }

        set<int> counted;
        for (int i = 0; i < 6; i++) {
            int comp = uf.find(i);
            if (counted.find(comp) == counted.end()) {
                diff++;
                counted.insert(comp);
            }
        }
        cout << 6 - diff << " ";
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    run();
    return 0;
}