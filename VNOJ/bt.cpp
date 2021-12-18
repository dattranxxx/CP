/*
	Author: Longhoang08 - Long Hoang
**/
#include <bits/stdc++.h>
#define rank _rank

using namespace std;

const int maxn = 50010;
const long long inf = 1e15;
const int base = 1e9 + 7;

int m, n, k;
long long d[22][maxn];

int g[22][maxn];
vector <pair<int, int>> edge[maxn*8];
int rank[maxn*8];


typedef pair<int, long long> ptq;

int getbit(int s, int i)
{
    return ((s>>i)&1);
}

namespace TopoSort
{
    bool visited[maxn*8];
    vector <int> topoList;
    int m;
    void init(int _m)
    {
        m = _m;
        //for(int i = 1; i <= m; i++) visited[i] = false;
    }

    void dfs(int u)
    {
        visited[u] = true;
        for(auto vv : edge[u])
        {
            int v = vv.first;
            if (!visited[v])
                dfs(v);
        }
        topoList.push_back(u);
    }

    void Topo()
    {
        for(int i = 1; i <= m; i++) 
            if (!visited[i]) dfs(i);
        reverse(topoList.begin(), topoList.end());
        int cnt = 0;
        for(int x : topoList) 
        {
            rank[x] = ++cnt;
        }
    }
}

class Interval
{
    int id[maxn];
    int base = 0;
public:
    int getId(int u)
    {
        return id[u];
    }

    void buildDown(int i, int lo, int hi)
    {
        
        if (lo == hi) 
        {
            id[lo] = i;
            base = max(base, i);
            return;
        }
        int mid = (lo + hi)>>1;
        edge[i*2].push_back({i, 0});
        edge[i*2+1].push_back({i, 0});
        buildDown(i*2, lo, mid);
        buildDown(i*2+1, mid+1, hi);
    }

    void buildUp(int i ,int lo, int hi)
    {
        if (lo == hi) return;
        int mid = (lo + hi)>>1;
        edge[base+i].push_back({i*2+base, 0});
        edge[base+i].push_back({i*2+1+base, 0});
        buildUp(i*2, lo, mid);
        buildUp(i*2+1, mid+1, hi);
    }

    // type == 2: from [l,r] -> u
    // type == 3: from u -> [l,r] 
    void update(int i, int lo, int hi, int l, int r, int u, int w, int type)
    {   
        if (lo > r || hi < l) return;
        if (lo >= l && hi <= r)
        {
            if (type == 2)
                edge[i].push_back({id[u], w});
            else
                edge[id[u]].push_back({i+base, w});
            return;
        }
        int mid = (lo + hi)>>1;
        update(i*2, lo, mid, l, r, u, w, type);
        update(i*2+1, mid+1, hi, l, r, u, w, type);
    }

    int getBase()
    {
        return base;
    }
} it;


struct qcmp
{
    bool operator()(ptq a, ptq b)
    {
        return (a.second > b.second)||(a.second == b.second && rank[a.first] > rank[b.first]);
    }
};

void add(int &a, const int &b)
{
    a += b;
    if (a >= base) a -= base;
}

int mul(const int &a, const int &b)
{
    return (1LL*a*b)%base;
}

// type == 2: from [l,r] -> u
// type == 3: from u -> [l,r] 

namespace Dijkstra
{   
    long long distance[maxn*8];
    int count[maxn*8];

    void BuildGraph()
    {
        it.buildDown(1, 1, n);
        it.buildUp(1, 1, n);
        for(int i = 1; i <= n; i++)
        {
            edge[it.getId(i)+it.getBase()].push_back({it.getId(i), 0});
        }
        TopoSort::init(it.getBase() * 2);
        TopoSort::Topo();
        for(int i = 1; i <= m; i++)
        {
            int u, v, l, r, type, w;
            cin >> type;
            if (type == 1)
            {
                cin >> u >> v >> w;
                it.update(1, 1, n, u, u, v, w, 2);
            }
            else if (type == 2)
            {
                cin >> l >> r >> u >> w;
                it.update(1, 1, n, l, r, u, w, type);
            }
            else if (type == 3)
            {
                cin >> u >> l >> r >> w;
                it.update(1, 1, n, l, r, u, w, type);
            }
        }
    }

    void solve(int vu, int num)
    {
        for(int i = 1; i <= it.getBase() * 2; i++) distance[i] = inf;
        int id = it.getId(vu);
        distance[id] = 0;
        count[id] = 1;
        priority_queue <ptq, vector <ptq>, qcmp> pq;
        pq.push({id, 0});
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int u = top.first;
            if (distance[u] != top.second) continue;
            for(auto vv : edge[u])
            {
                int v = vv.first, w = vv.second;
                if (distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                    count[v] = count[u];
                    pq.push({v, distance[v]});
                }
                else if (distance[v] == distance[u] + w) 
                    add(count[v], count[u]);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            d[num][i] = distance[it.getId(i)];
            g[num][i] = count[it.getId(i)];
        }
    }
}

bool inq[maxn];
int a[maxn];
long long f[(1<<20)+1][30];

namespace Solution
{
    int count[(1<<20)+1][30];
    void solve()
    {
        Dijkstra::BuildGraph();
        for(int i = 0; i < k; i++)
            Dijkstra::solve(a[i], i);
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
        int ALL = (1<<(k-1)) - 1;
        for(int s = 0; s <= ALL; s++)
            for(int i = 0; i < k; i++) f[s][i] = inf;
        for(int i = 1; i < k; i++) 
        {
            f[(1<<(i-1))][i-1] = d[0][a[i]];
            count[(1<<(i-1))][i-1] = g[0][a[i]];
        }
        for(int s = 0; s <= ALL; s++)
            for(int u = 1; u < k; u++)
            {
                if (f[s][u-1] == inf) continue;
                for(int v = 1; v < k; v++)
                    if (!getbit(s, v-1))
                    {
                        int nextS = s + (1<<(v-1));
                        long long temp = f[s][u-1] + d[u][a[v]];
                        if (f[nextS][v-1] > temp)
                        {
                            f[nextS][v-1] = temp;
                            count[nextS][v-1] = mul(count[s][u-1], g[u][a[v]]);
                        }
                        else if (f[nextS][v-1] == temp)
                            add(count[nextS][v-1], mul(count[s][u-1], g[u][a[v]]));
                    }
            }
        long long res = inf;
        int num = 0;
        for(int i = 1; i < k; i++)
        {
            long long temp = f[ALL][i-1] + d[i][1];
            if (res > temp)
            {
                res = temp;
                num = mul(count[ALL][i-1], g[i][1]);
            } 
            else if (res == temp) 
                add(num, mul(count[ALL][i-1], g[i][1]));
        }
        if (res == inf) cout << -1 << '\n';
        else cout << res << ' ' << num << '\n'; 
    }
}

int main()
{
    int s, t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        inq[x] = true;
    }
    inq[1] = true;
    k = 0;
    for(int i = 1; i <= n; i++) 
        if (inq[i]) a[k++] = i;
    Solution::solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}   
