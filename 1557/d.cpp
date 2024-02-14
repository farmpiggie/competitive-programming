#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);


template <class T, class U> 
struct Lazy_Seg_T{
	// modify the default value of the lazy array based on what is needed
	const U LAZY_DEFAULT = {0, -1};
	
	// modify the default value of the seg tree
	const T INIT_DEFAULT = {0, -1};
	
	vector<T> st;
	vector<U> lazy;
	int size;
	
	Lazy_Seg_T(int n, vector<T>& in){
		size = n;
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
		while((size&(size-1))){
			size++;
		}
		st.assign(2*size, INIT_DEFAULT);
		lazy.assign(2*size, LAZY_DEFAULT);
		
	}
	
	// change depending on how you want to combine for queries (i.e. min query, sum)
	// Template ver is for summing
	T query_comb(T a, T b){
		if (a.first > b.first) {
			return a;
		} else {
			return b;
		}
	}
	// change depending on how you want to combine for updates (i.e. add to a range)
	// template is for summing
	U update_comb(U a, U b){
		if (a.first > b.first) {
			return a;
		} else {
			return b;
		}
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
			// st[p] = max(st[p], lazy[p]);
			if (lazy[p].first > st[p].first) {
				st[p] = lazy[p];
			}
			//st[p] += lazy[p] * (R - L + 1);
			
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
		cout << endl;
		for(int i = 0; i < 2*size; i++){
			cout << st[i].first << " " << st[i].second << " ";
		}
		cout << endl;
		for(int i = 0; i < 2*size; i++){
			cout << lazy[i].first << " " << lazy[i].second << " ";
		}
		cout << endl;
	}
};

#define pii pair<int, int>
#define MAXN 300005
#define ll long long

int n, m;
vector<pii> arr[MAXN];

int main() {
	send help

	vector<int> val;
	unordered_map<int, int> mp;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int j, l, r;
		cin >> j >> l >> r;
		arr[j - 1].push_back({l, r});
		val.push_back(l);
		val.push_back(r);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());


	int temp = 0;
	for (int v : val) {
		mp[v] = temp++;
	}

	for (int i = 0; i < n; i++) {
		for (pii& p : arr[i]) {
			p.first = mp[p.first];
			p.second = mp[p.second];
		}
	}

	vector<int> prev(n + 1);
	Lazy_Seg_T<pii, pii> st(mp.size() + 1);

	for (int i = 0; i < n; i++) {
		pii val = {0, -1};
		for (pii& p : arr[i]) {
			pii p2 = st.query(1, 0, st.size - 1, p.first, p.second);
			if (val.first < p2.first) {
				val = p2;
			}
		}

		prev[i] = val.second;

		for (pii& p : arr[i]) {
			st.update(1, 0, st.size - 1, p.first, p.second, {1 + val.first, i});
		}
		// st.toString();
	}

	pii q = st.query(1, 0, st.size - 1, 0, mp.size());

	cout << (n - q.first) << '\n';

	int t = q.second;
	vector<int> used;
	while (t != -1) {
		used.push_back(t);
		t = prev[t];
	}

	int j = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (j < used.size() && used[j] == i) {
			j++;
		} else {
			cout << (i + 1) << ' ';
		}
	}	
	if (used.size() < n) cout << '\n';

	return 0;
}