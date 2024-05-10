// can we calculate len[i] = length of longest LCP that starts at i?
// can use poly hash...but do i want to do this?
// idea: binary search on answer. try to match length as soon as possible

#include <bits/stdc++.h>
using namespace std;

#define ll long long



class HashedString {
  private:
	// change M and B if you want
	static const long long M = 1e9 + 9;

	static const long long B;

	// pow[i] contains B^i % M
	static vector<long long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long long> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

	long long get_hash(int start, int end) {
		//start++;
		//end++;
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);


int main() {
	int t; cin >> t;
	while (t--) {
		int n, l, r; cin >> n >> l >> r;
		string s; cin >> s;

		HashedString hash_str(s);
		
//		cout << "Test\n";
//		cout << to_string(hash_str.get_hash(0, 0) == hash_str.get_hash(1, 1)) << '\n';
//		cout << to_string(hash_str.get_hash(1, 1) == hash_str.get_hash(2, 2)) << '\n';
//		cout << to_string(hash_str.get_hash(0, 0)) << '\n';
//		cout << to_string(hash_str.get_hash(1, 1)) << '\n';
//		cout << to_string(hash_str.get_hash(2, 2)) << '\n';
		int best = 0;
		int lo = 1, hi = n;
		while (lo <= hi) {
			int cur = 0;
			int mi = lo + (hi - lo) / 2;
			int i = 0;
			while (i + mi - 1 < n) {
				if (hash_str.get_hash(0, mi - 1) == hash_str.get_hash(i, i + mi - 1)) {
					cur++;
					i += mi;
				} else i++;
			}
			if (cur >= l) { // only compare to l
				best = max(best, mi);
				lo = mi + 1;
			} else {
				hi = mi - 1;
			}
		}
		cout << best << '\n';

	}
	return 0;
}
