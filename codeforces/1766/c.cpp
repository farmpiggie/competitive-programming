#include <bits/stdc++.h>
using namespace std;

int t, n, j, curr;
vector<vector<char> > board;
bool flag; // found start
// vector<vector<int>> visited;

void solve() {
	cin >> n;
	board.resize(2);
	for (int i = 0; i < 2; i++) {
		board[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}


	// flow is determined when we find first column with only 1 B
	j = 0;
	flag = false;
	while (!flag && j < n) {
		if (!(board[0][j] == 'B' && board[1][j] == 'B')) { // both not b
			flag = true;
			if (board[0][j] == 'B') curr = 0; // start at zero
			else curr = 1;
		} 
		j++;
	}

	// check if certain is possible
	for (; j < n; j++) {
		if (board[0][j] == 'B' && board[1][j] == 'B') {
			curr = !curr; // 1 to 0
		} else if ((curr == 1 && board[0][j] == 'B') || 
				   (curr == 0 && board[1][j] == 'B')) {
			// impossible
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;


	
	board.clear();
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}