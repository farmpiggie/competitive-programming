#include <bits/stdc++.h>
using namespace std;
int T, N, V;
bool arr[201];
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> V;
        for (int j = 0; j <= 200; j++) {
            arr[j] = 0;
        }
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            arr[a] = 1;
        }
        int idx = 1;
        for (int i = 1; i <= V; i++) {
            while (arr[idx]) {
                idx++;
            }
            arr[idx] = 1;
        }
        int mx = 0;
        for (int i = 1; i <= 200; i++) {
            if (arr[i]) {
                mx = i;
            } else {
                break;
            }
        }
        cout << mx << endl;
    }
    return 0;
}