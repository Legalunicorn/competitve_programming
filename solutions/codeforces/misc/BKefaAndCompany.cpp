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


// there are a few moving parts here 
// constraint: the min and max money <= d 
// requirement: maximise sum of friendship points 
// should we just sort by constraint 
// and for each take in the most? 
// we can consider give nsomeone is the min, 
// we know who them ax ise 
// and thne we just grap everything we can becaues its optimal

// basic sliding window problem
void solve(){
    ll n, d;
    cin >> n >> d;
    vpl a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S;
    }
    sort(all(a));
    debug(a);
    ll res = a[0].S;
    ll points = 0;
    for (int l = 0, r = 0; l < n; l++){
        while(r < n && a[r].F - a[l].F < d){
            points += a[r].S;
            r++;
        }
        debug(l, points);
        res = max(res, points);
        // remove left 
        points -= a[l].S;
    }
    cout << res << endl;
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
