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

void solve(){
    ll n,s,l;
    cin >> n >> s >> l;
    s--;
    vl a(n-1);
    for (auto& z:a) cin >>z;
    vl pf = a;
    for (ll i = 1;  i < n-1; i++) pf[i] += pf[i-1];
    ll res = 1;
    debug(n,s,l);
    debug(a);
    debug(pf);
    for (ll i = 0; i < n; i++){ // travel to the ith town
        ll d = 0ll;
        if (i == s){
            // actually this is not needed
            continue;
            // special case
            for (ll j = 0; j < n; j++){
                if (j < s){
                    ll dist = (s > 0? pf[s-1]:0) - (j > 0? pf[j-1]:0);
                    if (dist <= l) res = max(res, s - j + 1);
                } else if (j > s){
                    ll dist = (j > 0 ? pf[j-1]:0) - (s >0 ? pf[s-1]:0);
                    if (dist <= l) res = max(res, j-  s+1);
                }
            }
        } else if (i <s){
            d = (s>0? pf[s-1]:0) - (i > 0 ? pf[i-1]:0);
            // debug(i,d);
            if (d > l) continue;
            ll x = l - d; // left
            ll vis = s -i  +1;
            // ll left = min(n-1, s+1);
            ll left = s+1;
            ll right = n-1;
            ll evl = -1;
            while(left<=right){
                ll mid = (left+right)/2;
                // distance from mid to i;
                ll dist = (mid>0? pf[mid-1]:0) - (i > 0? pf[i-1]:0);
                if (dist <= x) {
                    evl = mid;
                    left = mid+1;
                } else right = mid-1;
            }
            if (evl!=-1 && evl>=s) vis+=evl-s;
            debug(i,vis);
            res = max(res, vis);

        } else { // s.. i 
            d = (i>0? pf[i-1]:0) - (s > 0 ? pf[s-1]: 0);
            // debug(i,d);
            if (d > l) continue;
            ll x = l -d;
            ll vis = i - s+ 1;
            // ll left = min(n-1,(ll)i+1);
            ll left = 0;
            ll right = s-1;
            debug(i,left,right);
            ll evl = -1;
            while(left<=right){
                ll mid = (left+right)/2;
                // debug(left,right,mid);
                ll dist = (i>0? pf[i-1]: 0)- (mid>0?pf[mid-1]:0);
                if (dist <= x){
                    evl = mid;
                    right = mid-1;
                } else left = mid+1;
            }
            if (evl!=-1 && s>=evl) vis+=(s-evl);

            res = max(res,vis);
        }
    }
    // sanity check
    res = min(res, n);
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
    while(T--) solve();
    return 0;
}
