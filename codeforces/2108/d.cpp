#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
        cout << "? " << x << endl;
        int res; cin >> res;
        return res;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                if (n == 2 * k) {
                        cout << "! " << k << ' ' << k << endl;
                        continue;
                }

                vector<int> left, right, r2;
                for (int i = 1; i <= k; i++) {
                        left.push_back(ask(i));
                }

                for (int i = 0; i < k; i++) {
                        r2.push_back(ask(n - i));
                }
                reverse(r2.begin(), r2.end()); // last k characters

                int rem = n % k;
                for (int i = 0; i < rem; i++) {
                        right.push_back(r2[k - 1 - i]);
                }
                reverse(right.begin(), right.end()); // last (n % k) elements in order
                for (int i = 0; i < k - rem; i++) {
                        right.push_back(r2[i]);
                }

                int orig_n = n;
                n += (k - rem) % k;
/*
                for (int x : left) cout << x << ' ';
                cout << '\n';
                for (int x : right) cout << x << ' ';
                cout << '\n';
*/

                int diff = -1;
                for (int i = 0; i < k; i++) {
                        if (left[i] != right[i]) {
                                diff = i;
                                break;
                        }
                }

                if (diff == -1) {
                        cout << "! -1" << endl;
                        continue;
                }

 //               cout << "diff: " << diff << '\n';

                int l = 1, r = n / k - 2;
                int mx = 0; // last element before change

                while (l <= r) {
                        int m = (l + r) / 2;
  //                      cout << "m: " << m << '\n';
   //                     cout << "asking: " << m * k + diff + 1 << '\n';
                        if (ask(m * k + diff + 1) == left[diff]) {
                                mx = max(mx, m);
                                l = m + 1;
                        } else {
                                r = m - 1;
                        }
                }

//                cout << "mx: " << mx << '\n';

                int lb = mx * k + diff, lr = (mx + 1) * k + diff; // leftbound, rightbound
                vector<int> overlap;
                overlap.push_back(left[diff]);
                for (int i = lb + 1; i < lr; i++) {
                        overlap.push_back(ask(i + 1));
                }
                overlap.push_back(right[diff]);
                int leftend = lb, rightend = lr;
//                cout << "lb: " << lb << '\n';
                for (int i = 0; i < k && orig_n - (lb + 1 + i) >= k; i++) {
                        if (overlap[i] == left[(diff + i) % k]) leftend = lb + i;
                        else break;
                }
                for (int i = 0; i < k && lr + 1 - i > k; i++) {
                        if (overlap[k - i] == right[(diff + k - i) % k]) rightend = lr - i;
                        else break;
                }
 //               cout << leftend << " " << rightend << '\n';
                if (leftend + 1 == rightend) {
                        cout << "! " << leftend + 1 << " " << orig_n - (leftend + 1) << endl;
                } else {
                        cout << "! -1" << endl;
                }
        }
}

                        


                













