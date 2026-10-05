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
// if we were to doo this greedily, we simular doing all operatoins then keep removing the smallest one 
// that means that after k operations there is a split somewhere that we take all the values 
// its possible that some elements of the split are taken and some are not ie:   x-1, x , x , x , x + 1 
// we might split in x, so some gets taken some dont
// we can still binry search over the split "x", but we need to be careful, 
// - note the total number of operation needed
// - note how many elements use "x", N 
// - if we exceed by M operations and M >= N, its a FALSE, otherwise is a TRUE, and we remove M "x"s from the acc


void solve(){
    int n;
    ll k;
    cin >> n >> k;
    // binary search over the min value i can scrape
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    ll l = 0ll,  r = (ll)1e12;
    ll res = 0ll;



    auto check = [&](ll x) -> bool{
        ll same = 0; // how many numbers has x in the sequence 
        ll gain = 0ll; // how much score we gained, only applicable if function -> TRUE
        ll ops = 0ll;
        for (int i = 0; i < n; i++){
            if (a[i] < x) continue; // nothing to take
            if (a[i] == x){
                ops++;
                same++;
                gain +=x;
                continue;
            }
            if (a[i] == b[i]){
                if (a[i]==x) same++;
                ops++;
                gain+=a[i];
                continue;
            }
            if (a[i] < b[i]){
                if (a[i]==x) same++;
                ops++;
                gain+=a[i];
                continue;
            }
            // a[i] > x, and we need to calculate 
            // (1) the sum from s>=x, s+b[i], s+2b[i], ... a[i] 
            // a[i] - yb[i] >= x 
            // a[i] - x >= y b[i]
            // (a[i]-x]/b[i]) >= y
            // y <= (a[i]-x])/b[i] 
            // debug(a[i],x,b[i]);
            ll y = (a[i]-x)/b[i];
            // debug(y);
            ll div = a[i]/b[i];
            // debug(div);
            if (y%b[i]!=0) div++;
            y = min(y, div);
            ll s = a[i] -y*b[i];
            if (s == x){
                same++;
            }
            ll sn = (2*s + y * b[i]) * (y+1ll) / 2ll;
            if (s < 0) sn += abs(s);
            debug(a[i],b[i],x, s, y, sn);
            gain += sn;
            ops += (y+1ll);
        }
        debug(x, ops, gain, k);
        if (ops <= k){
            res = max(res, gain);
            return true;
        }
        ll donate = same - 1;
        if (ops - k > donate) return false;
        ll gone = min(ops-k, donate);
        res = max(res, gain - gone * x);
        return true;
    };
    ll optm = -1;

    while(l<=r){
        ll mid = l+(r-l)/2;
        bool evl = check(mid);
        debug(mid, evl);
        if (evl){
            optm = mid;
            r = mid-1;
        } else l = mid + 1;
    }
    debug(optm);
    cout << res << endl;
    cerr << endl;

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
