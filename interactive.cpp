#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int l = 1, r = 1000000;
    while (l <= r) {
        int mid = (l + r + 1) / 2;
        cout << mid << '\n';
        cout << flush;

        string response;
        cin >> response;
        if (response == "<")
            r = mid - 1;
        else
            l = mid;
    }

    cout << "! " << l << '\n';
   	cout << flush;
}
