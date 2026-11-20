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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;
    debug(n,m);
    vvpl g(n);
    for (int i = 0; i  <m; i++){
        int u,v,w;
        cin >> u>> v >> w;
        u--, v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vl dist(n, INF);
    vi trace(n, -1);
    dist[0] = 0LL;
    debug(g);
    priority_queue<pl, vpl, greater<pl>> pq;
    //priority_queue<pl vpl, greater<vpl>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        pl t = pq.top(); pq.pop();
        debug(t);
        ll u = t.F, d = t.S;
        if (u == n-1){
            cout << d << endl;
            break;
        }
        if (dist[u] < d) continue;
        for (auto& [v,w] : g[u]) {
            ll d2 = dist[u] + w;
            if (d2 < dist[v]){
                trace[v] = u;
                dist[v] = d2;
                pq.push({v, d2});
            }
        }
    }
    if (trace[n-1] == -1) {
        cout << -1 << endl;
        return;
    }
    vi ans;
    int cur = n-1;
    while(cur != -1){
        ans.pb(cur+1);
        cur = trace[cur];
    }
    reverse(all(ans));
    for (int v: ans) cout <<  v << " ";

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
