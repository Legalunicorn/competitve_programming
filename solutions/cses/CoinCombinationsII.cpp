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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;


// 2, 3 , 5 
// 0 - > NULL 
// 1 -> 0 
// 2 -> {2} 
// 3 -> {3}
// 4 -> [2] +{2}
// 5 -> [3]+{2}   [2] +{3}   // {2,3}
// 6 -> [3]+{3} [2]+{2,2}
// 7 -> [2] + {2,3}  [3] + {2,2}, [5]+{2} 
//


void solve(){
    int n,x;
    cin >> n >> x;
    vi a(n);
    for (auto& z:a) cin >> z;
    vl dp(x+5,0);
    // dp[0] = 1;
    // sort(a.rbegin(),a.rend());
    sort(all(a));
    dp[0] = 1;
    for (auto& c: a){
        for (int i= c; i<= x; i++){
            dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
        debug(c, dp);
    }
    // for (int i = 0; i<=x; i++){
    //     for (auto& c: a){
    //         if (c > i) break;
    //         dp[i] = dp[i] + dp[i-c] % MOD;
    //     }
    // }
    debug(a);
    debug(dp);
    cout << dp[x] % MOD << endl;

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
