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

// u, d, l , r 
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;



int seen[1001][1001][4];



struct node {
    int x;
    int y;
    int d; // u, d, l , r
};

//node trace[1001][1001][4];

int trace[1001][1001][4];


void solve(){
    int n,m;
    cin >> n >> m;
    int sx = 0, sy = 0;
    int tx = 0, ty = 0;
    vector<string> g(n);
    for (auto&  z:g) cin >> z;
    for (int i =0 ; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (g[i][j] == 'G'){
                tx = i, ty = j;
            }
        }
    }
    memset(seen, -1, sizeof(seen));
    memset(trace, -1, sizeof(trace));

    debug(g);
    debug(sx,sy);
    debug(tx,ty);
    auto dfs = [&](auto& dfs, int i, int j, int d) -> bool { // return if we seed the stuff
        seen[i][j][d] = 1; // seen 
        if (i == tx && j == ty) return true;
        // debug(i, j, d);
        bool found = false;
        for (int p = 0; p < 4; p ++){
            vi dir = dirs[p];
            int r = i + dir[0];
            int c = j + dir[1];

            if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == '#') continue;
            if (seen[r][c][p] != -1) continue; // alreay seen;
            if (g[i][j] == 'o' && p != d) continue;
            if (g[i][j] == 'x' && p == d) continue;
            bool ans = dfs(dfs, r, c, p);
            if (ans){
                found = true;
                trace[r][c][p] = d;
                //trace[r][c][p] = {i,j,d};
            }
        }
        return found;
    };

    for (int d = 0; d < 4; d++){
        dfs(dfs, sx, sy, d);
    }
    string res; 
    vector<string> help = {"U","D","L","R"};
    bool found = false;
    for (int d = 0; d < 4; d++){
        if (seen[tx][ty][d] != -1){
            // u d l r 
            // d u r l
            debug(tx,ty);
            int x = tx, y = ty, dir = d;
            while( x != sx || y != sy ) {
                debug(x,y, dir);
                //if (d == -1) break;
                res += help[dir];
                int tt = x;
                int zz = y;
                x -= dirs[dir][0];
                y -= dirs[dir][1];
                dir = trace[tt][zz][dir];
            }
            found = true;
            break;
        }
    }
    reverse(all(res));
    if (found) {
        cout << "Yes" << endl;
        cout << res << endl;
    } else cout << "No" << endl;







    // we need to trace 
    // the obvious states are 
    // [row][col][dir] 
    // seen [row][col][dir] 
    // this just seems like a standard dfs, 
    // or actually we might need to do this iteratively
    // nah screw it imma try recurisve first 
    // then tracce is trivial 
    // when we need a sell, we just store the [row][col][dir] used to reached it 


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
