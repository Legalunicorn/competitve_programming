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

// take the floor of the divise 
// big / small -> ok 
// small / big ->  == 1 
//
//
// for all number to be the same 
// they all need to converge down to the MIN number OR smaller 
//
// ok yeah if we have a "2" present, anything large will just produce it 
// how do we get "1"? either its small / big 
// or same / same 
//
// the idea is probably just spam: largest divide by smallest
// if largest == smallest return false 

void solve(){
    int n;
    cin >> n;
    vpi a(n);
    vpi res;
    for (int i = 0; i < n; i++ ){
        int x; cin >> x;
        a[i] = {x, i};
    }
    for (int i = 0 ; i < 35 * n; i++){
        sort(all(a));
        if (a[0].F == a[n-1].F) break;
        int f = a[0].F;
        int b = a[n-1].F;
        int v  =b / f;
        if (b % f != 0) v++;
        a[n-1].F = v;
        res.pb({a[n-1].S+1, a[0].S+1});
    }
    if (a[0].F != a[n-1].F){
        cout << -1 << endl;
    } else{
        cout << res.size() << endl;
        for (auto& x: res){
            cout << x.F << " " << x.S << endl;
        }
    }

    // ai / aj 
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
