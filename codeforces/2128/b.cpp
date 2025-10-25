#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                deque<int> dq;
                for (int i = 0; i < n; i++) {
                        int x; cin >> x;
                        dq.push_back(x);
                }
                bool smaller = true;
                vector<char> ans;
                for (int i = 0; i < n; i++) {
                        if (smaller) {
                                if (dq.front() < dq.back()) {
                                        ans.push_back('L');
                                        dq.pop_front();
                                } else {
                                        ans.push_back('R');
                                        dq.pop_back();
                                }
                        } else {
                                if (dq.front() > dq.back()) {
                                        ans.push_back('L');
                                        dq.pop_front();
                                } else {
                                        ans.push_back('R');
                                        dq.pop_back();
                                }
                        }
                        smaller = !smaller;
                }
                for (char c : ans) cout << c;
                cout << '\n';
        }
}

 