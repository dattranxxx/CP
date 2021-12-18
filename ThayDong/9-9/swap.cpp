/*                 ..... .
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
             .''....;coolc,'',;.                */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
string s;
int n;
int poi[26], cnt[26]; 
vector<char> idx[26];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s; n = s.size();
    memset(poi, 0, sizeof(poi));
    memset(cnt, 0, sizeof(cnt));
    for (int c = 0; c < 26; ++c)
      idx[c].clear();
    vector<pair<int, char>> a;
    for (char ch : s) cnt[ch-'a']++;
    for (int c = 0; c < 26; ++c)
      if (cnt[c]) a.push_back({cnt[c], c + 'a'});
    sort(a.rbegin(), a.rend());
    if (a[0].first > n/2) {
      cout << "IMPOSSIBLE\n"; continue;
    }
    string u, v;
    for (int i = 0; i < a.size(); ++i)
      u += string(a[i].first, a[i].second);
    for (int i = 1; i < a.size(); ++i) 
      v += string(a[i].first, a[i].second);
    v += string(a[0].first, a[0].second);
    for (int i = 0; i < n; ++i) {
      int c = u[i] - 'a';
      idx[c].push_back(v[i]); 
    }
    for (char ch : s) {
      int c = ch - 'a';
      cout << idx[c][poi[c]];
      poi[c]++;
    }
    cout << '\n';
  }
  return 0;
}

