 /*
  * 1. any array with no zeros is magical.
  * 2. a magical array can have at most one zero.
  * 3. try doing n - cnt_0 or n - cnt_0 + 1
  * n - cnt_0 is always possible. therefore, we must determine if we can do n - cnt_0 + 1.
  *
  * lets say we decide to choose the 0 in some location (lets call it index j)
  *
  * min(a1, ai) >= mex(a[i + 1], a[n]) for all 1 <= i < j
  *
  * we can just keep track of running mex and running a_i. 
  */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                map<int, int> occ;
                int zeros = 0;
                for (int &x : a) {
                        cin >> x;
                        occ[x]++;
                        if (x == 0) zeros++;
                }
                
                int mex = 0;
                while (occ.find(mex) != occ.end()) {
                        mex++;
                }
                
                bool works = true;
                bool reached = false;
                int mn = INT_MAX;
                for (int i = 0; i < n; i++) {
                        if (a[i] == 0) {
                                reached = true;
                                break;
                        }
                        occ[a[i]]--;
                        mn = min(mn, a[i]);
                        if (occ[a[i]] == 0 && a[i] < mex) {
                                mex = a[i];
                        }
                        if (mn < mex) {
                                works = false;
                                break;
                        }
                }
                cout << n - zeros + (reached && works) << '\n';
        }
}







