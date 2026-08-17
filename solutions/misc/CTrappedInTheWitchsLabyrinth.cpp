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
    int n,m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    
    //vvb seen(n, vb(m, false));
    vvi dp(n, vi(m, -1) );
    // -1 unseend 
    // 0 in stack 
    // 1 completed: trap
    // 2: completed: exit


    auto go = [&](auto& go, int r, int c) -> int {
        if (r < 0 || r >=n || c < 0 || c >=m) return 2;
        // visited -> stuck
        if (dp[r][c] != -1) return dp[r][c];
        dp[r][c] = 1; // stuck by default
        int res = 2;
        if (g[r][c] == '?'){
            for (auto& d: dirs){
                int row = r + d[0];
                int col = c + d[1];
                int ans = go(go, row,col);
                if (ans == 1) res = 1;
            }
        } else if (g[r][c] == 'U'){
            res = go(go, r-1, c);
        } else if (g[r][c] == 'D'){
            res = go(go, r+1, c);
        } else if (g[r][c] == 'L'){
            res = go(go, r, c -1);
        } else {
            res = go(go, r, c+ 1);
        }
        return dp[r][c] = res;
    };

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dp[i][j] == -1) go(go,i,j);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dp[i][j] == 1) res++;
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
