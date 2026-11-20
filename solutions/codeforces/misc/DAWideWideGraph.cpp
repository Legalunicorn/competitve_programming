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
// impl 
// 1-> dfs from root 0 
// 2-> calcualte max distance to leaf for each node 
// 3 -> initialize each element as its own connected component 
// iterate from k = n -1 to k = 1, if mx == x, then cc -= count(x), because these elements are forevery connectted 
// inserted into res and just print res

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 0; i + 1< n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // reroot dp? 
    map<int,int> mp; // furthrstr distaince to leaf -> count 

    // vi depth(n);
    // vi dp(n);
    vi down(n), up(n), ans(n);
    vi res(n); // res depth;
    
    // calculate max distance to root 
    auto go = [&](auto& go, int u, int p) -> int{
        int evl = 0; 
        for (auto& v: g[u]){
            if (v == p) continue;
            evl = max(evl, 1 + go(go, v, u));
        }
        return down[u] = evl;
        // return dp[u] = depth[u] = evl;
    };
    go(go, 0, -1);
    // i need to calculate "up"
    // case 1: up[parent] + 1 
    // case 2: down[sibling] + 2
    // how do i know down sibling?, i need the prefix suffix means i


    // up[0] = 0; // 
    up[0] = 0;
    ans[0] = down[0];
    auto dfs = [&](auto& dfs, int u, int p) -> void{
        vi child, vals;
        for (auto& v: g[u]){
            if (v == p) continue;
            child.pb(v);
            vals.pb(down[v]);
        }
        if (child.size() == 1){
            up[child[0]] = up[u]+1;
            ans[child[0]] = max(down[child[0]], up[u]+1);
            dfs(dfs, child[0], u);
            return;
        }
        vi pf = vals, sf = vals;
        for (int i = 1; i < vals.size(); i++) pf[i] = max(pf[i],pf[i-1]);
        for (int i = vals.size()-2; i >= 0; i--) sf[i] = max(sf[i], sf[i+1]);
        for (int i = 0; i < vals.size(); i++){
            int sib = 0;
            if (i -1 >= 0) sib = max(sib, pf[i-1]);
            if (i + 1 < vals.size()) sib = max(sib, sf[i+1]);
            up[child[i]] = max(2 + sib, up[u] + 1);
            debug(child[i], up[child[i]]);
            debug(2+sib, u, up[u]+1);
            ans[child[i]] = max(up[child[i]], down[child[i]]);
        }
        debug(u);
        debug(child);
        debug(vals);
        cerr << endl;
        for (auto& v: g[u]){
            if (v == p) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs,0, -1);
    for (int i = 0; i < n; i++) mp[ans[i]]++;
    debug(down);
    debug(up);
    debug(ans);

    int cc = n; // all connected components 
    int f = 0;
    for (int k = n; k >= 1; k--){
        if (mp[k] > 0){
            if (f == 0) cc -= (mp[k]-1);
            else cc -= mp[k];
            f = -1;
        }
        res[k-1] = cc;
    }
    for (auto& r: res) cout << r << " ";
    cout << endl;

    // calculate the max using reroot dp 
    // if we transfer root from X -> Y 
    // X -> has their answer alrady calculatd 
    // the answer for Y is just MAX: ans(X) + 1, depth(Y);
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
