//
#include <bits/stdc++.h>
using namespace std;

int dp[100005][20];

bool cmp (string x, string y) //checks if number represented by x is less than num represented by y
{
    if (x == y)
    {
        return 0;
    }
    if (x.size() < y.size())
    {
        return 1;
    } else if (y.size() < x.size())
    {
        return 0;
    } else if (x < y)
    {
        return 1;
    }
    return 0;
}

int N, L;

/*
 * transition:
 *   from dp[i][j]:
 *      calculate substring from (i, i+j-1) and find value
 *      try adding digits on the left until > value, do a transition for each one
 */

int main() {

    string x, y;
    cin >> x >> y;

    N = x.length();
    L = y.length();
    
    if (x == "0" || N < L)
    {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i<=N; i++) {
        for(int j = 0; j<=L; j++) {
            dp[i][j] = 2*N;
        }
    }

    // base case: all numbers from the end such that <= B
    for(int i = 1; i<=L; i++) {
        //~ cout << x.substr(N-i,i) << " " << cmp(y, x.substr(N-i, i)) << "\n";
        if(cmp(y, x.substr(N-i, i))) break;
        if(x[N-i] == '0') continue;
        dp[N-i][i] = 0;
    }

    string temp;
    for(int i = N-1; i>=0; i--) {
        for(int j = 1; j<=L; j++) {
            if(i+j > N) break;
            if(dp[i][j] == 2*N) continue;
            temp = x.substr(i, j);
            for(int k = 1; k<=L; k++) {
                if(i-k < 0) break;
                if(cmp(temp, x.substr(i-k, k))) break;
                if(x[i-k] == '0') continue;
                dp[i-k][k] = min(dp[i-k][k], dp[i][j]+1);
                // cout << "try: " << i << " " << i+j-1 << " to " << i-k << " " << i-1 << endl;
            }
        }
    }
/*
    for(int i = 0; i<=N; i++) {
        for(int j = 0; j<=L; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
*/
    int ans = 2*N;
    for(int i = 0; i<=L; i++) {
        ans = min(ans, dp[0][i]);
    }

    if(ans == 2*N) cout << "NO WAY" << endl;
    else cout << ans << endl;

}
