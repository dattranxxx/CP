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
  const string FILE_NAME = "boundseq";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 5e5;
int a[N], L[N], R[N];
int n;
struct segment_tree {
  int n, x, y, z, res;
  vector<int> st;
  segment_tree(int n): n(n), st(n<<2) {
    build(1, 0, n-1); // R
  }
  void build(int k, int l, int r) {
    if (l == r) {
      st[k] = R[l]; return;
    }
    int m = (l + r) >> 1;
    build(k<<1, l, m);
    build(k<<1|1, m+1, r);
    st[k] = max(st[k<<1], st[k<<1|1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y && st[k] >= z) {
      if (l == r) {
        res = min(res, l); return;
      }
      int m = (l + r) >> 1;
      if (st[k<<1] >= z) get(k<<1, l, m);
      else get(k<<1|1, m+1, r);
      return;
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    get(k<<1, l, m);
    if (res != oo) return;
    get(k<<1|1, m+1, r);
  }
  int query(int l, int r, int val) {
    if (l > r) return oo;
    // l nho nhat [0, r] va R[l] >= val
    x = l; y = r; z = val; res = oo; get(1, 0, n-1);
    return res;
  }

};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  // tim [l, r] dai nhat sao cho a[l] <= min(l, r), max(1, r) <= a[r] 
  // <> a[l] = min(l, r), a[r] = max(l, r)
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  stack<int> st;
  for (int i = n-1; ~i; --i) {
    // tim r > i xa nhat thoa man i la min
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    if (!st.empty()) R[i] = st.top() - 1;
    else R[i] = n-1;
    st.push(i);
  }
  st = stack<int>();
  for (int i = 0; i < n; ++i) {
    // tim l < i nho nhat sao cho i la max
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    if (!st.empty()) L[i] = st.top() + 1;
    else L[i] = 0;
    st.push(i);
  }
  segment_tree se(n);
  int res = 1;
  for (int i = 0; i < n; ++i) {
    // tim l nho nhat sao cho l < i & R[l] >= i
    //cerr << i << ' ' << L[i] << '\n';
    int l = min(i, se.query(L[i], i-1, i));
    res = max(res, i - l + 1);
  }
  cout << (res == 1 ? -1 : res);
  return 0;
}

