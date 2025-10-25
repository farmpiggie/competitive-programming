//
// Created by hungw on 3/19/2020.
//
#include <bits/stdc++.h>
using namespace std;
int N;
vector<long long> arr;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long a; cin >> a;
        arr.push_back(a);
    }
    cout << arr[0] << " ";
    long long mx = arr[0];
    for (int i = 1; i < N; i++) {
        long long pog = arr[i] + mx;
        cout << pog << " ";
        mx = max(mx, pog);
    }
    cout << endl;
    return 0;
}
