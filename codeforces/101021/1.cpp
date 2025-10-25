#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l = 1, r = 1000000;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << mid << '\n' << flush;
        
        string response;
        cin >> response;
        if (response == "<") {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << "! " << ans << "\n";
    return 0;
}