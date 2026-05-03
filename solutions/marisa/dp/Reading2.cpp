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

// at each book B_i 
// we have j , j < k slots left 
// what we can do is choose how many to read 
// from 1 to j 
// sigma i = 0 to i = j
// ans + anwer(next book, j - i)
// we solve from the last book
//
// i mis read the problem 
// she can only take 1 or 0 books pershekf

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    ll dp[1001][1001];
    memset(dp, -1, sizeof(dp));
    auto go = [&](auto& go, int i, int left) -> ll {
        if (i == n) return (left == 0? 1: 0);
        if (dp[i][left] != -1) return dp[i][left];

        ll ans = go(go, i + 1, left);
        if (left > 0)  ans = (ans +  a[i]*go(go,i+1,left-1) % MOD) % MOD;
        return dp[i][left] = ans;
    };

    ll res = go(go, 0, k);
    cout << res << endl;
    // ll dp[1001][1001];
    // memset(dp[n], 1, sizeof(dp[n]));
    // for (int bk = n; bk >= 0; bk--){
    //     ll tot = 0;
    //     for (int left = 0; left <= k; left ++){
    //         ll evl = dp[bk+1][left];
    //         if (left > 0) evl = (evl + dp[bk+1][left-1]) % MOD;
    //         dp[bk][left] = evl;
    //     }
    // }
    // cout << dp[0][k] << endl;

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
