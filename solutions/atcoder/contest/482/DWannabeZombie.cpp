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

// NOTE:
// 1,N -> must walk the entire length
//
// the other zombies we cna consider
//  (1) go left all the way -> go right all the way
//  (1) go left to first neighbour then both u turn
//
//
//  (2) go right all the way go left all the way
//  ()
//
//
// (1) Go left 
//      
//
//      humans can move too ! 
//      this is math
//

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll r = a.back() - a.front();
    for (int i = 0;i < n; i++){
        if (i == 0 || i == n-1){
            cout << r/2 << endl;
            continue;
        }
        ll res = r * 5;
        debug(i);
        // go left
        {
            ll ms = (a[i] + a[i-1])/2;
            ll t = a[i] - ms; // time 
            ll end = a.back() - t;
            ll evl = t;
            ll v = 0;
            if (end > ms){
                ll g =  (ms + end)/2 - ms;
                v = max(v,g);
                debug(v,g);
            }
            ll st = a.front() + t;
            if (st < ms){
                ll g = ms - (ms+st)/2;
                v = max(v,g);
                debug(v,g);
            }
            debug(ms,t,evl,st,end);
            evl+=v;
            debug(evl);
            res = min(res,evl);
        }
        cerr << endl;


        // go to the right
        {
            ll ms = (a[i+1] + a[i]) /2;
            ll t = ms - a[i];
            ll evl = t;
            ll st = a.front() + t;
            ll end = a.back() - t;
            debug(ms,t,evl,st,end);
            ll v = 0;
            if (st < ms){
                ll g = ms - (st+ms)/2;
                v = max(v,g);
                debug(v,g);
            }
            if (end > ms){
                ll g = (end+ms)/2 - ms;
                v = max(v,g);
                debug(v,g);
            }
            evl+=v;
            debug(evl);
            res = min(res,evl);
        }
        // cerr << endl;
        cout << res << endl;
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
    while(T--) solve();
    return 0;
}
