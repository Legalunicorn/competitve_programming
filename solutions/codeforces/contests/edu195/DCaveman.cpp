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


bool check_bipartite(int u, vector<int>& color, vector<vector<int>>& g){
    //color ->{0: unassigne, 1: color one, 2: color two}
    int cur = color[u];
    int alt = 3 - cur;
    for (int v: g[u]){
        if (color[v]){
            if (color[v] == cur) return false;
        } else {
            color[v] = alt;
            if (!check_bipartite(v, color, g)) return false;
        } 
    }
    return true;
}

// NOTE:
// at least one neighbour of opposite color
// obviously if  |CC| = 1 -> impossible 
//
// when is it impossible
// 1. can bipartite color => definitely posible
//
// note: 
// a tree is always bipartite
// if we add more edges -> it ensures diff color 
// so conenct compoinent size >= 2 is always possibler
//
// zero -> CC of size 1 exist 
// 1 -> imposibe ans
// 2 -> only 1 CC, and its a bipartitej  
// remainig -> main


void solve(){
    int n,m;
    cin >> n >> m;
    vvi g(n);
    for (int i =0 ;i  < m; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // zero case
    for (int i = 0; i < n;i++){
        if (g[i].size()==0){
            cout << "Brain Melt" << endl;
            return;
        }
    }
    int cc = 0;
    vb seen(n, false);

    auto go = [&](auto& go, int u) -> void{
        seen[u]=true;
        for (int v: g[u]){
            if (seen[v]) continue;
            go(go, v);
        }
    };
    for (int i = 0;i<n;i++){
        if (!seen[i]){
            go(go,i);
            cc++;
        }
    }
    debug(cc);
    if (cc>1){
        cout << "Many" << endl;
        return;
    }


    // 1 CC only

    if (m >= n){
        cout << "Many" << endl;
        return;
    }

    // A tree
    vi color(n);
    bool is2 = false;
    for (int i = 0; i < n; i++){
        if (g[i].size() == n-1) is2 = true;
    }
    if (is2) cout << 2 << endl;
    else cout << "Many" << endl;

    // bool res = check_bipartite(0,color,g);
    // debug(color);
    // for (int i =0; i < n; i++){
    //     if (color[i] == 0){
    //         cout << "Many" << endl;
    //         return;
    //     }

    // 2 or many
    //

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
