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
// either counting or dp 
// max ~55 bits 
// t <= 100 
//
// t[i] = 0...t 
// are we constucting the numbre uwards?
// it t[i] = 
//
// its 2^weight * i 
// is this digit dp?? 
// or this some gredy shit, there is surely a min amount of bits we must use 
// its 2^weight as well 
// 10 * 2^pos -> 1010 
// i think it just means we convert the binary and skip the answer the length until the lsb "1" bit pos
//
// say 0b = 1101010 
// if we  = 4......
//        = 
//
// actually be careful of the direction we are expectiing 
//
// b[i] = 4 
//
// suppose t = 2, n = 2 
// 100
// 020 -> 100
// 012 -> 010 + 010 -> 100
//
// 2:
// t = 100 
// p = 50 

void solve(){
    ll n;
    int t;
    cin >> n >> t;
    ll mod = 998244353ll;
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
