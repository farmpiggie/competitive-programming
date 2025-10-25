#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<char>> a(3, vector<char>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	bool x_wins = false;
	bool o_wins = false;

	for (int i = 0; i < 3; i++) {
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2]) {
			if (a[i][0] == 'X') x_wins = true;
			else if (a[i][0] == 'O') o_wins = true;
		}
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i]) {
			if (a[0][i] == 'X') x_wins = true;
			else if (a[0][i] == 'O') o_wins = true;
		}
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2]) {
		if (a[0][0] == 'X') x_wins = true;
		else if (a[0][0] == 'O') o_wins = true;
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0]) {
		if (a[0][2] == 'X') x_wins = true;
		else if (a[0][2] == 'O') o_wins = true;
	}

	if (x_wins) cout << "X\n";
	else if (o_wins) cout << "O\n";
	else cout << "DRAW\n";
}
