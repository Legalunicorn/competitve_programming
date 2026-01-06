#include <bits/stdc++.h>
#include <iterator>
#include <queue>
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
    vl a(n);
    for (auto& z:a) cin >> z;
    priority_queue<pl> pq;
    for (int i=0;i<n;i++){
        if (a[i]<=0) continue;
        pq.push({a[i],(ll)i});
    }
    ll res = 0;
    // vvl talks;
    vpl talks;
    while(pq.size()>1){
        auto x = pq.top(); pq.pop();
        auto y = pq.top(); pq.pop();
        // if (x.F < y.F) swp(x,y);
        res++;
        talks.pb({x.S,y.S});
        if (x.F-1 > 0) pq.push({x.F-1, x.S});
        if (y.F-1 >0) pq.push({y.F-1,y.S});


        // ll mn = min(x.F,y.F);
        // res += mn;
        // talks.pb({x.S,y.S, mn});
        // if (x.F - mn > 0){
        //     pq.push({x.F-mn,x.S});
        // }
    }
    debug(a);
    debug(talks);
    cerr << endl;
    cout << res << endl;
    for (auto& rr: talks){
        cout << rr.F+1 << " " << rr.S+1 << endl;
        // cout << rr[0] < " " << rr
        // for (int i=0;i<rr[2]; i++){
        //     cout << rr[0]+1 << " " << rr[1]+1 << endl;
        // }
    }
    // priority_queue<ll> pq;
    // for (int i=0;i;i<n;i++) pq.push(a[i]);
    // ll res = 0;
    // vvl talks;
    // while(pq.size()>1){
    //     ll t = pq.top(); pq.pop();
    //     ll v = pq.top(); pq.pop();
    //     if (t<v) swap(t,v); // t > v 
    //     ll mn = min(t,v);
    //     res += mn;
    //     talks.pb()
    //     t -= v;
    //     if (t)
    // }

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
