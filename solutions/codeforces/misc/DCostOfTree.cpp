#include <bits/stdc++.h>
#include <sys/types.h>
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

// NOTE:
// for each NODE we need 
//  1. sum of subtree, SUM 
//  2. sum (distance * value) of subtree , EVL 
//  3. max depth to bottom 
//
//
//  Solution (more than 1 children)
//  1. for all children, put them in an array 
//  2. construct suffix and prefix MAX of their max depths 
//  3. for each children, u , get the MAX depth excluding it, d 
//      ans = 0 
//      ans = max(0,  EVL[u] + (d * SUM[u])  + EVL[v] - EVL[u] - SUM[u]   )
//
//  if only one children 
//      RES[v] = EVL[u] + sum[u]

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    vvi g(n);
    for (int i = 0; i + 1  < n;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vl sum(n), evl(n), res(n), mxd(n);
    // compute sum evl mxd during dfs #1 
    // returns the DEPTH, compute the rest 
    auto dfs1 = [&](auto& dfs1, int u, int p) -> void {
        if (g[u].size() ==1 && p!=-1){
            sum[u] = a[u]; // evl[u] = 0;
            mxd[u] = 1; // 1 depth
            return;
        } else {
            sum[u] = a[u];
            for (int v: g[u]){
                if (p == v) continue;
                dfs1(dfs1, v, u);
                sum[u] += sum[v]; 
                evl[u] += (sum[v] + evl[v]);
                mxd[u] = max(mxd[u], 1 + mxd[v]);
            }
        }
    };

    auto dfs2 = [&](auto& dfs2, int u, int p) -> void{
        if (g[u].size() == 1 && p != -1){
            res[u] = 0; // just for clarity
        } else{
            vi b;
            vl pre;
            for (int v: g[u]){
                if (v == p) {
                    continue;
                }
                b.pb(v); // list of children
                pre.pb(mxd[v]);
                dfs2(dfs2, v, u);
            }
            if (b.size() == 1){
                res[u] = res[b[0]] + sum[b[0]];
                return;
            }
            vl suf = pre;
            for (int i = 1; i < pre.size();i++) pre[i] = max(pre[i], pre[i-1]);
            for (int i = pre.size() - 2; i >= 0;i--) suf[i] = max(suf[i], suf[i+1]);
            for (int i = 0; i < b.size(); i++){
                ll d = 1;
                if (i+1 < b.size()) d = suf[i+1];
                if (i-1 >=0) d = max(d, pre[i-1]);
                int v = b[i];
                ll ans = (evl[u] -  evl[v] - sum[v]) + (evl[v] + (d+1) * sum[v]);
                // BUG: i missed this earlier
                ll ans2 = evl[u] + (res[v] - evl[v]);
                res[u] = max(res[u], ans2);
                res[u] = max(res[u], ans);
            }
        }
    };
    dfs1(dfs1, 0, -1);
    for (int i = 0; i < n; i++) res[i] = evl[i];
    dfs2(dfs2,0, -1);
    for (auto& z:res) cout << z << " ";
    cout << endl;

};

//      ans = max(0,  EVL[u] + (d * SUM[u])  + EVL[v] - EVL[u] - SUM[u]   )
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
