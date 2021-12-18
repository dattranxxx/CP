                 /*..... .
                 .';:;;;;'':.
                .:::::::::cl'
                .c;;o,.cc::::.
                ';l:.. ..;;;;.
                 .,::.'',:...
                  '.'cxdo;..d.
                  d..:olo.'dO.
                  kk. .. :kOO.
                 .k0k...'000d.
                  c00'.,00k:..
                  l00..xOk;..co'
                 .l00cdOO, ...oO;.
           .,;;. .:ld::do  .  .OOx'.
       ,cokcc,......;. ..      oOO00Oooc'
    .oOOOc..... .......      ..oK000OOOOOl.
   :OOOO:....    .'...      .lO0KK000OOOOOOo.
   ,OOO00;  ..   .           x0KK0000OOOOOOO:.
    'ck00k.  ...  ...... ... ':000OOOOOOOOOk;.
      :OOO0kdld:':O0:.,,,l'.':'OOOOOOo:l:;'.
       .;ooolOOOOOO000O00000OOOOOOx:..
             .''....;coolc,'',;.*/
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 105;
int calc(int x) {
  int res = 0;
  while (x) {
    res += x % 10; if (res >= 9) res -= 9; x /= 10;
  }
  return res;
}
struct S {
  string s; int r;
  S(): s(""), r(0) {}
  S(string s, int r): s(s), r(r) {}
  friend istream& operator >> (istream& is, S& s) {
    int x = 0; is >> x; s = S(to_string(x), calc(x)); return is;
  }
  int len() {
    return s.size();
  }
} a[N];
int n, k;
int dp[N][N][10], tr[N][N][10];
// do dai dai nhat 
int call(int pos, int cnt, int rem) {
  if (pos == n) return rem == 0 && cnt == k ? 0 : -oo;
  if (dp[pos][cnt][rem] != -1) return dp[pos][cnt][rem];
  if (call(pos + 1, cnt + 1, (rem + a[pos].r) % 9) + a[pos].len() >= call(pos + 1, cnt, rem)) {
    dp[pos][cnt][rem] = call(pos + 1, cnt + 1, (rem + a[pos].r) % 9) + a[pos].len();
    tr[pos][cnt][rem] = 1;
  } else {
    dp[pos][cnt][rem] = call(pos + 1, cnt, rem);
    tr[pos][cnt][rem] = 0;
  }
  return dp[pos][cnt][rem];
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) 
      cin >> a[i];
    // 2 lan dp: tim max len va tim max alphabet
    sort(a, a + n, [&](S& u, S& v) {
      return u.s + v.s > v.s + u.s;
    });
    memset(dp, -1, sizeof(dp));
    if (call(0, 0, 0) <= 0) {
      cout << -1 << '\n'; continue;
    }
    int pos = 0, cnt = 0, rem = 0;
    while (pos < n) {
      if (tr[pos][cnt][rem]) {
        cout << a[pos].s;
        cnt += 1; rem = (rem + a[pos].r) % 9;
      } 
      pos += 1;
    }
    cout << '\n';
  }
  return 0;
}

