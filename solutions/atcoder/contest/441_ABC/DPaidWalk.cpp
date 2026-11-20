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

//variables and functoins]b
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;


// this is definitely dp 
// 1. k (edge count) 
// we can use a map for edges but i have no idea 
// node, k  ... {cost -> answer}
// dp might be too slow even though its likely 
// 1. we can find shortest distance yes 
// 1. can we find shortest edge in the shortest distance ? idk 
//3. at least s and st
//
//
//  boolean [node][edges][cost] 
// cost is large so we cant index 
//
// -1 -> 
// 



void solve(){
    int n,m,l,s,t;
    cin >> n >> m >> l >> s >> t;
    debug(n,m);
    vvpi g(n);
    for (int i = 0; i < m; i++){
        int u,v,c;
        cin >> u >> v >> c;
        u--,v--;
        g[u].pb({v,c});
    }
    debug(g);

    set<int> res;

    vector<vector<map<ll,ll>>> dp(n, vector<map<ll,ll>>(l+1));

    auto dfs = [&](auto &dfs, int u, int len, ll cost) -> void {
        if (cost > t || len < 0)  return;
        if (dp[u][len].count(cost)) return;

        if (len == 0) {
            if (cost >= s ) res.insert(u + 1);
            dp[u][len][cost] = true;
            return;
        }

        for (auto & [v, w]: g[u]){
            dfs(dfs, v, len-1, cost + w);
        }

        dp[u][len][cost] = 1;
    };

    dfs(dfs,0,l,0LL);
    for (auto& x: res) cout << x << " ";
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
