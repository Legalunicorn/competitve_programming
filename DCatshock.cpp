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

// NOTE:
// somehow this problem looks a litlte familar 
// removes: n-1 
// jumps -> after each remove except the last
// n - 2 jumps min
// 2n - 3 base operations
// we can choose to jump twice if needed 
// 2n-3 + n- 2 = 3n - 5,  < 3n

// NOTE: TREE 
// 1. there is only one path from A to B 
// 2. consider Cat at the root?  
// 3. consider graph coloring -> a tree is definitely bipartite
// - It is NOT necessary the cat will jump, because we might accidentally force the the cat into 1 CC? then we might delete the node the cat is on 
// - the safe way is to ensure the tree remains 1 CC -> any we do that by only removing leaves 
// -> color the nodes, sort them by color


void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 0; i + 1 < n; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    debug(n, g);
    vpi red, blue;
    bool isred=1;
    auto go = [&](auto& go, int u, int p, int col, int d) -> void{
        if (u==0) isred = col==0? 1:0;
        if (col == 0) red.pb({d,u});
        else blue.pb({d,u});
        for (auto& v: g[u]) {
            if (v == p) continue;
            go(go, v, u, 1 - col, d+1);
        }
    };
    go(go, n-1, -1, 0, 0); // node n
    sort(all(red));
    sort(all(blue));
    stack<pi> b,r;
    for (auto& z: red) r.push(z);
    for (auto& z: blue) b.push(z);
    debug(red);
    debug(blue);

    vvi op;
    // remove n -1 nodes
    for (int i = 0; i + 1 < n; i++){
        // always remove the one with lowest possible depth
        pi rr = r.top(); r.pop();
        pi bb = b.top(); b.pop();
        // delete who ever is lower
        if (rr.F > bb.F){ // delete RED
            b.push(bb);
            if (isred){
                op.pb({1}); //change to blue
                isred = !isred;
                op.pb({2, rr.S+1});
            } else{
                op.pb({2, rr.S+1});
            }
        } else if (rr.F < bb.F) {
            r.push(rr);
            if (isred){
                op.pb({2, bb.S+1});
            } else{
                op.pb({1});
                isred = !isred;
                op.pb({2, bb.S+1});
            }
        }
        // compulsory change
        if (i < n-2){

            op.pb({1});
            isred = !isred;
        }
    }
    cout << op.size() << endl;
    for (auto& l: op){
        for (auto& z:l) cout << z << " ";
        cout << endl;
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
    while(T--) solve();
    return 0;
}
