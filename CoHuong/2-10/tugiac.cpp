#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "tugiac";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
using ld = long double;
const int oo = 1e9;
const double EPS = 1e-9;
ld sqr(ld x) {
  return x * x;
}
struct pt {
  ld x, y;
  pt(): x(0), y(0) {}
  friend ll cross(pt& a, pt& b, pt& c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  }
  ld dis(const pt& p) {
    return sqrt(sqr(x - p.x) + sqr(y - p.y));
  }
  bool operator<(const pt& p) const {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
} a[4];
ld quad_area() {
  ld res = 0;
  for (int i = 0; i < 4; ++i) {
    pt p = i ? a[i-1] : a[3];
    pt q = a[i];
    res += (p.x - q.x) * (p.y + q.y);
  }
  return fabs(res) / 2;
}

struct line {
    double a, b, c;

    line() {}
    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    double dist(pt p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

inline bool betw(double l, double r, double x)
{
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(double a, double b, double c, double d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    } else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}
ld tri_area(pt a, pt b, pt c) {
  ld AB = a.dis(b), BC = b.dis(c), CA = c.dis(a);
  ld p = (AB + BC + CA) / 2;
  return sqrt(p * (p - AB) * (p - BC) * (p - CA));
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  for (int i = 0; i < 4; ++i)
    cin >> a[i].x >> a[i].y;
  int ccw = 0, cw = 0;
  for (int i = 0; i < 4; ++i) {
    int c = cross(a[i], a[(i + 1) % 4], a[(i + 2) % 4]);
    if (c == 0) {
      cout << 0; return 0;
    }
    if (c > 0) ccw++;
    else cw++;
  }
  if (cw == 4 || ccw == 4) {
    cout << 1 << '\n' << fixed << setprecision(3) << quad_area();
  } else if ((cw == 3 && ccw == 1) || (ccw == 3 || cw == 1)) {
    cout << 2 << '\n' << fixed << setprecision(3) << quad_area();
  } else {
    cout << 3 << '\n';
    pt p, _;
    if (intersect(a[0], a[1], a[2], a[3], p, _)) {
      // [0-1] / [2-3]
      cout << fixed << setprecision(3) << tri_area(a[1], a[2], p) + tri_area(a[0], a[3], p);
    } else if (intersect(a[1], a[2], a[0], a[3], p, _)) {
      // [1-2] / [3-0]
      cout << fixed << setprecision(3) << tri_area(a[0], a[1], p) + tri_area(a[2], a[3], p);
    }
  }
  return 0;
}

