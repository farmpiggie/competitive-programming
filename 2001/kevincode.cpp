#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int MAXN = 1e4 + 1;

vector<int> factors[MAXN];

int main() {
    // precompute factors
    for (int i = 2; i < MAXN; i++) 
        for (int j = 1; j * i < MAXN; j++) 
            factors[j * i].push_back(i);
        
    
    // input: one number n (length of list), followed by n numbers
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    // sort elements in non-increasing order
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    // algo: if number is in set, we found our answer
    // otherwise, insert all factors of this number into our set
    // this way, if a number is in the set, it is a factor of a previous (larger) number
    unordered_set<int> s;
    for (int num : a) {
        if (s.find(num) != s.end()) {
            cout << num << '\n';
            break;
        }
        for (int fac : factors[num]) s.insert(fac);
    }
    
    return 0;
}