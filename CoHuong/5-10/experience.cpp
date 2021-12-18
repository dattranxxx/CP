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
void file() {
  const string FILE_NAME = "experience";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const ll oo = 1e18;
const int N = 1e5;
struct segment_tree {
  int n, x, y;
  ll z, res;
  vector<ll> st, lz;
  segment_tree(int n = 0): n(n), st(n << 2), lz(n << 2) {}
  void push(int k) {
    if (!lz[k]) return;
    ll x = lz[k]; lz[k] = 0;
    st[k<<1] += x, lz[k<<1] += x;
    st[k<<1|1] += x, lz[k<<1|1] += x;
  }
  void update(int k, int l, int r) {
    if (l > y || r < x) 
      return;
    if (l >= x && r <= y) 
      return st[k] += z, lz[k] += z, void();
    push(k);
    int m = (l + r) >> 1;
    update(k<<1, l, m);
    update(k<<1|1, m+1, r);
    st[k] = max(st[k<<1], st[k<<1|1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x)
      return;
    if (l >= x && r <= y)
      return res = max(res, st[k]), void();
    push(k);
    int m = (l + r) >> 1;
    get(k<<1, l, m);
    update(k<<1|1, m+1, r);
  }
  void add(int l, int r, ll v) {
    x = l, y = r, z = v;
    update(1, 0, n-1);
  }
  ll get(int l, int r) {
    x = l, y = r, res = -oo;
    get(1, 0, n-1);
    return res;
  }
};
vector<int> G[N];
int a[N], par[N];
ll dp[N];
int n;
namespace task_1 {
  ll call(int u);
  ll calc(int u, int mn, int mx) {
    mn = min(mn, a[u]);
    mx = max(mx, a[u]);
    ll sum = 0;
    for (int v : G[u]) 
      sum += call(v);
    ll res = mx - mn + sum;
    for (int v : G[u])
      res = max(res, calc(v, mn, mx) + sum - call(v));
    return res;
  }
  ll call(int u) {
    if (dp[u] != -1)
      return dp[u];
    ll sum = 0;
    for (int v : G[u])
      sum += call(v);
    dp[u] = sum;
    for (int v : G[u])
      dp[u] = max(dp[u], calc(v, a[u], a[u]) + sum - call(v));
    return dp[u];
  }
  void solve() {
    memset(dp, -1, sizeof(dp));
    cout << call(0);
  }
}
namespace task_2 {
  void solve() {
    vector<int> v(n+1);
    for (int i = 1, u = 0; i <= n; u = G[u][0], ++i) {
      v[i] = a[u];
      if (G[u].empty()) break;
    }
    stack<int> st_max, st_min;
    segment_tree st(n);
    // dp[i] = max(dp[j] + max - min) -> update max, update min
    for (int i = 1; i <= n; ++i) {
      while (!st_max.empty() && v[st_max.top()] < v[i]) {
        int cur = st_max.top(); st_max.pop();
        int pre = st_max.empty() ? 1 : st_max.top() + 1;
        st.add(pre - 1, cur - 1, v[i] - v[cur]);
      }
      st_max.push(i);
      while (!st_min.empty() && v[st_min.top()] > v[i]) {
        int cur = st_min.top(); st_min.pop();
        int pre = st_min.empty() ? 1 : st_min.top() + 1;
        st.add(pre - 1, cur - 1, v[cur] - v[i]);
      } 
      st_min.push(i);
      ll x = st.st[1];
      if (i == n) 
        return cout << x, void();
      st.add(i, i, x);
    }
  }
}
namespace task_3 {
  ll dp[N][2];
  void dfs(int u) {
    ll sum = 0;
    for (int v : G[u]) {
      dfs(v);
      sum += max(dp[v][0], dp[v][1]);
    }
    dp[u][0] = dp[u][1] = sum;
    for (int v : G[u]) {
      if (a[u] <= a[v]) 
        dp[u][0] = max(dp[u][0], dp[v][0] + a[v] - a[u] + sum - max(dp[v][0], dp[v][1]));
      if (a[u] >= a[u]) 
        dp[u][1] = max(dp[u][1], dp[v][1] - a[v] + a[u] + sum - max(dp[v][0], dp[v][1]));
    }
  }
  void solve() {
    dfs(0);
    cout << max(dp[0][0], dp[0][1]);
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int chain = 1;
  for (int i = 0, u, v; i < n-1; ++i) {
    cin >> u >> v; u--; v--;
    G[u].emplace_back(v);
    par[v] = u;
    chain &= G[u].size() == 1;
  }
  task_3::solve();
  return 0;
  if (chain) task_2::solve();
  else if (n <= 5000) task_1::solve();
  else task_3::solve();
  return 0;
}

