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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;



void solve(){
    int c,p;
    cin >> c >> p;
    vpi a(c);
    for (int i =0; i < c;i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    sort(all(a),[&](const auto& u, const auto& v) {
        if (u.F < v.F) return true;
        else if (u.F > v.F) return false;
        else{
            if (u.S == v.S) return false;
            if (u.S > v.S) return true;
        }
        return false;
    });
    debug(a);
    for (int i = 1; i < c;i++) a[i].S = max(a[i].S, a[i-1].S);
    // for (int i = c-2; i >= 0;i--){
    //     a[i].S = max(a[i].S, a[i+1].S);
    // }
    debug(a);
    ll res = 0;
    for (int i = 0; i < p; i ++){
        int q,d;
        cin >> q >> d;
        int l = 0, r = c-1, evl = 0;
        while(l<=r){
            int m = (l+r)/2;
            if (q >= a[m].F){
                evl = max(evl, a[m].S - d);
                l = m + 1;
            } else r = m -1;
        }
        debug(q,d,evl);
        res += evl;
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
