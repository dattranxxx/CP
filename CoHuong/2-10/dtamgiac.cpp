#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "dtamgiac";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
using ld = long double;
const int oo = 1e9;
const int N = 1e3;
ll sqr(ll x) {
  return x * x;
}
const ld eps = 1e-6;
struct T {
  struct P {
    ll x, y;
    P(): x(0), y(0) {}
    ld dis(const P& p) {
      return sqrt(sqr(x - p.x) + sqr(y - p.y));
    }
    friend ll cross(P& a, P& b, P& c) {
      return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    }
    bool inside(T& t) {
      ld s = T(t.a, t.b, *this).s + T(t.b, t.c, *this).s + T(t.c, t.a, *this).s;
      return s - t.s < eps;
    }
    friend istream& operator >> (istream& is, P& p) {
      return is >> p.x >> p.y;
    }
};
  P a, b, c;
  ld s = 0;
  void calc() {
    ld AB = a.dis(b), BC = b.dis(c), CA = c.dis(a);
    ld p = (AB + BC + CA) / 2;
    s = sqrt(p * (p - AB) * (p - BC) * (p - CA));
  }
  T(P a = P(), P b = P(), P c = P()): a(a), b(b), c(c) { calc(); }
  bool inside(T& t) {
    // nam trong tam giac t ?
    return a.inside(t) && b.inside(t) && c.inside(t);
  }
  friend istream& operator >> (istream& is, T& t) {
    is >> t.a >> t.b >> t.c; t.calc(); return is;
  }
  bool operator < (const T& t) const {
    return s < t.s;
  }
} a[N];
int dp[N];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  int res = 1;
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    for (int j = i-1; ~j; --j)
      if (a[j].inside(a[i])) 
        dp[i] = max(dp[i], dp[j] + 1);
    res = max(res, dp[i]);
  }
  cout << (res == 1 ? 0 : res);
  return 0;
}

