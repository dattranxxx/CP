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
using ull = unsigned long long;
void file() {
  const string FILE_NAME = "gen";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e6, base = 31, mod = 1e9 + 7;
int n;
struct hash_string {
  vector<pair<int, ull>> h;
  hash_string() {}
  hash_string(string& s): h(s.size()) {
    h[0].first = h[0].second = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); ++i) {
      h[i].first = (ll(h[i-1].first) * base % mod + s[i] - 'a' + 1) % mod;
      h[i].second = h[i-1].second * base + s[i] - 'a' + 1;
    }
  }
  friend istream& operator >> (istream& is, hash_string& hs) {
    string s; cin >> s; hs = hash_string(s); return is;
  }
  pair<int, ull> operator [] (int r) {
    return h[min(int(h.size()) - 1, r)];
  } 
  int size() {
    return h.size();
  }

} s[N];
int check(int r) {
  vector<pair<int, ull>> h; h.reserve(n);
  for (int i = 0; i < n; ++i)
    h.emplace_back(s[i][r]);
  sort(h.begin(), h.end());
  h.erase(unique(h.begin(), h.end()), h.end());
  return h.size() == n;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  int maxlen = -oo;
  for (int i = 0; i < n; ++i)
    cin >> s[i], maxlen = max(maxlen, int(s[i].size()));
  int lo = 1, hi = maxlen, mid, ans = maxlen;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (check(mid - 1)) {
      ans = mid; 
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans;
  return 0;
}

