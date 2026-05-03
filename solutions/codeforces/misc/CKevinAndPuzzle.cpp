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


// if a[i] >= i 
// -> this person is a liar 
//
// this is simple dp problem 
//
// let dp[i] be the number of valid configurations from [0.. i] 
//
// solution:  dp[n]
// base case: dp[i] = 1 or 2 depending 
// recurrance dp[i] = dp[i-1] * (1 or 2)
//
// you forget that no two liars can be next to each other 
//


void solve(){
    int n;
    cin >> n;
    ll mod = 998244353;
    vl a(n);
    for (auto& z:a) cin >> z;
    vvl dp(n+1, vl(2, 0));
    dp[1][0] = dp[1][1] = 1;
    if (a[0] != 0) dp[0][1] = 0; // cant be saying the truth
    for (int i = 2; i <= n; i++){
        int j = i -1;
        // if a[j] 
    }



    // vvl dp(n+1, vl(2, 0));
    // for (int i = 0; i + 1 < n; i ++){
    //     if (a[i] > i && a[i+1] > i+1){
    //         cout << 0 << endl;
    //         return;
    //     }
    // }
    // // dp[x][0] -> liar :w
    // // dp[x][1] -> truth
    // dp[0][1] = dp[0][0] = 1;
    // for (int i = 1; i <= n; i++){
    //     if (a[i-1] <= i -1) {
    //         dp[i][0] = dp[i-1][1];
    //     }
    //     dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % mod;
    // }
    // debug(a);
    // debug(dp);
    // cerr << endl;
    //
    // ll res = (dp[n][0] + dp[n][1]) % mod;
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
