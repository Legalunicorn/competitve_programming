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

// NOTE: 
// i think we can divide and conqueur this sort 
// given a range from [i..j] 
// we can pick something out to merge
// i know it dont work but it works trying 
// for every range [i ... j] (might not be the original array from i..j but we take it as oroginal bounds)
// we try to split for some i <= k <= j 
//
// NOTE: HINT 
// DP[i][j] be the min cost to mege A[i..j] into 1 element 
// is this a DNC problem? 

// what is the answer? solve(0, n)
// what is the base case: 
//      solve(i,i+1) = a[i] + a[i+1]
//      solve(i,i) = 0 
//
// what is the recurance relation? 
//      solve(i, j) 
//          -> we have to pick some element to merge FIRST, can we flip this into last? 
//
//
// i think the trick is, we figure out what is the last element to be merged! 
// i think i have it ! so its not we find a merge, but we split it into two segments
//  dp[i][j]   we find the min cost from dp[i][k] and dp[k+1][j] 
//  then we merge those last! 
//
//  not that every recurance has a smaller window that the source, so we can iteratr from small to large 
//  10 20 30
//  30 30 
//  60
//
//  10 20 30 
//  10 50 
//  60 (10 + 50 + 50)

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vvl dp(n, vl(n, 0));
    vl pf = a;
    for (int i = 1; i < n; i++) pf[i] += pf[i-1];
    debug(a);
    debug(pf);
    for (int s = 2; s <= n; s++){
        for (int i = 0; i + s - 1 < n; i ++){
            int j = i + s - 1;
            dp[i][j] = INF;
            for (int k = i; k  < j; k++){
                ll cost = dp[i][k] + dp[k+1][j];
                cost += (pf[j] - (i > 0 ? pf[i-1]: 0LL));
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    debug(dp);
    cout << dp[0][n-1] << endl;
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
