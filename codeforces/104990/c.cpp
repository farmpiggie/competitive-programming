#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;

const int MAXN = 105;
const int MOD = 1e9 + 7;

struct Mat {
    vector<vector<int>> m;
    int x, y;
    Mat (int _x, int _y){
        x = _x;
        y = _y;
        m = vector<vector<int>> (x, vector<int> (y));
    }
};

Mat id (Mat a){
    Mat res = Mat(a.x, a.y);
    
    for (int i = 0; i < res.x; i++)
    {
        for (int j = 0; j < res.y; j++)
        {
            if (i == j)
            {
                res.m[i][j] = 1;
            } else
            {
                res.m[i][j] = 0;
            }
        }
    }
    return res;
}

Mat mul (Mat a, Mat b){
    Mat res = Mat(a.x, b.y);
    
    for (int i = 0; i < res.x; i++)
    {
        for (int j = 0; j < res.y; j++)
        {
            for (int k = 0; k < a.y; k++)
            {
                res.m[i][j] += a.m[i][k] * b.m[k][j];
                res.m[i][j] %= MOD;
            }
        }
    }
    return res;
}

Mat add (Mat a, Mat b){
    Mat res = Mat(a.x, a.y);
    
    for (int i = 0; i < res.x; i++)
    {
        for (int j = 0; j < res.y; j++)
        {
            res.m[i][j] = (a.m[i][j] + b.m[i][j]) % MOD;
        }
    }
    return res;
}

Mat exp (Mat a, ll b, int m)
{
    Mat res = Mat(m,m);
    for (int i = 0; i < m; i++)
    {
        res.m[i][i] = 1;
    }
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    Mat dp = Mat(m, m);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (gcd(i + 1, j + 1) == 1)
            {
                dp.m[i][j] = 1;
            }
        }
    }
    
    dp = exp(dp, n, m);
    ll ans = 0;
    
    for (int i = 0; i < m; i++)
    {
        ans = (ans + dp.m[0][i]) % MOD;
    }
    cout << ans << "\n";   
 return 0;
}



