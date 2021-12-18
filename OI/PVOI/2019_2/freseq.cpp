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
void file() {
  const string FILE_NAME = "freseq";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e5;
int a[N];
vector<int> c;
int n, m, q;
namespace task_2 {
  void solve() {
    vector<vector<int>> cnt(n+1, vector<int>(m));
    for (int i = 1; i <= n; ++i) 
      for (int j = 0; j < m; ++j)
        cnt[i][j] = cnt[i-1][j] + (a[i] == j);
    int l, r, res;
    while (q--) {
      cin >> l >> r;
      res = 0;
      for (int i = 0; i < m; ++i)
        res = max(res, cnt[r][i] - cnt[l-1][i]);
      cout << res << '\n';
    }
  }
}
namespace task_3 {
  struct sparse_table {
    int n;
    int log_2[N + 1], spt[N + 1][20];
    sparse_table() {}
    void build(vector<int>& d) {
      n = d.size() - 1;
      for (int i = 2; i <= n; ++i)
        log_2[i] = log_2[i / 2] + 1;
      for (int i = 1; i <= n; ++i)
        spt[i][0] = d[i];
      for (int j = 1; j <= log_2[n]; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
          spt[i][j] = max(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
    }
    int get(int l, int r) {
      int k = log_2[r - l + 1];
      return max(spt[l][k], spt[r-(1<<k)+1][k]);
    }
  } spt;
  void solve() {
    vector<int> b;
    b.push_back(0);
    for (int i = 1; i < n; ++i)
      if (a[i] != a[i+1]) b.push_back(i);
    b.push_back(n);
    vector<int> d(b.size());
    for (int i = 1; i < d.size(); ++i)
      d[i] = b[i] - b[i-1];
    spt.build(d); 
    int l, r, i, res, L, R;
    while (q--) {
      cin >> l >> r; L = l; R = r;
      res = 0;
      i = lower_bound(b.begin(), b.end(), l) - b.begin();
      res = max(res, min(b[i], r) - l + 1); 
      l = i + 1; 
      i = upper_bound(b.begin(), b.end(), r) - b.begin() - 1;
      if (b[i] >= L-1) res = max(res, r - b[i]); 
      r = i;
      if (l <= r) res = max(res, spt.get(l, r));
      cout << res << '\n';
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> q; c.resize(n);
  for (int i = 1; i <= n; ++i)
    cin >> a[i], c[i-1] = a[i];
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  m = c.size();
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
  if ((n <= 1000 && q <= 1000) || m <= 11) task_2::solve();
  else task_3::solve();
  return 0;
}

