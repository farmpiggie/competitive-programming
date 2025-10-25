#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

typedef long long ll;


int main() {
    int T;
    cin >> T;

    int N = 1000;

    vector<vector<ll>> A(N+1, vector<ll>(N, 0));
    vector<vector<ll>> B(N+1, vector<ll>(N, 0));
    A[1][0] = 1;
    B[2][1] = 2;

    for(int i = 2; i<N; i++) {
        for(int k = 0; k<i; k++) {
            A[i][k] %= MOD;
            B[i][k] %= MOD;

            B[i+1][k+1] += 2*A[i][k] + B[i][k];
            B[i+1][k] += B[i][k];
            if(k > 0) A[i+1][k-1] += k*A[i][k] + (k-1)*B[i][k];
            A[i+1][k] += (i-k-1)*A[i][k] + (i-k)*B[i][k];
        }
    }

    for(int k = 0; k<N; k++) {
        A[N][k] %= MOD;
        B[N][k] %= MOD;
    }

    for(int i = 0; i<T; i++) {
        int a, b;
        cin >> a >> b;
        cout << (A[a][b] + B[a][b]) % MOD << endl;
    }

}