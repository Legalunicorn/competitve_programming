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


// NOTE:
// there might be N log N approach with brute force maybe 
// -> proof: each element 



void solve(){
    ll n,x;
    cin >> n >> x;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl p = a;
    ll res = 0;
    auto go = [&](auto& go, vi& b) -> void{
        if (b.size() <= 1) return; 
        for (auto& x:b) res += x;
        if (b.size() <= 3) return;
        vl one, two, three;

    };


    // for (int i =1;i<n;i++) p[i] += p[i-1];
    // ll res = 0;
    //
    // auto go = [&](auto& go, int l, int r, ll sum) -> void{
    //     int len = r - l + 1;
    //     if (len <= 1) return;
    //     ll pfsum = p[r] - (l? p[l-1]:0);
    //     res += pfsum;
    //     if (len <= 3) return; // done 
    //
    //
    //
    //     // if (b.size()<=1) return;
    //     // for (int i = 0; i < b.size(); i++) res += b[i];
    //     // if (b.size()<=3) return;  // done 
    //     //
    //     //
    //     // we need to divide theres number optimally, but how ? 
    //     // if
    // };




    // // if sum(a) = x, YES 
    // // else no? 
    // ll sum = n-1; // number of zeros by default?
    // for (auto z: a) sum +=z;
    // if (sum == x) cout << "YES" << endl;
    // else cout << "NO" << endl;

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
