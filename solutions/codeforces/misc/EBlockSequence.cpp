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

// 1 2 3 4 5 6 7 
//
// TUTORIAL 
// NOTE:
// Optiosn 
// 1. remove element at (i) and make the segment from (i+1) to (n) beautiful 
// 2. ake segment (i + a_i + 1) to (n) beautfful: 
//          dp[i] = dp[i + a_i + 1]
//
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;;
    int INF = n*10;
    vi dp(n, INF);
    dp[n-1] = 1; // remove itself 
    for (int i = n-2; i >= 0; i--){
        int skip = 1 + dp[i+1];
        int p = i + a[i] + 1;
        int take;
        if (p > n) take = INF;
        else if (p == n) take = 0; //the whole array is free 
        else take = dp[p];
        dp[i] = min(skip, take);
        debug(dp);
        debug(i, skip, take);
    }
    cout << dp[0] << endl;

    // what is the recurrance 
    // if we skip A[i], we only care about solution [i+1 .. N]
    // otherwise if we use A[i], we use dp[i + a[i] + 1];




    // dp[n] = 1;
    // for (int i = n -2 ; i >= 0; i--){
    //     int opt1 = dp[i+1] + 1;
    //     int opt2;
    //     int pos = i + a[i] + 1;
    //     if (pos < n) opt2 = dp[pos];
    //     else if (pos == n) opt2 = 0;
    //     else if (pos > n) opt2 = n*10;
    //     dp[i] = min(opt1, opt2);
    //     debug(dp);
    // }
    // cout << dp[0] << endl;


    // NOTE:
    // dp[i..N]
    // let dp[i] be the answer for the prefix A[0..i]
    // note that empty array is beautiful
    // the initial state shall be dp[i] = i + 1 (or N) 
    // then dp[0] = 1;

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
