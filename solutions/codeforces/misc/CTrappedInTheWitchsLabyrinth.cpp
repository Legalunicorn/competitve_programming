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

// this is some nice graph question 
// we only need to print maximal 
// consider no "?"
// all paths deterministic
// we can do traversal and return boolean (true = exit) 
//
// if we have "?", there must have been 4 directions, in which if ANY is a cycle we just say yes 
// this can be a sort of DP 
// dp[i][j][4] 
//


void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i =0; i < n; i++) cin >> g[i];

    vvi dp(n, vi(m, -1));
    vvb seen(n, vb(m));
    debug(n,m,g);

    // auto dfs = [&](auto& dfs, int r, int c, int d) -> int {
    //     if (r < 0 || r >= n || c < 0 || c >= m){
    //         // you made it 
    //         return true;
    //     }
    //     if (dp[r][c][d] != -1) return dp[r][c][d];
    //
    //     bool found = false;
    //     if (g[r][c] != '?'){
    //         char c = g[r][c];
    //         if (c=='U') found = dfs(dfs, r-1, c, 0);
    //         else if (c=='D') found  = dfs(dfs, r+1,c,1);
    //         else if (c=='L') found = dfs(dfs,r,c-1,2);
    //         else found = dfs(dfs,r,c+1,3);
    //     } else{
    //         // any direction works 
    //         for (int i = 0; i < 4; i++){
    //             int row = r + dirs[i][0];
    //             int col = c + dirs[i][1];
    //             found = found || dfs(dfs,row,col,i);
    //         }
    //     }
    //     return dp[r][c][d] = found;
    // };
    //
    // what the fuck was "d" for anyways? 
    //

    

    auto dfs = [&](auto& dfs, int r, int c) -> int {
        debug(r,c);
        if (r < 0 || r >= n || c < 0 || c >= m) return dp[r][c] = 0;
        if (seen[r][c]) return dp[r][c] = 1;
        seen[r][c] = true;
        if (dp[r][c] != -1) return dp[r][c];
        int found = 0;
        if (g[r][c] == '?') {
            for (auto& d: dirs){
                int rr = r + d[0], cc = c + d[1];
                //if (seen[rr][cc]) continue;
                found = found | dfs(dfs, rr,cc);
            }
        } else{
            // true is bad
            char c = g[r][c];
            if (c == 'U') found = dfs(dfs,r-1,c);
            else if (c=='D') found = dfs(dfs, r+1,c);
            else if (c=='L') found = dfs(dfs,r,c-1);
            else found = dfs(dfs,r,c+1);
        }
        return dp[r][c] = found;
    };


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            dfs(dfs,i, j);
            // if (g[i][j] != '?'){
            //     for (int d = 0; d < 4; d++) dfs(dfs, i,j);
            // } else{
            //     char c = g[i][j];
            //     if (c=='U') dfs(dfs,i, j);
            //     else if (c=='D')  dfs(dfs,i, j);
            //     else if (c=='L')dfs(dfs,i, j);
            //     else dfs(dfs,i ,jNO MORE);
            // }
        }
    }
    int res = 0;
    debug(dp);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dp[i][j]) res++;
        }
    }

    cout << res << endl;

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
