/*
 * use sqrt decomp.
 * at each hole, store power as well as next node in another block and # of steps to get to it.
 * to answer query, make at most sqrt(N) jumps
 * to update query, recompute all next[i], cnt[i] for each pos < i in same block.
 *
 * you can prob do this with link cut tree too?
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int n, m; cin >> n >> m;
        int k = sqrt(n);
        vector<int> power(n), next(n), cnt(n);
        for (int &x : power) cin >> x;

        for (int i = 0; i < n; i++) {
                int block = i / k;
                int pos = i;
                int jumps = 0;
                while (pos / k == block && pos < n) { // in same block, not out of bounds
                        pos += power[pos];
                        jumps++;
                }
                next[i] = pos;
                cnt[i] = jumps;
        }

        while (m--) {
                int type; cin >> type;
                if (type == 0) {
                        int a, b; cin >> a >> b;
                        --a;
                        power[a] = b;
                        int block = a / k;
                        int pos = a;
                        int jumps = 0;
                        while (pos / k == block && pos < n) { // in same block, not out of bounds
                                pos += power[pos];
                                jumps++;
                        }
                        next[a] = pos;
                        cnt[a] = jumps;

                        for (int i = a - 1; i >= (a / k) * k; i--) {
                                int x = i + power[i];
                                if (x / k == a / k) { // jump to same block
                                        next[i] = (x < n ? next[x] : n);
                                        cnt[i] = (x < n ? cnt[x] : 0) + 1;
                                }
                        }
                } else {
                        int x; cin >> x;
                        --x;
                        int prev;
                        int jumps = 0;
                        while (x < n) {
                                prev = x; // last block before we exit
                                jumps += cnt[x];
                                x = next[x];
                        }
                        int block = prev / k;
                        int exit;
                        while (prev / k == block && prev < n) { // still in same block
                                exit = prev;
                                prev += power[prev];
                        }
                        cout << exit + 1 << " " << jumps << '\n';
                }
        }
}



        
