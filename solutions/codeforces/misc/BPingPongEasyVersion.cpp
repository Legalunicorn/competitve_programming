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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    int n;
    cin >> n;
    int pos = 0;
    vpi a(n);
    bool found = false;
    vb seen(n,false);
    vvi g(n);
    auto dfs = [&](auto& dfs, int u, int t) -> void{
        seen[u] = true;
        if (u == t) found = true;
        if (found ) return;
        for (int v:g[u]){
            if (seen[v]) continue;
            dfs(dfs,v,t);
        }
    };
    
    for (int i=0;i<n;i++){
        int id; cin >> id;
        if (id == 1){
            int x,y; 
            cin >> x >> y;
            int t = pos;
            debug(x,y);
            a[pos].F = x;
            a[pos].S = y;
            pos++;
            for (int i = 0; i < pos; i ++ ){
                if (a[i].F < x && x < a[i].S || a[i].F < y && y < a[i].S){
                    g[t].pb(i);
                }
                if (x < a[i].F && a[i].F < y || x < a[i].S && a[i].S < y){
                    g[i].pb(t);
                }
            }
            // pos++;
        } else{
            int a,b; 
            cin >> a >> b;
            // traverse the dfs 
            found = false;
            seen.assign(n,false);
            dfs(dfs,a-1,b-1);
            cout << (found ? "YES":"NO") << endl;
        }
    }
    debug(a);
    debug(g);
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
