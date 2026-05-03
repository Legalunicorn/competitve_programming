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
#define S second :w
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// recurrances 
// cases 
// 1. (i-1) buys for both (i-1) and (i) then we skip to (i-2)
// 2. (i) buys for himself, then we go to (i-1)
//
// base case 
// the last person cannot ask the person behind him to buy 
// if he buys for himself its iomsple a[i];


void solve(){
    int n;
    cin >> n;
    vi t(n), r(n);
    for (auto& z:t) cin >> z;
    for (auto& z: r) cin >> z; 
    vi dp(n+1, 0);
    dp[n-1] = t[n-1]; 
    for (int i = n -2; i >= 0; i--){
        dp[i] = min(
                t[i] + dp[i+1],
                r[i] + dp[i+2]
                );
    }
    cout << dp[0] << endl;
    
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
