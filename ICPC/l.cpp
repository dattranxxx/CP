// Created by Shora
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cout << _ << ' ';} cout << endl;
using namespace std;
using ll = long long;
const int d = 998244353; 
const int N = 1e5;
vector<int> G[N];
int dep[N], vis[N], f[N], dp[N], pw[N];
int n;
int main() {
  while (cin >> n) {
    if (n == 0) break;
    for (int i = 0; i < n; ++i) 
      cin >> nxt[i], pre[nxt[i]] = i;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
      int len = 1, cur = i;
      while (nxt[cur] != cur) 
    }
  }
}

