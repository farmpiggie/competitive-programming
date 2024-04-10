#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int hh = stoi(s.substr(0, 2));
		int mm = stoi(s.substr(3, 2));
		int total = hh * 60 + mm;
		string zone;
		if (total < 12 * 60) {
			zone = "AM";
		} else {
			zone = "PM";
		}

		if (hh > 12) hh -= 12;
		if (hh == 0) hh = 12;
		string hour, minute;
		if (hh < 10) hour = "0" + to_string(hh);
		else hour = to_string(hh);
		if (mm < 10) minute = "0" + to_string(mm);
		else minute = to_string(mm);

		cout << hour << ":" << minute << " " << zone << '\n';
	}
}
