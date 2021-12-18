                      /*.........      .........               
                  ......  ..   ..  ..  ..      ... .           
                ...   ..  ..........'...,....  ..   ..      .. 
              .'.   ........'',,,,,,,,,,''.......    'l: .,;,;;
            ...  .....'',;::::::::::cccccc;........... .;ccc:;;;.
           .. ......,::::c:ccc:::::cccc:;'.',;;,..''...  .dc:;;;,;.
          ';. ..,,;::c:::c::::::::::cc;'.';;;;;;::'.'.    llc:::::;.
         ;;...,,,:cccc:cccc:::cc:::,',:;;;;;;;;;;;:;..... .l::;ccc:;.
        ;:  .,,'';:;c;:::cc::::;'',;,;;;::;;;;;;:::c:.'.   .oc::ccc;;.
       .c; .;,;;;:';:':';;;;'';;,,;;;;;;;::;::::::::::..   .occcc:::c;,
       :cl.:;,;::;;:c;::;;;;;;;;:;;;;;;::::::::c:cc:cc:... 'docclc::; .'.
      'cco;c,;;:;;;:c;::;;;;;;;;:c::::::::::::::::::;cc:;;;ldolccl:::.
      ;c:lc':::;;;;co::cc:;:;;:::lc:ccc:::::c::::::cl;co:ccoxooc:cc:,'
      c::lo,::c:::;lxocccc:::::::cd::::c:::::cc::cc:cc:lc:;cdloc::c:;,
     ,c;:ol:cccc:::oc;c:::cc:::::ccc;;::::::::cll:;;:ccloc::dooc;:cc;,.
    'll;:dc:::cc::cd,..:::::cc::;;c::..',,:cc:ccc:..;cc;..:;dxoc;:cc;;;'
    c.':cl::::cc::co.  .';;:;;:::;:oc:..:kKNNXX0Odc;;oo:c:c:dxd:;;cl::;,.
   .: .ccl::;;:c:;cc .....';;;;;;,;:.',''cX00kK0lxo.:lc.;,.cdol,,;cc:cl;,.
    c ':cl:x:;:c;;;;;kOOKKxl.'c;;;;;,. . o0OOkO0..;;:c:;c'.:do;,,;c:ccol,,.
    .;c::lldo;;:;;,dO,.O00OO0;....,,',.  .oocldl .,,:c;;::..oc,,,,:;ccc.c,;
     :;;ldldd;;;:,,l:  oKOOxkx         .....''....,,lc:;cc' :,,;,;;c;c' c,c.
   .'::olocoocc:;:,;:.  :od:c,.        ..........';;:;:;ll,.:,,;,,;:::. c;c.
 ...,:lx:l:oclodl:c;;;....'.....       ...........',,;::co::,,c;;;lc,:' o;:
    ,:lo:;::cldodldooo:..........       ..........,,,;::x:,c,;d;,:ll::ox;.
    ;;oc..;;cccoodxxl:c..........                .l,;;::;; l;cl:':xcoc,,;.
    ,,l:l. :;,:lododc;cc.......     .  ..       .;',:;:.c. ld:,o,':..,l,,:.
    .,:. '. ,,,oloooc,:cl' .                  ..,cc,:;c'.  :..,;c:,,,..l,;l.
       ..  ..',ccdolc,,cldo'..              .',,:c,,;:c.         .''.,::;cl.
            '',oodoo::,llol  . .....     .',,;:;:c,,;c,         ..,;....
         .',;,:,.:dlo:;lloc         :,,;:;,;:c:cc:':ccd,...  ..,...,'
        .',;'. .;odlo,;:lxl;'.  ..;cc;:,;::,...;:,,o:lk:'',,''......;.
                 ,oo;',:loo;;;;;'xNo..ldd,.   .:'';ock;;;,,,'.   ...cO,
                .,,;'',,l;oc,'''cXX; .k00c    .;,''x0l''',','.......'0Xx
                ..;''''':..',,''dKXl :0OOk'   .;oc';k,'',..  ........kXXc
                dc;.,,'',:,'..''k0Ok,k0OOOOc. .dkKdo;:;;.    ........KX0x
               l0c..';'',;;,''.,OOOOOOOOOOO0koO000Kk.....'.........lkXOkO.
               OK,    ...;;.. .l0OOOOOOOOOOOOOOOO0Kl   ..'.....  .;XXXOxk'
              ;OKk.......,..   xKOOOOOOOOOOOOOOOO00;   ..    ...;XXK000kO.
              okOo       ... ..0OOOOOOOOOOOOOOOOOOk.   .... ....;X0O00OkO.
              xO0d.     .''. ..KOOOOOOOOOOOOOOOOOOx.... ....,:..dKOOOOOOO
              x000:..... .... .kOOOOOOOOOOOOOOOOOOl........:xo,dKOOOOOOkk
              kO0Kx,;'    ....;',xkklc..::,:ocodoO,........cXXK0OOOOOOOkO'
             .O000000'    ...,......'..........' '....'.....xK000OOOOOOOk
             ,kkOOO00.. .''.. .. ..................  ......,k0O00000OOO*/
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const ll oo = 1e18;
const int N = 3e4, K = 20, M = 1e9 + 7;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
int mul(ll x, ll y) {
  return x * y % M;
}
int a[K + 1];
ll _dis[K+1][K+1], dp_min[1<<K][K];
int _cnt[K+1][K+1], dp_cnt[1<<K][K];
int n, m, k;
vector<pair<int, int>> G[N * 3];
int L[N * 3], R[N * 3], dis[N * 3], cnt[N * 3], t[N * 3];
bitset<N * 3> vis;
void calc() {
  /*
  vector<vector<pair<int, int>>> G(n * 3);
  vector<int> L(n * 3), R(n * 3);
  */
  int c = n;
  auto init = [&]() {
    function<pair<int, int>(int, int)> build = [&](int l, int r) {
      if (l == r) return make_pair(l, l);
      int m = (l + r) >> 1;
      pair<int, int> par = {c++, c++};
      auto left_c = build(l, m);
      auto right_c = build(m+1, r);
      G[par.first].emplace_back(left_c.first, 0);
      G[par.first].emplace_back(right_c.first, 0);
      L[par.first] = left_c.first, R[par.first] = right_c.first;
    
      G[left_c.second].emplace_back(par.second, 0);
      G[right_c.second].emplace_back(par.second, 0);
      L[par.second] = left_c.second, R[par.second] = right_c.second;

      return par;
    };
    return build(0, n-1);
  };
  auto root = init();
  int timer = 0;
  /*
  vector<int> t(c);
  */
  auto topo = [&]() {
    function<void(int)> dfs = [&](int u) {
      for (auto& p : G[u]) if (!vis[p.first])
        vis[p.first] = 1, dfs(p.first);
      t[u] = timer++;
    };
    dfs(n);
  };
  topo();
  auto insert_from_u = [&](int u, int x, int y, int w) {
    function<void(int, int, int)> insert = [&](int k, int l, int r) {
      if (l > y || r < x) 
        return;
      if (l >= x && r <= y)
        return G[u].emplace_back(k, w), void();
      int m = (l + r) >> 1;
      insert(L[k], l, m);
      insert(R[k], m+1, r);
    };
    insert(root.first, 0, n-1);
  };
  auto insert_to_u = [&](int x, int y, int u, int w) {
    function<void(int, int, int)> insert = [&](int k, int l, int r) {
      if (l > y || r < x)
        return;
      if (l >= x && r <= y)
        return G[k].emplace_back(u, w), void();
      int m = (l + r) >> 1;
      insert(L[k], l, m);
      insert(R[k], m+1, r);
    };
    insert(root.second, 0, n-1);
  };
  for (int i = 0, t, l, r, u, v, w; i < m; ++i) {
    cin >> t; t--;
    if (t == 0) {
      cin >> u >> v >> w; u--; v--;
      G[u].emplace_back(v, w);
    } else if (t == 1) {
      cin >> l >> r >> u >> w; u--; l--; r--; 
      insert_to_u(l, r, u, w);
    } else {
      cin >> u >> l >> r >> w; u--; l--; r--;
      insert_from_u(u, l, r, w);
    }
  }
  auto cmp = [&](const pair<int, ll>& u, const pair<int, ll>& v) {
    if (u.second == v.second)
      return t[u.first] < t[v.first];
    return u.second > v.second;
  };
  priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(cmp)> q(cmp);
  /*
  vector<ll> dis(c);
  vector<int> cnt(c);
  */
  for (int i = 0; i <= k; ++i) {
    /*
    fill(dis.begin(), dis.end(), oo);
    fill(cnt.begin(), cnt.end(), 0);
    */
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    dis[a[i]] = 0, cnt[a[i]] = 1;
    q.emplace(a[i], 0);
    while (!q.empty()) {
      int u = q.top().first, d = q.top().second; q.pop();
      if (d != dis[u]) continue;
      for (auto& p : G[u]) if (dis[u] + p.second < dis[p.first])
        dis[p.first] = dis[u] + p.second,
        cnt[p.first] = cnt[u], 
        q.emplace(p.first, dis[p.first]);
      else if (dis[u] + p.second == dis[p.first])
        add(cnt[p.first], cnt[u]);
    }
    for (int j = 0; j <= k; ++j)
      _dis[i][j] = dis[a[j]], _cnt[i][j] = cnt[a[j]];
  }

}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i)
    cin >> a[i], a[i]--;
  calc(); 
  sort(a, a + k, greater<int>());
  if (a[k-1] == 0) k--;
  /*
  vector<vector<ll>> dp_min(1 << k, vector<ll>(k, oo));
  vector<vector<int>> dp_cnt(1 << k, vector<int>(k));
  */
  memset(dp_min, 0x3f, sizeof(dp_min));
  int fin = (1 << k) - 1;
  for (int i = 0; i < k; ++i)
    dp_min[fin ^ (1 << i)][i] = _dis[i][k], 
    dp_cnt[fin ^ (1 << i)][i] = _cnt[i][k];
  ll res_min = oo, cur_min, cur;
  int res_cnt = 0;
  for (int mask = fin, nmask; ~mask; --mask)
    for (int i = 0; i < k; ++i) if (dp_cnt[mask][i]) 
    for (int j = 0; j < k; ++j) if (mask >> j & 1) {
      nmask = mask ^ (1 << j), cur = dp_min[mask][i] + _dis[j][i];
      if (cur < dp_min[nmask][j])
        dp_min[nmask][j] = cur,
        dp_cnt[nmask][j] = mul(dp_cnt[mask][i], _cnt[j][i]);
      else if (cur == dp_min[nmask][j])
        add(dp_cnt[nmask][j], mul(dp_cnt[mask][i], _cnt[j][i]));
    }
  for (int i = 0; i < k; ++i) {
    cur_min = dp_min[0][i] + _dis[k][i];
    if (cur_min < res_min)
      res_min = cur_min, 
      res_cnt = mul(dp_cnt[0][i], _cnt[k][i]);
    else if (cur_min == res_min)
      add(res_cnt, mul(dp_cnt[0][i], _cnt[k][i]));
  }
  if (res_cnt == 0)
    return cout << -1, 0;
  cout << res_min << ' ' << res_cnt;
  return 0;
}

