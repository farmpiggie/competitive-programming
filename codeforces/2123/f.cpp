// deepseek test
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
vector<int> global_primes;
vector<bool> is_prime_vector;

void sieve() {
    is_prime_vector.resize(MAX_N+1, true);
    is_prime_vector[0] = is_prime_vector[1] = false;
    for (int i=2; i<=MAX_N; i++) {
        if (is_prime_vector[i]) {
            global_primes.push_back(i);
            if ((long long)i*i <= MAX_N) {
                for (int j=i*i; j<=MAX_N; j+=i) {
                    is_prime_vector[j] = false;
                }
            }
        }
    }
}

int main() {
    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n+1, 0);

        p[1] = 1;

        vector<int> primes_list;
        for (int prime : global_primes) {
            if (prime > n) 
                break;
            if (prime > n/2) {
                p[prime] = prime;
            } else {
                primes_list.push_back(prime);
            }
        }

        sort(primes_list.rbegin(), primes_list.rend());

        for (int p_val : primes_list) {
            vector<int> L;
            for (int m = p_val; m <= n; m += p_val) {
                if (p[m] == 0) {
                    L.push_back(m);
                }
            }
            int k = L.size();
            if (k < 2) 
                continue;

            if (k % 2 == 0) {
                for (int i=0; i<k; i+=2) {
                    p[L[i]] = L[i+1];
                    p[L[i+1]] = L[i];
                }
            } else {
                p[L[k-1]] = L[k-3];
                p[L[k-3]] = L[k-2];
                p[L[k-2]] = L[k-1];
                for (int i=0; i<k-3; i+=2) {
                    p[L[i]] = L[i+1];
                    p[L[i+1]] = L[i];
                }
            }
        }

        for (int i=1; i<=n; i++) {
            cout << p[i];
            if (i < n) 
                cout << " ";
            else 
                cout << "\n";
        }
    }
    return 0;
}