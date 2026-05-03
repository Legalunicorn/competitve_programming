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

// reurance 
// dp[i][k]  as starting at this position 
// how many [k....sa] can i find 
// there is a constraints 





void solve(){
    string s;
    cin >> s;
    int k = 6;
    int n = s.size();
    string m = "marisa";
    vvl dp(n+1, vl(k+1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][k] = 1; 
    }


    for (int i = n -1; i >= 0; i--) {
        for (int j = k-1; j >= 0; j--) {
            if (s[i] == m[j]) dp[i][j] = dp[i+1][j+1];
            dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD; 
        }
    }
    for (int i = 0; i <= n; i++){
        debug(i, s[i], dp[i]);
    }
    cout << dp[0][0] << endl;


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
