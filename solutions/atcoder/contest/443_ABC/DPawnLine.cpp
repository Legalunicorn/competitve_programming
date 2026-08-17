#include <bits/stdc++.h>
#include <queue>
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


// we can only move up
// well the max piece defines the top 
// dont move it. 
// we need to solve this in O(n)
// n log n ? 
//
// we must constantly relax the bottom piece 
// but its possible we rela the bototm and its neighbour needs to be reliaxe as well 
//
//
// idea? 
// 1. find the max 
// 2. for each number, find the closest distance to a max 
// 3. guarenteeds such a number is less than or equal 
//
//
//
// i think this is a left relax 
// then right relax type of bull shit 
//
// i was stuck at a smilar lc question 


void solve(){
    ll n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    // i feel like ive seen a simlar leetcode question
    // i didnt understand how it worked buti rmbr tsol 
    vl left(n), right(n);
    ll res = 0;
    left[0] = a[0];
    right[n-1] = a[n-1];
    for (int i=1;i<n;i++){
        left[i] = min(a[i], left[i-1 ]+1);
    }
    for (int i = n-2; i>=0; i--){
        right[i] = min(a[i], right[i+1]+1);
    }
    for (int i = 0; i < n; i++){
        res += (a[i] - min(left[i],right[i]));
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
