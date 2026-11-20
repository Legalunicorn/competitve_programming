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


// NOTE: 
// sorting makes half sense only 
// there might be a greedy 
// notice there is a sort of grouping 
// imagine if set S is the answer 
// for every elment, the "other elemets" is the same 
// each element belongs to their own optimal bag 
// we need some searchable probalby of these bags to insert one more element 
// the all have a SIZE
//
// think in terms of swaps 
// if NEW y > grop size 
// we can only swap with the MIN element from the group 
//
//
// complicted, maybe we can query on something
//
// theorem 1. just search UP 
//
// 4 4 3  -> 4 4 4 + (4) ?? 
//
// ignore groups 
// how about 
// imagine we are given [x,y] how do we consstruct the answer in logn ? 
// sure some preprocessing helps 
// 


void solve(){
    int n,m;
    cin >> n >> m;
    vpl 
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
