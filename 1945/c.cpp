#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; 
        string a;
        cin >> n >> a;
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            right += (a[i] == '1');
        }
        int pos = -1;
        int best = n + 1;
        if (right >= (n + 1) / 2) {
            pos = 0;
            best = n;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') right--;
            else left++;
            
            int lsize = i + 1, rsize = n - (i + 1);
            if (left >= (lsize + 1) / 2 && right >= (rsize + 1) / 2) {
                int cur = abs(lsize - rsize);
                if (cur < best) {
                    best = cur;
                    pos = i + 1;
                }
            }
        }
        cout << pos << '\n';


    }
}
