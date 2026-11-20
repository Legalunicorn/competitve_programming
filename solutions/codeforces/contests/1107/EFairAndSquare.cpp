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


// fuck i type my comments for this in de 
// arnet all path perfect squares? 
// every node is twice
// no wait 
// not all nodes are picked twice 
// if one node is between two others, it gets pick treice
//
// NOTE: perfect square: all primes are powered in doubles EXCEPT FOR 1 it seems like there is always one guy that get picked trice 
// or like the middle guy somehow 
// everyone else has occurance EVEN number of times 
// EVEN + ODD = ODD 
// meaning the THIRD times guy is ALWAYS the issue 
// who ius the third time guy? 
// can we reroot? 
// if we reroot, then this guy left and right sides are always 
// 1,2,3,4,5
// 3,6,9,12,15,18, 
// when wetimes 3 the parity followws 
// no wait 
// its not needed that third guy is ONE of thw 3 nodes 
// but can we still iterate as if this node is the third guy 
// then count downwards
// CURRENT NOTE 
// third guy 
// if im EVEN -> USED 
//      -> find ANY two children 
// else 
//  -> find ANY 3 children BUG: 
//  -> finding any 3 children does not guarentee current guy is used 
//
//
// BUG: WE'EW NOT TAKING POWER WE TAKING MULTIPLE OMG 
// if we times all the paths if 
// PROD NODES * (2 * 2 * 2 * 2  * 3) 
// 2 pow x, 3 pow 1 
//
// NOTE: im confgusing the times again 
// im getting somewhere 
//
// we consider each node as one of the used node, then find two other nodes in the subtree 
// if node is good we can pick any two 
// if node is bad? .. 




map<int,int> factor(int n){
    map<int,int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            // res.push_back(i);
            res[i]++;
            n /= i;
        }
    }
    // if (n>1) res.push_back(n);
    if (n>1) res[n]++;
    return res;
}



// we are saying this IS the bad node 
// BUG: i find it weired there is no MOD 
//
//


// BUG: 
// just because you are HEAD, does not make u the triple 
// what makes u the TRIPLE 
// is that all the chosen are from differren branches


// BUG:
// this might be some disguesting reroot dp 
//


// for each node chosen or note chosen dfs 
// presume we only pick from children so TTT cannot be above 
// if we PICK 
// TTT 
// - either a middle of a linear path 
// - or the lca of 3 notes 
// why not we count by each ans ? 
// 1. middle of a linear path 
// then we pick 2 from any random path number 
//
// LCA: then we pick 3 includ

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    vvi g(n);
    for (int i = 0; i + 1 < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vb good(n,false);
    for (int i = 0; i < n; i++){
        map<int,int> evl = factor(a[i]);
        bool bad = false;
        for (auto& [val, freq]: evl){
            if (freq % 2 == 1){
                bad = true;
                break;
            }
        }
        if (!bad) good[i] = true;
    }
    // return number of children
    ll res = 0;
    debug(good);
    auto go = [&](auto& go, int u, int p) -> int{
        int ans = 0;
        vl branch;
        for (auto& v:g[u]){
            if (v == p) continue;
            int evl = go(go, v, u);
            branch.pb(evl);
            ans += evl;
        }
        ll l = 0;
        ll rem = n - 1 - ans;
        if (rem > 0) branch.pb(rem);
        if (good[u]){
            {
                // pairs case 
                ll x = n - 1;
                ll tot = x * (x-1) / 2LL;
                for (auto& b: branch){
                    if (b < 2) continue;
                    tot -= b * (b-1) / 2LL;
                }
                l += tot;
            }

            {
                // triple case
                ll x = n -1 ;
                ll tot = x * (x-1) * (x-2) / 6LL;
                for(auto& b :branch){
                    if (b >= 3) tot -= b * (b-1) * (b-2LL) / 6LL;
                    if (b >= 2) tot -= (b * (b-1) / 2LL) * (n - b - 1LL);
                }
                l += tot;
            }
            debug(l);
        }
        debug(u, l, branch);
        res += l;
        return ans+1; // how many children in this branch
    };

    go(go, 0, -1);
    cout << res << endl;
    cerr << endl;

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
