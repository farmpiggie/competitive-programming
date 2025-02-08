/*
 * each swap combines two positions
 * aka (3, 1, 2, 1) -> (5, 2)
 * every swap we create, we lose 0, 1, or 2 groups.
 * we can only merge consecutive groups of (0, 1) together
 * is it as simple as checking (1) if the # of groups of 0s and 1s are a combination of a prefix of 0 and 1 groups
 * can we greedily just swap 0s and 1s together to form said group?
 *
 *
 * let say we need to form prefix 00000 (5 zeros)
 * can we just greedily form the values?
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int tc; cin >> tc;
        while (tc--) {
                string s, t; cin >> s >> t;
                int n = (int) s.length();

                vector<array<int, 2>> a, b;
                char c = s[0];
                int len = 0;
                for (int i = 0; i < n; i++) {
                        if (c == s[i]) len++;
                        else {
                                a.push_back({c - '0', len});
                                c = s[i];
                                len = 1;
                        }
                }
                a.push_back({c - '0', len});
                c = t[0];
                len = 0;
                for (int i = 0; i < n; i++) {
                        if (c == t[i]) len++;
                        else {
                                b.push_back({c - '0', len});
                                c = t[i];
                                len = 1;
                        }
                }
                b.push_back({c - '0', len});

                vector<int> ones, zeros;
                for (auto [val, cnt] : a) {
                        if (val) {
                                ones.push_back(cnt);
                        } else {
                                zeros.push_back(cnt);
                        }
                }
                
                if (zeros.size() == 0 || ones.size() == 0) {
                        cout << (s == t ? 0 : -1) << '\n';
                        continue;
                }

                int i = 1, j = 1; // zeros, ones
                int zero_cnt = zeros[0], one_cnt = ones[0];
                bool works = true;
                int ans = 0;
                
                if (a[0][0] != b[0][0]) { // swap between the first two
                        if (b[0][0]) { // beginning value is 1
                                if (i < zeros.size()) {
                                        zero_cnt += zeros[i];
                                        i++;
                                }
                        } else { // beginning value is 0
                                if (j < ones.size()) {
                                        one_cnt += ones[j];
                                        j++;
                                }
                        }
                        ans++;
                }
                //cout << "here" << endl;


                for (auto [val, cnt] : b) {
                        //cout << "val and cnt: " << val << " " << cnt << endl;
                        if (val == 0) {
                                //cout << "zeros size: " << zeros.size() << endl;
                                while (i < zeros.size() && zero_cnt < cnt) {
                                        //cout << "adding " << zeros[i] << " zeros "<< endl;
                                        zero_cnt += zeros[i]; // use these zeros
                                        i++;
                                        if (j < ones.size()) {
                                                //cout << "adding " << ones[j] << " ones" << endl; 
                                                one_cnt += ones[j];
                                                j++;
                                        }
                                        ans++;
                                }
                                //cout << "match check (expected vs actual): " << cnt << " " << zero_cnt << endl;
                                if (zero_cnt != cnt) {
                                        works = false;
                                        break;
                                } else {
                                        zero_cnt = (i < zeros.size() ? zeros[i++] : 0);
                                }
                        } else {
                                while (j < ones.size() && one_cnt < cnt) {
                                        //cout << "adding " << ones[j] << "ones" << endl;
                                        one_cnt += ones[j];
                                        j++;
                                        if (i < zeros.size()) {
                                                //cout << "adding " << zeros[i] << " zeros" << endl;
                                                zero_cnt += zeros[i];
                                                i++;
                                        }
                                        ans++;
                                }
                                //cout << "match check (expected vs actual): " << cnt << " " << one_cnt << endl;

                                if (one_cnt != cnt) {
                                        works = false;
                                        break;
                                } else {
                                        one_cnt = (j < ones.size() ? ones[j++] : 0);
                                }
                        }
                }

                cout << (works ? max(0, ans) : -1) << '\n';
        }
}

                                

                        

