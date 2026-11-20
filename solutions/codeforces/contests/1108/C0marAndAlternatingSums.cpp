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


// NOTE :
// find the number of possibe values where alternatve sum is 0 > 
// 2. we can form some kind of recurrance
// 
//
// ther eis no zeros but there is some positive number s
// this screams like dp 
// but mixed with prefix sum or sorts
// dp[i] -> the number of subseqeucens ending at x, being some value 
// not that this is alternating sums 
//
//  unlikely to be DP but could be 
//  the alternative is some kind of construction or something 
//  fuck codeforces

// dp[pos][parity][used]  ->  
// can we just shift the array by +2? no. if its odd the last number will have excess 
// if we plus x 
// 1. off sert 
// 2. dp 
// 3. map<freq> 
//
// NOTE: the first number cannot be "positive" only negative 
// (1) MAP 
// -> consider a[i] = 2 
// then i want to know how many subsequecnes stop a (-) and is -2 
// stop (-), sum = -2 
// stop at (+), sum = 2 
//
// then i need to add "2" to add to all in stop (-) and put them in (+),
// vice verdass 
// ok so this is like a add ing process that can blow up to 2 ^ n 
// i can instead keep track of the offsets (?) 
// this is too complicated and idt even possible 
// NOTE: array is non decreasing! 
// all the "-1" is at the start 
// non decreasing make this more important 
// because4 the -1 must be a prefix 
// we can use some combination of them to get 
// either -1, or 0 
// -1 -> any ODD ways to pick -1s 
// 0 -> any EVEN ways to pick -1s (also part of the answer)
// ########################## 
// then the remaining array is positive, from which all additions are positive 
// from which.... say sum = 28, if we can make alternative sum = 14 etc
// close but not there 
// supopse . 
// pfsum -> useless her
// we maintain a map
// the sorted array is very important isnt it ? 
// i feel like it proves something 
// that the answer or something cannot exceed the value for instance 
//
//
// NOTE:
// sorted positive array.
// all previous elements alternatiuve + and - 
// i theoreize its impossible for the sum to exceed the value? 
// more importantantly how do we solve for a[i]? 
// im starting to believe that all elements needs to be in pairs, or even count 
// and if not we must use -1 to take care 
// so this is just count possible wyas like that 
// 1. then just count ways to pairs, its just 
// for all numbers, count number of ways to pick 0,2,4,6,8... frequency, then multiply 
// this includes -1, 
// ############## 
// 1. consider using one -1 
// then now, exactly one element can be paired with oarger 
// 2,2, 3,3 5,5 ,6 6, 6, 7 
// this is very messy to count 
// 1. choose the element to have the "higher pair "
// -> if higher dont exist ignore 
// -> recalculate number of ways for "higher" to 
//
// given N distinct items, there are 2 ^ {n-1} ways to choose n distinct items 
// that means that okay fuck, 
//
// 1. collect frequencyu 
// 2. put in array 
// 3. prefix and suffix multiplication 
// 4. 
// wait a second  
//
// six 2's
// 32 ways to pick even pairs (including 0)
// 31 ways (excluding 0)



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

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    map<ll,ll> mp;
    for (auto& z:a) mp[z]++;
    int m = mp.size();
    vpl b;
    for (auto& [v,f] : mp){
        b.pb({v,f});
    }
    vl c;
    vl vals;
    ll mult = 1;
    for (int i = 0; i < m; i++){
        ll f = b[i].S;
        ll val = binpowmod(2ll, f-1ll, MOD);
        mult = (mult * val) % MOD;
        // c[i] = val;
        if (b[i].F != -1) {
            c.pb(val);
            vals.pb(b[i].F);
        }
    }
    ll res = mult;
    
    m = c.size();
    vl pf = c, sf = c;
    ll neg = 1LL;
    if (mp.count(-1ll)){
        neg = binpowmod(2ll, mp[-1ll]-1, MOD);
    } else{
        cout << mult << endl;
        return;
    }
    for (int i = 1; i < m; i++) pf[i] = (pf[i] * pf[i-1]) % MOD;
    for (int i = m - 2; i >= 0; i --) sf[i] = (sf[i] * sf[i+1]) % MOD;
    // what happen to the bigger number ? 
    // one -> sacrificed to pair with lower 
    // rest -> even number 
    // -> becomes pick an odd number
    debug(neg);
    debug(m);
    debug(neg);
    debug(mp);
    debug(vals);
    debug(c);
    debug(pf); debug(sf);
    for (int i = 0; i + 1 < m; i ++){
        ll x = vals[i];
        ll y = vals[i+1];
        if (x + 1 != y) continue; 
        ll evl = neg;
        if (i -1 >= 0) evl = (evl * pf[i-1]) % MOD;
        if (i + 2 < m) evl = (evl * sf[i+2]) % MOD;
        ll f = mp[x];
        ll evenPos = binpowmod(2ll, f-1, MOD);
        // evenPos = (evenPos + MOD - 1) % MOD; // remove choosing zeros 
        ll g = mp[y];
        ll succ = binpowmod(2ll, g-1, MOD);

        evl = (evl * evenPos) % MOD;
        evl = (evl * succ) % MOD;
        debug(i, vals[i], evl, evenPos, succ);
        res = (res + evl) % MOD;
    }
    debug(mult);
    // cerr << endl;
    cout << res << endl;
    
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
