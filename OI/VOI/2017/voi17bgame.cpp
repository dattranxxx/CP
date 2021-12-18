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
const int N = 1e5;
struct E {
  int u, v, w;
  E(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
  bool operator < (const E& e) const {
    return w < e.w;
  }
};
vector<E> e;
int n, m;
struct online_bridge {
  int cc[N], scc[N], sz[N]; // dsu va 2ecc dsu
  pair<int, int> par[N];  
  int res = -1;
  void init() {
    for (int i = 0; i < n; ++i) {
      cc[i] = i;
      scc[i] = i;
      sz[i] = 1;
      par[i] = {-1, -1};
    }
  }
  int find_scc(int u) {
    if (u == -1) return -1;
    return scc[u] == u ? u : scc[u] = find_scc(scc[u]);
  }
  int find_cc(int u) {
    return cc[u] == u ? u : cc[u] = find_cc(cc[u]);
  }
  void re_root(int u) {
    u = find_scc(u);
    int root = u, child = -1, cur_edge = -1;
    while (u != -1) {
      int p = find_scc(par[u].first);
      par[u].first = child;
      swap(par[u].second, cur_edge);
      cc[u] = root;
      child = u;
      u = p;
    }
    sz[root] = sz[child];
  }
  int cur_itr = 0;
  int last_vis[N];
  void merge_path(int u, int v) {
    cur_itr++;
    int lca = -1;
    vector<int> path_u, path_v;
    while (lca == -1) {
      if (u != -1) {
        u = find_scc(u);
        path_u.emplace_back(u);
        if (last_vis[u] == cur_itr) {
          lca = u; break;
        }
        last_vis[u] = cur_itr;
        u = par[u].first;
      }
      if (v != -1) {
        v = find_scc(v);
        path_v.emplace_back(v);
        if (last_vis[v] == cur_itr) {
          lca = v; break;
        }
        last_vis[v] = cur_itr;
        v = par[v].first;
      }
    }
    for (int cur : path_u) {
      scc[cur] = lca;
      if (cur == lca) 
        break;
      res = max(res, par[cur].second);
    }
    for (int cur : path_v) {
      scc[cur] = lca;
      if (cur == lca) 
        break;
      res = max(res, par[cur].second);
    }
  }
  bool create_cycle(int u, int v, int w) {
    //int _u = u, _v = v;
    u = find_scc(u), v = find_scc(v);
    if (u == v) 
      return 0;
    int cu = find_cc(u), cv = find_cc(v);
    if (cu != cv) {
      if (sz[cu] > sz[cv])
        swap(u, v), swap(cu, cv);
      re_root(u);
      par[u].first = cc[u] = v;
      par[u].second = w;
      sz[cv] += sz[u];
      return 0;
    } else {
      res = -1;
      merge_path(u, v);
      return 1;
    }
  }
} G;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m; e.reserve(m);
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    e.emplace_back(u, v, w);
  }
  sort(e.rbegin(), e.rend());
  G.init();
  int res = 0;
  // canh ko phai cau lon nhat xet do thi gom i canh dau tien 
  for (int i = 0; i < m; ++i) {
    if(G.create_cycle(e[i].u, e[i].v, e[i].w))
      res = max(res, G.res + e[i].w);
  }
  cout << res;
  return 0;
}

