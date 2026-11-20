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


// 26 * n dp seems pretty easy 
// READ THE PROBLEM NEXT TIME HOLY 
// we just need to greedy this
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int nxt = 0;
    for (int i = 0; i < n; i++){
        if (nxt == 26) break;
        if (s[i]-'a' <= nxt){
            s[i] = (char)(nxt + 'a');
            nxt++;
        }
    }
    debug(s,nxt);
    if (nxt == 26) cout << s << endl;
    else cout << -1 << endl;
    // string s;
    // cin >> s;
    // int n = s.size();
    // if (s.size()  < 26){
    //     cout << -1 << endl;
    //     return;
    // }
    // int INV = 2800000; // invalid valiue AKA INF
    // debug(s);
    // vvi dp(n+1, vi(30,INV));
    // for (int i = 0 ; i <= n ;i++) dp[i][27] = 0; 
    // for (int i = n; i >= 0; i--){
    //     for (int a = 0; a < 26; a++) {
    //         debug(i,a);
    //         if (s[i] - 'a' <= a){
    //             dp[i][a] = min(dp[i][a], a - (s[i]-'a') + dp[i+1][a+1]);
    //         }
    //         dp[i][a] = min(dp[i][a], dp[i+1][a]); // dont pick
    //     }
    // }
    // int res = dp[0][0];
    // if (res == INV) res =-1;
    // cout << res << endl;
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
