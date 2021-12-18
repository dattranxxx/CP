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
  const string FILE_NAME = "connect";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const ll oo = 1e15;
const int N = 2e5;
ll a[N];
int n; ll D;
namespace kruskal {
  struct E {
    int u, v; ll w;
    E(int u, int v, ll w): u(u), v(v), w(w) {}
    bool operator < (const E& e) const {
      return w < e.w;
    }
  };
  int li[N], sz[N];
  int find(int u) {
    if (u == li[u]) return u;
    return li[u] = find(li[u]);
  }
  ll res = 0, cnt;
  void unite(int u, int v, ll w) {
    u = find(u); v = find(v);
    if (u == v) return;
    res += w; cnt--;
    if (sz[u] < sz[v]) swap(u, v);
    li[v] = u; sz[u] += sz[v];
  }
  void solve() {
    vector<E> e; e.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        e.emplace_back(i, j, ll(a[i]) + a[j] + (j - i) * D);
    sort(e.begin(), e.end());
    for (int i = 0; i < n; ++i)
      li[i] = i, sz[i] = 1;
    cnt = n;
    for (E& c : e) {
      unite(c.u, c.v, c.w);
      if (cnt == 1) break;
    }
    cout << res;
  }
};
namespace boruvka {
  struct segment_tree {
    struct node {
      ll min[2]; int idx[2];
      node() {}
    };
    int n, x, y, idx, t; ll val, res;
    vector<node> st;
    segment_tree(int n): n(n), st(n << 2) { build(1, 0, n-1); }
    void build(int k, int l, int r) {
      if (l == r) {
        st[k].min[0] = a[l] - D * l; 
        st[k].min[1] = a[l] + D * l; 
        st[k].idx[0] = st[k].idx[1] = l; return;
      }
      int m = (l + r) >> 1;
      build(k<<1, l, m);
      build(k<<1|1, m+1, r);
      for (int i = 0; i <= 1; ++i) {
        if (st[k<<1].min[i] < st[k<<1|1].min[i]) {
          st[k].min[i] = st[k<<1].min[i];
          st[k].idx[i] = st[k<<1].idx[i];
        } else {
          st[k].min[i] = st[k<<1|1].min[i];
          st[k].idx[i] = st[k<<1|1].idx[i];
        }
      }
    }
    void update(int k, int l, int r) {
      if (l > x || r < x) return;
      if (l == r) {
        st[k].min[0] += val; 
        st[k].min[1] += val; return;
      }
      int m = (l + r) >> 1;
      update(k<<1, l, m);
      update(k<<1|1, m+1, r);
      for (int i = 0; i <= 1; ++i) {
        if (st[k<<1].min[i] < st[k<<1|1].min[i]) {
          st[k].min[i] = st[k<<1].min[i];
          st[k].idx[i] = st[k<<1].idx[i];
        } else {
          st[k].min[i] = st[k<<1|1].min[i];
          st[k].idx[i] = st[k<<1|1].idx[i];
        }
      } 
    }
    void get(int k, int l, int r) {
      if (l > y || r < x) return;
      if (l >= x && r <= y) {
        if (st[k].min[t] < res) {
          res = st[k].min[t];
          idx = st[k].idx[t];
        }
        return;
      }
      int m = (l + r) >> 1;
      get(k<<1, l, m);
      get(k<<1|1, m+1, r);
    }
    void change(int i, ll v) {
      x = i; val = v; 
      update(1, 0, n-1);
    }
    pair<int, ll> query(int l, int r, int f) {
      x = l; y = r; res = oo; idx = -1; t = f;
      if (l <= r) get(1, 0, n-1);
      return {idx, res};
    }

  };
  int li[N], sz[N];
  vector<int> comp[N];
  int find(int u) {
    if (u == li[u]) return u;
    return li[u] = find(li[u]);
  }
  ll res = 0; int cnt;
  void unite(int u, int v, ll w) {
    u = find(u); v = find(v);
    if (u == v) return;
    res += w; cnt--;
    if (sz[u] < sz[v]) swap(u, v);
    li[v] = u; sz[u] += sz[v];
  }  
  void solve() {
    segment_tree st(n);
    for (int i = 0; i < n; ++i)
      li[i] = i, sz[i] = 1;
    cnt = n;
    while (cnt > 1) {
      for (int i = 0; i < n; ++i)
        comp[i].clear();
      for (int i = 0; i < n; ++i)
        comp[find(i)].push_back(i);
      for (int i = 0; i < n; ++i) if (comp[i].size()) {
        // remove vertices
        for (int v : comp[i]) st.change(v, oo);
        // get minimum edge
        int best_u = -1, best_v = -1; ll wei = oo;
        pair<int, ll> p;
        for (int v : comp[i]) {
          p = st.query(0, v-1, 0);
          if (p.first != -1 && a[v] + D * v + p.second < wei) {
            wei = a[v] + D * v + p.second; best_u = v; best_v = p.first;
          }
          p = st.query(v+1, n-1, 1); 
          if (p.first != -1 && a[v] - D * v + p.second < wei) {
            wei = a[v] - D * v + p.second; best_u = v; best_v = p.first;
          }
        }
        // new edge
        if (best_u != -1) unite(best_u, best_v, wei);
        // add vertice
        for (int v : comp[i]) st.change(v, -oo);

        if (cnt == 1) break;
      }
    }
    cout << res;
  }
};








namespace boruvka_d0 {
  struct segment_tree {
    struct node {
      ll min; int idx;
      node(): min(0), idx(0) {}
    };
    int n, x, y; ll val;
    vector<node> st;
    segment_tree(int n): n(n), st(n << 2) { build(1, 0, n-1); }
    void build(int k, int l, int r) {
      if (l == r) {
        st[k].min = a[l]; 
        st[k].idx = l; return;
      }
      int m = (l + r) >> 1;
      build(k<<1, l, m);
      build(k<<1|1, m+1, r);
      if (st[k<<1].min < st[k<<1|1].min) {
        st[k].min = st[k<<1].min;
        st[k].idx = st[k<<1].idx;
      } else {
        st[k].min = st[k<<1|1].min;
        st[k].idx = st[k<<1|1].idx;
      }
    }
    void update(int k, int l, int r) {
      if (l > x || r < x) return;
      if (l == r) {
        st[k].min += val; return;
      }
      int m = (l + r) >> 1;
      update(k<<1, l, m);
      update(k<<1|1, m+1, r);
      if (st[k<<1].min < st[k<<1|1].min) {
        st[k].min = st[k<<1].min;
        st[k].idx = st[k<<1].idx;
      } else {
        st[k].min = st[k<<1|1].min;
        st[k].idx = st[k<<1|1].idx;
      } 
    }
    void change(int i, ll v) {
      x = i; val = v; 
      update(1, 0, n-1);
    }

  };
  int li[N], sz[N];
  vector<int> comp[N];
  int find(int u) {
    if (u == li[u]) return u;
    return li[u] = find(li[u]);
  }
  ll res = 0; int cnt;
  void unite(int u, int v, ll w) {
    u = find(u); v = find(v);
    if (u == v) return;
    res += w; cnt--;
    if (sz[u] < sz[v]) swap(u, v);
    li[v] = u; sz[u] += sz[v];
  }  
  void solve() {
    segment_tree st(n);
    for (int i = 0; i < n; ++i)
      li[i] = i, sz[i] = 1;
    cnt = n;
    while (cnt > 1) {
      for (int i = 0; i < n; ++i)
        comp[i].clear();
      for (int i = 0; i < n; ++i)
        comp[find(i)].push_back(i);
      for (int i = 0; i < n; ++i) if (comp[i].size()) {
        // remove vertices
        int best_u = comp[i][0];
        for (int v : comp[i]) {
          st.change(v, oo);
          if (a[v] < a[best_u]) best_u = v;
        }
        // get minimum edge
        int best_v = st.st[1].idx; ll wei = a[best_u] + st.st[1].min;
        // new edge
        unite(best_u, best_v, wei);
        // add vertice
        for (int v : comp[i]) st.change(v, -oo);
         
        if (cnt == 1) break;
      }
    }
    cout << res;
  }
};







int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> D;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  if (n <= 1000) kruskal::solve();
  else if (D == 0) boruvka_d0::solve();
  else boruvka::solve();
  return 0;
}

