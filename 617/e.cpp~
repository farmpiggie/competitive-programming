#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

struct Query {
    int left, right, number;
    
    bool operator<(const Query other) const {
        return right < other.right;
    }
};


const int BLOCK_SIZE = (int) sqrt(1e5);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> pre(n + 1);
    
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] ^ a[i - 1];
    }    
    
    
    vector<vector<Query>> blocks(n / BLOCK_SIZE + 2, vector<Query>());
    
    vector<int> cnt(1 << 20, 0);
    for (int i = 0; i < m; i++) {
        int left, right; cin >> left >> right;
        left--; right++;
        blocks[left / BLOCK_SIZE].push_back({left, right, i});
    }
    for (auto &i : blocks) {
        sort(i.begin(), i.end());
    }
    
    ll result = 0;    
    vector<ll> answer(m);
    for (int i = 0; i < blocks.size(); i++) {
        int left, right;
        left = right = i * BLOCK_SIZE;
        for (auto &q: blocks[i]) {
            while (right < q.right) {
                result += cnt[pre[right] ^ k];
                cnt[pre[right]]++;
                right++;
            }
            while (left <  q.left) {
                cnt[pre[left]]--;
                result -= cnt[pre[left] ^ k];
                left++;
            }
            while (left > q.left) {
                left--;
                result += cnt[pre[left] ^ k];
                cnt[pre[left]]++;
            }
            answer[q.number] = result;
        }
        for (int j = left; j < right; j++) {
            cnt[pre[j]]--;
            result -= cnt[pre[j] ^ k];
        }
    }

    for (auto i : answer) {
        cout << i << '\n';
    }
    
    
    return 0;
}
