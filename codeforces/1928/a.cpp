#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int t, a, b;

int main() {
	send help
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        bool works = false;
        if (a % 2 == 0) {
            int c = a / 2;
            int d = b * 2;
            if (c > d) swap(c, d);
            if (a != c || b != d) {
                works = true;
            }
        }
        if (b % 2 == 0) {
            int c = b / 2;
            int d = a * 2;
            if (c > d) swap(c, d);
            if (a != c || b != d) {
                works = true;
            }
        }
        if (works) cout << "Yes\n";
        else cout << "No\n";
    }
	return 0;
}