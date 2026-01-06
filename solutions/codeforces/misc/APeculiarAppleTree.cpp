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

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i=0;i<n-1;i++){
        int c; cin >> c, c--; // c -> parent , i -> 
        g[i+1].pb(c);
        g[c].pb(i+1);
        // parent is i +1 ,
    }
    int odd = 1;

    vi depth(n,0);

    // maybe its the path with the max number of odd children; 
    //

    auto dfs = [&](auto& dfs, int u, int p, int d) -> void {
        depth[d]++;
        for (int v:g[u]){
            if (v == p) continue;
            dfs(dfs,v,u,d+1);
        }
    };
    dfs(dfs,0,-1,0);
    debug(depth);
    int ans = 0;
    for (int i=0;i<n;i++){
        if (depth[i]%2==1) ans++;
    }
    cout << ans << endl;

    
    // auto dfs = [&](auto& dfs, int u, int p) -> int {
    //     int score = 1;
    //     for (int v:g[u]){
    //         if (v==p) continue;
    //         score += dfs(dfs,v,u);
    //     }
    //     if (p != -1) score %= 2;
    //     return score;
    // };
    //
    // int ans = dfs(dfs,0,-1);
    // cout << ans << endl;

};


// collision happens except at the root 
// this just a simple dfs? the root handle the answer differnly 

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
