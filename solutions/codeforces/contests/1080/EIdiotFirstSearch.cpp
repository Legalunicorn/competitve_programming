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
    int n;
    cin >> n;
    vpi child(n+1);
    for (int i = 1; i <= n; i++) cin >> child[i].F >> child[i].S;
    vl res(n+1,1);

    vl base(n+1,0);

    auto go1 = [&](auto& go1, int u) -> ll {
        if (child[u].F == 0) return 0;
        ll left = go1(go1, child[u].F);
        left = (left + 2LL) % MOD;

        ll right = go1(go1, child[u].S);
        right = (right + 2LL)% MOD;

        ll ans = (left + right) % MOD;

        return base[u] = ans;
    };

    auto dfs = [&](auto& dfs, int u, ll val) -> void {
        val = (val + base[u]) % MOD;

        val = (val + 1LL) % MOD;
        res[u] = val;
        if (child[u].F == 0) return;
        dfs(dfs, child[u].F, val);
        dfs(dfs,child[u].S, val);
    };


    go1(go1,1);
    dfs(dfs,1,0LL);
    // cerr << endl;

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout <<endl;


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
    return 0;
}
