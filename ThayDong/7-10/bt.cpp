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
const int V = 1000;
int dis[V+1][V+1], p[21];
int n, m, v;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> v >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> p[i];
  queue<pair<int, int>> q;
  q.emplace(v, 0);
  memset(dis, 0x3f, sizeof(dis));
  dis[v][0] = 0;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second, z = v - (x + y);
    q.pop();
    printf("%d %d %d = %d\n", x, y, z, dis[x][y]);
    if (x == m || y == m || z == m)
      return cout << dis[x][y], 0;
    for (int i = 0; i <= n; ++i) {
      if (x >= p[i]) {
        if (dis[x][y] + 1 < dis[p[i]][y+(x-p[i])])
          dis[p[i]][y+(x-p[i])] = dis[x][y] + 1, q.emplace(p[i], y+(x-p[i]));
        if (dis[x][y] + 1 < dis[p[i]][y])
          dis[p[i]][y] = dis[x][y] + 1, q.emplace(p[i], y);
      }
      if (p[i] > y && x >= (p[i] - y))
        if (dis[x][y] + 1 < dis[x-(p[i]-y)][p[i]])
          dis[x-(p[i]-y)][p[i]] = dis[x][y] + 1, q.emplace(x-(p[i]-y), p[i]);
      if (p[i] > z && x >= (p[i] - z))
        if (dis[x][y] + 1 < dis[x-(p[i]-z)][y])
          dis[x-(p[i]-z)][y] = dis[x][y] + 1, q.emplace(x-(p[i]-z), y);


      if (y >= p[i]) {
        if (dis[x][y] + 1 < dis[x+(y-p[i])][p[i]])
          dis[x+(y-p[i])][p[i]] = dis[x][y] + 1, q.emplace(x+(y-p[i]), p[i]);
        if (dis[x][y] + 1 < dis[x][p[i]])
          dis[x][p[i]] = dis[x][y] + 1, q.emplace(x, p[i]);
      }
      if (p[i] > x && y >= (p[i] - x))
        if (dis[x][y] + 1 < dis[p[i]][y-(p[i]-x)])
          dis[p[i]][y-(p[i]-x)] = dis[x][y] + 1, q.emplace(p[i], y-(p[i]-x));
      if (p[i] > z && y >= (p[i] - z))
        if (dis[x][y] + 1 < dis[x][y-(p[i]-z)])
          dis[x][y-(p[i]-z)] = dis[x][y] + 1, q.emplace(x, y-(p[i]-z));


      if (z >= p[i]) {
        if (dis[x][y] + 1 < dis[x+(z-p[i])][y])
          dis[x+(z-p[i])][y] = dis[x][y] + 1, q.emplace(x+(z-p[i]), y);
        if (dis[x][y] + 1 < dis[x][y+(z-p[i])])
          dis[x][y+(z-p[i])] = dis[x][y] + 1, q.emplace(x, y+(z-p[i]));
      }
      if (p[i] > x && z >= (p[i] - x))
        if (dis[x][y] + 1 < dis[p[i]][y])
          dis[p[i]][y] = dis[x][y] + 1, q.emplace(p[i], y);
      if (p[i] > y && z >= (p[i] - y))
        if (dis[x][y] + 1 < dis[x][p[i]])
          dis[x][p[i]] = dis[x][y] + 1, q.emplace(x, p[i]);
    }
  }
  cout << -1;
  return 0;
}

