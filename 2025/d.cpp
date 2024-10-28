/*
dp[i][j] = # of checks passed with entries 0...i given strength = j

if i is a strength check
dp[i][j] = dp[i - 1][j] + 1 for all j >= |r_i|

if i is an intelligence check
dp[i][j] = dp[i - 1][j] + 1 for all sum[i] - j >= |r_i|

otherwise
dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) // adding one pt, so this should only affect a value dp[i - 1] is not currently i

runtime should be O(n * log(m)) + m^2 log m

*/

#include <bits/stdc++.h>
using namespace std;

template <class T, class U> 
struct Lazy_Seg_T{
	// modify the default value of the lazy array based on what is needed
	const U LAZY_DEFAULT = 0;
	
	// modify the default value of the seg tree
	const T INIT_DEFAULT = 0;
	
	vector<T> st;
	vector<U> lazy;
	int size;
	int orig_size;
	
	Lazy_Seg_T(int n, vector<T>& in){
		size = n;
		orig_size = n;
		cout << "size: " << size << endl;
		while((size&(size-1))){
			size++;
		}
		
		st.assign(2*size, INIT_DEFAULT);
		lazy.assign(2*size, LAZY_DEFAULT);
		for(int i = 0; i < in.size(); i++){
			int pos = i+size;
			st[pos] = in[i];
			for(pos/=2; pos >= 1; pos/=2){
				//change to query comb
				st[pos] = query_comb(st[left(pos)], st[right(pos)]);
			}
		}
	}
	
	Lazy_Seg_T(int n){
		size = n;
		orig_size = n;
		while((size&(size-1))){
			size++;
		}
		st.assign(2*size, INIT_DEFAULT);
		lazy.assign(2*size, LAZY_DEFAULT);
		
	}
	
	// change depending on how you want to combine for queries (i.e. min query, sum)
	// Template ver is for summing
	T query_comb(T a, T b){
		return max(a, b);
	}

	// change depending on how you want to combine for updates (i.e. add to a range)
	// template is for summing
	U update_comb(U a, U b){
		return a + b; // addition
	}
	
	// helper
	int left(int p) {
		return (p << 1);
	}
	
	// helper
	int right(int p) {
		return (p << 1) + 1;
	}
	
	void push(int p, int L, int R) {
		
		if(lazy[p] != LAZY_DEFAULT){
			// change depending on what your query combine is
			// i.e. for min query, replace with st[p] = st[p] + lazy[p], since all values in the range will grow by lazy[p]
			// default is for summing
			st[p] = st[p] + lazy[p];
			
			if(L != R) {
				lazy[left(p)] = update_comb(lazy[left(p)], lazy[p]);
				
				lazy[right(p)] = update_comb(lazy[right(p)], lazy[p]);
			}
			lazy[p] = LAZY_DEFAULT;
		}
	}
	
	// for range/point updates (point updates i == j)
	// takes twice as long as normal point update seg tree, but same time complexity
	void update(int p, int L, int R, int i, int j, U val) {
		push(p, L, R);
		// completely outside the segment
		if(i > R || j < L) return;
		// fully inside the segment
		if(L >= i && R <= j) {
			
			lazy[p] = val;
			
			push(p, L, R);
			return;
		}
		// half in half out of segment
		update(left(p), L, (L + R)/2, i, j, val);
		update(right(p), (L + R)/2 + 1, R, i, j, val);
		// change to query combine
		st[p] = query_comb(st[left(p)], st[right(p)]);
	}
	
	T query(int p, int L, int R, int i, int j) {
		push(p, L, R);
		// completely outside the segment
		// Default always loses in comb()
		if(i > R || j < L) return INIT_DEFAULT;
		// fully inside the segment
		if(L >= i && R <= j) return st[p];
		// change to query combine
		return query_comb(query(left(p), L, (L + R)/2, i, j), query(right(p), (L + R)/2 + 1, R, i, j));
	}
	
	// For debugging purposes
	void toString(){
		cout << size << endl;
		for (int i = 0; i < orig_size; i++) {
			cout << query(1, 0, orig_size - 1, i, i) << " ";
		}
		cout << endl;
		cout << query(1, 0, orig_size - 1, 0, orig_size - 1) << endl;
		cout << endl;
	}
};

// queries are [start, end)
int main() {
	int t; t = 1;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> points(n, 0);
		vector<int> arr(n);
		for (int& x : arr) cin >> x;

		points[0] = (arr[0] == 0);
		for (int i = 1; i < n; i++) {
			points[i] = points[i - 1] + (arr[i] == 0);
		}
		// cout << "m: " << m << endl;

		// Lazy_Seg_T<int, int> st(m + 1);
		vector<int> push(m + 2, 0);
		vector<int> dp(m + 1, 0);

		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				vector<int> ndp(m + 1, 0);
				vector<int> psum(m + 2, 0);
				psum[0] = push[0];
				push[0] = 0;
				for (int i = 1; i < m + 2; i++) {
					psum[i] = psum[i - 1] + push[i];
					push[i] = 0;
				}

				for (int i = 0; i <= m; i++) {
					dp[i] += psum[i]; // push lazy updates
				}

				ndp[0] = dp[0];
				for (int i = 1; i <= m; i++) {
					ndp[i] = max(dp[i], dp[i - 1]);
				}
				dp = ndp;
			} else if (arr[i] < 0) { // strength check
				arr[i] *= -1;
				if (arr[i] > points[i]) continue;
				push[arr[i]]++;
				push[min(points[i], m) + 1]--;
				// st.update(1, 0, m, arr[i], min(psum[i], m), 1); // add 1 to these values
			} else { // intelligence check
				int intelligence = points[i] - arr[i];
				if (intelligence < 0) continue;
				push[0]++;
				// cout << intelligence << " " << points[i] << '\n';
				push[min(intelligence, points[i]) + 1]--;
				//st.update(1, 0, m, 0, min(intelligence, psum[i]), 1);
			}
			// cout << "dp: ";
			// for (int i = 0; i <= m; i++) cout << dp[i] << " ";
			// cout << endl;
			// cout << "psum: ";
			// for (int i = 0; i <= m; i++) cout << push[i] << " ";
			// cout << endl;

		}


		vector<int> psum(m + 2, 0);
		psum[0] = push[0];
		push[0] = 0;
		for (int i = 1; i < m + 2; i++) {
			psum[i] = psum[i - 1] + push[i];
			push[i] = 0;
		}

		for (int i = 0; i <= m; i++) {
			dp[i] += psum[i]; // push lazy updates
		}

		int ans = 0;
		for (int i = 0; i <= m; i++) ans = max(ans, dp[i]);


		// for (int i = 0; i < m; i++) mx = max(mx, st.query(1, 0, m, i, i));
		cout << ans << '\n';
		//cout << mx << endl;
	}
	return 0;
}
