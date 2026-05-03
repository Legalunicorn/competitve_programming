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


//NOTE: solution
// i dont understand how this isnt just basic knapsack? why is this called "2" 
// probaly just constraint issue we can memoru optimise i think nah not even nneded


void solve(){
    int n,s;
    cin >> n >> s;
    vpi a(n);
    for (int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    debug(n,s);
    debug(a);
    vvi dp(n+1, vi(s+1, 0));
    // solve row by row, in increasing sum 
    // because we are querying backwards
    for (int i = 1; i <= n; i++){
        for (int x = 0;  x <=s; x ++){
            dp[i][x] = dp[i-1][x];
            if (a[i-1].F <= x) dp[i][x] = max(dp[i][x], a[i-1].S + dp[i-1][x-a[i-1].F]);
        }
        debug(i, dp[i]);
    }
    cout << dp[n][s] << endl;
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
