#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll merge_array(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
	int i, j, k;
    ll inv_count = 0;
 
    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
        	i++;
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}


ll inversion_count(vector<int>& arr, vector<int>& temp, int left, int right) {
	int mid;
	ll inv_count = 0;
	if (right > left) {
		mid = left + (right - left) / 2;
		inv_count += inversion_count(arr, temp, left, mid);
		inv_count += inversion_count(arr, temp, mid + 1, right);

		inv_count += merge_array(arr, temp, left, mid + 1, right);
	}

	return inv_count;
}

ll inversion_count(vector<int>& arr) {
	vector<int> temp((int) arr.size(), 0);
	return inversion_count(arr, temp, 0, (int) arr.size() - 1);
}


ll n;
vector<int> a, b, c;
vector<int> ta, tb, tc;

int main() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	ta.resize(n + 1);
	tb.resize(n + 1);
	tc.resize(n + 1);
	int i = 1;
	for (int &x : a) {
		cin >> x;
		ta[x] = i++;
	}

	i = 1;
	for (int &x : b) {
		cin >> x;
		tb[x] = i++;
	}

	i = 1;
	for (int &x : c) {
		cin >> x;
		tc[x] = i++;
	}

	ll ans = 0;
	// compare a and b
	vector<int> change_b(n);
	for (int i = 0; i < n; i++) {
		change_b[i] = ta[b[i]];
	}

	// for (int &x : change_b) cout << x << '\n';
	ll inv_b = inversion_count(change_b);
	ans += inv_b;
	// b and c

	vector<int> change_c(n);
	for (int i = 0; i < n; i++) {
		change_c[i] = tb[c[i]];
	}

	// for (int &x : change_c) cout << x << '\n';
	ll inv_c = inversion_count(change_c);
	ans += inv_c;
	// c and a



	vector<int> change_a(n);
	for (int i = 0; i < n; i++) {
		change_a[i] = tc[a[i]];
	}

	// for (int &x : change_a) cout << x << '\n';
	ll inv_a = inversion_count(change_a);
	ans += inv_a;


	cout << n * (n - 1) / 2 - ans / 2 << '\n';



	return 0;
}