#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

// seg tree to query HLD
template <class T> 
struct SegTree {
	/** The operation to use for combining two elements. (Must be associative) 
		Used for querying (when the parent combines its two children)
	 */
	 // change as necessary
	T query_comb(T a, T b) { 
		return max(a, b);
	}
	
	// operation for updating element at the specified index
	// change as necessary
	T update_comb(T a, T b) {
		return b; // set to b
	}
	
	const T DEFAULT = 0;  // Default value, change as necessary

	vector<T> segtree;
	int len;

	SegTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	vector<pair<pii, int>> edges;
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

	/** queries the range [start, end] */
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

// HLD TEMPLATE
vector<int> parent, depth, heavy, head, pos;
int cur_pos;

// compute depths of tree & heavy edges
int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

// decomposes tree into heavy paths
void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    // cout << "position of node " << v << " is " << pos[v] << '\n';
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

// runs HLD on a tree
void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

// query along a path from a to b
// uses SegTree methods (st.DEFAULT, st.query_comb)
int query(int a, int b, SegTree<int>& st) {
    int res = st.DEFAULT;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = st.query(pos[head[b]], pos[b]);
        // TODO: replace operation as needed
        res = st.query_comb(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    // for edges, dont include the last node on the top (if edge weight assigned to node w/ greater depth)
    // would use pos[a] + 1 instead
    int last_heavy_path_max = st.query(pos[a], pos[b]);
    // TODO: replace operation as needed
    res = st.query_comb(res, last_heavy_path_max);
    return res;
}

