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
    vi a(n);
    for(auto& z:a) cin >> z;
    // 0 -> nothing
    // 1 -> option 1 
    // 2 -> option 2
    // 3 -> both options
    //
    vvi dp(n, vi(3,-1));

    auto go = [&](auto& go, int i, int op) -> int{
        if (i == n) return 0;
        if (dp[i][op]!=-1) return dp[i][op];
        debug(i,a[i],op);
        int res = 0; 
        // default is to skip 
        if (a[i] == op || a[i] == 3){
        
            res = max(res, 1+go(go,i+1, 3 - op));
        }
        res = max({res,go(go,i+1,1), go(go,i+1,2)});
        debug(i,op,res);
        return dp[i][op] = res;
    };

    int res = max(go(go,0,1), go(go,0,2));
    debug(res);
    cout << n - res << endl;

    

};

// n = 100 
// min res days = max activity days 
// 1. select activty at local level
// 2. based on selected activity, we have options for next activity 
// 3. dp[i][activty_chosen];
//

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
