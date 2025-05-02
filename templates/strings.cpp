#include <bits/stdc++.h>
using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
struct stringhash {
private:
	long long M = 1e9 + 9;
	long long B = uniform_int_distribution<ll>(0, M - 1)(rng);
	vector<long long> pow, p_hash;

public:
	stringhash(const string& s): p_hash(s.size() + 1) {
		pow = {1};
		while (pow.size() <= s.size()) {
			pow.push_back((pow.back() * B) % M);
		}
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

	long long get_hash(int start, int end) {
		long long raw_val = (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
