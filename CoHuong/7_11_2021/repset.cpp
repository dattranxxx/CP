#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "repset";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 2e5;
struct S {
  ll l = 0, r = 0, c = 0;
} a[N];
ll f[N + 1];
int n; 
vector<pair<ll, ll>> p; // luu cac doan da dc to
void insert(pair<ll, ll> cur) {
  p.push_back(cur);
  if (p.size() == 1)
    f[p.size() - 1] = cur.second - cur.first + 1;
  else
    f[p.size() - 1] = f[p.size() - 2] + cur.second - cur.first + 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i].l >> a[i].r >> a[i].c;
  sort(a, a + n, [&](S& u, S& v) {
    return u.r != v.r ? u.r < v.r : u.c > v.c;
  });
  ll res = 0;
  for (int i = 0, m; i < n; ++i) {
    m = p.size();
    // cnp doan da to dau tien co r >= a[i].l
    int lo = 0, hi = m - 1, mid, ans = -1;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (p[mid].second >= a[i].l) 
        ans = mid,
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    // ko co r >= a[i].l thi phai to het ci cai cuoi
    if (ans == -1) {
      insert({a[i].r - a[i].c + 1, a[i].r});
      res += a[i].c; 
      continue;
    }
    // tong diem da to
    ll cnt = f[m - 1] - (ans ? f[ans - 1] : 0); 
    if (p[ans].first < a[i].l)
      cnt -= a[i].l - p[ans].first;
    // to
    if (a[i].c > cnt) {
      res += a[i].c - cnt;
      pair<ll, ll> cur = {a[i].r, a[i].r};
      ll x = a[i].c - cnt - 1; // phan con lai can phai to
      while (x) {
        if (!p.empty() && cur.first - p.back().second - 1 <= x) {
          x -= cur.first - p.back().second - 1,
          cur.first = p.back().first,
          p.pop_back();
        } else {
          cur.first -= x;
          break;
        }
      }
      insert(cur); 
    }
  }
  cout << res;
  return 0;
}

