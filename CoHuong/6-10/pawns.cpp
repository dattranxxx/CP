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
  const string FILE_NAME = "pawns";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 13;
int dp[1594323], tr[1594323], pw[N];
int n, fin = 0;
void call(int mask, int curw, int curb) {
  if (mask == fin)
    return dp[mask] = 0, void();
  if (dp[mask])
    return;
  dp[mask] = oo;
  int nmask, used = curw ^ curb;
  for (int i = n-1; ~i; --i) {
    if (curb & (1 << i)) {
      if (i + 1 < n && !(used >> (i + 1) & 1)) {
        nmask = mask - pw[i]*2 + pw[i+1]*2;
        call(nmask, curw, curb ^ (1 << i) ^ (1 << (i + 1)));
        if (dp[mask] > dp[nmask] + 1) 
          dp[mask] = dp[nmask] + 1, tr[mask] = i;
      }
      if (i + 2 < n && (used >> (i + 1) & 1) && !(used >> (i + 2) & 1)) {
        nmask = mask - pw[i]*2 + pw[i+2]*2;
        call(nmask, curw, curb ^ (1 << i) ^ (1 << (i + 2)));
        if (dp[mask] > dp[nmask] + 1)
          dp[mask] = dp[nmask] + 1, tr[mask] = i;
      }
    } else if (curw & (1 << i)) {
      if (i - 1 >= 0 && !(used >> (i - 1) & 1)) {
        nmask = mask - pw[i] + pw[i-1];
        call(nmask, curw ^ (1 << i) ^ (1 << (i - 1)), curb);
        if (dp[mask] > dp[nmask] + 1)
          dp[mask] = dp[nmask] + 1, tr[mask] = i;
      }
      if (i - 2 >= 0 && (used >> (i - 1) & 1) && !(used >> (i + 2) & 1)) {
        nmask = mask - pw[i] + pw[i-2];
        call(nmask, curw ^ (1 << i) ^ (1 << (i - 2)), curb);
        if (dp[mask] > dp[nmask] + 1)
          dp[mask] = dp[nmask] + 1, tr[mask] = i;      
      }
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  pw[0] = 1;
  for (int i = 1; i < n; ++i)
    pw[i] = pw[i-1] * 3;
  int mask = 0, curw = 0, curb = 0, w = 0, b = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    mask += x * pw[i];
    if (x == 1) w++, curw ^= 1 << i;
    else if (x == 2) b++, curb ^= 1 << i;
  }
  for (int i = 0; i < w; ++i)
    fin += pw[i];
  for (int i = n-1; i >= n-b; --i)
    fin += 2 * pw[i];
  call(mask, curw, curb);
  cout << dp[mask] << '\n';
  for (int i = tr[mask]; mask != fin; i = tr[mask]) {
    cout << i + 1 << ' ';
    int used = curw ^ curb;
    if (curb >> i & 1) {
      mask -= pw[i] << 1, curb ^= 1 << i;
      if (!(used >> (i + 1) & 1)) {
        mask += pw[i + 1] << 1, curb ^= 1 << (i + 1);
      } else /* if () */ {
        mask += pw[i + 2] << 1, curb ^= 1 << (i + 2);
      }
    } else /* if (curw >> i & 1) */ {
      mask -= pw[i], curw ^= 1 << i;
      if (!(used >> (i - 1) & 1)) {
        mask += pw[i - 1], curw ^= 1 << (i - 1);
      } else /* if () */ {
        mask += pw[i - 2], curw ^= 1 << (i - 2);
      }
    }
  }
  return 0;
}

