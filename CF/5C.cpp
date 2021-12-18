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
const int N = 1e6;
int dp[N + 1];
string s;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> s;
  int n = s.size(); 
  s = ' ' + s;
  stack<int> st;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') st.push(i);
    else if (!st.empty()) {
      dp[i] = dp[st.top() - 1] + (i - st.top() + 1);
      st.pop();
      res = max(res, dp[i]);
    }
  }
  if (res == 0) {
    printf("0 1"); return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    cnt += dp[i] == res;
  cout << res << ' ' << cnt;
  return 0;
}

