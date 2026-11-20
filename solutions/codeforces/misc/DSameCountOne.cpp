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
// 1 1 1 
// 0 1 0 
// 0 0 0 
// 0 0 0
//
// 0 1 0 
// 0 0 1 
// 1 0 0
// NOTE: there is no need for intermediate swaps 
// 1. swap same numbers does nothing so it never is optimal
// 2. swap difference number twice is the same as one swap
// 3. hence each position on a string only gets touched once
//
// NOTE: is sum(1) % n == 0 sufficient to be possible? or is it somehow not possible in some case
// 1. Assume our array is inbalance
// 2. Then some rows have more than others 
// 3. if we swap, MORE--, LESS++,
// 4. hence the difference does not work if its odd 
// 5. hence its only impossible to balance if we have some x, some x+1 
//          -> but this means its not possible to be divislbe 
//          -> we can reduce all cases to either its x, x+1 or not
//  NOTE: 
//  a row is either LESS, EQUAL, or MORE
//  1. a row that ha a required number no longer needs to be touched
//  2. a row that has 
//  3. swaps MUST happen between LESS and MORE
//      LESS  -> fast queue ? on zero spaces {INDEX, row}
//      MORE  -> fast queue ? oon one spaces {INDEX, row}
//      Map<INDEX, rows> less 
//      Map<INDEX, rows> more
//      total storage n log n
//      do
//          
//      -> COMBINE
//          1. for each row check if its less or more
//          2. for less

// Annoyin to implement 
// easy to solve
void solve(){

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
