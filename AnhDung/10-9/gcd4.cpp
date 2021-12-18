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
const int N = 1e4;
int a[N], cnt[N+1];
bool p[N+1];
vector<int> pr;
ll C[N+1][5];
int n, M;
ll res;
void call(int pos, int cur, int c) {
  int z_cnt = 0;
  for (int i = cur; i <= M; i += cur) 
    z_cnt += cnt[i]; 
  if (c & 1) res -= C[z_cnt][4];
  else res += C[z_cnt][4];
  for (int i = pos + 1; i < pr.size(); ++i) 
    if (cur * pr[i] <= M) call(i, cur * pr[i], c + 1);
  
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  C[0][0] = 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j <= 4; ++j)
      if (j == 0) C[i][j] = C[i-1][j];
      else C[i][j] = C[i-1][j] + C[i-1][j-1]; 
  fill(begin(p), end(p), 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i <= N; ++i) 
    if (p[i]) for (int j = i * i; j <= N; j += i) 
      p[j] = 0;
  for (int i = 2; i <= N; ++i) if (p[i]) pr.push_back(i);
  while (cin >> n) {
    M = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i)
      cin >> a[i], M = max(M, a[i]), cnt[a[i]]++;
    res = 0;
    call(-1, 1, 0);
    cout << res << '\n';
  }
  return 0;
}

