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

// for each position find the range of validty 
// then put the range on a difference array? 
// lets say a[i] = [2, 10] 
// can we fix left and find all right 
// we know for each pos the smalelst bound to make it work 
// there are n^2 possible pairs 


// my solutions is not anywhere close as intended 
// i think we are supposed to use some kind of sliding winfow to solve htis 

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    // i think we just find the tightest bound 
    vpi pf(n), sf(n);
    int temp = a[0];
    pf[0].F = pf[0].S = temp;
    for (int i = 1 ; i< n; i++){
        pf[i].F = max(pf[i-1].F , a[i]);
        pf[i].S = min(pf[i-1].S , a[i]);
    }
    int v = b[n-1];
    sf[n-1].F = sf[n-1].S = v;
    for (int i = n-2; i>= 0; i--){
        sf[i].F = max(sf[i+1].F, b[i]);
        sf[i].S = min(sf[i+1].S, b[i]);
    }

    debug(pf);
    debug(sf);

    int low = 1, high = 2*n;
    for (int i = 0; i < n; i++ ){
        int right = max(pf[i].F, sf[i].F );
        int left = min(pf[i].S, sf[i].S);

        low = max(left, low);
        high = min(high, right);
        debug(left, right);
    }
    debug(low, high);
    ll x = low;
    ll y = 2 * n - high + 1;
    cout << x * y << endl;

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
