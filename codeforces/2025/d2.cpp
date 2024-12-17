/*
dp[i][j] = # of checks passed with entries 0...i given strength = j

if i is a strength check
dp[i][j] = dp[i - 1][j] + 1 for all j >= |r_i|

if i is an intelligence check
dp[i][j] = dp[i - 1][j] + 1 for all sum[i] - j >= |r_i|

otherwise
dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) // adding one pt, so this should only affect a value dp[i - 1] is not currently i

// only need to do this 5000 times.

*/

// Taken from https://github.com/VeryAmazed/My_Comp-Programming_Template/blob/main/Templates/point_update.cpp
// initially from USACO.guide

#include <bits/stdc++.h>
using namespace std;

// monkey8's Lazy Prop Seg Tree Template
// Modified by Me
// Modified again to to allow for different updates and query types

// p is curent pos in array, always start at 1
// L, R is current bounds of the segment, always start at 0, size-1
// i, j is the range you are querying, both inclusive
// default version of this tempalte is for adding

// Modify to be Templated, w/ 2 different types, one for vector and one for lazy, like below

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
		vector<int> psum(n + 1, 0);
		vector<int> arr(n);
		for (int& x : arr) cin >> x;

		for (int i = 1; i <= n; i++) {
			psum[i] = psum[i - 1] + (arr[i - 1] == 0 ? 1 : 0);
		}
		// cout << "m: " << m << endl;

		Lazy_Seg_T<int, int> st(m + 1);
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				vector<int> values;
				for (int j = 1; j <= psum[i + 1]; j++) {
					values.push_back(st.query(1, 0, m, j - 1, j)); // i - 1, i
				}
				for (int j = 1; j <= psum[i + 1]; j++) {
					st.update(1, 0, m, j, j, values[j - 1] - st.query(1, 0, m, j, j)); // update the difference
				}
			} else if (arr[i] < 0) { // strength check
				arr[i] *= -1;
				if (arr[i] > psum[i + 1]) continue;
				st.update(1, 0, m, arr[i], min(psum[i + 1], m), 1); // add 1 to these values
			} else { // intelligence check
				// psum[i] - j >= arr[i]
				int intelligence = psum[i + 1] - arr[i];
				// cout << "intelligence: " << intelligence << endl;
				if (intelligence < 0) continue;
				// cout << 0 << " " << intelligence	 << endl;

				st.update(1, 0, m, 0, min(intelligence, psum[i + 1]), 1);
			}
			cout << "dp: ";
			st.toString();
		}
		int mx = 0;
		// for (int i = 0; i < m; i++) mx = max(mx, st.query(1, 0, m, i, i));
		cout << st.query(1, 0, m, 0, m) << '\n';
		//cout << mx << endl;
	}
	return 0;
}