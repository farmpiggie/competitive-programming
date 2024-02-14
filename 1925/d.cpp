#include <bits/stdc++.h>
using namespace std;

#define i128 __int128
#define ll long long

#define MOD (ll) (1e9 + 7)

// __int128 read() {
//     __int128 x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }
//     return x * f;
// }

// void print(__int128 x) {
//     if (x < 0) {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9) print(x / 10);
//     putchar(x % 10 + '0');
// }

std::ostream& operator << (std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value<0?-value:value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            -- d;
            *d = "0123456789"[tmp%10];
            tmp/=10;
        }while(tmp!=0);
        if(value<0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer)-d;
        if (dest.rdbuf()->sputn(d,len)!=len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 read(ll a) {
	string s = to_string(a);
    __int128 x = 0, f = 1;
    for (int i = 0; i < s.length(); i++) {
    	x = x * 10 + (s[i] - '0');
    }
    return x;
}

i128 inv(i128 a) {
  a %= MOD;
  if (a < 0) a += MOD;
  i128 b = MOD, u = 0, v = 1;
  while (a) {
    ll q = b / a;
    b -= q * a; swap(a, b);
    u -= q * v; swap(u, v);
  }
  assert(b == 1); // also why assert here?
  if (u < 0) u += MOD;
  return u;
}

i128 mygcd(i128 a, i128 b) {
	if (a == 0)
        return b;
    return mygcd(b % a, a);
}

int t;
ll n, m, k;

void solve() {
	cin >> n >> m >> k;
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		sum += c;
	}

	i128 p = 0, q = 0;
	i128 i_k = read(k), i_n = read(n), i_m = read(m), i_sum = read(sum);
	p += i_k * i_n * (i_n - 1) / 2 * i_sum + (i_k - 1) * (i_k) / 2 * i_m;
	q = i_n * (i_n - 1) / 2;
	q *= q;

	// cout << p << " " << q << '\n';
	// cout << (p / q) << '\n';

	i128 divisor = mygcd(p, q);

	p /= divisor;
	q /= divisor;

	i128 q_inverse = inv(q);

	p = (p * q_inverse) % MOD;

	cout << p << '\n';



}

int main() {
	cin >> t;
	while (t--) solve();
}