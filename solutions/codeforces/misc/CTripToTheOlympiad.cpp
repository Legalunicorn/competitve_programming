#include <bits/stdc++.h>
#include <iomanip>
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
// this problem is genuinely driving me nuts 
// we need pairwise DISTINCT numbers 
// n^3 solution is unacceptable 
//
// NOTE: (1) Proove some property of the max of (a^b) + b ^ c + c  ^ all
// (2) construct numbers a,bc, using the property 
//
//
// NOTE: (2) construct flippin bits and shit greedily 
//
// NOTE: (3) start from L,R and use their properties uniquely 
//
// i i+1   ... r 
//
// lets say 
// r = 011010101 
// then maybe we can find "a" "b" based on fixing this "r" 
// 1 0 1 1 0 1 
// we want them to be as different as possible, which maintainining the >= L constraint 
// bit by bit i guess 
// -> if (1 << mxbit) is >= L thats good becuase the xor will produce the largest power of 2 
// 1 0 0 0 00 
// 
//
void tobin(ll x){
    string s;
    while(x){
        if (x%2==1) s+='1';
        else s+='0';
        x/=2;
    }
    reverse(all(s));
    while(s.size() < 31) s = "0" + s;
    debug(s);
}


// 1 1 1 
// 1 1 0 
void solve(){

    ll l,r;
    cin >> l >> r;
    int k = 0;
    int mx = 0;
    for (int i = 34; i >= 0;i -- ){
        if (l >> i & 1) mx = max(mx,i);
        if ((l>>i&1) != (r>>i&1)) k = max(k,i);
    }
    // find max bit for r 
    debug(l,r,k);
    ll one = (r >> k) << k;
    ll two = one - 1;
    ll three;
    if (two - 1 >= l) three = two-1;
    else three = one+1;
    cout << one << " " << two <<  " " << three << endl;
  
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // debug(123 ^ 121, 121 ^ 118, 118 ^ 123);
    // debug(7 ^ 16 , 16 ^ 11, 11^7);
    // ll a = 1073741823LL;
    // ll b = 965321865LL;
    // ll c = 375544086LL;
    // ll d = 12551794LL;
    // debug(b ^ c, b ^ d, c ^ d);
    // tobin(b^c);
    // tobin(b^d);
    // tobin(c^d);
    // tobin(1073741823LL);
    // tobin(965321865LL);
    // tobin(375544086LL);
    // tobin(12551794LL);
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
