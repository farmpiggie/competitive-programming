/*
 * if 9 | x:
 *      9 | S(x)
 *
 *               1000000000
 * 9999999999 -> 1111111111 * 9
 *
 * 1. multiply by 9
 * 2. digit
 * [9, 18, 27, 36, ...., 81]
 * 3. digit
 * [9]
 * the resulting number always equals 9
 * add (n - 9)
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll n; cin >> n;
                cout << "mul 9" << endl;
                int res; cin >> res;
                cout << "digit" << endl;
                cin >> res;
                cout << "digit" << endl;
                cin >> res;
                cout << "add " << (n - 9) << endl;
                cin >> res;
                cout << "!" << endl;
                cin >> res;
        }
}


