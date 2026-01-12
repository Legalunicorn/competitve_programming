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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// the max answer is ~ n 
// we need to find any way to perform the operations 
// 1. we establish how many ops needed 
// 2. now we need to throw the nodes int "buckets" 
// 1. we have the number of children 
// 2. depth of each node 
//
// is it sufficient to assign them in to n buckets? 
//
// 1. your bucket != parent bucket 
// 2. no bucket must contain the same depth 
// 3. can we use a PQ of buckets? or something 
// i think a BFS might do the trick 
// 
// for every depth, 

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    vi depth(n,0);
    vi par(n,0);
    map<int, vi> dmp;
    for (int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    int mxd = 0, mxrow = 1;
    int ans = 0;
    auto dfs = [&](auto& dfs, int u, int p, int d)->void{
        par[u] = p;
        dmp[d].pb(u);
        depth[d]++;
        int st = 1;
        mxd = max(mxd, d);
        for (int v:g[u]){
            if (v==p) continue;
            st++;
            dfs(dfs,v,u,d+1);
        }
        ans = max(ans,st);
    };

    dfs(dfs,0,-1,0);
    debug(depth);
    for (int i=0;i<=mxd;i++){
        mxrow = max(mxrow,depth[i]);
    }
    int res = max(mxrow, ans);


    vvi bucket(res);
    // reset from pos 1 every depth ;
    vi where(n,-1);
    bucket[0].pb(0);
    where[0] = 0;
    // too slow 
    // 1. no parent 
    // 2. no same depth 
    // 3. can we use a pq  instead or some fuck shit 
    //
    for (int d = 1; d<=mxd; d++){
        int id = 0;
        set<int> used;
        for (auto& u: dmp[d]){ // every node at this depth 
            int pb = where[par[u]];
            while(used.count(pb) || pb == where[par[u]]) pb = (pb + 1) % res;
            bucket[pb].pb(u);
            where[u] = pb;
            used.insert(pb);
            pb = (pb + 1) % res;

        }
    }
    debug(bucket);
    cout << res << endl;
    for (int i=0;i<res;i++){
        cout << bucket[i].size() << " ";
        for (auto& b: bucket[i]){
            cout << (b+1) << " ";
        }
        cout << endl;
    }
    





    // cout << res << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
