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
const int N = 100;
const int base1 = 31, base2 = 37, mod = 1e9 + 7;
int sum(int x, int y) {
  return x + y >= mod ? x + y - mod : x + y;
}
int dif(int x, int y) {
  return x - y < 0 ? x - y + mod : x - y;
}
int mul(ll x, ll y) {
  return x * y % mod;
}
string s[2][N];
int n, m;
pair<int, ull> h[N][N], pw[N * N + 1], row[N][N], col[N][N];
pair<int, ull> calc_row(int i, int l, int r) {
  if (l == 0)
    return h[i][r];
  return {dif(h[i][r].first, mul(h[i][l-1].first, pw[r-l+1].first)), 
          h[i][r].second - h[i][l-1].second * pw[r-l+1].second};
}
pair<int, ull> calc_col(int l, int r, int j, int _) {
  if (l == 0)
    return h[r][j];
  return {dif(h[r][j].first, mul(h[l-1][j].first, pw[(r-l+1)*_].first)),
          h[r][j].second - h[l-1][j].second * pw[(r-l+1)*_].second};
}
vector<pair<int, ull>> build(int r, int c, int t) {
  for (int i = 0; i < n; ++i) {
    h[i][0].first = h[i][0].second = s[t][i][0] - 'a' + 1;
    for (int j = 1; j < m; ++j)
      h[i][j].first = sum(mul(h[i][j-1].first, base1), s[t][i][j] - 'a' + 1),
      h[i][j].second = h[i][j-1].second * base2 + s[t][i][j] - 'a' + 1;
    for (int j = c-1; j < m; ++j)
      row[i][j] = calc_row(i, j-c+1, j);
  }
  vector<pair<int, ull>> res;
  res.reserve((n - r + 1) * (m - c + 1));
  for (int j = c-1; j < m; ++j) {
    h[0][j] = row[0][j];
    for (int i = 1; i < n; ++i)
      h[i][j].first = sum(mul(h[i-1][j].first, pw[c].first), row[i][j].first),
      h[i][j].second = h[i-1][j].second * pw[c].second + row[i][j].second;
    for (int i = r-1; i < n; ++i)
      col[i][j] = calc_col(i-r+1, i, j, c),
      res.emplace_back(col[i][j]);
  }
  return res;
}
int check(int r, int c) {
  vector<pair<int, ull>> a = build(r, c, 0), b = build(r, c, 1);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0, j = 0; i < a.size() && j < b.size();) {
    if (a[i] == b[j]) return 1;
    else if (a[i] < b[j]) i++;
    else j++;
  }
  return 0;

}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  pw[0].first = pw[0].second = 1;
  for (int i = 1; i <= N * N; ++i) 
    pw[i].first = mul(pw[i-1].first, base1),
    pw[i].second = pw[i-1].second * base2;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
      cin >> s[0][i];
    for (int i = 0; i < n; ++i)
      cin >> s[1][i];
    int res = 0;
    for (int r = 1, c = m; r <= n && c; ) {
      while (check(r, c))
        res = max(res, r * c), r++;
      c--;
    }
    cout << res << '\n';
  }
  return 0;
}

