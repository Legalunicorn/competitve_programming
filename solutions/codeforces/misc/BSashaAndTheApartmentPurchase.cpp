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


int close(vl& a, ll x, int s){
    int pos = s;
    auto it = lower_bound(all(a), x);
    if (it == a.end()) return a.size() - 1;
    else if (it == a.begin()) return 0;
    auto low = prev(it);
    if (abs(x - *low) < abs(x - *it)) {
        return low - a.begin();
    } return it - a.begin();
}


void solve(){
    int n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));

    int m = n - k; // open bars
    vl pf(n);
    pf[0] = a[0];
    for (int i = 1; i < n; i++){
        pf[i] = a[i] + pf[i-1];
    }
    debug(m);
    debug(pf);

    map<ll,int> mp;

    for (int i = 0; i + m - 1 < n; i++){
        ll s = 0;
        ll e = i + m - 1;
        ll mid = (a[e] - a[s]) /2;
        // now we need to binary search for closes
        int pos = close(a, mid, s);
        debug(i,s,e,pos);
        ll sum = 0;
        if (pos > s){
            // return from s, s+ 1.. until pos)
            ll evl = pf[pos] - (s > 0? pf[s-1]: 0);
            ll t = (ll)(pos - s);
            sum += (a[pos] * t - evl);
        }
        if (pos < e){
            ll t = (ll)(e - pos);
            ll evl = pf[e] - (pos >0 ? pf[pos-1]: 0);
            sum += (evl - a[pos] * t);
        }
        mp[sum]++;
        debug(s,e,sum);
    }
    int res = mp.begin()->second;
    cerr << endl ;
    debug(mp);
    cerr << endl << endl;
    cout << res << endl;



    
};

/*
 * NOTE: we pick houses on the number line 
 * we can close k, so m = n - k bars OPEN 
 * we can try for all windows of size m (open bars)
 * compute the sum of distance from the middle 
 * maybe use a hash map then we just return the count of the min 
 *
 * NOTE: the second challenge is computing function from 
 *
 * TODO: i would say, insead of bars we calculate by window, 
 * then we binary search for the BAR in the window closes to the middle 
 * then we find the distance to said bar 
 * using some path and prefix sums 
 */



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
