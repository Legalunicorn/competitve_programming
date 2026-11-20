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

// NOTE::
// let dp[i][j] be the max length of equal strings
// a[...i] and b[....j] 
// if i == 0 j != 0, vv -> return INVALID
// i == 0 j == 0 return 0 its free 
// NOTE: HINT 1: consider prefix sum mod 10 
// if both arr are equal both string are equal? 
// the observations are non trivial and dont make sense to me 1
// 1) merging === deleting one element from pf sum, dont need modify the other 
// 2) prefix sum mod 10 equals <--> string is equal 

int dp[5005][5005];
void solve(){
    string p,q;
    cin >> p>> q;
    vi a,b;
    a.pb(0), b.pb(0);
    for (char c: p) a.pb(c-'0');
    for (char c: q) b.pb(c-'0');
    int n = a.size(), m = b.size();
    for (int i = 1 ; i < n; i++){
        a[i] += a[i-1];
        a[i] %= 10;
    }
    for (int i = 1; i < m; i++){
        b[i] += b[i-1];
        b[i] %= 10;
    }
    if (a.back() != b.back()){
        cout << -1 << endl;
        return;
    }
    int INV = 2 * (n + m);
    for (int i = 0; i <= n+1; i++){
        for (int j = 0; j <= m + 1; j++) dp[i][j] = -INV;
    }
    dp[0][0] = -1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int ans = 0;
            if (a[i-1] == b[j-1]){
                ans = 1 + dp[i-1][j-1];
            }
            ans = max({ans, dp[i-1][j], dp[i][j-1]});
            dp[i][j] = ans;
        }
    }
    cout << dp[n][m] << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
