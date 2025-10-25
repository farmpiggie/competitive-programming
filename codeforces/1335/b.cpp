#include <bits/stdc++.h>
using namespace std;
int T, N, A, B;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> A >> B;
        // substrings of length A, length B
        vector<char> str;
        map<char, int> mp;
        for (int j = 0; j < B; j++) {
            str.push_back('a' + j);
            mp['a' + j]++;
        }
        for (int j = 0; j < (A - B); j++) {
            str.push_back(str[str.size() - 1]);
            mp[str[str.size() - 1]]++;
        }
        for (int j = 0; j < (N - A); j++) {
            mp[str[j]]--;
            if (mp[str[j]] == 0) {
                mp.erase(str[j]);
            }
            if (mp.size() == B) {
                str.push_back(str[str.size() - 1]);
                mp[str[str.size() - 1]]++;
            } else {
                str.push_back(str[j]);
                mp[str[j]]++;
            }
        }
        for (char c : str) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}