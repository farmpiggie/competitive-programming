#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<int>> grid;
vector<vector<int>> psum, prv, nxt;
vector<int> l;

int distance(int i, int l, int r) {
    auto& s = psum[i];
    r++;
    return s[l] + (r-l)-(s[r]-s[l]) + (s[c]-s[r]);
}

int main() {
    cin >> r >> c;

    grid.assign(r, vector<int>(c, 0));

    for (vector<int>& a : grid) {
        for (int& x : a) {
            char y; cin >> y;
            x = (y - '0');
        }
    }

    if (c > r) {
        vector<vector<int>> new_grid = vector<vector<int>>(c, vector<int>(r, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                new_grid[j][i] = grid[i][j];
            }
        }
        grid = new_grid;
        swap(r, c);
    }

    psum = {r, vector<int>(c + 1, 0)};

    for (int i = 0; i < r; i++) {
        psum[i][0] = 0;
        for (int j = 1; j <= c; j++) {
            psum[i][j] = psum[i][j - 1] + grid[i][j - 1];
        }
    }

    prv.assign(c, vector<int>(c, 0));
    for (int k = 0; k < r; k++) {
        nxt.assign(c, vector<int>(c, INT_MAX));
        l.assign(c, INT_MAX); // l[j] stores from i from 0 to l, min of prv[i][j]
        for (int i = 0; i < c; i++) {
            for (int j = i; j < c; j++) {
                l[j] = min(l[j], prv[i][j]); // l[j] stores min of dp[l, r] from 0 <= l' <= l
                // if (i - 1 >= 0) l[j] = min(l[j], prv[i - 1][j])
            }
            int cur = INT_MAX;
            if (i - 1 >= 0) cur = min(cur, l[i - 1]);
            for (int j = i; j < c; j++) {
                cur = min(cur, l[j]);
                int d = distance(k, i, j);
                nxt[i][j] = min(nxt[i][j], d + cur);
            }
            if(k==0&&i==0) break;
        }
        prv = nxt;
    }

    int ans = INT_MAX;
    for (int i = 0; i < c; i++) {
            ans = min(ans, prv[i][c-1]);
    }

    cout << ans << '\n';


}
