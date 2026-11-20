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
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    // 1 ticket -> m rides, cost b 
    // 1 ride -> a rubbles 
    if (a * m <=b){
        cout << a * n << endl;
        return;
    }
    // bad problem statement 
    int d = n/m;
    int cover = d*b;
    int rem = n - d*m;
    int res = min(cover+b, cover+rem*a);
    cout << res << endl;



    // int d = n/m;
    // debug(d);
    // debug(a*(n-d*m));
    // debug(d*b);
    // int res = a * (n - d*m) + d*b;
    // cout << res << endl;
    // // int res = b * d + a * (n - m*b);
    // cout << res << endl;
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
