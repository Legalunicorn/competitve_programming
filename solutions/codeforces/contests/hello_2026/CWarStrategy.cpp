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

// this is either math or greedy or binary search 
// after each "m" a new guy comes in 
// the goal is to have as much "1 1 1 1 1 1 " as possible 
// i feel like this has to do with depth counting 
// we can only take 1 from each depth, that is a limitation 
// 1. we select each node one and only once 


/// accumulate and SPREAD? 
// we already get moves for free though, no point hogging 
// we can move amount amove, so we should move to a moved square? 
// 1. take the first guy and move him fucking far 
// 2. 
// i think its optimal to go half left and half right 
// i think there is greedy idea + some computation 
// the no edge connecting this is a big limiitation 
// if i have 
//
// 1 guy has to move fucking far 
// we can think of this in parts maybe 
// 1. build up at K (at solo guy moves)
// 2. moves in direction 1 
// 2b (built up as guy moves)
// 3. move in directin 2 
//
// so its like 3 part to maximise is it? 
// this can form the premise of our checker as well 
// 1. calc Left and Right space 
// 2. make Large and Small space 
// 0 0 0 1 0 0 0   d0
// 0 0 0 1 1 0 0     d1
// 0 0 0 2 0 1 0    d2
// 0 0 0 3 0 0 1     d3
// 0 0 0 2 2 0 1     d4
// 0 0 0 3 1 1 1    d5
// 0 0 3 1 1 1 1    d6
// 0 2 1 1 1 1 1    d7 
//
//
// 0 0 0 1 0 0 0 
// 0 0 0 1 1 0 0 
// 0 0 0 
//
// to built up in one direction 
// say we want "x" 
//
// it cost x and x -1 
// then the build up = x 
// and min(x, N - x - x  +1 ) will be the remaining 
// this is either math or 

void solve(){
    ll n,m,k;
    cin >> n >> m >> k;

    ll e1 = k -1 ;
    ll e2 = n - k;
    if (e1 > e2) swap(e1,e2);

    ll res =0;

    auto go = [&](auto& go, ll x ) -> ll {
        // lets just make sure this is correct first 
        // initial part
        x = min(x, e2);
        ll tax = x + ( x -1 );
        if (tax > m) {
            return -1; // not possible right? 
        }
        ll evl = 1 + x; //we travelled thus far 
        ll ops = m - tax;
        ll extra = min({ops, e1, x});
            
        evl += extra;
        return min(n,evl);

    };
    // debug(e1,e2);
    // ll ub = e2;
    // for (int i=1;i<ub;i++){
    //     if (i>=1000) break;
    //     ll ckh = go(go, i);
    //     debug(i, ckh);
    // }
    // cerr << endl;
    // wht if m is fricking small
    // ll l = 0, r = min(e2, (m+1)/2);
    ll l = 0, r = min(e2, (m+1)/2);
    ll best = 1;
    while(l<=r){
        debug(l, r);
        ll m = l + (r-l)/2;
        ll chk = go(go,m);
        ll chk2 = go(go,m+1);
        debug(l,r,m,chk,chk2);
        if (chk2 >= chk){
            best = chk2;
            l = m +1;
        } else{
            r = m -1;
        }
        // debug(l,r,m,chk);
        // if (chk>best){
        //     best = chk;
        //     l = m + 1;
        // } else r = m - 1;
    }

    // debug(go(go,35));
    debug(" == ");
    cout << best << endl;


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
