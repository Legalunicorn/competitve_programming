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
// if we edit an item 
// 1. it only affects [i,n] 
// option 1
//  -> make pf[i] = 0
// option 2
//  -> maximise the future a[i] 
//
//  my confuse is option 2 might current be better, but what if 1 has 
//  side effects that turns out to be better? 
//
//  say we store the prefixses in a map ish and some offset 
//  oh we can only touch a[i] = 0 as well if that mattes 
//  say the pf situtation is lie 
//  3 3 3 
//  0 0 
//  2 2 
//  1 
//  9 
// the data structure or invariant we need to maintain is 
// 1) what is the most frequenet ement 
// 2) shift all elements by x 
// 3) add new elemnents 
//
// we can instead maintain an offset
// how do i 
// 1) add + get max fast? 
// map<value -> freq>  store the freq 
// then set<{freq, value}> for order


// NOTE: 
// 1. interate the array 
// if u find a zero, iterate until before the next zero
// maintain a fr
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    // compute prefix 
    // store all the p

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
