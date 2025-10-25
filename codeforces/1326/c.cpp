//
// Created by hungw on 3/19/2020.
//
#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<long long> arr;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        arr.push_back(a);
    }
    long long mx = 0;
    for (int i = 0; i < K; i++) {
        mx += N - i;
    }
    bool started = false;
    long long total = 1;
    int count = 1;
    cout << mx << " ";
    for (int i = 0; i < N; i++) {
        long long value = arr[i];
        if (value >= N - K + 1) {
            if (!started) {
                started = true;
            } else {
                total = (total * count) % (long long) 998244353;
                count = 1;
            }
        } else {
            if (started)
                count++;
        }
    }
    cout << total << endl;
    return 0;
}
