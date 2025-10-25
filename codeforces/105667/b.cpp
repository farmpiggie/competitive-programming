/*
 * all (good) shapes are:
 * 1 block or
 * 2+ blocks, where 2 blocks have 3 sides and the rest of the blocks have 2 sides with 90 degree diff
 * 
 * h[i][j] = length of longest horizontal (left to right) ending at (i, j)
 * v[i][j] = length of longest veritcal (up to down) ending at (i, j)
 *
 * sq[i][j] = whether or not there is a 2x2 square at [i, j]
 *
 * after we calculate, replace all h[i][j] >= 3 with 1, otherwise 0
 * same with v[i][j]
 * psum sq[i][j] as well
 *
 * then we 2d psum for h[i][j], v[i][j], as well as sq[i][j]
 *
 * subrectangle is (a, b) -> (c, d)
 * sum(h(a, b + 2, c, d))
 * sum(w(a + 2, b, c, d))
 * sum(sq(a + 1, b + 1, c, d))
 *
 * 2 2
 * 2 2
 */
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    v2i arr(n + 1, vi(m + 1, 1e9)); // 1 index
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    v2i ver(n + 1, vi(m + 1, 0));
    v2i hor(n + 1, vi(m + 1, 0));
    v2i sq(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == arr[i][j - 1]) hor[i][j] = hor[i][j - 1] + 1;
            else hor[i][j] = 1;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (arr[i][j] == arr[i - 1][j]) ver[i][j] = ver[i - 1][j] + 1;
            else ver[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i - 1][j - 1] == arr[i - 1][j] && arr[i - 1][j] == arr[i][j - 1] && arr[i][j - 1] == arr[i][j]) {
                sq[i][j] = 1;
            } else sq[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ver[i][j] >= 3) ver[i][j] = 1;
            else ver[i][j] = 0;
            if (hor[i][j] >= 3) hor[i][j] = 1;
            else hor[i][j] = 0;
        }
    }

    v2i vp(n + 1, vi(m + 1, 0));
    v2i hp(n + 1, vi(m + 1, 0));
    v2i sp(n + 1, vi(m + 1, 0));

    auto calculate_psum = [&](v2i& fill, v2i& orig) -> void {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                fill[i][j] = orig[i][j] + fill[i - 1][j] + fill[i][j - 1] - fill[i - 1][j - 1];
            }
        }
    };

    calculate_psum(vp, ver);
    calculate_psum(hp, hor);
    calculate_psum(sp, sq);
   
    // x1, y1 >= 1
    auto query = [&](v2i& psum, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return 0;
        return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
    };

    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        
        if (query(hp, x1, y1 + 2, x2, y2) + query(vp, x1 + 2, y1, x2, y2) + query(sp, x1 + 1, y1 + 1, x2, y2) == 0) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}
