// summation sparse table

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 25; // log2(1e7)

int main() {
        int n;
        vector<int> a(n); // the input array
        vector<vector<int>> st(K + 1, vector<int>(N)); // sparse table

        auto merge = [&](int a, int b) {
                return a + b; // TODO: replace said function
        };

        copy(a.begin(), a.end(), st[0]);
        for (int i = 1; i <= K; i++) {
                for (int j = 0; j + (1 << i) < n; i++) {
                        st[i][j] = merge(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
        }

        // sum query from [l, r] in O(log n)
        auto query = [&](int l, int r) {
                long long sum = 0;
                for (int i = K; i >= 0; i--) {
                        if ((1 << i) <= r - l + 1) {
                                sum += st[i][l];
                                l += (1 << i);
                        }
                }
                return sum;
        };

        // min query from [l, r]
        #include <bit>
        auto log2_floor = [&](unsigned long i) {
                return bit_width(i) - 1;
        };

        auto query2 = [&](int l, int r) {
                int i = log2_floor(r - l + 1);
                return min(st[i][l], st[i][r - (1 << i) + 1]);
        };
}


