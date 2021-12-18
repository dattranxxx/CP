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
void file() {
  const string FILE_NAME = "cutting";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 2e5 + 1;
int a[N]; ll f[N];
int n, m;
struct segment_tree {
  int n, x, y;
  ll z, res;
  vector<ll> st, lz;
  segment_tree(int n): n(n), st(n<<2), lz(n<<2) {}
  void push(int k) {
    int t = lz[k]; lz[k] = 0;
    st[k<<1] += t; lz[k<<1] += t;
    st[k<<1|1] += t; lz[k<<1|1] += t;
  }
  void update(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      st[k] += z; lz[k] += z; return;
    }
    push(k);
    int m = (l + r) >> 1;
    update(k<<1, l, m);
    update(k<<1|1, m+1, r);
    st[k] = min(st[k<<1], st[k<<1|1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      res = min(res, st[k]); return;
    }
    push(k);
    int m = (l + r) >> 1;
    get(k<<1, l, m);
    get(k<<1|1, m+1, r);
  }
  void add(int l, int r, ll v) {
    x = l; y = r; z = v;
    update(1, 0, n-1);
  }
  ll query(int l, int r) {
    x = l; y = r; res = oo;
    get(1, 0, n-1);
    return res;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) 
    cin >> a[i], f[i] = f[i-1] + a[i];
  stack<int> st;
  segment_tree se(n);
  // dp[i] = min(dp[j] + max) -> update(max)
  for (int i = 1; i <= n; ++i) {
    // update dp[st.top()-1] -> dp[cur-1]
    se.add(i-1, i-1, a[i]);
    while (!st.empty() && a[st.top()] < a[i]) {
      int cur = st.top(); st.pop();
      int pre = st.empty() ? 1 : st.top() + 1;
      se.add(pre-1, cur-1, a[i] - a[cur]); 
    } 
    st.push(i);
    int lo = 1, hi = i, mid, ans = 0; // chat tim l-1
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (f[i] - f[mid-1] <= m) {
        ans = mid; 
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (!ans) {
      cout << -1; return 0;
    }
    int x = se.query(ans-1, i-1); // l min sao cho f[i] - f[l-1] <= m <> f[l-1] >= f[i]-m
    if (i == n) {
      cout << x; return 0;
    }
    se.add(i, i, x);
  }
  return 0;
}

