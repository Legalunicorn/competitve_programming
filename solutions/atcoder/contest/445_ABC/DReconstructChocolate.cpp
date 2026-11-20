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

    ll h,w;
    cin >> h >> w;
    int n;
    cin >> n;

    vvl a(n);
    for (int i = 0; i < n; i++){
        ll h,w;
        cin >> h >> w;
        a[i] = {h,w,i};
    }
    vvl b = a;
    sort(all(a), [&](const auto& p, const auto& q){
            return p[0] > q[0];
    }); // H 
    
    sort(all(b), [&](const auto& p, const auto& q){
            return p[1] > q[1];
    }); // W 
    vb seen(n, false);
    int one = 0, two = 0;
    ll l = 1, r = w;
    ll u = 1, d = h;

    vpi res(n);
    for (int i = 0; i < n; i++ ){
        ll cw = r - l +1 ;
        ll ch = d - u + 1;
        // move both pointers 
        while(one < n && seen[a[one][2]]) one++;
        while(two < n && seen[b[two][2]]) two++;

        if (one < n && a[one][0] == ch ) {
            debug(1,a[one]);
            int pos = a[one][2];
            res[pos] = {u,l};
            debug(res[pos]);
            l += a[one][1];
            one++;
            seen[pos] = true;

        } else if (two < n && b[two][1] == cw){
            debug(2, b[two]);
            int pos = b[two][2];
            res[pos] = {u,l};
            debug(res[pos]);
            u += b[two][0];
            two++;
            seen[pos] = true;
        } else{
            debug("failed!");
        }
        debug(l,r,u,d);
        // cerr << endl;
    }
    for (int i  = 0; i < n; i++){
        cout << res[i].F << " " << res[i].S << endl;
    }

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
