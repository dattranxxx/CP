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
struct trie {
  static const int H = 16;
  struct node {
    int nxt[2], cnt, child, bit[H+1]; 
    node(): cnt(0), child(0) {}
  };
  #define nxt(v, c) tri[v].nxt[c]
  #define cnt(v) tri[v].cnt
  #define child(v) tri[v].child
  #define bit(v) tri[v].bit
  vector<node> tri;
  int G;
  trie(): tri(1), G(0) {}
  void add(int x, int v = 0, int i = H) {
    if (i < 0) {
      cnt(v)++; child(v)++;
      for (int b = 0; b <= H; ++b)
        bit(v)[b] += (x >> b & 1) ^ (G >> b & 1);
      return;
    }
    int c = (x >> i & 1) ^ (G >> i & 1);
    if (!nxt(v, c)) {
      nxt(v, c) = tri.size();
      tri.emplace_back();
    }
    child(v) -= child(nxt(v, c));
    for (int b = 0; b <= H; ++b)
      bit(v)[b] -= bit(nxt(v, c))[b];
    add(x, nxt(v, c), i - 1);
    child(v) += child(nxt(v, c));
    for (int b = 0; b <= H; ++b)
      bit(v)[b] += bit(nxt(v, c))[b]; 
  }
  void erase(int x, int v = 0, int i = H) {
    if (i < 0) {
      if (cnt(v)) {
        cnt(v)--; child(v)--;
        for (int b = 0; b <= H; ++b)
          bit(v)[b] -= (x >> b & 1) ^ (G >> b & 1);
      }
      return;
    }
    int c = (x >> i & 1) ^ (G >> i & 1);
    if (!nxt(v, c)) {
      nxt(v, c) = tri.size();
      tri.emplace_back();
    }
    child(v) -= child(nxt(v, c));
    for (int b = 0; b <= H; ++b)
      bit(v)[b] -= bit(nxt(v, c))[b];
    erase(x, nxt(v, c), i - 1);
    child(v) += child(nxt(v, c));
    for (int b = 0; b <= H; ++b)
      bit(v)[b] += bit(nxt(v, c))[b];
  } 
  void __xor(int x) {
    G ^= x;
  }
  ll query(int k, int v = 0, int i = H, int cur = 0) {
    // tong k so nho nhat
    if (k == 0) return 0;
    if (i < 0) return cur * k;
    if (!nxt(v, 0)) {
      nxt(v, 0) = tri.size();
      tri.emplace_back();
    }
    if (!nxt(v, 1)) {
      nxt(v, 1) = tri.size();
      tri.emplace_back();
    }
    int zero = nxt(v, 0), one = nxt(v, 1);
    if (G >> i & 1) swap(zero, one);
    ll sum = 0;
    if (k >= child(zero)) {
      for (int b = 0; b <= H; ++b) {
        int c = bit(zero)[b];
        if (G >> b & 1) c = child(zero) - c;
        sum += c * (1 << b);
      }
      return sum + query(k - child(zero), one, i - 1, cur * 2 + 1);
    } else return query(k, zero, i - 1, cur * 2);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int q;
  cin >> q;
  int t, x;
  trie tri;
  while (q--) {
    cin >> t >> x;
    if (t == 0) {
      tri.add(x);
    } else if (t == 1) {
      tri.erase(x);
    } else if (t == 2) {
      tri.__xor(x);
    } else {
      cout << tri.query(x) << '\n';
    }
  }
  return 0;
}

