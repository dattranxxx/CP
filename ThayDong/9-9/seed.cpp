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
const int K = 2;
struct trie {
  struct node {
    int nxt[K], go[K], link; 
    bool leaf; 
    node(): leaf(0), link(0) {}
  };
  vector<node> tri;
  trie(): tri(1) {}
  #define nxt(v, c) tri[v].nxt[c]
  #define link(v) tri[v].link
  bool& leaf(int v) {
    return tri[v].leaf;
  }
  int& go(int v, int c) {
    return tri[v].go[c];
  }
  void add(string& s) {
    int v = 0;
    for (char ch : s) {
      int c = ch - '0';
      if (!nxt(v, c)) {
        nxt(v, c) = tri.size();
        tri.emplace_back();
      } 
      v = nxt(v, c);
    }
    leaf(v) = 1;
  }
  void build() {
    queue<int> q; q.push(0);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      leaf(u) |= leaf(link(u));
      for (int c = 0; c < K; ++c) {
        int v = nxt(u, c);
        if (v) {
          link(v) = u ? go(link(u), c) : 0;
          go(u, c) = v;
          q.push(v);
        } else go(u, c) = go(link(u), c);
      }
    }
  }
  int size() {
    return tri.size();
  }
} tri;
const int N = 50;
int n;
string s;
void search(int pos, string& t) {
  if (pos == s.size()) {
    tri.add(t);
  } else if (s[pos] == '1') {
    t[pos] = '1';
    search(pos + 1, t);
  } else {
    t[pos] = '0';
    search(pos + 1, t);
    t[pos] = '1';
    search(pos + 1, t);
  }
}

ll dp[N+1][1 << 17];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> s;
  string t(s.size(), '0');
  search(0, t);
  tri.build();
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) 
    for (int u = 0; u < tri.size(); ++u) 
      for (int c = 0, v = tri.go(u, c); c <= 1; ++c, v = tri.go(u, c))
        if (!tri.leaf(v)) dp[i + 1][v] += dp[i][u];
  ll res = 1LL << n;
  for (int u = 0; u < tri.size(); ++u) 
    res -= dp[n][u];
  cout << res;
  return 0;
}

