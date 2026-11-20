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


// peroid of W, and we can shift it anyhow 
// [0,w) ..


// each index MOD "w"

void solve(){
    int n,w;
    cin >> n >> w;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl odd(w,0), even(w,0);
    bool is_odd = false;
    for (int i=0;i<n;i++){
        int m = i%w;
        if (m == 0) is_odd = !is_odd;
        if (is_odd){
            odd[m] += a[i];
        } else{
            even[m] += a[i];
        }
    }

    vl podd = odd;
    vl peven = even;
    vl sodd = odd;
    vl seven = even;




    for (int i= 1;i<w;i++) podd[i] += podd[i-1];
    for (int i=1;i<w;i++) peven[i] += peven[i-1];
    for (int i = w-2; i>=0;i--) sodd[i] += sodd[i+1];
    for (int i= w-2; i>=0 ;i--) seven[i] += seven[i+1];

    ll res = min(podd[w-1], peven[w-1]);
    // int id = w 
    for (int i=0;i<w;i++){
        // take i from left 
        int r = w - i;
        ll val = 0;
        if (i>0) val += podd[i-1];
        val += seven[i];
        res = min(res,val);
    }
    for (int i=0 ;i < w;i++){
        ll val = 0;
        val += sodd[i];
        if (i > 0) val += peven[i-1];
        res = min(res,val);
    }
    cout << res << endl;





    
    // debug(odd,even);
    // // suff for odd, prefix for even
    // for (int i = w - 2; i>=0;i--) odd[i] += odd[i+1];
    // for (int i= 1;i<w;i++) even[i] += even[i-1];
    // debug(odd,even);
    //
    // ll res = min(odd[0], even[w-1]);
    // debug(res);
    // int id = 1;
    // for (int i = 0; i < w; i++){
    //     ll val = 0;
    //     if (i<w) val += even[i];
    //     if (id<w) val += odd[id];
    //     debug(i,id,val);
    //     id++;
    //     res = min(res,val);
    //
    //     // if (i > 0 ) val += even[i -1]; // prefix 
    //     // int s = w - i - 1;
    //     // if (s > 0 ) val += odd[s]; //suffix
    //     // debug(i-1,s, val);
    //     // res = min(res, val);
    //     // int s = w - i ; // 0 1 2, 3 2 1 
    // }
    // cout << res << endl;

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
