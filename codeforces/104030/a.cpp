/*
the only time going from x_i, y_i to x_j, y_j is:
min(x_i, y_i) <= min(x_j, y_j)

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int a = 0, b = 0;
    int error = -1;

    vector<string> arr(n);
    for (string& x : arr) cin >> x;

    bool gameover = false;

    for (int i = 0; i < n; i++) {
        string s = arr[i];

        int cur_a = stoi(s.substr(0, s.find("-")));
        int cur_b = stoi(s.substr(s.find("-") + 1));

        if (((cur_a + cur_b + 1) / 2) % 2 == 1) { // swap a and b
            swap(cur_a, cur_b);
        } 

        // gameover and change in score
        if (gameover && (cur_a != a || cur_b != b)) {
            error = i + 1;
            break;
        }

        // point size is > 11 (if all points < 11) or sum of points > 21 (at least 11 11)
        if (max(cur_a, cur_b) > 11 || cur_a + cur_b > 21) {
            error = i + 1;
            break;
        }

        if (a > cur_a || b > cur_b) {
            error = i + 1;
            break;
        }

        a = cur_a;
        b = cur_b;

        if (a == 11 || b == 11) {
            gameover = true;
        }

    }
    if (error == -1) cout << "ok\n";
    else cout << "error " << error << '\n';
    return 0;
}