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

// NOTE: we need to formalize the problem 
// both SAME episiode 
//  => x = a[i] = b[i], and all [1,x-1] has been seen 
//  this sounds like a dp problem 
// 
// the constraints are pretty funny 
// the dont have options its determinisitc 
//
// they must watch the shows together 
// -> all previous epsiodes must laone in the same day 
//
// we need a smart way to pivot or query or count 
//
// this is either a query based problem using DS 
// or a dp problem 
//
// NOTE: 
// start from L... extend out 
// if its invalid from R, its invalid all the way 
// -> in otherwords find the first invalid position 
// -> in otherwords we can MAP from the back to the front storing sommething 
//
//
// query based problem 
// starting at L 
// -> count all R that makes sense 
//      -> either find the next (inclusive of L) {1,1} or {1,x} or {x,1} 
//      -> everything between is automatically valid 
//
//
// select R 
// -> find all L that makes snse 
//      -> 

// NOTE:
// map from the back to the from 
// if watched x episodes together 
// the invalid state would be [x+1, not (x+1)]  
// the valid state would be [x+1, x+1] 
//
// and the state of i = [x+1, x+1] is a cachalbe problem 
// 
//
// NOTE: 
// solve from back to front 
// query fron fron to back 
//
//
//BUG: back to front 
//MAP<x, int> // {x, NOT x} 
//MAP,x, int> // {x,x} 


void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    map<int,vi> good, bad;
    for (int i = 0; i < n; i++){
        if (a[i] == b[i]){
            good[a[i]].pb(i);
        } else{
            bad[a[i]].pb(i);
            bad[b[i]].pb(i);
        }
    }
    // binary search over the position i guess 
    ll res = 0;
    vi dp(n,0);
    for (int i = 0; i < n;i++) dp[i] = i; 

    auto bs = [&](vi& pos, int g) -> int{
        int l = 0, r = pos.size()-1;
        int res = -1;
        while(l<=r){
            int m = (l+r)/2;
            if (pos[m] > g){
                res = pos[m];
                r = m -1;
            } else l = m + 1;
        }
        return res;
    };

    // we only care about good dont we?
    for (int i = n-1; i >= 0; i--){
        if (a[i] == b[i]){
            int x = a[i] + 1;
            // either we search for x+1, or we search for 
            int gd = n, bd = n;
            if (!good[x].empty()){
                    debug(good[x], i);
                int y = bs(good[x], i);
                if (y != -1) gd = y;

            }
            if (!bad[x].empty()){
                    debug(good[x], i);
                 int y =  bs(bad[x], i);
                 if (y != -1) bd = y;
            }
            debug(i,gd,bd, bad[x]);
            if (gd == n && bd == n){
                dp[i] = n-1;
            } else if (gd == n){
                dp[i] = bd-1;
            } else if (bd == n){
                dp[i] = dp[gd];
            } else{
                if (gd < bd) dp[i] = dp[gd];
                else dp[i] = bd-1;
            }
        }
    }
    // actual search answer
    for (int l = 0; l < n; l ++){
        // if (a[i]==1 && b[i] == 0 || a[i]==0 && b[i] =)
        if (a[l]== 1 && b[l] != 1 || a[l]!=1 && b[l]==1) continue; 
        int x = 1; 
        if (a[l]==1 && b[l]==1) x = 2;
        int gd = n, bd = n;

        if (!good[x].empty()){
            int  y  = bs(good[x],l);
            if (y!=-1) gd = y;
        }
        if (!bad[x].empty()){
            int y =  bs(bad[x],l);
            if (y!=-1) bd = y;
        }

        if (gd == n && bd == n){
            ll v = n - l;
            res += v;
        } else if (gd == n){
            ll d = (bd - l);
            res += d;
        } else if (bd == n){
            ll p = dp[gd];
            ll d = p - l + 1;
            res += d;
        } else{
            if (gd < bd) {
                // good first 
                ll p = dp[gd];
                ll d = p - l + 1;
                res += d;
            } else{
                // bad came first 
                ll d = (bd - l);
                res += d;
            }
        }
    }
    cout << res << endl;

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
