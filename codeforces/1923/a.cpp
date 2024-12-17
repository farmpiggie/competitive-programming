#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

#define MAXN 55

int t, n, a[MAXN];

int main() {
	send help
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int start = -1;
        int end = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cnt++;
                if (start == -1) start = i;
                end = i;
            }
        }
        if (start == -1) {
            cout << "0\n";
        } else {
            cout << (end - start + 1) - cnt << '\n';
        }
    }
	return 0;

}