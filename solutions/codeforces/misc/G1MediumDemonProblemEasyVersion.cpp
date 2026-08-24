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
// there must be a cycle within each connected component 
// we need to find the max distance from a node not in a cycle to a cycle
// sucessor graph 
// for EACH connected component 
// 1. the gay approach 
// -> binary search  + binary lifting then check if k != k + 1 
//
// 2. the graph approach
// -> detect cycles in the graph
// -> use khans algo, just take ANY unprocessed NODE, run a DFS from it to find all nodes in the cycle 
// -> flip all the edges 
// -> run the max dist algo 
// -> this is super impl heavy.. and im lazy
//
void solve(){
    // this is omega trivial 
    int n;
    cin >> n;
    vi indeg(n);
    vvi g(n);
    vb seen(n);
    for (int i = 0; i < n; i++){
        int p; cin >> p;
        p--;
        g[i].pb(p);
        indeg[p]++;
    }
    int res = 2;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0){
            q.push(i);
            seen[i] = true;
        }
    }
    while(!q.empty()){
        int  u= q.front(); q.pop();
        seen[u] = true;
        for (int v: g[u]){
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    vb cycle(n);
    auto dfs = [&](auto& dfs,int u) -> void{
        if (cycle[u]) return;
        cycle[u] = true;
        for (int v: g[u]){
            if (!cycle[v]) dfs(dfs,v);
        }
    };
    for (int i = 0; i < n; i++){
        if (!seen[i] && !cycle[i]){
            dfs(dfs,i);
        }
    }
    vi dist(n,-1);
    auto go = [&](auto& go, int u) -> int{
        if (dist[u]!=-1) return dist[u];
        if (cycle[u]) {
            dist[u] = 2;
            res = max(res, 2);
            return 2;
        } else{
            int x = go(go, g[u][0]);
            dist[u] = x + 1;
            res = max(res, x + 1);
            return x+1;

        }
    };
    for (int i = 0; i < n; i++){
        if (!cycle[i]) {
            go(go, i);
        }
    }
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
