// Created by Shora
#include <bits/stdc++.h>
#define print(_v) for (auto _ : _v) {cout << _ << ' ';} cout << endl;
using namespace std;
using ll = long long;
const string FILE_NAME = "FILE_NAME";
void file() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
	freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
vector<int> a, f; int n;
bool check(int Min, int Max) {
	//cout << Min << ' ' << Max << endl;
	vector<int> dp(n); set<int> st; st.insert(0); 
	for (int i = 1; i <= 2*n; ++i) {
		auto x = st.lower_bound(f[i] - Max), y = st.upper_bound(f[i] - Min);
		if (x != y) {
			dp[i] = 1; 
			st.insert(f[i]);
		}
	}
	return dp[n];
}
// O(n^3 log(n^2) log(n))
void solve() {
	cin >> n;
	a.resize(2*n + 1); f.resize(2*n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = n + 1; i <= 2*n; ++i) a[i] = a[i - n];
	for (int i = 1; i <= 2*n; ++i) f[i] = f[i - 1] + a[i];
	set<int> st;
	for (int i = 1; i <= n; ++i) {
		int k = 0;
		for (int j = i; j <= 2*n; ++j) {
			k += a[j];
			st.insert(k);
		}
	}
	vector<int> s(st.begin(), st.end()); 
	int result = INT_MAX;
	for (int i = 0; i < s.size(); ++i) {
		int lo = i, hi = s.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (check(s[i], s[mid])) {
				cout << s[i] << ' ' << s[mid] << endl;
				result = min(result, s[mid] - s[i]);
				hi = mid - 1;
			} else lo = mid + 1;
		}
	}
	cout << result;
}

int main() {
	solve();
	return 0;
}

