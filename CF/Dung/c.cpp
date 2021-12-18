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
const int N = 1.5e6;
struct segment_tree {
  int n, x, res;
  ll sum;
  vector<ll> st;
  segment_tree(int n = 0): n(n), st(n << 2) {}
  void insert(int k, int l, int r) {
    if (l == r) 
      return st[k] = l, void();
    int m = (l + r) >> 1;
    if (x <= m) insert(k<<1, l, m);
    else insert(k<<1|1, m+1, r);
    st[k] = st[k<<1] + st[k<<1|1];
  }
  void erase(int k, int l, int r) {
    if (l == r) 
      return st[k] = 0, void();
    int m = (l + r) >> 1;
    if (x <= m) erase(k<<1, l, m);
    else erase(k<<1|1, m+1, r);
    st[k] = st[k<<1] + st[k<<1|1];
  }
  void get(int k, int l, int r) {
    if (l == r)
      return res = l, void();
    ll m = (l + r) >> 1;
    if (m * (m + 1) / 2 != sum + st[k<<1]) get(k<<1, l, m);
    else sum += st[k<<1], get(k<<1|1, m+1, r);
  }
  void insert(int p) {
    if (p == 0) return;
    x = p;
    insert(1, 1, n);
  }
  void erase(int p) {
    if (p == 0) return;
    x = p;
    erase(1, 1, n);
  }
  int get() {
    sum = 0;
    get(1, 1, n);
    return res;
  }
} st;
int a[N];
int cnt[N];
int n, k;
void insert(int x) {
  if (!cnt[x]) st.insert(x);
  cnt[x]++;
}
void erase(int x) {
  cnt[x]--;
  if (!cnt[x]) st.erase(x);
}
int get() {
  if (!cnt[0]) return 0;
  return st.get();
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> k;
  st = segment_tree(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < k; ++i) 
    insert(a[i]);
  int res = get();
  for (int i = k; i < n; ++i) {
    erase(a[i-k]);
    insert(a[i]);
    res = min(res, get());
  }
  cout << res;
  return 0;
}

