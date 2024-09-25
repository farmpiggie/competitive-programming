#include <bits/stdc++.h>
using namespace std;

 
using cd = complex<double>;
const double PI = acos(-1);

#define ll long long

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
 
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, x; cin >> n >> x;
	vector<int> a(n);
	vector<int> pre(n + 1, 0);
	for (int& x : a) cin >> x;
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + (a[i] < x);
	}
	vector<ll> occ(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		occ[pre[i]]++;
	}

	// answer for some k = d is sum(r[i] * r[j]) for all i - j = d
	// create reverse of array
	vector<ll> occ_rev(occ);
	reverse(occ_rev.begin(), occ_rev.end());

	vector<ll> p = multiply(occ, occ_rev);
	
	vector<int> ans;
	int l = 0;
	ll cnt = 0, len;
	for (int i = 0; i < n; i++) {
		if (a[i] < x) {
			len = i - l;
			cnt += len * (len + 1) / 2;
			l = i + 1;
		}
	}
	len = (n - 1 - l + 1);
	cnt += len * (len + 1) / 2;
	cout << cnt << " ";
	for (int i = 1; i <= n; i++) {
		cout << p[n + i] << " ";
	}
	cout << '\n';
	
	return 0;
}