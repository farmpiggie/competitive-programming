/*
 * reorder some substring of s to make s a palindrome
 * minimize size of substring needed
 *
 * you can rearrange s into a palindrome by reordering substring [l, r] if:
 *	end = min(l, n - 1 - r)
 *	s.substr(0, end) == s.substr(n - end, end)
 *
 * might help to find the longest matching prefix and suffix of s first.
 *
 * we know all characters in s have even occurrence (since len(s)) is even.
 * we have a shorter substring (call it t) that doesnt match on either end (say the leftmost char is x, rightmost char is y)
 *
 * we can try "anchoring" a prefix or suffix of t and seeing if we can create an answer.
 * can create palindrome with some anchored suffix as long as:
 * [parity of characters occuring in prefix = parity of characters anchored in suffix]
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = (int) s.length();
		int l = 0, r = n - 1;
		while (l < r && s[l] == s[r]) {
			l++;
			r--;
		}
		if (l >= r) {
			cout << "0\n";
			continue;
		}

		// find "centered" palindrome
		// [x, y] will be centered palindrome
		int x = n / 2 - 1, y = n / 2; 
		int len = 0;
		while (x >= 0 && y < n && s[x] == s[y]) {
			len += 2;
			x--;
			y++;
		}
		x++;
		y--;

		int ans = r - l + 1;

		if (len > 0) { // we have a centered palindrome to use
			bool works = true;
			vector<int> cnt(26, 0);
			for (int i = l; i < x; i++) {
				cnt[s[i] - 'a']++;
			}
			for (int i = y + 1; i <= r; i++) {
				cnt[s[i] - 'a']--;
			}
			for (int i = 0; i < 26; i++) {
				if (cnt[i] != 0) {
					works = false;
					break;
				}
			}
			if (works) ans = x - l; // reverse elements around centered palindrome
		} 
		// if there is no centered palindrome, we must try larger sizes that go over the halfway point.
		vector<int> left(26, 0), right(26, 0);
		for (int i = l; i <= r; i++) {
			right[s[i] - 'a']++;
		}
		for (int i = l; i < r; i++) {
			left[s[i] - 'a']++;
			right[s[i] - 'a']--;
			bool right_bigger = (i <= l + (r - l) / 2);

			bool works = true;
			for (int j = 0; j < 26; j++) {
				if (right_bigger) {
					if (right[j] - left[j] < 0 || (right[j] - left[j]) % 2 != 0) {
						works = false;
						break;
					}
				} else {
					if (left[j] - right[j] < 0 || (left[j] - right[j]) % 2 != 0) {
						works = false;
						break;
					}
				}
			}
			if (works) ans = min(ans, max(i - l + 1, r - i));
		}
		cout << ans << '\n';
	}
}



