#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int mx = 0;
        vector<int> arr;
        multiset<int> a, b;
        set<int> yeet;
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            arr.push_back(a);
            b.insert(a);
            yeet.insert(a);
        }
        vector<int> pogchamp;
        int asiz = 0;
        int bsiz = yeet.size();
//        cout << yeet.size() << endl;
        for (int j = 0; j < N - 1; j++) {
            b.erase(b.find(arr[j]));
            if (b.find(arr[j]) == b.end()) {
                bsiz--;
            }
            if (a.find(arr[j]) == a.end()) {
                asiz++;
            }
            a.insert(arr[j]);
//            cout << asiz << " omegalul " << bsiz << endl;
//            cout << *(--a.end()) << " yeet " << *(--b.end()) << endl;
            if (asiz == *(--a.end()) && *(--a.end()) == j + 1 && bsiz == *(--b.end()) && bsiz == N - (j + 1)) {
                pogchamp.push_back(j + 1);
            }
        }
        cout << pogchamp.size();
        for (int val : pogchamp) {
            cout << endl << val << " " << N - val;
        }
        cout << endl;
    }
    return 0;
}