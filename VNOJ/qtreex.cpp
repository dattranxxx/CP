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
const int oo = 1e9;
const int N = 1e4;
struct C {
  int v, i;
  C(int v = 0, int i = 0): v(v), i(i) {}
};
int e[N];
struct segment_tree {
  int n, p, v, x, y, res;
  vector<int> mx, mn, parity;
  segment_tree(int n = 0): n(n), mx(n << 2), mn(n << 2), parity(n << 2) {}
  void _swap(int& u, int& v) {
    swap(u, v); u = -u; v = -v;
  }
  void push(int k) {
    if (!parity[k]) return;
    parity[k<<1] ^= parity[k];
    _swap(mx[k<<1], mn[k<<1]),
    parity[k<<1|1] ^= parity[k];
    _swap(mx[k<<1|1], mn[k<<1|1]);
    parity[k] = 0;
  }
  void set(int k, int l, int r) {
    if (l == r) 
      return mx[k] = mn[k] = v, void();
    push(k);
    int m = (l + r) >> 1;
    if (p <= m) set(k<<1, l, m);
    else set(k<<1|1, m+1, r);
    mx[k] = max(mx[k<<1], mx[k<<1|1]);
    mn[k] = min(mn[k<<1], mn[k<<1|1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) 
      return res = max(res, mx[k]), void();
    push(k);
    int m = (l + r) >> 1;
    get(k<<1, l, m);
    get(k<<1|1, m+1, r);
  }
  void negate(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) 
      return parity[k] ^= 1, _swap(mx[k], mn[k]), void();
    push(k);
    int m = (l + r) >> 1;
    negate(k<<1, l, m);
    negate(k<<1|1, m+1, r);
    mx[k] = max(mx[k<<1], mx[k<<1|1]);
    mn[k] = min(mn[k<<1], mn[k<<1|1]);
  }

  void set(int pos, int val) {
    p = pos; v = val; 
    set(1, 0, n-1);
  }
  int get(int l, int r) {
    if (l > r) return -oo;
    x = l; y = r; res = -oo;
    get(1, 0, n-1);
    return res;
  }
  void negate(int l, int r) {
    if (l > r) return;
    x = l; y = r; 
    negate(1, 0, n-1);
  }
} st;
vector<C> G[N];
int n;
int dep[N], par[N], he[N], heavy[N], head[N], pos[N], of[N];
int cur_pos;
int dfs(int u = 0) {
  int size = 1, max_size = 0;
  heavy[u] = 0;
  for (C& c : G[u]) if (c.v != par[u]) {
    par[c.v] = u; 
    dep[c.v] = dep[u] + 1;
    int c_size = dfs(c.v);
    if (c_size > max_size)
      max_size = c_size, heavy[u] = c.v, he[u] = c.i;
    size += c_size;
  }
  return size;
}
void build(int u = 0, int h = 0, int i = -1) {
  head[u] = h, pos[u] = cur_pos++;
  if (u != 0) 
    st.set(pos[u], e[i]), of[i] = pos[u];
  if (heavy[u])
    build(heavy[u], h, he[u]);
  for (C& c : G[u]) 
    if (c.v != par[u] && c.v != heavy[u])
      build(c.v, c.v, c.i);
}
int query(int u, int v) {
  if (u == v) return 0;
  int res = -oo;
  for (; head[u] != head[v]; u = par[head[u]]) {
    if (dep[head[u]] < dep[head[v]]) swap(u, v);
    res = max(res, st.get(pos[head[u]], pos[u]));
  }
  if (dep[u] < dep[v]) swap(u, v);
  res = max(res, st.get(pos[v] + 1, pos[u]));
  return res;
}
void _negate(int u, int v) {
  if (u == v) return;
  for (; head[u] != head[v]; u = par[head[u]]) {
    if (dep[head[u]] < dep[head[v]]) swap(u, v);
    st.negate(pos[head[u]], pos[u]);
  }
  if (dep[u] < dep[v]) swap(u, v);
  st.negate(pos[v] + 1, pos[u]);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int u = 0; u < n; ++u)
      G[u].clear();
    for (int i = 0, u, v, w; i < n-1; ++i) {
      cin >> u >> v >> w; u--; v--;
      G[u].emplace_back(v, i);
      G[v].emplace_back(u, i);
      e[i] = w;
    }
    cur_pos = 0;
    st = segment_tree(n);
    dfs();
    build();
    string s;
    for (int u, v;;) {
      cin >> s;
      if (s[0] == 'D') break;
      cin >> u >> v;
      if (s[0] == 'Q') {
        u--; v--;
        cout << query(u, v) << '\n';
      } else if (s[0] == 'N') {
        u--; v--;
        _negate(u, v);
      } else if (s[0] == 'C') {
        u--; 
        st.set(of[u], v);
      } 
    }
  }
  return 0;
}

 
