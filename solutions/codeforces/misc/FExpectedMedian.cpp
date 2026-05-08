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
// 1. we can consider for each element, how many times does it appear as the median 
// k is odd, k // 2 is the length of each side 
//
// i mean cant we reduce this to a combinatorics problem 
// if a[i] == 0 skip 
//
// left: i - 1;
// right: n - i- 1;
//
// ans = left choose k/2  times right choose k/2 
// res += ans ;
//


// recap on k chosoe k 
// binomai coefficient module lar ge prime 
const int N = 200005;
ll fac[N];


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

void init() {
    // init factorial
    fac[0] = 1;
    for (int i = 1;  i < N; i++) fac[i] = fac[i-1] * i % MOD;
};

ll inverse(ll n){
    return binpowmod(n, MOD-2, MOD);
}

ll nchoosek(int n, int k) {
    return fac[n] * inverse( fac[k] * fac[n-k] % MOD ) % MOD;
};


// NOTE 
// median IS THE MIDDLE OF THE SUM U DUMB ASS 
// sinc ethe elements = {0, 1}
// for length k to have median of 1 
// the sum needs to > k/2 
//
// the order does not matter 
// k = low + high 
// (count1 choose high) * (n - high choose low) 

// maybe this is a dp problem 
// Count of subsequence of length k with at least h "1" 
//
//  h = n = k = 10e5 
//
//  how about we make it more precise for the remainig part "l"

// how about we try to force the number of "1"s and "0" chose 
void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    ll res = 0;
    int l = k/2, h = l + 1;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) c1 += a[i];
    c0 = n - c1;
    debug(c1,c0);
    for (int i = h; i <= k; i++){
        int j = k - i;
        if (i > c1 || j > c0) continue;
        debug(k, i , j, c1, c0);
        ll evl = nchoosek(c1, i) * nchoosek(c0, j) % MOD;
        res = (res + evl) % MOD;
    }
    debug(" ");
    cout << res << endl;
    // i have another stupid method 
    // which is to image the array is s

    // int c1 = 0;
    // for (auto& z:a) c1 += z;
    // ll top = nchoosek(c1, h) * nchoosek(n - h, l) % MOD;
    // cout << top << endl;
    // int h = k/2;
    // ll res = 0;
    // for (int i = h; i + h <= n-1; i++){
    //     if (a[i] == 0) continue;
    //     ll left = nchoosek(i, h);
    //     ll right = nchoosek(n - i - 1, h);
    //     ll evl = left * right % MOD;
    //     res += evl;
    // }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    init();
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
