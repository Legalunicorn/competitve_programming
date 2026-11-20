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
// we can do some annoying case splitting 
// 1st/last interval >= k then we just clip that ends 
// otherwise lets try interval by iunterva l
// [l,r+1] 
// this is the only range we should be concerned with i guess 
// [l,r+1] -> [l+m-1, r+m]
//
// (1,4) m = 10
// 1,2,3,4,5*
// 10,11,12,13,14,15
//
// guaranteed range 5,6,7,8,9,10 -> 
//
// PERF:
// is we go from [L,R]
// we are guanranteed as we slide in the block the leftside consistently -1 each slide 
// so it either stay the same or decrease 
// hence if sum < k, we can ignore
// otherrwise we need to decreaase by k - sum, which is binary searchable
// so we binary searh over the distance 
// there is also a reverse effect


// the only part left is querying from a range of [X, X+M-1] quicly
// i can try in log nm 


void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    vpl a(n);
    vl pf(n);
    for (int i= 0 ; i < n; i++) cin >> a[i].F >> a[i].S;
    for (int i = 0; i < n; i++) pf[i] = a[i].S - a[i].F + 1;
    for (int i = 1; i < n; i++) pf[i]+=pf[i-1];
    
    // trivial case first or last edge
    // BUG: 
    // todo
    

    auto query = [&](ll left) -> ll{
        ll right = left+m-1ll;
        ll sum = 0;
        int l = 0, r = n-1;
        int st = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if (a[mid].F >= left){
                st = mid;
                r = mid-1;
            } else l = mid+1;
        }
        l = 0, r = n -1;
        if (st == -1) return 0ll;
        int end = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if (a[mid].S >= right){
                end = mid;
                l = mid+1;
            } else r = mid-1;
        }


        return sum;
    };

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
