#include <bits/stdc++.h>

using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                vector<int> b(n);
                for (int i = 0; i < n; ++i) {
                       cin >> b[i];
                }

                int min_prefix = b[0];
                bool possible = true;

                for (int i = 1; i < n; ++i) {
                        bool works = true;
                        int check = b[i];
                        if (check > 0) {
                                int rem = check;
                                int cur = min_prefix;
                                while (rem > 0) {
                                        if (cur <= 0) {
                                                works = false;
                                                break;
                                        }

                                        int upper = min(cur, rem);
                                        int lower = rem / 2;

                                        if (upper <= lower) {
                                                works = false;
                                                break;
                                        }
                                        int x = upper;
                                        rem -= x;
                                        cur = x - 1; 
                                }
                        }

                        if (!works) {
                                possible = false;
                                break; 
                        }
                        min_prefix = min(min_prefix, b[i]);
                }
                cout << (possible ? "YES" : "NO") << '\n';

        }
}