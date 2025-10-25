#include <bits/stdc++.h>
using namespace std;
int T;
int sudoku[9][9];
int main() {
    cin >> T;
    for (int x = 0; x < T; x++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c; cin >> c;
                sudoku[i][j] = c - '0';

            }
            cout << endl;
        }


        pair<int, int> pairs[9] = {
                {0, 0},
                {3, 1},
                {6, 2},
                {1, 3},
                {4, 4},
                {7, 5},
                {2, 6},
                {5, 7},
                {8, 8}
        };
        for (auto p : pairs) {
            sudoku[p.first][p.second] = sudoku[p.first][p.second] % 9 + 1;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j];
            }
            cout << endl;
        }

    }

}