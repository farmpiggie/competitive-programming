#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    int ans = 0;
    for(int i = 1; i<=N; i++) {
        int a;
        cin >> a;
        ans = max(ans, a-i);
    }

    cout << ans+1 << endl;

}