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


//NOTE:
//1. the first thing to consider to small/marge cases. but i realised the large cases is not large enough? 
//   we can make path of size 3, so the entire tree can be in groups of 3, all small cases?
//  
// PERF: Claim #1: If a path has 2 consueqnetive elements not the majority, we can split out a smaller path
// - intuitively we want the smallest path to check
// - let O be majority and X be other numbers 
// - ... O O ... 
// - if we assume we are inside a path that contains "X X"
// - the "X X " is not contributing then i can loosely claim at least one of the  the left || right side also has a majority
// - if by contradiction both left && right side of the "X X" does not have , then if we join together its not possible to have 
// - hence one of left/right side (which is shorter than the initial path) already has majority "O"
// - we can repeat this process until the path has at most one "X" in a row 
//  
//
// PERF: we can reduce the path to a small set of short patterns
// from claim #1 we know "x x" will not be in shortest path
//  Consider "o x o x" -> not majority but "o x o" is 
//  Consider "o x o x o" -> we can simplify to "o x o" 
//  consider "x o o x o o x"" or any case with "o o" -> we can just simplify to "o o"
// Hence the two cases are 
// 1) o o
// 2) o x o 
//
// PERF: Mark o o case trivially 
// -> perfom dfs, if parent and child node are same value, just mark that value as YES 
//
// PERF: Mark o x o 
// case1: o,o are siblings OR 
// case2: o is grandfather of o
// -> grand father, we just track the parent parent during dfs to mark
// -> simblings, each node we just run a frequency map any anthing more than 1 gets set
// -> actually these are the same cases, we can just check all edges from 1-n
//
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    for (auto& z:a) z--;

    vvi g(n);
    for (int i= 0 ;i+1<n;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi res(n);
    debug(a);
    for (int i= 0; i < n; i++){
        map<int,int> mp;
        for (auto& v: g[i]) mp[a[v]]++;
        debug(i, mp);
        for (auto& [v,c]: mp){
            if (c>1) {
                debug("grand!",i,v,c);
                res[v]=1;
            }
        }
    }
    auto dfs = [&](auto& dfs, int u, int p) -> void{
        if (p!=-1 && a[u] == a[p]) {
            debug("sib",u,p);
            res[a[u]] =1;
        }
        for (auto& v: g[u]){
            if (v==p) continue;
            dfs(dfs,v,u);
        }
    };
    dfs(dfs,0,-1);
    for (int i= 0 ;i < n; i++) cout << res[i];
    cout << endl;
    // cerr << endl;
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
