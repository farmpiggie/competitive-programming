/*
 * partition string into substrings of alternating letters
 * strings of length 1 & 2 are handled first
 * for strings of length >= 3, split into two groups:
 *	groups of odd length: [start letter] + (len - 1) / 2 of [AB]/[BA] (mix is fine)
 *	groups of even length:
 *		if the substring starts with A:
 *			len / 2 of [AB] 
 *			OR
 *			1 [A], 1 [B], x of [AB], (len / 2 - x - 1) of [BA]
 *		else:
 *			len / 2 of [BA]
 *			OR
 *			1 [A], 1 [B], x of [BA], (len / 2 - x - 1) of [AB]
 *
 *	we strictly want to use AB and BA as much as possible, then it's easiest to use it on groups of odd length.
 *	let's say the groups of odd length us up a maximum of x [AB]/[BA]s
 *	
*		let's start by assigning all [AB] blocks to [AB]+ substrings and [BA] blocks to [BA]+ substrings
*		assign greedily by size of substring
*		eventually we will be left with the following:
*			1. we run out of AB and BA blocks before finishing all [AB]+ and [BA]+ substrings
*				in this case, we have used (ab + ba) As and Bs.
*				check if (# of As in string) - (ab + ba) >= a, (# of Bs in string) - (ab + ba) >= b
*			2. we complete all [AB]+ and [BA]+ substrings with their respective blocks
*				in this case, we can use remaining [AB] and [BA] blocks for odd groupings
*				y = len(all [AB]+ and [BA]+ blocks)
*				rem = (ab + ba) - y
*				check that (# of As in string) - y - rem >= a, (# of Bs in string) - y - rem >= b
*			3. either we have leftover [AB] or [BA] (one of [AB]+ or [BA]+ is fully satisfied)
*				in this case, we have some remaining blocks that must be satisfied with the other type
*				each block will take 1 [A], 1 [B], and len(block) - 1 uses of [AB] or [BA].
*				continue this until the remainder is used up.
*				then re-evaluate
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.length();
		int a, b, ab, ba; cin >> a >> b >> ab >> ba;
		
		vector<string> partitions;
		string cur = string() + s[0];
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				partitions.push_back(cur);
				cur = string() + s[i];
			} else {
				cur += s[i];
			}
		}
		partitions.push_back(cur);

		//for (string str : partitions) cout << str << '\n';


		vector<string> even, odd;
		for (string substr : partitions) {
			if (substr == "A") {
				--a;
			} else if (substr == "B") {
				--b;
			} else if (substr == "AB") {
				if (ab > 0) --ab;
				else {
					--a;
					--b;
				}
			} else if (substr == "BA") {
				if (ba > 0) --ba;
				else {
					--a; 
					--b;
				}
			} else if (substr.length() % 2) {
				odd.push_back(substr);
			} else {
				even.push_back(substr);
			}
		}

		int could_use = 0; // # of [AB], [BA] that could be used
		for (string substr : odd) {
			if (substr[0] == 'A') {
				--a;
			} else {
				--b;
			}
			could_use += (substr.length() - 1) / 2;
		}


		if (a < 0 || b < 0) {
			cout << "NO\n";
			continue;
		}

		vector<int> ae, be;
		for (string substr : even) {
			if (substr[0] == 'A') ae.push_back(substr.length() / 2);
			else be.push_back(substr.length() / 2);
		}
		sort(ae.rbegin(), ae.rend());
		sort(be.rbegin(), be.rend());

		while (ab > 0 && !ae.empty()) {
			if (ab >= ae.back()) {
				ab -= ae.back();
				ae.pop_back();
			} else {
				ae[ae.size() - 1] -= ab;
				ab = 0;
			}
		}

		while (ba > 0 && !be.empty()) {
			if (ba >= be.back()) {
				ba -= be.back();
				be.pop_back();
			} else {
				be[be.size() - 1] -= ba;
				ba = 0;
			}
		}
	
		/*
		for (int x : ae) cout << x << " ";
		cout << '\n';
		for (int x : be) cout << x << " ";
		cout << '\n';
		*/
		

		bool works = false;
		int remainder = ab + ba;

		if (ae.empty() && be.empty()) {
			could_use -= min(could_use, remainder); // remainder of [AB]/[BA] in odd string length not yet accounted for with remainder
			works = (could_use <= a && could_use <= b);
		} else if (!ae.empty() && !be.empty()) { // we only have [A] and [B] left
			int need = could_use; // need this many [AB]/[BA]
			for (int x : ae) need += x; // need this many [AB]
			for (int x : be) need += x; // need this many [BA]
			works = (need <= a && need <= b);
		} else if (!ae.empty()) { // we have leftover [BA] to use to fill [AB]
			while (ba > 0 && !ae.empty()) {
				if (ba + 1 >= ae.back() && a > 0 && b > 0) {
					ba -= ae.back() - 1;
					--a;
					--b;
					ae.pop_back();
				} else {
					ae[ae.size() - 1] -= min(ae.back() - 1, ba);
					ba = 0;
				}
			}
			// fill the rest of ae with As and Bs.
			int need = max(0, could_use - ba); // can reuse BA for could_use if extras.
			for (int x : ae) need += x;
			works = (need <= a && need <= b);
		} else {
			while (ab > 0 && !be.empty()) {
				if (ab + 1 >= be.back() && a > 0 && b > 0) {
					ab -= be.back() - 1;
					--a;
					--b;
					be.pop_back();
				} else {
					be[be.size() - 1] -= min(be.back() - 1,  ab);
					ab = 0;
				}
			}
			// fill the rest of ae with As and Bs.
			int need = max(0, could_use - ab);
			for (int x : be) need += x;
			works = (need <= a && need <= b);
		}
		cout << (works ? "YES" : "NO") << '\n';
	}
}



			


		







