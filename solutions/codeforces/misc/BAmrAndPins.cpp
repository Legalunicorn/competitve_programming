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


// d = sqrt(dx^2 + dy^2) 
// we want to find d/r 
// and d mod r 
//


void solve(){
    ll r,x,y,x2,y2;
    cin >> r >> x >> y >> x2 >> y2;
    if (x==x2 && y==y2){
        cout << 0 << endl;
        return;
    }
    ll sqd = abs(x-x2)*abs(x-x2) + abs(y-y2)*abs(y-y2);
    ld d = sqrt(sqd*1.0);
    ld m = d/(r*2.0);
    ll ml = (ll)m;
    ld net = m - ml;
    // 16 -> d = 4 
    //

    debug(to_string(sqd),to_string(d),to_string(m));
    ll res = ml;
    debug(abs(net));
    if (abs(net)>(1e-15)) res++;
    cout << res << endl;



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
