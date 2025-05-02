#include "bits/stdc++.h"
using namespace std;

using i64 = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int MOD = 1e9 + 7;

int compute_p_min(int n, int l) {
    int low = 1, high = n + 1;
    while (low < high) {
        int mid = (low + high) / 2;
        i64 m_power = 1;
        bool overflow = false;
        for (int i = 0; i < l; i++) {
            m_power *= mid;
            if (m_power > n) {
                overflow = true;
                break;
            }
        }
        if (overflow) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int compute_p_max(int n, int l) {
    int low = 1, high = n;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        i64 m_power = 1;
        bool overflow = false;
        for (int i = 0; i < l - 1; i++) {
            m_power *= mid;
            if (m_power > n) {
                overflow = true;
                break;
            }
        }
        if (overflow) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

i64 sum_floor_div(i64 n, int a, int b) {
    if (a > b) return 0;
    i64 res = 0;
    int q_max = n / a;
    for (int q = q_max; q >= 1; q--) {
        int p_low = max(a, (int)(n / (q + 1)) + 1);
        int p_high = min(b, (int)(n / q));
        if (p_low > p_high) continue;
        res += q * 1LL * (p_high - p_low + 1);
    }
    return res;
}

i64 sum_floor_div_p2(i64 n, int a, int b) {
    if (a > b) return 0;
    i64 res = 0;
    int q_max = n / a;
    for (int q = q_max; q >= 1; q--) {
        int p_low = max(a, (int)(n / (q + 1)) + 1);
        int p_high = min(b, (int)(n / q));
        if (p_low > p_high) continue;
        auto sum_p2 = [](i64 l, i64 r) {
            return (r * (r + 1) * (2 * r + 1) / 6) - ((l - 1) * l * (2 * l - 1) / 6);
        };
        res += q * 1LL * sum_p2(p_low, p_high);
    }
    return res;
}

i64 compute_rev(i64 n, int p) {
    if (n == 0) return 0;
    vector<int> digits;
    i64 temp = n;
    while (temp > 0) {
        digits.push_back(temp % p);
        temp /= p;
    }
    reverse(digits.begin(), digits.end());
    i64 res = 0;
    for (int d : digits) {
        res = res * p + d;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        i64 n, k;
        cin >> n >> k;
        i64 sum = 0;

        i64 min_nk = min(n, k);
        if (min_nk >= 2) {
            int sqrt_n = sqrt(n);
            int p_start = sqrt_n + 1;
            int p_end = min_nk;
            if (p_start <= p_end) {
                i64 sum_p = (p_end * 1LL * (p_end + 1) / 2) - ((p_start - 1LL) * p_start / 2);
                i64 sum_q = sum_floor_div(n, p_start, p_end);
                i64 sum_q_p2 = sum_floor_div_p2(n, p_start, p_end);
                sum = (sum + (n % MOD) * (sum_p % MOD) % MOD + sum_q % MOD - sum_q_p2 % MOD) % MOD;
            }

            for (int l = 3;; l++) {
                int p_min = compute_p_min(n, l);
                int p_max = compute_p_max(n, l);
                int p_start = max(p_min, 2);
                int p_end = min(p_max, (int)min_nk);
                if (p_start > p_end) break;
                for (int p = p_start; p <= p_end; p++) {
                    i64 rev = compute_rev(n, p);
                    sum = (sum + rev) % MOD;
                }
                if (p_max == 0) break;
            }
        }

        i64 lower = max(n + 1, 2LL);
        if (k >= lower) {
            i64 cnt = k - lower + 1;
            sum = (sum + n % MOD * (cnt % MOD)) % MOD;
        }

        sum = (sum % MOD + MOD) % MOD;
        cout << sum << '\n';
    }
}
