#include <bits/stdc++.h>
using namespace std;
int T;
long long N;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N < 3) {
            cout << 0 << endl;
        } else {
            cout << (N - 1) / 2 << endl;
        }
    }
    return 0;
}

