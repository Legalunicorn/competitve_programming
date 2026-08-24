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
// max division for 10^12 is around 6700 

// NOTE:
// obviously we have to prime factorize S 
// no i mean 
// we have to integer division S maybe 
// d1, d2, d3, d4, d4 
// we also have quries, which im prettys sure need offline processing
// we need to find the intersection, but we can decpose area as vertical slices
// Q = (X, Y) 
// there is also issue of double counting 
// S is fixed in this stair case form 
// lets sort the query by width
// lets slice S by the x axis, everytime it changes
// then for each Query 
//  - its in the form: underneath, under, under, equal, over over ? 
//
//  //NOTE: fact 1 -> we have at most 7,000 segments of "X" 
//  10^3 x 10^4 = 10^8 is just tight enough
//  NOTE:
//  as the widhti ncrease the height decrease
//  we can just binary search over the first 
//
//  NOTE: 
// given some query 
// -> 
// -> actually we can precompute the sum of the first n divisor
// -> special case: query HEIGht = 1, we just brute force 
// -> 
// split into 3 parts 
// let qX be the width 
// 1. find the LAST divisor >= h     ->  calculate square area
// 2. check if qX IS just nice a divisor 
//      YES -> find prefix sum 
//      NO 
//          -> find prefix sum to the largest bound < Qx 
//          -> the last part calculate normally

// Pseudo implementation 
// 1. get a list of factorz of S, then double the list to get all the divisors 
// < 15,000 divisiors
//
// 2. for each query
//  -> take not of the Y 
//  -> split the X into parts and 
//
//  

void solve(){
    ll s;
    int q;
    cin >> s >>q;
    vl d;
    set<int> dst;
    for (ll i =1; i * i <= s; i++){
        if (s%i==0){
            d.pb(i);
            dst.insert(i);
        }
    }
    int len = d.size();
    if (d.back() * d.back() == s) len--;
    for (int i = len-1; i>=0; i--){
        ll x = s/d[i];
        dst.insert(x);
        d.pb(x);
    }
    int m = d.size();
    vl h = d;
    reverse(all(h));
    vl pf(m);
    pf[0] = s;
    for (int i = 1; i < m; i++){
        ll w = d[i] - d[i-1];
        ll area = w * h[i];
        pf[i] = area + pf[i-1];
    }

    debug(s);
    debug(d);
    debug(h);
    debug(pf);


    while(q--){
        ll qx, qy;
        cin >> qx >> qy;
        ll cnt = 0LL;
        int lb = -1;
        // first the LAST height >= qy
        {
            int l = 0, r = m-1, best = -1;
            while(l <= r){
                int mid = (l+r)/2;
                if (h[mid] >= qy){
                    best = mid;
                    l = mid +1;
                } else r = mid-1;
            }
            if (best != -1){
                debug(qx,qy, best);
                lb = best;
                // ll area = qy * d[best];
                ll area =min(qx, d[best]) * qy;
                cnt += area;
            }
        }
        debug(qx,qy, cnt);
        // find the last WIDTH <= qx
        if (qx > d[lb]){
            int l = 0, r = m-1, best = -1;
            while(l<=r){
                int mid = (l+r)/2;
                if (d[mid]<= qx){
                    best=  mid;
                    l = mid + 1;
                } else r= mid-1;
            }
            if (best != -1){
                ll pfarea = pf[best];
                if (lb >=0) pfarea -= pf[lb];
                cnt += pfarea;
                debug(">> ", qx,qy, best, pf[best], lb, pfarea, cnt);
                debug(qx, d[best], best, d.size());
                // get the special area
                if (qx > d[best] && best + 1 < d.size()){
                    debug("hi!");
                    ll ht = h[best+1];
                    ll wd = qx - d[best];
                    ll evl = ht * wd;
                    cnt += evl;
                }
            }
        }
        debug(cnt);
        // cerr << "  .   " << endl;  
        // special tail case
        cout << cnt << endl;
    }
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
