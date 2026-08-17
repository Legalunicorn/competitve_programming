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

void solve(){
    ll x,y;
    cin >> x >> y;
    // the y is determinisitc 
    // x + 6  , y = 0 
    // x + 3, y = 0 
    if (y == 0) {
        // x must be a multiple of x 
        if (x % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if (y < 0) {
        // there is a net negative 
        x -= (abs(y) * 4LL);
        if (x % 3 == 0 && x >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        x -= (y  * 2LL);
        if (x % 3 == 0 && x >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
