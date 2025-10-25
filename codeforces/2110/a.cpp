#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;

                sort(a.begin(), a.end());

                if ((a[0] + a[n - 1]) % 2 == 0) {
                        cout << "0\n";
                        continue;
                }

                int l = 0;
                for (int i = 1; i < n; i++) {
                        if (a[i] % 2 != a[0] % 2) {
                                l = i;
                                break;
                        }
                }

                int r = 0;
                for (int i = n - 2; i >= 0; i--) {
                        if (a[i] % 2 != a[n - 1] % 2) {
                                r = (n - 1) - i;
                                break;
                        }
                }

                cout << min(l, r) << '\n';
        }
}
