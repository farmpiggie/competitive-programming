//
// Created by hungw on 3/14/2020.
//
#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a;
        for (int i = 0; i < N; i++) {
            int c; cin >> c;
            a.push_back(c);
        }
        sort(a.begin(), a.end());
        int biggest = 1;
        int curr = 1;
        for (int i = 1; i < N; i++) {
            if (a[i - 1] == a[i]) curr--;
            curr++;
            biggest = max(biggest, curr);
        }
        cout << biggest << endl;
    }
    return 0;
}
