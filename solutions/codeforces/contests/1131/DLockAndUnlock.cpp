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
//  
//  if I lock 
// thery
// the optimal final value isa value in A 
//
// min op is a mint 
// its always the sum of deltas? 
//
// meaning we only 
// how we reac tha
//
// 2, 3 3, 4 4, 5 ,8, 9 9 


void solve(){
    int n;
    cin >> n;
    vi a(n);
    map<int,int> mp;
    for (auto& z:a) cin >> z;

    for (auto& z: a) mp[z]++;
    vpi b;
    for (auto& x: mp) b.pb(x);
    debug(b);
    if (b.size() == 1){
        cout << "0 0" << endl;
        return;
    }
    int m = b.size();
    ll op =0;
    for (int i = 1; i < m; i++) op += b[i].F - b[i-1].F;
    vl pf(m), sf(m);
    for (int i = 0; i < m; i++){
        pf[i] = b[i].S;
        sf[i] = b[i].S;
    }
    for (int i = 1 ;i < m;i++) pf[i]+=pf[i-1];
    for (int i = m-2; i >= 0; i--) sf[i] += sf[i+1];
    // compute right cost
    ll left = 0, right = 0;
    for (int i = 1; i < m; i++){
        ll d = b[i].F - b[0].S;
        right += d * b[i].S;
    }
    debug(pf);
    debug(sf);
    debug(left,right);
    ll res = right;
    for (int i = 1; i < m; i++){
        ll d = b[i].F - b[i-1].F;
        ll freq = sf[i];
        right -=  d * freq;
        ll f2 = pf[i-1];
        left += d * f2;
        res = min(res, left + right);
    }
    cout << res << " " << op << endl;
    cerr << endl;


    // this is messy but i get the idea
    //

    
    // ll op = 0;
    // for (int i = 1; i < b.size(); i++){
    //     op += b[i].F - b[i-1].F;
    // }
    // for (int t = 0; t < b.size(); t++){
    //     // b[t] is the one with final value
    // }
    // vl s;
    // // ll tot = 0;
    // for (auto& z: b){
    //     s.pb(z.S);
    //     // tot += z.S;
    // }
    // sort(all(s));

    // int mx = MAX(s);
    // int res = tot - mx;
    // cout <<res << " " << op << endl;
    //
    


    // ll res = INF;
    // ll of = 0;
    // // foward
    // {
    //     ll evl = 0;
    //     ll op = 0;
    //     ll lock = b.back().S;
    //     for (int i = b.size()-1; i > 0; i--){
    //         ll d = abs(b[i].F - b[i-1].F); 
    //         op +=d;
    //         if (i == 1) evl += d * min(lock, n - lock);
    //         else evl += d*lock;
    //         lock += b[i-1].S;
    //     }
    //     res = evl;
    //     of = op;
    //     debug(evl,op);
    // }
    // // backward
    // {
    //     ll evl = 0;
    //     ll lock = b.front().S;
    //     ll op = 0;
    //     for (int i = 0; i + 1 < n; i++){
    //         ll d = abs(b[i+1].F - b[i].F);
    //         op += d;
    //         if (i == n-1) evl += d * min(lock, n - lock);
    //         else evl += d*lock;
    //         debug(evl,d,lock);
    //         lock += b[i+1].S;
    //     }
    //     debug(evl,op);
    //     if (evl < res){
    //         res = evl;
    //         of = op;
    //     } else if (evl ==res){
    //         of = min(of, op);
    //     }
    // }
    // cout << res << " " << of << endl;
    // cerr << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
