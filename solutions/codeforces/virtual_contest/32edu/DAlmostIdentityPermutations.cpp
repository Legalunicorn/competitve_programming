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
// at peast n - k pi - i 
// wrong = n - k;
// wrong = 1 impossible 
// wrong = 2 yes
// wrong = 3 yes (triple swap)
// wrong = 4 (multipe ways)
//
// k =4 :  1 +2 + 3 + 4 
// k = 1 -> 1 (impossible )
// k = 2 -> n choose 2 -> n * (n-1) /2 
// k = 3 -> n choose 3, A B C // n chosoe 3 * 2 
// k = 4 -> n choose 4 times 
// 
// 10* 2 = 20 
// 10 
// 1 
// A B C D 
// c 
// b a d c 
// b c d a 
// c d a b 
// d a b c 
//
// A B C 
// c a b 
// b c a 

// int N = 1500;
// vi fac(N);
// void init(){
//     fac[0] = 1;
//     for (int i = 1; i < N;i++) fac[i] 
// }

void solve(){
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    if (k >= 1) res++;
    if (k >= 2){
        ll x = n * (n-1) / 2;
        res += x;
        debug(2,x);
    }
    if (k >= 3){
        // n choose 3
        ll top = n * (n-1) * (n - 2);
        ll bot = 3 * 2 * 1;
        ll x = top/bot;
        x *= 2;
        debug(3,x);
        res += x;
    }
    if (k >= 4){
        ll top = n * (n-1) * (n-2) * (n-3);
        ll bot = 24;
        ll x = top/bot;
        x *= 9;
        debug(4,x);
        res += x;
    }
    cout << res << endl;
    // k  = 4 
    // n = 1000 
    // this seems like a simple cashs splitting

};

int main(){
    ios::sync_with_stdio(0);
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
