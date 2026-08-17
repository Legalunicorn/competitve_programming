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


// x -> multipled by number of levels computed 
// i canot prove if this is monotonic.. 
// i know that x increases, levels completed decreases 
// monsters die by the NUMBER of sword strikes, not HP 
//
// hence. 
// for each level to completed 
// -> find the 

void solve(){
    int n;
    cin >> n;
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;

    for (int i =1 ; i< n;i ++) b[i] += b[i-1];
    sort(all(a));
    debug(b,a);
    cerr << endl;
    ll evl = 0;
    for (int i = 0; i < n; i++){
        if (b[i] > n) break;
        ll p = b[i];
        ll x = a[n - p];
        ll res = (i + 1) * x;
        evl = max(evl, res);
    }
    cout << evl << endl;

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
