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
// m operations 
// we just need to care digit i,k op -> how many digitis eventually 
// dp[i][k] = dp[(i+1)]

const int N = 200005;
ll dp[N][10];

void init(){
    for (int k = 0; k < N; k++){
        for (int d = 0; d < 10; d++){
            if (k == 0) dp[k][d] = 1;
            else if (d == 9) dp[k][d] = (dp[k-1][0] + dp[k-1][1]) % MOD;
            else dp[k][d] = dp[k-1][d+1];
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    ll res = 0;
    while(n){
        int r = n % 10;
        debug(r,m, dp[m][r]);
        res = (res + dp[m][r]) % MOD;
        n/=10;
    }
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
