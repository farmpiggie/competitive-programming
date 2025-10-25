#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
 
main()
 {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    
    unordered_map<int, ordered_set> mp1, mp2;
    
    for (int i = 0; i < n; i++) {
        int a, t, x; cin >> a >> t >> x;
        if (a == 1) {
            mp1[x].insert(t);   
        } else if (a == 2) {
            mp2[x].insert(t);
        } else {
            cout << mp1[x].order_of_key(t + 1) - mp2[x].order_of_key(t + 1) << '\n';
        }
    }
    
}