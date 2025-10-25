#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    cout << "1\n";
    if (n == 25) {
        cout << "50\n";
        for (int i = 0; i < 25; i++) cout << "1 ";
        for (int i = 0; i < 25; i++) cout << "5 ";
        cout << '\n';
    } else {
        cout << 2 * n + 1 << "\n";
        for (int i = 0; i < 2 * n; i++) {
            cout << "1 ";
        }
        cout << n << "\n";
    }
}