/* 
 * if a query returns 0, it must be object A
 * if a query returns x >= n, then it must be object B
 *
 * if all x_i are distinct
 * choose i, j s.t. x_1 = 1, x_j = n
 * query(i, j)
 * if ans = 0 or ans < n - 1, then print A
 * if ans >= n, print B
 * if ans = n - 1:
 *      query (j, i)
 *      if ans = n - 1, print B
 *      otherwise print A
 *
 * if not all x_i are distinct
 * lets say x_i == x_j
 * let us choose 1 <= k <= n s.t. k is not in x.
 * query(i, k) and query(k, i)
 * if either is zero, then print A
 * otherwise both must be equal, and print B
 */
#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y) {
        cout << "? " << x << " " << y << endl;
        int res; cin >> res;
        return res;
}


int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> x(n);
                set<int> unique;
                for (int &y : x) {
                        cin >> y;
                        unique.insert(y);
                }
                if (unique.size() == n) {
                        int i, j;
                        for (int k = 0; k < n; k++) {
                                if (x[k] == 1) i = k + 1;
                                if (x[k] == n) j = k + 1;
                        }
                        int res1 = ask(i, j);
                        if (res1 == 0 || res1 < n - 1) {
                                cout << "! A" << endl;
                                continue;
                        } else if (res1 >= n) {
                                cout << "! B" << endl;
                        } else { // res1 == n - 1
                                int res2 = ask(j, i);
                                if (res2 == n - 1) cout << "! B" << endl;
                                else cout << "! A" << endl;
                        }
                } else {
                        int i, j;
                        for (int x = 1; x <= n; x++) {
                                if (!unique.count(x)) {
                                        i = x;
                                        break;
                                }
                        }
                        j = (i == 1 ? 2 : 1);
                        int res1 = ask(i, j);
                        int res2 = ask(j, i);
                        if (res1 == 0 || res2 == 0) cout << "! A" << endl;
                        else cout << "! B" << endl;
                }
        }
}





