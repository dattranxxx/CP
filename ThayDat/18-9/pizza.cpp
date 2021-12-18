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
const int oo = 1e9;
void file() {
  const string FILE_NAME = "pizza";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int K = 26;
struct trie {
  struct node {
    int nxt[K], leaf, cnt;
    node(): leaf(0), cnt(0) {}
  };
  vector<node> tri;
  trie(): tri(1) {}
  #define nxt(v, c) tri[v].nxt[c - 'a']
  #define cnt(v) tri[v].cnt
  #define leaf(v) tri[v].leaf
  void add(const string& s, int v = 0, int i = 0) {
    if (i == s.size()) {
      leaf(v) += 1; cnt(v) += 1; return;
    }
    char c = s[i];
    if (!nxt(v, c)) {
      nxt(v, c) = tri.size();
      tri.emplace_back();
    }
    add(s, nxt(v, c), i + 1);
    cnt(v) += cnt(nxt(v, c));
  }
  int leo(const string& s) {
    int v = 0, res = 0;
    for (char c : s) {
      if (!nxt(v, c)) break;
      v = nxt(v, c);
      res += leaf(v);
    }
    return res;
  }
  int size(const string& s) {
    int v = 0, res = 0;
    for (char c : s) {
      if (!nxt(v, c)) return 0;
      v = nxt(v, c);
    }
    return cnt(v);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int q, t; 
  string s;
  trie tri;
  cin >> q;
  while (q--) {
    cin >> t >> s;
    if (t == 0) tri.add(s);
    else if (t == 1) cout << tri.leo(s) << '\n';
    else cout << tri.size(s) << '\n';
  }
  return 0;
}

