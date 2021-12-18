/*                 ..... .
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
             .''....;coolc,'',;.                */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9, MOD = 1e9 + 7;
void file() {
  const string FILE_NAME = "treegcd";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
void add(int& x, int y) {
  x += y; if (x >= MOD) x -= MOD;
}
int mul(ll x, ll y) {
  return x * y % MOD;
}

const int N = 100, M = 10000, K = 13665;
// dp[u][mask]
int lp[M+1], par[N];
vector<int> G[N];
int n, m;
void root(int u, int e) {
  par[u] = e;
  for (int v : G[u]) if (v != e) 
    root(v, u);
}
vector<int> pr;
void sieve() {
  for (int i=2; i<=m; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=m; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
int dem = 0, siz = 0;
map<vector<int>, int> idx;
vector<int> msk[K];
int dp[N][K], cnt[K];
void build(int i, ll cur, vector<int>& p) {
  if (i == pr.size() || cur * pr[i] > m) {
    if (cur == 1) return;
    idx[p] = dem; 
    msk[dem] = p;
    dem++;
    siz += p.size();
    return;
  }
  build(i + 1, cur, p);
  p.push_back(pr[i]);
  build(i + 1, cur * pr[i], p);
  p.pop_back();
}
int ints(vector<int>& u, vector<int>& v) {
  for (int i = 0; i < u.size(); ++i)
    for (int j = 0; j < v.size(); ++j)
      if (u[i] == v[j]) return 1;
  return 0;
}
int call(int u, int id) {
  if (dp[u][id] != -1)
    return dp[u][id];
  dp[u][id] = cnt[id];
  for (int v : G[u]) if (v != par[u]) {
    int sum = 0;
    for (int nxt = 0; nxt < dem; ++nxt) if (ints(msk[id], msk[nxt])) { 
      add(sum, call(v, nxt));
    }
    dp[u][id] = mul(dp[u][id], sum);
  }
  return dp[u][id];
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  for (int i = 0, u, v; i < n-1; ++i) {
    cin >> u >> v; u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  root(0, 0);

  sieve();
  vector<int> p;
  build(0, 1, p);

  for (int i = 2; i <= m; ++i) {
    p.clear();
    int cur = i;
    while (cur > 1) {
      for (int x : pr) if (cur % x == 0) {
        p.push_back(x);
        while (cur % x == 0) {
          cur /= x;
        } 
      }
    }
    add(cnt[idx[p]], 1); 
  }
  memset(dp, -1, sizeof(dp));
  int res = 0;
  for (int i = 0; i < dem; ++i) {
    call(0, i);
    add(res, dp[0][i]);
  }
  cout << res << '\n';
  return 0;
}

