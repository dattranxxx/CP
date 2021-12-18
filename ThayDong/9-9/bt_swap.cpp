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
namespace task_1 {
  unordered_set<int> st[26];
  int check(string& s) {
    for (int i = 0; i < n; ++i) {
      if (st[s[i] - 'a'].count(i)) return 0;
    }
    return 1;
  }
  void solve() {
    for (int c = 0; c < 26; ++c) 
      st[c] = unordered_set<int>();
    for (int i = 0; i < n; ++i)
      st[s[i] - 'a'].insert(i);
    sort(s.begin(), s.end());
    do {
      if (check(s)) {
        cout << s << '\n'; return;
      }
    } while (next_permutation(s.begin(), s.end()));
    cout << "IMPOSSIBLE\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s; n = s.size();
    task_1::solve();
  }
  return 0;
}

