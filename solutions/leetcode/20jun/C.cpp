
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
const int inv= 1e9;




class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& base) {
        ll WORST = 100000000000000;
        if (n == 1){
            return base[0];
        }
        vvi g(n);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            g[u].pb(v);
            g[v].pb(u);
        }
        ll res = 0;
        vl early(n), late(n), ans(n);
        auto dfs = [&](auto& dfs, int u, int p) -> void{
            if (g[u].size() == 1 && p != -1){
                // this is a leaf 
                ans[u] = (ll) base[u];
                return;
            } else{
                ll mn = WORST, mx = -WORST;
                for (int v: g[u]){
                    if (v == p) continue;
                    dfs(dfs, v, u);
                    mn = min(mn, ans[v]);
                    mx = max(mx, ans[v]);
                }
                ans[u] = (ll)base[u] + mx + mx - mn;
                return;
            }
        };
        dfs(dfs,0, -1);
        return ans[0];
    }
};

#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << "w" << endl;
    return 0;
}
#endif
