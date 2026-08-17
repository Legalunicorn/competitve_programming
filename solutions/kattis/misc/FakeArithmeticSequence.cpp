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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    // this is clearly a dp problem 
    // we can do n^3 i think 
    // reduce this to a dp problem
    // means we solve for each starting position (i, j) 
    // or oterwise we just want to know for a subsequence with prev1 = x, and prev2 = y what is the longest answer? 
    // or otherwise itsm ore like 

    vector<vvl> dp(n+1, vvl(n+1, vl(n+1, -1)));
    auto go = [&](auto& go, int i, int j, int k) -> int {
        if (k == n || j == n) return 0;
        if (dp[i][j][k]!=-1) return dp[i][j][k];
        int ans = 0;
        if (a[k] == a[i]+a[j]) ans = 1 + go(go, j ,k, k+1);
        ans = max(ans, go(go, i,j, k + 1));
        return dp[i][j][k] = ans;
    };
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j +1< n; j++){
            ans = max(ans, go(go, i,j,j+1));
        }
    }
    ans+=2;
    cout << ans;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
