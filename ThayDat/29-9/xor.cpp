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
const ll oo = 1e17;
const int N = 1e5;
int a[N];
unordered_map<int, pair<ll, int>> dp[30]; 
int val[30][2];
vector<int> L, R;
int n, k;
pair<ll, int> call(int pos, int smaller, int larger, int rem) {
  if (pos == int(L.size())) 
    if (rem == 0) return {0, 1};
    else return {-oo, 0};
  if (smaller && larger && dp[pos].count(rem)) 
    return dp[pos][rem];
  int b = larger ? 0 : L[pos];
  int e = smaller ? 1 : R[pos];
  ll res = -oo, ans = 0;
  int idx = L.size() - pos - 1;
  pair<ll, int> p;
  for (int i = b; i <= e; ++i) {
    p = call(pos + 1, smaller | (i < R[pos]), larger | (i > L[pos]), ((rem * 2) + i) % k);
    p.first += (1LL << idx) * val[pos][i]; 
    if (p.first > res) {
      res = p.first; ans = p.second;
    } else if (p.first == res) {
      ans += p.second;
    }
  }
  if (smaller && larger) 
    dp[pos][rem] = {res, ans};
  return {res, ans};
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int l, r;
  cin >> n >> l >> r >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  if (k >= 3e4) {
    ll res = -oo, ans = 0, cur = 0;
    for (int x = ((l + k - 1) / k) * k; x <= r; x += k) {
      cur = 0;
      for (int i = 0; i < n; ++i) 
        cur += a[i] ^ x;
      if (cur > res) res = cur, ans = 1;
      else if (cur == res) ans += 1;
    }
    cout << res << '\n' << ans;
  } else {
    while (l || r) {
      L.emplace_back(l % 2); l /= 2;
      R.emplace_back(r % 2); r /= 2;
    }
    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());
    for (int i = 0; i < int(L.size()); ++i) {
      int idx = L.size() - i - 1;
        for (int j = 0; j < n; ++j)
          val[i][0] += (a[j] >> idx & 1),
          val[i][1] += (a[j] >> idx & 1) ^ 1;
    }
    auto p = call(0, 0, 0, 0);
    cout << p.first << '\n' << p.second;
  }
  return 0;
}

