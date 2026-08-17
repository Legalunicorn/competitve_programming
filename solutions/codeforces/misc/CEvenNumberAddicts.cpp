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
// how i tackle the game here 
// -> the DP result is TIED to a specifc player 
// not the currnet player intension 
// then win is "|" and lose is "&" 
//
// sort of min max dp

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int co = 0, ce = 0;
    for (auto& z:a) {
        if (z%2==0) ce ++;
        else co ++;
    }

    int dp[101][101][2][2];
    memset(dp, -1, sizeof(dp));
    // dp reptoo verbse iresnets if the current player can FORCE ALICE to win
    auto dfs = [&](auto& dfs, int even, int odd, int p, int t) -> int {
        if (even + odd == 0){
            return (p == 0) ? 1 : 0; // if this currnet player can force alice to win
        }
        if (dp[even][odd][p][t] != -1) return dp[even][odd][p][t];
        int ans;
        if (t == 0){
            ans = 0; // cannot force a win -> try to force a win
            if (even > 0){
                ans = ans |  dfs(dfs, even-1, odd, p, 1 - t);
            }
            if (odd > 0){
                ans = ans |  dfs(dfs, even, odd-1, 1 - p, 1 - t); 
            }
        } else {
            ans = 1; 
            if (even > 0){
                ans = ans & dfs(dfs,even-1, odd,p, 1-t);
            }
            if (odd > 0){
                ans = ans & (dfs(dfs, even, odd-1, p, 1-t));
            }
        }
        return dp[even][odd][p][t] = ans;
    };

    int res = dfs(dfs, ce, co, 0, 0);
    cout << (res == 1 ? "Alice":"Bob") << endl;


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
