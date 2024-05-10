// number of times the length of substring would change is at most log(n)?
// run previous solution log(n) times
#include <bits/stdc++.h>
using namespace std;

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
		
	}
	return 0;
}
