/*
operation: given some i != j, given a[i] >= a[j], you can change a[i] := a[i] - a[j] or a[i] := a[i] + a[j]
you can do this operation any number of times
maximize the MEX(k) of the array
 
MEX(k) = kth non-negative integer that is absent in the array
maximizing MEX(k) means that optimally, we can get all a[i] to be < n + k - 1
MEX(1) is maximized if we keep all #s as such: [0....n - 1] -> n
MEX(2) is maximized if we keep all #s as such: [0...[one gap]... n] -> n + 1
MEX(x) is maximized if we keep all #s as such: [0...[x - 1 missing]...n + x - 2] -> n + x - 1
 
we can always do this if we can get any value a[i] == 1.
 
what if we cannot do this?
4 5
2 2 2 16 -> 8, so we should have [0...[4 gaps]...7], 8
0 2 2 16
0 2 2 14
0 2 2 10
0 2 2 8
0 2 4 6
 
let g = gcd(a[1...n])
note in this case: we cannot create any number x where x % g != 0
we should be able to count this.
 
can we make all #s from 0, g, ..., gcd * (n - 1)?
i believe so.
given an array [x, y] where g = gcd(x, y)
 
[a * g, b * g] where a = x / g, b = y / g. (a, b) are coprime.
we can always use euclidean algo to get to 1.
 
therefore:
 given g = gcd(a1...an)
for any array a, MEX(K) equals:
gaps = (n - 1) * (g - 2).
if (k <= gaps) ans = g * ((k - 1) / gaps) + (k - 1) % gaps
else ans = g * (n - 1) + 1 + (k - gaps)
*/

// 0...6
// 1 2 3 4 5
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n); for (ll& x : a) cin >> x;
        
        if (n == 1) {
            if (k <= a[0]) cout << k - 1 << endl;
            else cout << k << endl;
            continue;
        }
        
        
        ll g = a[0];
        for (int i = 1; i < n; i++) g = gcd(g, a[i]);
        
        ll gaps = (n - 1) * (g - 1); // 1 * 5
        
        if (k <= gaps) { // g * 0 + 5
            cout << g * ((k - 1) / (g - 1)) + ((k - 1) % (g - 1)) + 1 << '\n';
        } else {
            cout << g * (n - 1) + (k - gaps) << '\n';
        }
        
    }
    return 0;
}
