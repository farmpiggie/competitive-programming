//
// Created by Wesley Hung on 4/12/20.
//
#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int x = 1; x <= T; x++) {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + N);
        for (int i = (N - 1) / 2; i >= 0; i--) {
            cout << arr[i] << " ";
            if (N - 1 - i != (N - 1) / 2)
                cout << arr[N - 1 - i] << " ";
        }
        cout << endl;
    }
    return 0;
}
