/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 3e4;
int a[N];
int n;
const int S = 600;
vector<int> blo[N / S];
void change(int i, int x) {
  int k = i / S;
  blo[k].erase(lower_bound(blo[k].begin(), blo[k].end(), a[i]));
  a[i] = x;
  blo[k].insert(upper_bound(blo[k].begin(), blo[k].end(), a[i]), a[i]);
}
int query(int l, int r, int k) {
  int res = 0, L = (l + S - 1) / S, R = r / S;
  if (L >= R) {
    for (int i = l; i <= r; ++i)
      if (a[i] < k) res += 1;
    return res;
  }
  for (int i = L; i < R; ++i)
    res += lower_bound(blo[i].begin(), blo[i].end(), k) - blo[i].begin();
  for (int i = l, lim = L * S; i < lim; ++i)
    if (a[i] < k) res += 1;
  for (int i = R * S; i <= r; ++i)
    if (a[i] < k) res += 1;
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i], a[i] = -a[i];
  for (int i = 0; i < n; ++i)
    blo[i / S].push_back(a[i]);
  for (int i = 0; i <= (n - 1) / S; ++i)
    sort(blo[i].begin(), blo[i].end());
  int q, t, i, j, k;
  cin >> q;
  while (q--) {
    cin >> t >> i >> j;
    if (t == 0) {
      i--; j = -j; change(i, j);
    } else {
      cin >> k; k = -k; i--; j--;
      cout << query(i, j, k) << '\n';
    }
  }

  return 0;
}

