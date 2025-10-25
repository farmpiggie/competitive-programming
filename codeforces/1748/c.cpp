// if only the first number is zero, a_i should be whatever value that can create the most amount of psums to equal zero
// if the middle number is zero, a_i should be whatever value that can do the most of one of two things: either create ONE psum for psum[i], or try to create multiple multiples psums of 0 from i + 1 onwards
// if there are two numbers that are zero, then a_i should focus on psum[i] to psum[j - 1], while a_j can focus on psum[j] to psum[n - 1]
 
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
using namespace std;
int main() {
	// ifstream cin("zerosumprefixes.in");
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		vector<long long> psum(n);
		psum[0] = arr[0];

		for (int i = 1; i < n; i++) {
			psum[i] = psum[i - 1] + arr[i];
		}
		
		int ans = 0;
		int count = 1;

		vector<map<long long, int> > temp(n);
		int index = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (temp[index].find(psum[i]) == temp[index].end()) temp[index][psum[i]] = 1;
			else temp[index][psum[i]]++;
			count = max(count, temp[index][psum[i]]);
			if (arr[i] == 0) {
				ans += count;
				index++;
				count = 1;
			}
		}
		int i = 0;
		while (i < n && arr[i] != 0) {
			if (psum[i] == 0) {
				ans++;
			}
			i++;
		}

		cout << ans << endl;



	}
	return 0;
}