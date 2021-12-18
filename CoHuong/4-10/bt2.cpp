// Created by Shora
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cout << _ << ' ';} cout << endl;
using namespace std;
using ll = long long;
const string FILE_NAME = "cake";
void file() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen((FILE_NAME + ".in").c_str(), "r", stdin);
	freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
void cal(vector<int>& S, vector<int> a) {
	int n = a.size() - 1;
  vector<int> b(n * 2 + 1);
  for (int i = 1; i <= n; ++i)
    b[i] = a[i];
  for (int i = n + 1; i <= n*2; ++i)
    b[i] = a[i - n];
	for (int i = 1; i <= n; ++i) {
		int k = 0;
		for (int j = i; j <= i + n; ++j) {
			k += b[j]; S.push_back(k);
		}
	}
}
void solve() {
	int n; cin >> n; int res = INT_MAX;
	vector<int> a(n+1);
	vector<int> S; cal(S, a);
	sort(S.begin(), S.end()); 
  S.erase(unique(S.begin(), S.end()), S.end());
  a.resize(n * 2 + 1);
  for (int i = n+1; i <= n*2; ++i) 
    a[i] = a[n-i];
  n = a.size() - 1;
  vector<int> f(n + 1);
  for (int i = 1; i <= n; ++i)
    f[i] = f[i-1] + a[i];
	vector<vector<int>> dp(n+1, vector<int>(S.size(), INT_MAX));
	for (int x = 0; x < S.size(); ++x) dp[0][x] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j >= 1; --j) {
			int k = lower_bound(S.begin(), S.end(), f[i]-f[j-1]) - S.begin();
			for (int x = 0; x < S.size(); ++x) {
				int d = S[x] < S[k] ? x : k;
				dp[i][d] = min(dp[i][d], max(dp[j - 1][x], S[k]));
			}
		}
	}
	for (int i = n; i >= 2; --i) {
		int k = lower_bound(S.begin(), S.end(), f[n]-f[i-1]) - S.begin();
		for (int x = 0; x < S.size(); ++x) {
			int d = S[x] < S[k] ? x : k;
			dp[n][d] = min(dp[n][d], max(dp[i - 1][x], S[k]));
		}
	}
	for (int x = 0; x < S.size(); ++x) {
		res = min(res, dp[n][x] - S[x]);
	}
	cout << res;
}

int main() {
	//file();
	solve();
	return 0;
}


