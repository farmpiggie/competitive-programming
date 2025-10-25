#include <bits/stdc++.h>
using namespace std;

int thrw(int x) {
    cout << "throw " << x << '\n' << flush;
    int res;
    cin >> res;
    return res;
}

void swp(int x) { cout << "swap " << x << '\n' << flush; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // a[n] = value of throw
        vector<int> a(n + 1, 0);
        vector<int> ans(n + 1, 0);

        a[n] = 1;
        a[n - 1] = thrw(n - 1);
        if (a[n - 1] == 1)
            ans[n - 1] = 2;
        else
            ans[n - 1] = 1;

        for (int i = n - 2; i >= 1; i--) {
            if (ans[i + 1] == 2) {
                a[i] = a[i + 1] + 1;
                continue;
            }
            a[i] = thrw(i);
            if (a[i] == a[i + 1] + 1)
                ans[i] = 1;
            else
                ans[i] = 2;
        }

        /*
        for (int i = 1; i <= n; i++)
            cout << a[i] << '\n';
        */
        vector<int> swaps;

        for (int i = 1; i < n - 1; i++) {
            if (ans[i] == 0) {
                swaps.push_back(i);
                swp(i);
                swap(ans[i], ans[i + 1]);
                swap(a[i], a[i + 1]);
                a[i + 1] = thrw(i + 1);
                if (a[i + 1] == a[i + 2] + 1) {
                    ans[i + 1] = 1;
                } else {
                    ans[i + 1] = 2;
                }

                /*
                for (int i = 1; i <= n; i++)
                    cout << ans[i] << " ";
                cout << '\n' << flush;
                */
            }
        }

        swaps.push_back(n - 1);
        swp(n - 1);
        swap(a[n - 1], a[n]);
        swap(ans[n - 1], ans[n]);

        /*
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << '\n' << flush;
        */

        ans[n - 1] = (thrw(n - 1) == 1) ? 2 : 1;

        reverse(swaps.begin(), swaps.end());
        for (int i : swaps) {
            swap(ans[i], ans[i + 1]);
        }

        cout << "! ";

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n' << flush;
    }
}