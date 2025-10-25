//
// Created by Wesley Hung on 4/13/20.
//
#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        map<int, int> mp;
        cin >> N;
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            mp[a]++;
        }
        int mx = 0;
        for (pair<int, int> p : mp) {
            if (mp.size() - 1 >= p.second) {
                mx = max(mx, p.second);
            } else {
                mx = max(mx, ((int) mp.size()) - 1);
            }
            if (mp.size() <= p.second - 1) {
                mx = max(mx, (int) mp.size());
            }
        }
        cout << mx << endl;
    }
    return 0;
}