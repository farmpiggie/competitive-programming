//
// Created by hungw on 3/19/2020.
//
#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N == 1) {
            cout << -1 << endl;
        } else {
            for (int j = 0; j < N - 1; j++) {
                cout << 9;
            }
            cout << 8 << endl;
        }
    }
    return 0;
}
