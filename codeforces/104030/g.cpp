#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());


    vector<vector<double>> dp(n + 1, vector<double>(2 * n + 1));
    dp[0][n] = 1; //impl note: using n for 0 and then adjusting becasue of funny negative things
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2*n; j++)
        {
            if (j == 0)
            {
                dp[i + 1][j] = dp[i][j + 1] * (1 - a[i]); //miss this Q
            } else if (j == 2 * n)
            {
                dp[i + 1][j] = dp[i][j - 1] * a[i]; //get this Q
            } else
            {
                dp[i + 1][j] = dp[i][j-1] * a[i] + dp[i][j+1] * (1 - a[i]); //miss and lose 1 pt or get it and win 1 pt
            }
        }
        double cnt = 0;
        for (int j = 2 * n; j >= n + k; j--)
        {
            cnt += dp[i + 1][j];
        }
        ans = max(ans, cnt);
    }

    cout << fixed << setprecision(7) << ans << "\n";

}