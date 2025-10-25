#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef uint64_t ull;
struct H {
	ull x; H(ull x = 0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (ll) 1e11 + 3;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str): ha((int) str.size() + 1), pw(ha) {
		pw[0] = 1;
		for (int i = 0; i < str.size(); i++) {
			ha[i + 1] = ha[i] * C + str[i];
			pw[i + 1] = pw[i] * C;
		}
	}
	H hashInterval(int a, int b) { // hash[a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

H hashString(string& s) {H h{}; for (char c : s) h = h * C + c; return h; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b; cin >> a >> b;
	int n = (int) a.length();
	if (a == b) {
		cout << "0\n";
		return 0;
	}
	string t = a + a;
	H hash_b = hashString(b);
	HashInterval hash_t(t);
	bool works = false;
	for (int i = 0; i < n; i++) {
		if (hash_t.hashInterval(i, i + n) == hash_b) {
			works = true;
			break;
		}
	}
	cout << (works ? 1 : -1) << '\n';
}








	