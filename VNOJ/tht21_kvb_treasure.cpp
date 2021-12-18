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
const int N = 96, M = 1000 * N;
int a[N], dp[2][M * 2 + 1];
ll f[N], s;
int n;
void fuck() {
  f[0] = a[0];
  for (int i = 1; i < n; ++i)
    f[i] = f[i-1] + a[i];
  unordered_map<int, int> cur, nxt;
  cur[0] = 0;
  for (int i = 0; i < n; ++i) {
    unordered_map<int, int>().swap(nxt);
    for (auto& p : cur) {
      if (nxt.count(p.first))
        nxt[p.first] = min(nxt[p.first], p.second + a[i]);
      else nxt[p.first] = p.second + a[i];
      if (p.first + a[i] <= s - f[i]) {
        if (nxt.count(p.first + a[i]))
          nxt[p.first + a[i]] = min(nxt[p.first + a[i]], p.second);
        else nxt[p.first + a[i]] = p.second;
      }
      if (p.first - a[i] >= -(s - f[i])) {
        if (nxt.count(p.first - a[i]))
          nxt[p.first - a[i]] = min(nxt[p.first - a[i]], p.second);
        else nxt[p.first - a[i]] = p.second;
      }
    }
    cur.swap(nxt);
  }
  cout << cur[0] << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); 
  while (cin >> n) {
    s = 0;
    for (int i = 0; i < n; ++i)
      cin >> a[i], s += a[i];
    if (n <= 24) {
      fuck(); continue;
    }
    memset(dp[0], 0x3f, sizeof(dp[0]));
    dp[0][s] = 0;
    for (int i = 0; i < n; ++i) {
      int cur = i & 1, nxt = cur ^ 1; 
      memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
      for (int j = -s; j <= s; ++j) {
        dp[nxt][j + s] = min(dp[nxt][j + s], dp[cur][j + s] + a[i]);
        if (j + a[i] <= s)
          dp[nxt][j + a[i] + s] = min(dp[nxt][j + a[i] + s], dp[cur][j + s]);
        if (j - a[i] >= -s)
          dp[nxt][j - a[i] + s] = min(dp[nxt][j - a[i] + s], dp[cur][j + s]);
      }
    }
    cout << dp[n & 1][s] << '\n';
  }
  return 0;
}

