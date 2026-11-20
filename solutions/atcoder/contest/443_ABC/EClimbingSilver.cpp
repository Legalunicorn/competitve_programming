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

void solve(){
    int n,c;
    cin >> n >> c;
    vector<string> g(n);
    for (auto& z:g) cin >> z;
    // bruh what the fuck is this 
    // if dest is empty he can mot 

    // return the max steps he can reach 
    // of dp[n-1][0] == n-1, we win
    vvb free(n, vb(n, false));
    for (int i = 0; i < n ; i++){
        for (int j = n-1; j >= 0; j --){
            if (g[j][i]=='#') break;
            free[j][i] = true;
            // if (g[i][j]=='#') break;
            // free[i][j] = true;
        }
    }
    debug(free);
        
    for (auto& x: g){
        debug(x);
    }
    

    // vvi dp(n+1, vi(n+1,-1));

    vector<vvi> dp(n+1, vvi(n+1, vi(2,-1)));

    // maybe its like 3d dp 
    //

    vb reach(n,false);
    auto go = [&](auto& go, int r, int c, int f) -> int {
        if (r == 0) {
            reach[c] = true;
            return 1;
        }
        if (dp[r][c][f]!=-1) return dp[r][c][f];
        debug(r,c);
        int col;
        int res = 0;
        for (int i = -1; i<=1; i++){
            col = c + i;
            if (col<0 || col >=n) continue;
            // if (g[r][col]=='.') res = max(res, 1 + go(go,r-1,col));
            if (g[r][col]=='.') res = max(res, 1+ go(go,r-1,col, f && free[r-1][col]));
            else{
                if (col+1 >= n || free[r-1][col+1] || f==1  ) {
                    res = max(res, 1+ go(go,r-1,col, 1));
                }
            }
        }
        return dp[r][c][f] = res;
    };
    go(go,n-1,c, free[n-1][c]);
    debug(dp);

    for (int i = 0; i < n; i++){
        if (reach[i]) cout << "1";
        else cout << "0";
    }
    cout << endl;

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
