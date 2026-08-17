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

// we need to sort but remember the position 
// for each number as the focuss 
//  

// natural idea 
// -> is there a transition from x_i to x_{i+1} 
// formalize the problem 
// 
// maybe we slowly increment "left"
// and the right we calculate or something 
//
// the left side is easy to compute 
// we just add the delta, times "i" layers 
//
// what then we can compute the right using the same logic right 
//
// or just ocmpute them independently 
//
// 1. create the array stored with indecreased
// 2. sorted it, and compute suffix and prefix values 
// for i to n store the answer and prefix _+ suffix in res[i] 
// 3. output res[i] from i to n 

void solve(){
    int n;
    cin >> n;
    vpl a(n);
    vl pre(n), suf(n);
    for (int i =0 ;i < n; i++){
        ll x; cin >> x;
        a[i] = {x,i};
    }
    sort(all(a));
    ll sum = 0;
    for (int i = 1; i < n; i++){
        ll d = a[i].F - a[i-1].F;
        sum += (d * i) + 1;
        pre[ a[i].S ] = sum;
    }
    sum = 0;
    for (int i = n -2; i >= 0; i--){
        ll d = a[i+1].F - a[i].F;
        sum += (d * (n - i -1)) + 1;
        suf[ a[i].S] = sum;
    }
    for (int i = 0; i < n; i++) cout << pre[i] + suf[i] + 1 << " ";
    cout << endl;
    debug(a);
    debug(pre);
    debug(suf);
    cerr << endl;
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
