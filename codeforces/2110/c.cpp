#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> d(n);
                for (int &x : d) cin >> x;
                vector<pii> h(n);
                for (auto &[x, y] : h) cin >> x >> y;

                bool works = true;
                pii cur = make_pair(0, 0);
                vector<pii> arr;
                arr.push_back(cur);
                for (int i = 0; i < n; i++) {
                        pair<int, int> p = h[i];
                        if (d[i] == 1) {
                                cur.first++;
                                cur.second++;
                                if (cur.second < p.first || cur.first > p.second) {
                                        works = false;
                                        break;
                                }
                                cur = make_pair(max(cur.first, p.first), min(cur.second, p.second));
                        } else if (d[i] == -1) {
                                cur = make_pair(max(cur.first, p.first), min(cur.second + 1, p.second)); // if we can rise up by one
                                if (cur.first > cur.second) {
                                        works = false;
                                        break;
                                }
                        } else {
                                if (cur.second < p.first || cur.first > p.second) {
                                        works = false;
                                        break;
                                }
                                cur = make_pair(max(cur.first, p.first), min(cur.second, p.second));
                        }
//                        cout << cur.first << " " << cur.second << '\n';
                        arr.push_back(cur);
                }

                if (works) {
                        int start = cur.first;
                        for (int i = n - 1; i >= 0; i--) {
                                pair<int, int> prev = arr[i];
//                                cout << "prev: " << prev.first << " " << prev.second << '\n';
                                int move = d[i];
//                                cout << "move: " << move << '\n';
                                if (move == 1) {
                                        start--;
                                } else if (move == -1) {
                                        if (prev.second < start) {
                                                start--;
 //                                               cout << "set to 1\n";
                                                d[i] = 1;
                                        } else {
  //                                              cout << "set to 0\n";
                                                d[i] = 0;
                                        }
                                }
                        }

                        for (int &x : d) cout << x << " ";
                        cout << '\n';
                } else {
                        cout << "-1\n";
                }

        }
}





