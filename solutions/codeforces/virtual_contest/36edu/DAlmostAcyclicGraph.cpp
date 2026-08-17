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

// how can 1 edge remove all cycles? 
// ALL cycles must contain this edge
// can we find all cycles?
// its trivial to find ONE cycle -> cycle detection algo , but not all cycles 
// what if we find a cycle 
// the answer must be within those nodes, which can be up to n 
// what if we use SCC algorithm
//  the fuck ? n * (n + m) can pass? 
// then this shit is triial just find a cycle and try for each
//
// impl dry run 
// 1. use cycle detecthio nalgo to get a cycle in order 
//
//
// 2. for each node in a cycle we run a cycle detecthion 
// except we specifically ignore {u,v} 






void solve(){

    int n, m;
    cin >> n >> m;
    vvi g(n);
    vi color(n), parent(n);
    vi cycle;
    int st = -1, ed = -1;
    bool print = true;
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >>v;
        u--, v--; 
        g[u].pb(v);
    }
    bool stop = false;

    auto dfs = [&](auto& dfs, int v, int a, int b) -> bool {
        color[v] = 1;
        for (int u :g[v]){
            if (v == a && u ==b) continue;
            if (color[u]==0){
                parent[u] = v;
                if (dfs(dfs,u,a,b)) return true;
            } else if (color[u] == 1){
                ed = v, st = u;
                return true;
            }
        }
        color[v] = 2;
        return false;
    };

    auto find = [&](int a, int b) -> bool{
        color.assign(n, 0);
        parent.assign(n ,-1);
        st = -1, ed = -1;
        for (int v = 0; v < n; v++){
            if (color[v] == 0 && dfs(dfs,v,a,b)) break;
        }
        if (st == -1) return false;;
        if (stop) return true;
        cycle.pb(st);
        for (int v = ed; v!= st; v = parent[v]){
            cycle.pb(v);
        }
        cycle.pb(st);
        reverse(all(cycle));
        return true;
    };

    find(-1,-1);
    stop = true;
    if (cycle.empty()){
        cout << "YES" << endl;
        return;
    }
    for (int i = 1 ; i < cycle.size(); i++){
        bool clear = !find(cycle[i-1], cycle[i]);
        if (clear){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;



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
