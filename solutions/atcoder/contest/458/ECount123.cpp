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

// dp underconstaints not possible i think 
// star and bars?? 
// the only illegal matching is 
// BUG: 
// 1 <-> 3 
// BUG:
// im missing another observation maybe?  or development 
// [1] , [2,3] 
// [1,3] [3,1]  
// maybe i permutate all {1,2}, then try to insert the "3"s 
// "2" -> can go anywhere 
// imagine i have "1"s only : 11111111 
// then i have to insert "2"s 
// this is star and bars , figure it out later 
// but 
// -> [derived] the number of {1,2} combinations 
// 2 1 2 2 1 1 2 1 2 
// isnt this stars and bars again ? 
// the number of bars -> the number of groups of "2"s ?? 
// how the heck do we calcualte that 
// NOTE: approach 1;: add one by one 
// 1. we can permutate {1,2} 
// 2. we can try to insert {3} 
// issue -> we dont know how many "2" are stuck together 
// solution -> iterate through the number of components of "2"s? 
// we need some theorem related to compoentns -> gaps because its not sufficent 
// x1 -> ones 
// x1 + 1 -> number of bars to insert x2 
// 
//
//
// NOTE: approach 2: sum - count 
// so if we can count ALL matches and MINUS 
// all matches that has at least one (1,3), (3,1) couple it works 
// for loop: 
// iterate through the counts of [1,3] (or [3,1] or both) 
// from (0 to min(x1,x3)); 
// so we have {1} {2} {3} {1,3} 
// -> guarantee that that remaining {1} and {3} do not touch 
// what abott [1,3,1] is this 1 or 2 pairs... complex
//
//
//
//
// NOTE: approach 3: insert {3,1} then insert "2" 
// {1,3} -> star and bars 
// -> then to insert "2" we need 1 to divide EVERY 3,1 OR 1,3 boundar sync_with_stdio
// |   1 | 3 3|  1 | 3 3|  1|  3|  1 | 3 | 
// | 1 1 1 1 | 3 3 3 3 | 1 1 1 1  | 
// how do we account for the sides?? 
//
// NOTE: approach 4: 
// maybe there is some for loop involved, we can do O(x1) 
//

// what can we loop over if needed? 
// i dont think this is O(1) solution 
// we can loop over the number of segments using only {1,2} 
// wait a minut endl
//
// NOTE : 
// 1. we consider segments 1,333,1,333,111,3,3,1, 
// where must the "2" go? -> anywhere between the segments 
// or at the side 
// this is star and bars 
// we just need to iterate the nummber of segments 
// x1: 3 
// x3 : 5 
// exame 
// 111,33333 -> 2 segments -> 3 bars (2 segments is min )
// what is max number of segmetns? 
// -> min(x1,x3) * 2  // if one is bigger then + 1 
// for each segment, how many combinations are there 
//
// lets say segs = 4 
// 1,3,1,3 
// OR 
// 3,1,3,1 
// -> we just need to fill the exceed "1"s and "3"s 
// -> this is stara and bars??? 
// -> we have two one segs 
// -> we have x sparse ones? 
// what is the possible extensions to this 
// i feel like this is some star and bars shot 
// im overcomplicated this 
// if i have five "1" segments STRICTLY FIVE 
// how many ways to put x1-5 into 5 boxes -> 
// 4 bars 
//
//
// PSEUDO CODE:
// 1. iterate the possible number of atlernative segments (from 2 to max) 
// 2. both start with different (ensure its possible)
//   ONE = number of ways to fit 1 
//   THREE = number of ways to fit 3 
// 
// 1,3,1,3,1,3 
// 3,1,3,1,3,1,3 
//
// 3 -> fill each gap with "2"s then star and bars it 
//
// for each 


ll mod = 998244353;
const ll MAXN = 4000005;
ll fac[MAXN];
ll invfac[MAXN];
void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++){
        fac[i] = fac[i-1] * i % mod;
    }
}


ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}


ll inv(ll x){
    return binpowmod(x,  mod-2, mod);
}
ll ncr(int n, int k){
    if (k<0||k>n) return 0;
    return fac[n] * inv(fac[k] * fac[n-k] % mod) % mod;
}

void solve(){
    ll mod = 998244353;
    ll one, two, three;
    cin >> one >> two >> three;
    debug(one,two,three);

    ll res = 0; 
    for (int seg = 1; seg <= (one+two+three); seg++){

        if (two < seg - 1) break;
        int f = (seg+1)/2;
        int s = (seg)/2;

        int items = two - (seg-1);
        int boxes = seg+1;
        ll e3 = ncr(items+boxes-1, items);
        // ll e1 = 0, e2 = 0, e3 = 0;
        if (one >= f && three >= s){
            // ll e1 = 0, e2 = 0, e3 = 0;
            int oneleft = one - f;
            int threeleft = three - s;
            // oneleft into f boxes 
            ll e1 = ncr(oneleft+f-1, oneleft);
            ll e2 = ncr(threeleft+s-1, threeleft);
            ll xx = (e1 * e2) % mod;
            ll yy = (xx * e3) % mod;
            res = (res + yy) % mod;
        } 
        if (three >= f && one >= s){
            int oneleft = one - s;
            int threeleft = three - f;
            ll e1 = ncr(oneleft+s-1, oneleft);
            ll e2 = ncr(threeleft+f-1, threeleft);
            ll xx = (e1 * e2) % mod;
            ll yy = (xx * e3) % mod;
            res = (res + yy) % mod;
        }
    }
    cout << res << endl;
};

int main(){
    debug(ncr(5,1));
    ios::sync_with_stdio(0);
    init();
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
