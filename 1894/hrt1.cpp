#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
int m, n, arr[MAXN][MAXN] = {{0}};

bool inrange(int x, int y) {
	return x >= 0 && x <= m && y >= 0 && y <= n;
}

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

void floodfill(int x, int y) {
	if (!inrange(x, y)) return;
	if (arr[x][y] == 1 || arr[x][y] == -1) return;
	arr[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];
		floodfill(new_x, new_y);
	}
}

bool solve(int width, int height, vector<vector<int>>& segments) {
	set<int> xs, ys;
	for (const vector<int>& v : segments) {
		xs.insert(v[0]);
		ys.insert(v[1]);
		xs.insert(v[2]);
		ys.insert(v[3]);
	}
	unordered_map<int, int> convert_x, convert_y;
	int x_idx = 1, y_idx = 0;
	for (int coord : xs) {
		convert_x[coord] = x_idx;
		x_idx += 2;
	}
	for (int coord : ys) {
		convert_y[coord] = y_idx;
		y_idx += 2;
	}

	m = x_idx; // m = width, height = n
	if (*(--ys.end()) == height) {
		n = y_idx - 2; // can never reach y_idx - 1, which is the highest one
		// cout << "limited" << endl;
		// cout << y_idx << endl;
		// cout << n << endl;
	} else {
		n = y_idx;
	}

	for (vector<int>& v : segments) {
		int x1 = convert_x[v[0]], x2 = convert_x[v[2]];
		int y1 = convert_y[v[1]], y2 = convert_y[v[3]];

		if (x1 > x2 || y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		if (x1 == x2) {
			for (int j = y1; j <= y2; j++) {
				arr[x1][j] = -1;
			}
		} else {
			for (int i = x1; i <= x2; i++) {
				arr[i][y1] = -1;
			}
		}
	}

	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << arr[i][j] << '\t';
	// 	}
	// 	cout << "boop\n";
	// }

	floodfill(0, 0);

	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << arr[i][j] << '\t';
	// 	}
	// 	cout << "boop2\n";;
	// }

	// the bank is x_idx
	for (int j = 0; j <= n; j++) {
		if (arr[m][j] == 1) return true;
	}

	return false;


	// run floodfill

}

int main() {
	// vector<vector<int>> segments = {{1, 1, 1, 0}, {0, 2, 3, 2}, {2, 3, 2, 4}};
	vector<vector<int>> segments = {{1, 2, 2, 2}, {2, 2, 3, 2}, {0, 2, 1, 2}, {1, 0, 1, 2}, {2, 2, 2, 4}, {1, 2, 1, 3}, {2, 2, 2, 1}};
	// vector<vector<int>> segments = {{6, 3, 6, 0}, {4, 7, 3, 7}, {1, 7, 3, 7}, {4, 10, 3, 10}, {3, 7, 3, 5}, {3, 7, 3, 9}, {5, 12, 5, 4}, {2, 2, 2, 0}, {2, 5, 1, 5}, {1, 5, 1, 7}, {2, 5, 2, 2}, {5, 1, 3, 1}, {0, 5, 1, 5}, {1, 2, 2, 2}, {4, 11, 4, 10}, {4, 8, 4, 10}, {5, 4, 7, 4}, {3, 2, 2, 2}, {1, 9, 3, 9}, {5, 1, 5, 4}, {1, 2, 1, 5}, {2, 6, 2, 5}, {2, 5, 3, 5}, {1, 9, 1, 11}};
	cout << solve(3, 4, segments) << '\n';
	// cout << solve(7, 12, segments) << '\n';
	return 0;
}