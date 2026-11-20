#include <bits/stdc++.h>
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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// we need to match our elemenhts that appear often
// we gather a map of common elements 
//

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> mp;
    for (auto& z: a) mp[z]++;
    int res = 0;
    for (auto& [v,f]: mp){
        res = max(res,f);
    }
    cout << res << endl;
    // priority_queue<int> pq;
    // for (auto& [x,v]: mp){
    //     pq.push(v);
    // }
    // int res = n;
    // while(pq.size() > 1){
    //     auto t = pq.top(); pq.pop();
    //     auto u = pq.top(); pq.pop();
    //     if (t>1) pq.push(t-1);
    //     if (u>1) pq.push(u-1);
    //     res--;
    //
    // }
    //
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
