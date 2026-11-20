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

void solve(){
    int n;
    cin >> n;
    int m = 2*n;
    vl a(m);
    for (auto& z:a) cin >> z;
    sort(all(a));
    vl pf = a;
    ll res = INF;
    ll dx = a[n-1] - a[0];
    ll dy = a[m-1] - a[n];
    res = dx*dy;
    dy = a[m-1] - a[0];
    debug(a);
    for (int k = 0; k<n;k++){
        debug(n-1+k, k);
        dx = a[n-1+k] - a[k];
        res = min(res, dx*dy);
        debug(dx,dy);
    }
    cout << res << endl;

    // ?? why is it 2n 
    // oh because the order is messed up 
    // we dont know which is x or y coordinates 
    // we want the minimal area given some reactange 
    //
};

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
