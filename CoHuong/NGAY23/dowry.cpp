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
  const string FILE_NAME = "dowry";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const ll oo = 1e18;
const int N = 16;
struct S {
  ll w, v;
  unsigned int mask;
  S(ll w = 0, ll v = 0, unsigned int mask = 0): w(w), v(v), mask(mask) {}
  bool operator < (const S& s) const {
    return w < s.w;
  }
} a[N], b[N], c[1 << N], d[1 << N];
pair<ll, int> spt[1 << N][N + 1];
int n, m, _n = 0, _m = 0;
ll L, R;
#define log_2(x) 31 - __builtin_clz(x)
void build() {
  for (int i = 0; i < _m; ++i)
    spt[i][0] = {d[i].v, d[i].mask};
  for (int j = 1; j <= 16; ++j)
    for (int i = 0; i + (1 << j) - 1 < _m; ++i)
      spt[i][j] = max(spt[i][j-1], spt[i + (1 << (j - 1))][j-1]);
}
pair<ll, int> get(int l, int r) {
  int k = log_2(r - l + 1);
  return max(spt[l][k], spt[r - (1 << k) + 1][k]);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> L >> R, m = n / 2, n -= m;
  for (int i = 0; i < n; ++i)
    cin >> a[i].w >> a[i].v, a[i].mask = 1 << i;
  for (int i = 0; i < m; ++i)
    cin >> b[i].w >> b[i].v, b[i].mask = 1 << (n + i);
  for (int msk = 0; msk < 1 << n; msk++, _n++) {
    ll cur_w = 0, cur_v = 0;
    unsigned int mask = 0;
    for (int i = 0; i < n; ++i) if (msk >> i & 1)
      cur_w += a[i].w, cur_v += a[i].v, mask |= a[i].mask;
    c[_n] = {cur_w, cur_v, mask};
  }
  for (int msk = 0; msk < 1 << m; msk++, _m++) {
    ll cur_w = 0, cur_v = 0;
    unsigned int mask = 0;
    for (int i = 0; i < m; ++i) if (msk >> i & 1)
      cur_w += b[i].w, cur_v += b[i].v, mask |= b[i].mask;
    d[_m] = {cur_w, cur_v, mask};
  }
  sort(d, d + _m);
  ll res = -oo;
  unsigned int tra = 0;
  for (int i = 0, lo, hi, mid, l, r; i < _n; ++i) {
    // (l, r)
    lo = 0, hi = _m-1, l = -1;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (c[i].w + d[mid].w >= L) 
        l = mid, hi = mid - 1;
      else lo = mid + 1;
    }
    lo = 0, hi = _m-1, r = -1;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (c[i].w + d[mid].w <= R) 
        r = mid, lo = mid + 1;
      else hi = mid - 1;
    }
    if (l == -1 || r == -1 || l > r) continue;
    auto p = get(l, r);
    if (c[i].v + p.first > res) {
      res = c[i].v + p.first;
      tra = c[i].mask | d[p.second].mask;
    }
  }
  cerr << res << '\n';
  vector<int> ans;
  for (int i = 0; i < 32; ++i) 
    if (tra >> i & 1) ans.emplace_back(i + 1);
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
  return 0;
}


