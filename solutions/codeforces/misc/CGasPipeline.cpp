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

// what the hell is this problem 
// look unnecessarily messy 
// making it harder to implement for 0 reason 
//
// NOTE:
//
// "0" inbetween "1"s are useless 
// 1 0 0 1 
// -> heigh 2 cost  4a + 8b 
//  -> tight cost :  6a + 6b 
//  difference in cost 
//  -2a + 2b 



//
//
// 1. each time we go up we must go down, the extra cost is 2a 
// 2. we have a base pillar price of sum(s) + length(s) 
// 3. imagine the tightest fit pip first 
//      => from there try to lift up pipes of needed? 
//

// what the fuck? LOL 
// this is supposed to be a DP problem ?? 

// Note 
// Define DP[POS][H] -> as the min cost for the prefix POS, and current height H 
//
// Answer DP[N][0] 
//
// Base Case DP[1][0] = 0, DP[1][1] = INF? 
//
// Recurance relations / transitiopn 
//
// if S[i] == 0 
//    DP[i][0] = MIN ( DP[i-1][0] + a + b , DP[i-1][1] + 2a + 2b) 
//    DP[i][1] = MIN ( DP[i-1][0] + 2a + 2b, DP[i-1][1] + a + 2b )
//
// else S[i] == 1
//    DP[i][0] = INF 
//    DP[i][1] = MIN 
//      

void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    string s; cin >> s;
    vvl dp(n+1, vl(2, 0));
    dp[0][0] = b;
    dp[0][1] = INF;
    for (int i = 0; i < n; i++){
        int x = i + 1;
        if (s[i] == '0') {
            dp[x][0] = min(dp[x-1][0] + a + b, dp[x-1][1] + 2 * a + 2 * b);
            dp[x][1] = min(dp[x-1][0] + 2*a + 2*b, dp[x-1][1] + a + 2 * b);
        } else {
            dp[x][0] = INF;
            dp[x][1] = min( dp[x-1][0] + 2*a + 2*b, dp[x-1][1] + a + 2 * b);
        }
    }
    cout << dp[n][0] << endl;

    // dp[pos][add] -> the minimal answer for prefix of length pos of height add + 1 
    // 

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
