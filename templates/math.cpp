// MATH UTILITY
ll fact[MAXFAC];

ll mygcd(ll a, ll b) {
    if (a == 0)
        return b;
    return mygcd(b % a, a);
}

// a ^ b mod p
ll powmod(ll a, ll b, ll p){
    if (b == 0) return 1;
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

// modular inverse
ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}
