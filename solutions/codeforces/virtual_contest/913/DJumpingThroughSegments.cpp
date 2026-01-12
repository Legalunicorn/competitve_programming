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


// sequence of intervals 
//


void solve(){
    int n;
    cin >> n;
    vpl a(n);
    for (int i=0;i<n;i++){
        int x,y;
        cin >> x >> y; 
        a[i] = {x,y};
    }
    ll l = 0, r = INF; 
    ll res = r;

    auto go = [&](ll k) -> bool{
        bool evl = true; 
        ll mn = 0, mx = 0; // our range of jumps 

        for (auto& [l,r]: a){
            ll low2 = -1 ,high2 = -1;
            if (mx + k < l) return false;
            if (mn - k > r) return false;


            // im over complicating this 
            ll l_mx = mx - k, r_mx = mx + k;
            ll l_mn = mn - k, r_mn = mn + k;
            ll high = min(r_mx, r);
            ll low  = max(l_mn, l);
            mn = low;
            mx = high;
        }
        return true;
    };

    while (l<=r){
        ll m = l + (r-l)/2;
        bool chk = go(m);
        if (chk){
            res = m;
            r = m -1;
        } else{
            l = m + 1;
        }
    }
    cout << res << endl;
    // can we binary serch + greedy, maintain min and max 
    // impl is kinda sketchy but i think i get it 

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
