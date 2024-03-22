#include <bits/stdc++.h>
using namespace std;
static const int DEFAULT = 0;  // Default value, change as necessary

template <class T> 
struct SegTree {
	/** The operation to use for combining two elements. (Must be associative) 
		Used for querying (when the parent combines its two children)
	 */
	 // change as necessary
	T query_comb(T a, T b) { 
		return a + b;
	}
	
	// operation for updating element at the specified index
	// change as necessary
	T update_comb(T a, T b) {
		return b;
	}
	

	vector<T> segtree;
	int len;

	SegTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	
	// look at ASSERTS to see how you should be indexing things
	
	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		// assert(0 <= ind && ind < len);
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = query_comb(segtree[ind], segtree[ind ^ 1]);
		}
	}
	
	/** updates the value at ind to val. */
	void update(int ind, T val) {
		// assert(0 <= ind && ind < len);
		ind += len;
		segtree[ind] = update_comb(segtree[ind], val);
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = query_comb(segtree[ind], segtree[ind ^ 1]);
		}
	}

	/** queries the range [start, end) */
	T query(int start, int end) {
		end++;
		// assert(0 <= start && start < len && 0 < end && end <= len);
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if ((start & 1) != 0) { sum = query_comb(sum, segtree[start++]); }
			if ((end & 1) != 0) { sum = query_comb(sum, segtree[--end]); }
		}
		return sum;
	}
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> x(n), y(n);
        vector<SegTree<int>> st1;
        vector<SegTree<int>> st2;
        st1.assign(30, SegTree<int>(n));
        st2.assign(30, SegTree<int>(n));
        
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
		int q; cin >> q;

        for (int i = 0; i < n; i++) {
            bool matches = true;
            for (int bit = 29; bit >= 0; bit--) {
                int lbit = (x[i] >> bit) & 1;
                int rbit = (y[i] >> bit) & 1;
                if (matches && lbit == rbit) {
                    st1[bit].set(i, lbit);
					// cout << "should be 1: " << st1[bit].query(i, i) << '\n';
                } else {
					matches = false;
					st2[bit].set(i, rbit);
					// cout << "should be " << rbit << ": " << st2[bit].query(i, i) << '\n';
				}
            }
        }

		while (q--) {
			int l, r; cin >> l >> r; l--; r--;
			int ans = 0;
			for (int bit = 29; bit >= 0; bit--) {
				int a = st1[bit].query(l, r);
				int p = st2[bit].query(l, r);
				if ((a > 0 && p > 0) || p >  1) {
					ans |= (1 << (bit + 1)) - 1;
					break;
				} else if ((a > 0 && p == 0) || p == 1) {
					ans |= (1 << bit);
				}
			}
			cout << ans << ' ';
		}
		cout << '\n';



    }
    return 0;
}
