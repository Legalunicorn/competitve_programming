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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;






void solve(){
    int n,m; 
    cin >> n >> m;
    vvi g(n);
    for (int i = 0; i < m; i++){
        int u,v; 
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    debug(n,m);
    bool flag = true;
    vi cnt = {0,0,0};
    vi color(n, 0); 
    int res = 0;

    auto dfs = [&](auto& dfs, int u, int col) -> void {
        //debug(u+1, col);
        color[u] = col;
        cnt[col]++;
        for (int v: g[u]){
            if (color[v] == col){
                flag = false;
            } else if (color[v] == 0){
                dfs(dfs,v, 3 - col);
            }
        }
    };

    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            flag = true;
            cnt = {0,0,0};
            dfs(dfs, i, 1);
            debug(flag, cnt);
            if (flag){
                res += max(cnt[1], cnt[2]);
                // bipartitle != half is one color bro
                //res += (size+1)/2;
            }
        }
    }


    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
