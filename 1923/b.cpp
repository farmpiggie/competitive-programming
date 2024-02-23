#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

#define MAXN 300005

int t, n, a[MAXN], x[MAXN];
ll k;

int main() {
	send help
    cin >> t;
    while (t--) {
        vector<pii> arr; // (time to reach, health)

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            // cout << abs(x[i]) << " " << a[i] << '\n';
            arr.push_back({abs(x[i]), a[i]});
        }

        sort(arr.begin(), arr.end());

        int time = 0;
        ll firepower = 0;
        ll damage = 0;
        bool works = true;
        for (pair<int, int>& p : arr) {
            // cout << p.first << " " << p.second << '\n';
            firepower += k * (p.first - time);
            damage += p.second;
            // cout << (p.first - t) << " " << t << " " << firepower << " " << damage << '\n';
            time = p.first;
            if (damage > firepower) {
                works = false;
                break;
            }
        }

        if (works) cout << "Yes\n";
        else cout << "No\n";
    }
    

	return 0;
}