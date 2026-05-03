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


// "1" has no effect on the subrray 
// 6 = 2 * 3 
// anything divisible by 6 will mayb the subarray divisible by 6 
// anything divisible by 6 should go in front 
// otherwise 
// 2 3 should be together?



void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    //
    // tst(a);

    // tst(a);
    vi zero, two, three, rest;

    for (int i = 0; i < n; i++){
        if (a[i]%6==0) zero.pb(a[i]);
        else if (a[i]%2 == 0) two.pb(a[i]);
        else if (a[i]%3==0) three.pb(a[i]);
        else rest.pb(a[i]);
    }
    for (auto& z: two) zero.pb(z);
    for (auto& z: rest) zero.pb(z);
    for (auto& z: three) zero.pb(z);
    for (auto& z: zero) cout << z << " ";
    cout << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi g = {12, 18, 4, 7 ,5 ,9};
    debug("---");
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
