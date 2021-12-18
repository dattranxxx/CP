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
struct S {
  int i, j, t;
  S(int i = 0, int j = 0, int t = 0): i(i), j(j), t(t) {}
};
const int N = 1000 + 5;
int f[N+2][N+2], col[N+2][N+2], vis[N+2][N+2][6];
int A, B, C, n, m, k;
int _a[6], _b[6], _c[6], nxt[6], pre[6];
int check(int i, int j, int t) {
  int a = _a[t], b = _b[t];
  // bang a x b co goc trai tren la i j
  return 1 <= i && i + a - 1 <= n && 1 <= j && j + b - 1 <= m && 
  f[i+a-1][j+b-1] - f[i-1][j+b-1] - f[i+a-1][j-1] + f[i-1][j-1] == 0;
}
void paint(int i, int j, int t) {
  int a = _a[t], b = _b[t];
  col[i][j] += 1;
  col[i][j+b] -= 1;
  col[i+a][j] -= 1;
  col[i+a][j+b] += 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  // (A, B, C) ---> (A, C, B)
  //     |
  //     v
  // (C, B, A)
  // -> 6 hoan vi 
  // 0: A B C
  // 1: A C B
  // 2: B C A
  // 3: B A C -> lien truoc va lien sau
  // 4: C A B
  // 5: C B A
  cin >> A >> B >> C >> n >> m >> k;
  _a[0] = _a[1] = A, _a[2] = _a[3] = B, _a[4] = _a[5] = C;
  _b[0] = _b[5] = B, _b[1] = _b[2] = C, _b[3] = _b[4] = A;
  _c[0] = _c[3] = C, _c[1] = _c[4] = B, _c[2] = _c[5] = A;
  nxt[0] = 1, nxt[1] = 0, nxt[2] = 3, nxt[3] = 2, nxt[4] = 5, nxt[5] = 4;
  pre[0] = 5, pre[1] = 2, pre[2] = 1, pre[3] = 4, pre[4] = 3, pre[5] = 0;
  for (int i = 0, r, c; i < k; ++i) {
    cin >> r >> c;
    f[r][c] = 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
  queue<S> q;
  q.emplace(1, 1, 0);
  vis[1][1][0] = 1;
  paint(1, 1, 0);
  while (!q.empty()) {
    int i = q.front().i, j = q.front().j, t = q.front().t;
    q.pop();
    if (check(i-1, j, t) && !vis[i-1][j][t]) 
      vis[i-1][j][t] = 1, paint(i-1, j, t),
      q.emplace(i-1, j, t);
    if (check(i+1, j, t) && !vis[i+1][j][t])
      vis[i+1][j][t] = 1, paint(i+1, j, t),
      q.emplace(i+1, j, t);
    if (check(i, j-1, t) && !vis[i][j-1][t])
      vis[i][j-1][t] = 1, paint(i, j-1, t),
      q.emplace(i, j-1, t);
    if (check(i, j+1, t) && !vis[i][j+1][t])
      vis[i][j+1][t] = 1, paint(i, j+1, t),
      q.emplace(i, j+1, t);

    if (check(i, j+_b[t], nxt[t]) && !vis[i][j+_b[t]][nxt[t]])
      vis[i][j+_b[t]][nxt[t]] = 1, paint(i, j+_b[t], nxt[t]),
      q.emplace(i, j+_b[t], nxt[t]);
    if (check(i, j-_c[t], nxt[t]) && !vis[i][j-_c[t]][nxt[t]])
      vis[i][j-_c[t]][nxt[t]] = 1, paint(i, j-_c[t], nxt[t]),
      q.emplace(i, j-_c[t], nxt[t]);

    if (check(i+_a[t], j, pre[t]) && !vis[i+_a[t]][j][pre[t]]) 
      vis[i+_a[t]][j][pre[t]] = 1, paint(i+_a[t], j, pre[t]),
      q.emplace(i+_a[t], j, pre[t]);
    if (check(i-_c[t], j, pre[t]) && !vis[i-_c[t]][j][pre[t]]) 
      vis[i-_c[t]][j][pre[t]] = 1, paint(i-_c[t], j, pre[t]),
      q.emplace(i-_c[t], j, pre[t]);
  }
  int res = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      col[i][j] += col[i-1][j] + col[i][j-1] - col[i-1][j-1],
      res += col[i][j] != 0;
  cout << res;
  return 0;
}

