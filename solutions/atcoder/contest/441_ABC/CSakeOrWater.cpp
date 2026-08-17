#include <bits/stdc++.h>
#include <type_traits>
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

void solve(){
     ll n , k , x;
     cin >> n >> k >> x;
     vl a(n);
     for (auto& z:a) cin >> z;
     sort(all(a));
     ll sum =0;
     for (int i=0;i<k;i++){
         sum += a[i];
     }
     if (sum < x) { // this part should be obvious 
         cout << -1 << endl;
         return;
     }

     sum = 0LL;
     for (int i = k -1; i >=0; i--){
         sum += a[i];
         if (sum >= x){
             cout << n - i << endl;
             return;
         }
     }
     // int cnt = 0;
     // for (int i = n -1; i>= 0; i --, cnt++){
     //     sum += a[i];
     //
     // }

     // ll heavy = 0;
     // ll light = 0;
     // int j = 0;
     // for (int i = n - k; i < n ; i ++, j++){
     //     heavy += a[i];
     //     light += a[j];
     //     ll test = min(heavy,light);
     //     if (test >= x){
     //         cout << i+1 << endl;
     //         return;
     //     }
     // }
    


     // cout << n << endl;

};

// 1. smallkest k cups must be 
// 2,3,4 but he wants 10, we cannot guarantee 
// assume smallest k cups >= k, 
// how do we ensure he drink at least x ? 
// 1. we assume that non of the cups he chose nwas sake 
// we find the index after k where it accumulates to at least .. k? 
// and if its non we must drink all 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
