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
// uses the center part at most twice
// if none is the center, it uses it exaclty 0 or 2 times
//
//
// outside - outside
// 0 is trivial -> precompute each direction and take the mine, make it circular 
//
// 2 times is tricly 
//
// convert this to array 
// we need to jump 
//
//
//
// outside - inside
//
// dikjsta from super noite 

void solve(){
    int n,q;
    cin >> n >> q;
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    ll tot =0;
    for (auto& r: a) tot+=r;
    for (auto& z:b) cin >> z;
    // we need to preprocesss NOT TAKING THE EDGE
    vl left(n);
    left = a;
    vl right(n);
    right = a;
    for (int i =1; i < n;i++) left[i]+=left[i-1];
    for (int i = n-2;i>=0; i--) right[i]+=right[i+1];
    debug(a);
    debug(left);
    debug(right);



    //

// vl left = a;
    // vl right = a;
    // for (int i = 0; i )
    //

    // impl the dijskta first 
    vvpl g(n+1);
    for(int i = 0 ;i < n; i++){
        int u = i, v = (i+1)%n;
        g[u].pb({v, a[i]});
        g[v].pb({u, a[i]});
    }
    debug(false);
    for (int i = 0; i < n; i++){
        g[i].pb({n, b[i]});
        g[n].pb({i, b[i]});
    }
    debug(false);
    priority_queue<pl,vpl,greater<pl>> pq;
    vl dist(n+1, INF);
    dist[n] =0ll;
    pq.push({0, n});
    while(!pq.empty()){
        pl t = pq.top(); pq.pop();
        int u = t.S;
        ll w = t.F;
        if (dist[u] < w) continue;
        for (auto& [v,ww]: g[u]){
            ll w2 = dist[u]+ww;
            if (w2 < dist[v]){
                dist[v] = w2;
                pq.push({w2, v});
            }
        }
    }
    debug("ok");
    debug(dist);

    // s ->>>> e
    auto qq = [&](int s, int e) -> ll {
        if (s ==e) return 0ll;
        if (s < e){
            ll evl = left[e-1] - (s>0? left[s-1]:0);
            return evl;
        } else{
            ll evl = right[s];
            if (e - 1 >= 0) evl += left[e-1];
            return  evl;
        }
    };

    while(q--){
        int s,t;
        cin >> s >> t;
        s--, t--;
        if (s==n){
            cout << dist[t] << endl;
        } else if (t==n){
            cout << dist[s] << endl;
        } else{
            ll evl = qq(s,t);
            evl = min(evl, tot - evl);
            evl = min(evl, dist[t] + dist[s]);
            // evl = min(evl, b[s] + dist[t]);
            // evl = min(evl, b[t] + dist[s]);
            cout << evl << endl;
        }
    }

    

    // all the queries

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
