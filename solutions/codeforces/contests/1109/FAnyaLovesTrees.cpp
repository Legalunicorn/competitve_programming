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
// thjis fels like a divide and conquer problem 
// the thing is 
// when we rotate, we can only rotate within a subtree
//  this implies than every node with subtrees are in sequence OR its a cyclic shift of a permutation [1,K]
//  we probably dont need to shift anytthing, but just maintain sets 
//  1. at most one set can be discintinuis>? no but it can merge
//  mayube we need to find 1 and k first
//
//  1 2 3 4 5 .. k 
//  we can use some small to large merging but.. 
//  my clarification is very unclear. 
// NOTE: 
// CLAIM 1  ==> all leaves in a subtree MUST be a contiguopus part of a permutation [1,k] (shifteed)
// CLAIM 2  ==> t
//
//
// CLAIM 3 ==> the order actuall matters! 
// we cant just check values. we musst 
//
// this is surely jus some dfs with stl merge 
// -> dfs 
// -> both return some set
// -> merge the children 
// -> we can start from min and iterate 
// if there is a gap two conditions must be met 
// "1" and "k" must exist in the set
// then we just return upwards???? 
// i want to be super sure before impl or just guess idk


// NOTE: 
// this is harder there is more observations 
// k = 9
// 1,2 8, 9  ==> there is no way to fix this innit>> ??? 
// chgildrnwe: 
// [left] [parent] [parent] how? 
// i can only swap within, 
// i have to think of them as blocks 
// i cant "SORT" but i can shift 
// so the requirement is even stricter? 
//
// CLAIM: 
// -> start from the block which has the least value 
// -> go tthorughall blocks and the must align 
// -> if so, return block [MN, MX]
//

void solve(){
    int n;
    cin >> n;
    // we store by parent interesting 
    vi par(n);
    par[0] = -1;
    vvi g(n);
    vi a(n);
    // how do i sort the order? 
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        g[x].pb(i); // like this??
    }
    for (auto& z:a) cin >> z;
    int k = MAX(a);
    bool valid = true; 

    auto dfs = [&](auto& dfs, int u, int p) -> pi{
        if (a[u] != 0) {
            return {a[u], a[u]};
        }
        vpi b;
        for (int v: g[u]){
            if (v==p) continue;
            pi evl = dfs(dfs, v, u);
            b.pb(evl);
        }
        int x = b.size();
        // find the min 
        int pos = 0, low = b[0].F;
        pi ans = b[0];
        for (int i = 0; i < x; i++){
            ans.F = min(ans.F, b[i].F);
            ans.S = max(ans.S, b[i].S);
            if (b[i].F < low){
                low = b[i].F;
                pos = i;
            }
        }
        for (int i = 1; i < x; i++){
            int p = (pos + i) % x;
            int las = (pos + i - 1 + x) % x;
            if (b[las].S + 1 != b[p].F){
                valid = false;
            }
        }
        debug(u, ans, valid);
        return ans;
    };
    dfs(dfs, 0, -1);
    // cerr << endl;
    if (valid) cout << "YES" << endl;
    else cout << "NO" << endl;
    // auto dfs = [&](auto& dfs, int u, int p) -> vi {
    //     vi cur;
    //     if (a[u] != 0) cur.pb(a[u]); // leaf value
    //     for (int v: g[u]){
    //         if (v==p) continue;
    //         vi leaves = dfs(dfs, v, u);
    //         if (cur.size() < leaves.size()) swap(cur,leaves);
    //         for (auto& z: leaves) cur.pb(z);
    //     }
    //     // checker!
    //     int mn = n + 5, mx = -1;
    //     int last = -67;
    //     int st = *cur.begin();
    //     bool gap = false;
    //     for (auto& l: cur){
    //         mn = min(mn, l);
    //         mx = max(mx, l);
    //         if (last == -67){
    //             last = l;
    //         } else{
    //             if (l != last + 1) gap = true;
    //         }
    //     }
    //     if (gap && ( mn !=1 || mx != k)) {
    //         valid = false;
    //     }
    //     debug(u, cur);
    //     return cur;
    // };


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
