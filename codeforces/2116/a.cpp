#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int a, b, c, d; 
                cin >> a >> b >> c >> d;
                if (min(a, c) >= min(b, d)) {
                        cout << "Gellyfish\n";
                } else cout << "Flower\n";
        }
}