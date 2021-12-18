/*
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
void file() {
  const string FILE_NAME = "btcd";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 1e5;
int n, m, q;
struct Q {
	int u, v, i, l, r, ans;
	Q(): u(0), v(0), i(0), l(0), r(int(1e9)), ans(0) {}
	friend istream& operator >> (istream& is, Q& q) {
		return is >> q.u >> q.v;
	}
	bool operator < (const Q& q) const {
		return ((l + r) >> 1) < ((q.l + q.r) >> 1);
	}
};
struct E {
	int u, v, w;
	E(int u, int v, int w): u(u), v(v), w(w) {}
	bool operator < (const E& e) const {
		return w < e.w;
	}
};
int li[N];
int find(int u) {
	if (u == li[u]) return u;
	return li[u] = find(li[u]);
}
void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	li[v] = u;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m; 
  vector<E> e; e.reserve(m);
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    e.push_back(E(u, v, w));
  } 
	sort(e.begin(), e.end());
	cin >> q;
	vector<Q> qrs(q);
	for (int i = 0; i < q; ++i) 
		cin >> qrs[i], qrs[i].u--, qrs[i].v--, qrs[i].i = i;
	for (int r = 0; r <= log2(1e9) + 1; ++r) {
		for (int i = 0; i < n; ++i) li[i] = i;
		sort(qrs.begin(), qrs.end());
		int j = e.size() - 1;
		for (int i = q-1; ~i; --i) {
			if (qrs[i].l > qrs[i].r) continue;
			int m = (qrs[i].l + qrs[i].r) >> 1;
			while (j && e[j].w >= m) {
				unite(e[j].u, e[j].v); j--;
			}
			if (find(qrs[i].u) == find(qrs[i].v)) {
				qrs[i].ans = m;
				qrs[i].l = m + 1;
			} else {
				qrs[i].r = m - 1;
			}
		}
	}
	vector<int> res(q);
	for (int i = 0; i < q; ++i)
		res[qrs[i].i] = qrs[i].ans;
	for (int i = 0; i < q; ++i)
		cout << res[i] << '\n';
  return 0;
}
