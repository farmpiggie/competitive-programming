#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int inv = -1;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                inv = i;
                break;
            }
        }
        if (k == 1) {
            cout << "YES\n";
            cout << "1" << '\n';
            continue;
        }
        // 4 1 2 3, i = 1.
        // 1 2 4 3, i = 3
        //
        // 1 2 5 3 4 6, i = 3
        // start from inversion, add numbers from left and right of it.
        int l = inv - 1, r = inv;
        deque<int> dq;
        while (l >= 0 && r < n && dq.size() + 2 <= k) {
            dq.push_front(l);
            dq.push_back(r);
            l--;
            r++;
        }
        auto check = [&](deque<int>& dq, int offset) {
            vector<int> ans;
            for (int num : dq) ans.push_back(num);
            int inv = -1;
            for (int i = 1; i < ans.size(); i++) {
                if (a[ans[i - 1]] > a[ans[i]]) {
                    inv = i;
                    break;
                }
            }
            // always has an inverse
            bool works = true;
            for (int j = inv; j < ans.size() && j - inv + offset < inv; j++) {
                if (a[ans[j - inv + offset]] < a[ans[j]]) {
                    works = false;
                    break;
                }
            }
            return works;
        };
 
        if (dq.size() < k) { // we can afford to add one element on either side
            if (l >= 0) {
                dq.push_front(l);
                if (check(dq, 1)) {
                    cout << "YES\n";
                    for (int num : dq) {
                        cout << num + 1 << " ";
                    }
                    cout << '\n';
                    continue;
                }
                dq.pop_front();
            }

            if (r < n) {
                dq.push_back(r);
                 if (check(dq, 0)) {
                    cout << "YES\n";
                    for (int num : dq) {
                        cout << num + 1 << " ";
                    }
                    cout << '\n';
                    continue;
                }
                dq.pop_front();  
            }

            cout << "NO\n";
        } else {
            if (check(dq, 0)) {
                cout << "YES\n";
                for (int num : dq) {
                    cout << num + 1 << " ";
                }
                cout << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
}



