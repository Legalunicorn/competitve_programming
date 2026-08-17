#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE: 
// this is a graph layering problem 
// layer[titans][sharmans][node] is max 100 * 100 * 100 
// then we run dijsktra on this graph 
// 1. search by titan first, if titan T is possible we ignore T+1... 
// 2. if any S is possible ignore and just return the SSSP 
//
ll dp[105][105][105];

struct edge{
    int v;
    ll w;
    int c;
};


void solve(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++){
        int a,b,c;
        ll w;
        cin >> a >> b >> w >> c;
        a--, b--;
        g[a].pb({b,w,c});
        g[b].pb({a,w,c});
    }
    vector<array<ll,3>> dist(n,{INF,INF,INF});
    using state = tuple<ll,ll,ll,int>;
    priority_queue<state,vector<state>, greater<state>> pq;
    dist[x] = {0,0,0};
    pq.push({0,0,0,x});
    while(!pq.empty()){
        auto [t,s,d,u] = pq.top(); pq.pop();
        if (array<ll,3>{t,s,d} != dist[u]) continue;
        for (auto& e: g[u]){
            ll nt = t + (e.c ==2);
            ll ns = s + (e.c == 1);
            ll nd = d + e.w;
            array<ll,3> can = {nt,ns,nd};
            if (can < dist[e.v]){
                dist[e.v] = can;
                pq.push({nt,ns,nd, e.v});
            }
        }
    }
    if (dist[y][2] == INF){
        cout << "IMPOSSIBLE";
    } else cout << dist[y][2] << " "  << dist[y][1] << " " << dist[y][0] << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
