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

// for each empty cell COUT how many that 
// -> can reach asafe cell is k moves 
//
// we can try to find all safe empoty cells first
// then start a dfs? 
// what about the k constraint
// let k min the min distance to reach some celsl 
// then we cant how manty ewmptry <= k
//

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (auto& z:g) cin >> z;
    // find all good empty cell 
    // for each bomb cell we mark the row and col
    // the
    vi markrow(n);
    vi markcol(m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] =='#'){
                markrow[i] = 1;
                markcol[j] = 1;
            }
        }
    }
    vvi dist(n, vi(m, k + 10));
    vvb seen(n, vb(m, false));
    queue<pi> q;
    for (int i = 0; i < n; i++){
        if (markrow[i] ==1) continue;
        for (int j = 0; j < m; j++){
            if (!markcol[j]){
                debug("good",i,j);
                q.push({i,j});
                dist[i][j] = 0;
                seen[i][j] = 1;
            }
        }
    }
    if (q.size() == 0){
        debug("none");
        cout << 0 << endl;
        return;
    }
    int d = 1;
    // bfs
    while(!q.empty()){
        int len = q.size();
        for (int z = 0; z < len; z++){
            pi t = q.front();
            q.pop();
            for (auto& dir: dirs){
                int r = t.F + dir[0];
                int c = t.S + dir[1];
                if (r < 0 || r >= n || c <0 || c >= m || g[r][c]=='#' || seen[r][c]) continue;
                dist[r][c] = min(dist[r][c], d);
                seen[r][c] = true;
                q.push({r,c});
            }
        }
        d++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dist[i][j] <= k) ans++;
        }
    }
    debug(dist);
    cout << ans << endl;
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
