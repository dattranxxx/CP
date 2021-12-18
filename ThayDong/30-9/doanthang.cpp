                 /*..... .
                 .';:;;;;'':.
                .:::::::::cl'
                .c;;o,.cc::::.
                ';l:.. ..;;;;.
                 .,::.'',:...
                  '.'cxdo;..d.
                  d..:olo.'dO.
                  kk. .. :kOO.
                 .k0k...'000d.
                  c00'.,00k:..
                  l00..xOk;..co'
                 .l00cdOO, ...oO;.
           .,;;. .:ld::do  .  .OOx'.
       ,cokcc,......;. ..      oOO00Oooc'
    .oOOOc..... .......      ..oK000OOOOOl.
   :OOOO:....    .'...      .lO0KK000OOOOOOo.
   ,OOO00;  ..   .           x0KK0000OOOOOOO:.
    'ck00k.  ...  ...... ... ':000OOOOOOOOOk;.
      :OOO0kdld:':O0:.,,,l'.':'OOOOOOo:l:;'.
       .;ooolOOOOOO000O00000OOOOOOx:..
             .''....;coolc,'',;.*/
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 500;
struct S {
  int a, b, c, d;
  S(): a(0), b(0), c(0), d(0) {}
} a[N];
int n, w, h;
int vis[N][N];
vector<int> W, H;
int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
set<pair<int, int>> s;
ll dfs(int r, int c) {
  int u = r * (W.size() - 1) + c;
  ll res = ll(H[r+1] - H[r]) * (W[c+1] - W[c]);
  for (int i = 0; i < 4; ++i) {
    if (!(r + dr[i] >= 0 && r + dr[i] < H.size() - 1 && c + dc[i] >= 0 && c + dc[i] < W.size() - 1))
      continue;
    if (vis[r + dr[i]][c + dc[i]]) continue;
    int v = (r + dr[i]) * (W.size() - 1) + (c + dc[i]);
    if (!s.count(make_pair(u, v)))  
      vis[r + dr[i]][c + dc[i]] = 1, 
      res += dfs(r + dr[i], c + dc[i]);
  }
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> w >> h >> n;
  W.emplace_back(0); 
  W.emplace_back(w);
  H.emplace_back(0);
  H.emplace_back(h);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    if (a[i].a == a[i].c && a[i].b == a[i].d) continue;
    if (a[i].a == a[i].c) {
      if (a[i].a <= 0 || a[i].a >= w) continue;
      if (a[i].b > a[i].d) swap(a[i].b, a[i].d);
      a[i].b = max(0, a[i].b), a[i].b = min(h, a[i].b);
      a[i].d = max(0, a[i].d), a[i].d = min(h, a[i].d); 
      W.emplace_back(a[i].a),
      H.emplace_back(a[i].b),
      H.emplace_back(a[i].d);
    } else { 
      if (a[i].b <= 0 || a[i].b >= h) continue;
      if (a[i].a > a[i].c) swap(a[i].a, a[i].c);
      a[i].a = max(0, a[i].a), a[i].a = min(w, a[i].a);
      a[i].c = max(0, a[i].c), a[i].c = min(w, a[i].c);
      H.emplace_back(a[i].b),
      W.emplace_back(a[i].a),
      W.emplace_back(a[i].c);
    }
  }
  sort(W.begin(), W.end());
  W.erase(unique(W.begin(), W.end()), W.end());
  sort(H.begin(), H.end());
  H.erase(unique(H.begin(), H.end()), H.end());
  for (int i = 0; i < n; ++i) {
    if (a[i].a == a[i].c && a[i].b == a[i].d) continue;
    if (a[i].a == a[i].c) {
      if (a[i].a <= 0 || a[i].a >= w) continue;
      int c = lower_bound(W.begin(), W.end(), a[i].a) - W.begin();
      for (int r = lower_bound(H.begin(), H.end(), a[i].b) - H.begin(); r < H.size() && H[r] < a[i].d; ++r) {
        int u = r * (W.size() - 1) + c - 1, v = r * (W.size() - 1) + c;
        s.insert(make_pair(u, v));
        s.insert(make_pair(v, u));
      }
    } else {
      if (a[i].b <= 0 || a[i].b >= h) continue;
      int r = lower_bound(H.begin(), H.end(), a[i].b) - H.begin();
      for (int c = lower_bound(W.begin(), W.end(), a[i].a) - W.begin(); c < W.size() && W[c] < a[i].c; ++c) {
        int u = (r - 1) * (W.size() - 1) + c, v = r * (W.size() - 1) + c;
        s.insert(make_pair(u, v));
        s.insert(make_pair(v, u));
      }
    }
  }
  vector<ll> res;
  for (int r = 0; r < H.size() - 1; ++r) {
    for (int c = 0; c < W.size() - 1; ++c) {
      if (!vis[r][c]) {
        vis[r][c] = 1;
        res.emplace_back(dfs(r, c));
      }
    }
  }
  sort(res.rbegin(), res.rend());
  for (ll x : res)
    cout << x << '\n';
  return 0;
}

