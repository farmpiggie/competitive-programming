/*
take the smallest element c_m.
assume we don't take c_m, and go about our way from months 1...m - 1
if we take any element from 1...m - 1, we could have just take c_m.
therefore we can greedily take the smallest elements

*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>
#define pii pair<int, int>

int main() {
	int t; cin >> t;
	while (t--) {
		int m, x; cin >> m >> x;
		vector<int> c(m);
		for (int& x : c) cin >> x;
	
		priority_queue<int> pq;
		
		int money = 0;
		for (int i : c) {
			if (money >= i) {
				pq.push(i);
				money -= i;
			} else if (pq.size() > 0 && pq.top() > i) {
				money += pq.top() - i; pq.pop();
				pq.push(i);
			}
			money += x;
		}
		cout << pq.size() << '\n';
			
	}
	return 0;
}
