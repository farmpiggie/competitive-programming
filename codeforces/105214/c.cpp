#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>


int main() {
    int n; cin >> n;
    vector<pll> points(n);
    vector<char> letter(n);
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second >> letter[i];

    bool infinite = false;
    bool two = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (letter[i] != letter[j]) continue;
            two = true;
            // given two same letters, see if any pt exists not on said line.
            ll xi = points[i].first, yi = points[i].second;
            ll xj = points[j].first, yj = points[j].second;
            // check if there are points that are not on this line
            // slope = (y_j - y_i) / (x_j - x_i)
            // y - y_i = m * (x - x_i)

            ll slope_num = yj - yi, slope_dem = xj - xi;
            for (int k = 0; k < n; k++) {
                ll x = points[k].first, y = points[k].second;
                // on slope, no integer division
                if (slope_dem == 0) {
                    if (x != xi) {
                        infinite = true;
                    } 
                } else {
                    if ((y - yi == slope_num * (x - xi) / slope_dem && (slope_num * (x - xi)) % slope_dem == 0)) {
                        // do nothing
                    } else {
                        infinite = true;
                    }
                }
            }
        }
    }

    if (infinite) cout << "Infinity\n";
    else if (two) cout << "2\n";
    else cout << "1\n";

    return 0;
}