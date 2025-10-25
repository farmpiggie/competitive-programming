#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll n, m;
                cin >> n >> m;
                if (m < n || m > n * (n + 1) / 2) {
                        cout << "-1\n";
                        continue;
                }
                ll diff = m - n;
                if (diff == 0) {
                        cout << "1\n";
                        for (int i = 1; i < n; i++) {
                                cout << i << " " << i + 1 << '\n';
                        }
                        continue;
                }

                ll cur = n * (n + 1) / 2;
                vector<int> ans;
                int cnt = 1;
                set<int> nums;
                for (int i = 1; i <= n; i++) nums.insert(i);
                while (cur > m) {
                        if (cur - cnt >= m) {
                                ans.push_back(n - cnt);
                                nums.erase(n - cnt);
                                cur -= cnt;
                                cnt++;
                        } else break;
                }
                reverse(ans.begin(), ans.end());

                vector<int> ans2(n, 0);
                for (int i = 0; i < ans.size(); i++) {
                        ans2[i] = ans[i];
                }
                int pos = cur - m; // offset of (n - cnt)
                if (ans2[cnt - pos] != 0) {
                        for (int i = n - 2; i >= cnt - pos; i--) {
                                ans2[i + 1] = ans2[i];
                        }
                }

                ans2[cnt - pos] = n - cnt;
//                cout << "setting: " << cnt - pos << " to " << n - cnt << '\n';
//                cout << "cnt is: " << cnt << '\n';
                nums.erase(n - cnt);

 //               cout << "size: " << nums.size() << '\n';

 //               for (int i = 0; i < n; i++) cout << ans2[i] << " ";
 //               cout << '\n';

                if (nums.size() > 0) {
                        for (int i = 0; i < n; i++) {
                                if (ans2[i] == 0) {
  //                                      cout << "size of nums: " << nums.size() << '\n';
                                        ans2[i] = *(--nums.end());
                                        nums.erase(ans2[i]);
                                }
                        }
                }

                cout << ans2[0] << '\n';
                for (int i = 0; i < n - 1; i++) {
                        cout << ans2[i] << " " << ans2[i + 1] << '\n';
                }
        }
}



                


                        







