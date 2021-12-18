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
  const string FILE_NAME = "restring";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
using ull = unsigned long long;
const int oo = 1e9;
const int N = 2e6;
const int base1 = 31, base2 = 37, mod = 1e9 + 7;
int dif(int x, int y) {
  return x - y < 0 ? x - y + mod : x - y;
}
int mul(ll x, ll y) {
  return x * y % mod;
}
pair<int, ull> pw[N];
struct hash_string {
  vector<pair<int, ull>> h;
  hash_string(string& s): h(s.size()) {
    h[0] = {s[0] - 'A' + 1, s[0] - 'A' + 1};
    for (int i = 1; i < s.size(); ++i)
      h[i].first = (ll(h[i-1].first) * base1 + s[i] - 'A' + 1) % mod,
      h[i].second = h[i-1].second * base2 + s[i] - 'A' + 1;
  }
  pair<int, ull> operator() (int l, int r) {
    if (l > r) 
      return {0, 0};
    if (l == 0) 
      return h[r];
    return {dif(h[r].first, mul(h[l-1].first, pw[r-l+1].first)), 
                h[r].second - h[l-1].second * pw[r-l+1].second};
  }
};
int n;
int check(string s, string t) {
  // [0, m-1] vs [m, n-1]
  if (s.size() > t.size()) 
    swap(s, t);
  hash_string a(s), b(t);
  int lo = 0, hi = s.size() - 1, mid, ans = -1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (a(0, mid) == b(0, mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return a(ans + 1, s.size() - 1) == b(ans + 2, t.size() - 1);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 == 0) 
    return cout << "NOT POSSIBLE", 0;
  if (n == 1)
    return cout << "", 0;
  pw[0] = {1, 1};
  for (int i = 1; i <= (n + 1) / 2; ++i)
    pw[i].first = ll(pw[i-1].first) * base1 % mod,
    pw[i].second = pw[i-1].second * base2;

  int c1 = check(s.substr(0, n/2), s.substr(n/2, n/2+1)), c2 = check(s.substr(0, n/2+1), s.substr(n/2+1, n/2));
  if (!c1 && !c2)
    return cout << "NOT POSSIBLE", 0;
  string a, b;
  if (c1) a = s.substr(0, n/2);
  if (c2) b = s.substr(n/2+1, n/2);
  if (c1 && c2 && a != b)
    return cout << "NOT UNIQUE", 0;
  if (c1)
    return cout << a, 0;
  else 
    return cout << b, 0;
  return 0;
}

