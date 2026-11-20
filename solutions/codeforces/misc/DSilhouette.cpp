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

// a[i] = 0 
// -> a[i] is the smallest vlaue
//
// base on output 
// if a[i] == a[j]
// b[i] = a[j] 
//
// if a[i] > a[j] 
//    b[i] > b[j]
// hence we can deduce there is some reduction! 
// note that the position of the array literally does not matter 
// note that smallest group in a[i] must be 0 
// so map, {val, pos}
// 0: p1, p2p, .. okay value is unknown, there is nothing below 
// x : 
//

void solve(){
    int n;
    vl b(n);
    ll sum = 0;
    for (auto& z:b) cin >> z;
    vl a(n);
    map<ll,vi> mp;
    for (int i = 0;i < n;i++) mp[b[i]].pb(i);
    if (mp.begin()->F != 0){
        cout << -1 << endl;
        return;
    }
    ll prev = 0;
    map<ll,ll> t;
    for (auto& [v,p]: mp){
        if (v == 0) {
            prev = p.size();
            continue;
        }
        else{}
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
    while(T--) solve();
    return 0;
}
