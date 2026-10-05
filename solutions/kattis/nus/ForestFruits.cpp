#include <bits/stdc++.h>
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
// M 1e9 
// K 1e9 
// V 1e4, E 1e5 
// C <= V 
//
// NOTE: impossible case s
// (1) if all the fruits are on reset 
//  -> C fruits 
//  -> if we take all [1,C] fruit and they are still on cook down K ? 
//  -> 5 fruits and the cool down is 5 y
//  -> if  K > C its impossible
// -> k <= c 
// -> pick the first k fruits with the shortest distance and just cycles them 
// m / k;
void solve(){
    int v,e,c,k,m;
    cin >> v >> e >> c >> k >> m;
    int t = min(k,m);
    if (t > c){
        cout <<-1 <<endl;
        return;
    }
    debug(v,e,c,k,m);
    vvpl g(v);
    
    for (int i = 0; i < e; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    debug(g);
    vb fruit(v);
    for (int i = 0; i < c; i++){
        int x; cin >> x;
        fruit[x-1] = true;
    }
    debug(fruit);
    // dijsktas
    vl dist(v, INF);
    priority_queue<pl,vpl, greater<pl>> pq;
    pq.push({0ll,0ll});
    dist[0] = 0ll;
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto& [y, w]: g[u]) {
            ll d2 = dist[u]+w;
            if (d2 < dist[y]){
                dist[y]=d2;
                pq.push({d2,y});
            }
        }
    }
    ll res = 0ll;
    vl b;
    for (int i = 0; i < v;i++) {
        if (dist[i]!=INF) dist[i]*=2ll;
    }

    debug(dist);
    for (int i = 0; i < v; i++){
        if (fruit[i] && dist[i]!=INF) b.pb(dist[i]);
    }

    if (b.size() < t){
        cout << -1 << endl;
        return;
    }

    sort(all(b));

    ll mx = b[0];
    for (int i = 0; i < t; i++) mx = max(mx,b[i]);
    cout << mx << endl;

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
