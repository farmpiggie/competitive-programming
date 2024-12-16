// inspiration taken from https://github.com/VeryAmazed/My_Comp-Programming_Template/blob/main/Templates/number_theory.cpp, thanks Alan

// extended euclid's
// solves ax + by = gcd(a, b)
// a and b must be positive
ll gcd_ext(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// solves linear diophantine equation (ax + by = c, g = gcd(a, b))
// all solutions for x and y can be expressed as x = x0 + k(b/g) and y = y0 - k(a/g)
// uses gcd_ext
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd_ext(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

const ll MOD = 1e9 + 7;

// calculates a ^ b quickly
ll binpow(ll a, ll b) {
    if (b == 0) return 1;
	ll res = binpow(a, b / 2);
	res = res * res % MOD;
	if (b % 2 == 1) res = res * a % MOD;
	return res;
}

// find mod inverse of a number. Uses eulaer's and fermat's little theorem so only works when 
// mod is prime, if m is prime x^(-1) = x^(m-2)
ll mod_inv(ll a) {
	return binpow(a, MOD - 2);
}

vector<ll> fac = {1};
ll fact(int n) {
	while (fac.size() <= n) {
		fac.push_back(fac.back() * fac.size() % MOD);
	}
	return fac[n];
}

// calculates (nCk) % MOD using modular inverse
ll nCk(ll n, ll k){
    return fact(n) * inv(fact(n)) % MOD * inv(fact(n - k)) % MOD;
}

// Sieve of Eratosthenes
// Primes are in the primes vector
// Also allows for the getting of all prime factors and their powers of some given number a[i] < mxn
// Basically we set primes to themselves and every composite number we store the smallest prime in it's 
// prime factorization then to get the prime factors just use the while loop below
// Basically inductively, for every number that is composed purely of primes less than the current prime, 
// we have a correct prime factorization
// Then for the current prime, the division either takes you to another number that is marked with the 
// current prime, or to a number for which following the path will produce a correct prime factorization
ll sieve[mxn+1] = {0};
vector<ll> primes;
for (ll i = 2; i <= mxn; i++) {
    if (sieve[i] != 0) continue;
    sieve[i] = i;
    primes.pb(i);
    for (ll j = 2*i; j <= mxn; j+=i) {
        if (sieve[j] != 0) continue;
        sieve[j] = i;
    }
}

while (a[i] > 1) {
    a[i] /= sieve[a[i]];
}

// From -is-this-fft-
// Fast integer sqrt that works like a binary search, i.e. O(logn)
ll int_sqrt (ll x) {
  ll ans = 0;
  for (ll k = (ll)1 << 31; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}



