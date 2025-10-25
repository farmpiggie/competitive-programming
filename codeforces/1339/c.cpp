//
// Created by Wesley Hung on 4/12/20.
//

#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int x = 0; x < T; x++) {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int cur_mx = arr[0];
        int cur_gap = 0;
        vector<int> indices;
        indices.push_back(cur_mx);
        int mn = arr[0];
        for (int i = 1; i < N; i++) {
            if (cur_mx < arr[i]) {
//                cout << "new max! " << arr[i] << endl;
                cur_gap = max(cur_gap, cur_mx - mn);
//                cout << "current gap: " << cur_gap << endl;
                cur_mx = arr[i];
                indices.push_back(arr[i]);
                mn = arr[i];
            } else {
                mn = min(mn, arr[i]);
//                cout << "new min of range: " << mn << endl;
            }
        }
//        cout << "last gap: " << indices[indices.size() - 1] - arr[N - 1] << endl;
        cur_gap = max(cur_gap, indices[indices.size() - 1] - mn);
//        cout << cur_gap << endl;
        if (cur_gap == 0) cout << 0 << endl;
        else cout << (int)(log2(cur_gap)) + 1 << endl;
    }
    return 0;
}