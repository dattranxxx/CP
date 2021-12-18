/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
struct tree {
  struct node {
    int v[2], siz;
    node(): siz(0) { v[0] = v[1] = -1; }
  };
  vector<node> tr;
  tree(): tr(1) {}
  void add(int x) {
    int u = 0;
    for (int i = 30; ~i; --i) {
      if (tr[u].v[!!(x & (1 << i))] == -1) {
        tr[u].v[!!(x & (1 << i))] = tr.size();
        tr.emplace_back();
      }
      u = tr[u].v[!!(x & (1 << i))];
    }
    tr[u].siz += 1;
  }
  void build(int u = 0) {
    if (tr[u].v[0] != -1)
      build(tr[u].v[0]), tr[u].siz += tr[tr[u].v[0]].siz;
    if (tr[u].v[1] != -1) 
      build(tr[u].v[1]), tr[u].siz += tr[tr[u].v[1]].siz;
  } 
  int k_th(int k, int x) {
    int u = 0, res = 0;
    for (int i = 30; ~i; --i) {
      int left = tr[u].v[0], right = tr[u].v[1];
      res *= 2;
      if (x & (1 << i)) swap(left, right);
      if (left != -1 && k > tr[right].siz) {
        k -= tr[right].siz;
        u = left;
      } else if (right != -1) {
        u = right;
        res += 1;
      } else {
        assert(0);
      }
    }
    return res;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  tree tr;
  for (int i = 0, x; i < n; ++i)
    cin >> x, tr.add(x);
  tr.build();
  int x = 0, k; string s;
  while (q--) {
    cin >> s >> k;
    if (s[0] == 'F') {
      cout << tr.k_th(k, x) << '\n';
    } else {
      x ^= k;
    }
  }
  return 0;
}

