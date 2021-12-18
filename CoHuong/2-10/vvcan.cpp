#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "vvcan";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
using ld = long double;
const int oo = 1e9;
const int N = 50;
ll sqr(ll x) {
  return x * x;
}
struct P {
  ll x, y;
  P(): x(0), y(0) {}
  P(ll x, ll y): x(x), y(y) {}
  ld dis(const P& p) {
    return sqrt(sqr(x - p.x) + sqr(y - p.y));
  }
  friend ll cross(P& a, P& b, P& c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  }
  friend istream& operator >> (istream& is, P& p) {
    return is >> p.x >> p.y;
  }
  friend ostream& operator << (ostream& os, const P& p) {
    return os << '[' << p.x << ", " << p.y << ']';
  }
};
struct S {
  P a, b, c, d;
  ll e;
  friend istream& operator >> (istream& is, S& s) {
    ll x, y;
    is >> x >> y >> s.e;
    s.a = P(x, y), s.b = P(x + s.e, y), s.c = P(x + s.e, y + s.e), s.d = P(x, y + s.e);
    return is;
  }
} a[N];
ld dis[N * 4 + 2];
int n;
int orien(P p, P q, P r) {
  ll val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0; 
  return (val > 0) ? 1: 2;
}
bool intersect(P& p1, P& q1, P& p2, P& q2) {
  int o1 = orien(p1, q1, p2),
      o2 = orien(p1, q1, q2),
      o3 = orien(p2, q2, p1),
      o4 = orien(p2, q2, q1);
  if (o1 == 0 || o2 == 0 || o3 == 0 || o4 == 0) return 0;
  if (o1 != o2 && o3 != o4) return 1;
  return 0;
}
bool onSegment(P p, P q, P r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
      q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
     return 1;
  return 0;
}
bool check(P& u, P& v) {
  for (int i = 0; i < n; ++i) {
    if (intersect(u, v, a[i].a, a[i].b)) return 0;
    if (intersect(u, v, a[i].b, a[i].c)) return 0;
    if (intersect(u, v, a[i].c, a[i].d)) return 0;
    if (intersect(u, v, a[i].d, a[i].a)) return 0;
    if (orien(u, v, a[i].a) == 0 && orien(u, v, a[i].c) == 0) return 0;
    if (orien(u, v, a[i].b) == 0 && orien(u, v, a[i].d) == 0) return 0;
  }
  return 1;
}
struct T {
  int u; ld d;
  T(int u, ld d): u(u), d(d) {}
  bool operator < (const T& t) const {
    return d > t.d;
  }
};
int tra[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  vector<P> V;
  V.emplace_back(0, 0);
  for (int i = 0; i < n; ++i)
    cin >> a[i],
    V.emplace_back(a[i].a),
    V.emplace_back(a[i].b),
    V.emplace_back(a[i].c),
    V.emplace_back(a[i].d);
  V.emplace_back(100, 100);
  fill(begin(dis), end(dis), oo);
  priority_queue<T> q;
  dis[0] = 0; q.emplace(0, 0);
  while (!q.empty()) {
    T t = q.top(); q.pop();
    if (t.d != dis[t.u]) continue;
    for (int v = 0; v < V.size(); ++v) if (v != t.u) {
      if (!check(V[t.u], V[v])) continue;
      ld d = V[t.u].dis(V[v]);
      if (dis[t.u] + d < dis[v]) {
        dis[v] = dis[t.u] + d;
        tra[v] = t.u;
        q.emplace(v, dis[v]);
      } 
    }
  }
  cout << fixed << setprecision(3) << dis[V.size() - 1] << '\n';
  vector<int> t;
  int i = tra[V.size() - 1];
  while (i > 0) {
    t.emplace_back(i);
    i = tra[i];
  }
  vector<int> res;
  for (int i = 0; i < t.size();) {
    res.emplace_back(t[i]);
    int j = i + 2;
    while (j < t.size() && cross(V[t[i]], V[t[i+1]], V[t[j]]) == 0) j++;
    i = j - 1;
  }
  cout << res.size() << '\n';
  reverse(res.begin(), res.end());
  for (int i = 0; i < res.size(); ++i)
    cout << V[res[i]].x << ' ' << V[res[i]].y << '\n';
  return 0;
}

