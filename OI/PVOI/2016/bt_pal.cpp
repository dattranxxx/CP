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
using ull = unsigned long long;
const int oo = 1e9;
const int N = 5000;
const int mod = 1e9 + 7;
const pair<int, ull> base = {31, 37};
int sum(int x, int y) {
  return x + y >= mod ? x + y - mod : x + y;
}
int dif(int x, int y) {
  return x - y < 0 ? x - y + mod : x - y;
}
int mul(ll x, ll y) {
  return x * y % mod;
}
pair<int, ull> pw[N+1];
struct hash_string {
  vector<pair<int, ull>> h;
  hash_string() {}
  hash_string(string s): h(s.size()) {
    h[0].first = h[0].second = s[0] - '0' + 1;
    for (int i = 1; i < s.size(); ++i)
      h[i].first = sum(mul(h[i-1].first, base.first), s[i] - '0' + 1),
      h[i].second = h[i-1].second * base.second + s[i] - '0' + 1; 
  }
  pair<int, ull> operator() (int l, int r) {
    if (l == 0)
      return h[r];
    return {dif(h[r].first, mul(h[l-1].first, pw[r-l+1].first)),
            h[r].second - h[l-1].second * pw[r-l+1].second};
  }
} h;
int pal[N][N+1], f[N];
string s;
int n;
int check(int i, int l) {
  int S = f[i+l-1] - f[i-1];
  if (l > 1 && !S) return 0;
  if (!pal[i][l]) return 0;
  if (S % 3) return 0;
  return 1;
}
pair<int, int> best(pair<int, int>& u, pair<int, int> v) {
  if (u.first == -1) return v;
  if (u.second != v.second) return u.second > v.second ? u : v;
  int lo = 1, hi = u.second, mid, ans = 0;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (h(u.first, u.first + mid - 1) == h(v.first, v.first + mid - 1)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return s[u.first + ans] > s[v.first + ans] ? u : v;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> s; n = s.size();
  pw[0].first = pw[0].second = 1;
  for (int i = 1; i <= n; ++i)
    pw[i].first = mul(pw[i-1].first, base.first),
    pw[i].second = pw[i-1].second * base.second;
  h = hash_string(s);
  for (int i = 0; i < n; ++i)
    pal[i][0] = pal[i][1] = 1;
  f[0] = s[0] - '0';
  for (int i = 1; i < n; ++i)
    f[i] = f[i-1] + s[i] - '0';
  for (int l = 2; l <= n; ++l) 
    for (int i = 0; i + l - 1 < n; ++i)
      pal[i][l] = (s[i] == s[i+l-1]) && pal[i+1][l-2];
  int res = 0;
  pair<int, int> p = {-1, -1};
  for (int l = n; l; --l)
    for (int i = 0; i + l - 1 < n; ++i)
      if (check(i, l))
        res++, p = best(p, {i, l});
  cout << res << '\n' << (p.first == -1 ? "" : s.substr(p.first, p.second));
  return 0;
}

