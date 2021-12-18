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
  const string FILE_NAME = "archer";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
struct P {
  int x, y, z;
  P(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
  bool operator < (const P& p) const {
    if (x == p.x)
      if (y == p.y) return z < p.z;
      else return y < p.y;
    else return x < p.x;
  }
  bool operator == (const P& p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  friend ostream& operator << (ostream& os, const P& p) {
    return os << '[' << p.x << ", " << p.y << " ," << p.z << ']';
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int n;
  cin >> n;
  vector<P> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i].x >> a[i].y >> a[i].z;
  int res = 1;
  for (int i = 0; i < n; ++i) {
    vector<P> b; b.reserve(n - 1);
    int c = 0;
    for (int j = 0; j < n; ++j) if (a[j].z != a[i].z) 
      b.emplace_back(a[j].x - a[i].x, a[j].y - a[i].y, a[j].z - a[i].z);
    else if (a[i].x == a[j].x && a[i].y == a[j].y) c++;
    for (P& p : b) {
      int g;
      if (p.x == 0 && p.y == 0) continue;
      else if (p.x == 0) g = __gcd(p.z, p.y);
      else if (p.y == 0) g = __gcd(p.z, p.x);
      else g = __gcd(p.z, __gcd(p.x, p.y));
      p.x /= g, p.y /= g, p.z /= g;
    }
    sort(b.begin(), b.end());
    for (int j = 0, k; j < b.size();) {
      k = j + 1;
      while (k < b.size() && b[k] == b[j]) k++;
      res = max(res, k - j + c), j = k;
    }
  }
  cout << res;
  return 0;
}

