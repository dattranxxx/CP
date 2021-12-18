// Created by Shora
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cout << _ << ' ';} cout << endl;
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 32 - 2;
vector<pii> decode(vector<int>& prufer) {
	int n = prufer.size() + 2;
	vector<int> degree(n, 1);
	for (int u : prufer) degree[u]++;
	int ptr = 0;
	while (degree[ptr] != 1) ptr++;
	int leaf = ptr;
	vector<pii> edges;
	for (int u : prufer) {
		edges.emplace_back(leaf, u);
		if (--degree[u] == 1 && u < ptr) leaf = u;
		else {
			ptr++; while (degree[ptr] != 1) ptr++;
			leaf = ptr;
		}
	}
	edges.emplace_back(leaf, n-1);
	return edges;
}
void solve() {
	int n = rng() % maxn + 3;
	vector<int> prufer(n - 2);
	uniform_int_distribution<> gen(0, n-1);
	for (int i = 0; i < n - 2; ++i) prufer[i] = gen(rng);
	vector<pii> tree = decode(prufer);
	for (pii e : tree) {
		cout << e.X+1 << ' ' << e.Y+1 << '\n';
	}
}

int main() {
	solve(); // NHO TINH DO PHUC TAP KHONG DE TRAN SO
	return 0;
}




