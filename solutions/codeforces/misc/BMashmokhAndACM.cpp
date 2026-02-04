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
#define MAX(a) *max_el znement(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    // n,k <= 2000 
    // we can probably dp on this? 
    // we want exaclty k numbers 
    // dp[num][pos] 
    // then we sum dp[x][0] for all x 
    int n,k;
    cin >> n >> k;
    vvl dp(k, vl(n+1,-1));

    debug(n,k);
    auto go = [&](auto& go, int i, int num) -> ll{
        if (i == k-1) return 1;
        if (dp[i][num] != -1) return dp[i][num];

        ll ans = 0;
        for (int z = num; z <= n; z += num){
            ans = (ans + go(go, i+1, z)) % MOD;
        }
        return dp[i][num] = ans;
    };

    ll res = 0;
    for (int st = 1; st<=n; st++){
        debug(st,go(go,0,st));
        res = (res + go(go,0,st)) % MOD;
    }
    cout << res << endl;


    // for (int p = k -1; p >= 0; p --){
    //
    // }
    //
    // auto go = [&](auto& go, int i, int pos) -> ll{
    //     if (i >= n || pos >= k) return 1;
    //     if (dp[i][pos]!=-1) return dp[i][pos];
    //
    // }
    // for (int )
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
