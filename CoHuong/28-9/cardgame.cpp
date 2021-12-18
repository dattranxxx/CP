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
void file() {
  const string file_name = "cardgame";
  freopen((file_name + ".in").c_str(), "r", stdin);
  freopen((file_name + ".out").c_str(), "w", stdout);
}
using ll = long long;
const ll oo = 1e18;
const int N = 16;
ll dp[1 << N];
int a[N], b[N];
int n;
ll Call(int mask, int cnt) {
  if (cnt == 1) return 0;
  if (dp[mask] != -1) return dp[mask];
  ll res = oo;
  for (int i = 0; i < n; ++i) if (mask & (1 << i))
    for (int j = i + 1; j < n; ++j) if (mask & (1 << j))
      res = min(res, min(Call(mask ^ (1 << i), cnt - 1),
                         Call(mask ^ (1 << j), cnt - 1)) + min(a[i] ^ b[j], a[j] ^ b[i]));
  return dp[mask] = res;
}
ll call(int mask, int cnt) {
  if (cnt == 1) return 0;
  if (dp[mask] != -1) return dp[mask];
  ll res = oo; 
  set<pair<int, int>> st_a; 
  set<pair<int, int>> st_b; 
  for (int i = 0; i < n; ++i) if (mask & (1 << i))
    st_a.insert({a[i], i}), st_b.insert({b[i], i});
  auto it_a = st_a.begin();
  auto it_b = st_b.begin();
  for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
    st_a.erase({a[i], i}); st_b.erase({b[i], i});
    int min_xor = 2e9;
    it_a = st_a.lower_bound({b[i], 0});
    if (it_a != st_a.end()) {
      min_xor = min(min_xor, b[i] ^ a[it_a->second]);
    }
    it_a = st_a.upper_bound({b[i], 0});
    if (it_a != st_a.begin()) {
      it_a--;
      min_xor = min(min_xor, b[i] ^ a[it_a->second]);
    }
    it_b = st_b.lower_bound({a[i], 0});
    if (it_b != st_b.end()) {
      min_xor = min(min_xor, a[i] ^ b[it_b->second]);
    }
    it_b = st_b.upper_bound({a[i], 0});
    if (it_b != st_b.begin()) {
      it_b--;
      min_xor = min(min_xor, a[i] ^ b[it_b->second]);
    }
    res = min(res, call(mask ^ (1 << i), cnt - 1) + min_xor);
    st_a.insert({a[i], i}); st_b.insert({b[i], i});
  } 
  return dp[mask] = res;
}
int main() {
  file();
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << Call((1 << n) - 1, n) << '\n';
  }
  return 0;
}

