/*
define query(x) = query with set (1, 2, ...n) and start node x.

let us run query on all nodes (1....n).

let us say the start of our path is p_0, the node with largest query(x).

we know that the next node in the path, p_1, must have a query value of
query(p_0) - 1

let us say three nodes qualify here: s0, s1, s2 all have query value of
query(p_0) - 1

define query2(removed, x) = query with set of (1, ... n) \ (removed), x

then we run the queries for
s0 = query2({s1, s2}, x)
s1 = query2({s0, s2}, x)
s2 = query2({s0, s1}, x)

whichever node has query value = query(p_0), we can use. add that to the path
and continue this process.

this takes O(n) calls initially, and then O(n) to find the node.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        auto query = [&](set<int> s, int x) {
            cout << "? " << x << " " << (n - s.size()) << " ";
            for (int i = 1; i <= n; i++)
                if (!s.count(i))
                    cout << i << ' ';
            cout << '\n' << flush;
            int res;
            cin >> res;
            return res;
        };

        vector<int> a(n + 1);
        map<int, set<int>> lenToNode;
        for (int i = 1; i <= n; i++) {
            a[i] = query({}, i);
            lenToNode[a[i]].insert(i);
        }

        vector<int> path;
        int mx = 0;
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > mx) {
                mx = a[i];
                start = i;
            }
        }

        path.push_back(start);
        set<int> removed;
        int cur_len = mx - 1;
        while (cur_len > 0) {
            for (int u : lenToNode[cur_len]) {
                set<int> s2(lenToNode[cur_len]);
                s2.erase(u);
                set<int> s3(removed.begin(), removed.end());
                for (int v : s2)
                    s3.insert(v);
                if (query(s3, start) == mx) {
                    path.push_back(u);
                    for (int v : s2)
                        removed.insert(v);
                    break;
                }
            }
            cur_len--;
        }
        cout << "! " << path.size() << " ";
        for (int node : path)
            cout << node << " ";
        cout << '\n' << flush;
    }
}