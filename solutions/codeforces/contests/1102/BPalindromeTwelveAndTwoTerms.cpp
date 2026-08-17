#include <bits/stdc++.h>
#include <csignal>
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
// brute force all palindromes done work 
// we need another method 
// obsercation with div by 12? 
// 12 
// 24 
// 36 
// 48 60 72 8 4 9 6 108 120 132 
// i have a feeling this shit always exist 
// like we can carve a by minusing 12 
// swear this is th dumb 
// swear this is some dumb shit 
// we just try 
// 0 1 2 3 4 5 6 7 8 9 , 11 , 12 



void solve(){
    ll n,a,b;
    cin >> n;
    for (ll r = 0; r < 12; r++){
        a = r;
        if (r == 10) a = 22;
        if (a > n) continue;
        debug(a,b,n);
        ll b = n - a;
        if (b % 12 == 0){
            cout << a << " " << b << endl;
            return;
        }
    }
    cout << -1  << endl;
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
