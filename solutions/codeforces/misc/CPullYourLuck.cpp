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
// 1 2 3 .. n 1 2 3 .. n 1 2 3 .. n 
// 1 2 3 4  5  6  7  8  9  10 
// 1 3 6 10 15 21 28 36 45 55 66 78 91 
// 0 1 0 2  0  3  0  4  0  5  0  6  0 
//
//
// sum of 1 to 2n 
// (2n)(2n+1)/2 
// n (2n+1) , % n = 0 -> repeats forever

void solve(){
    ll n, x, p;
    cin >> n >> x >> p;
    // odd numbers -> 0 modulus 
    // even numbers -> have half modulus 
    // we only need to check two cycles at most 
    ll sum  = 0;
    for (int i = 1; i <=  min(2 * n, p); i++){
        sum += i;
        ll p  = (x + sum) % n;
        if (p == 0){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;


    // it seems like the mod is either 0 or hal 


    // ll dist = n - x;
    // ll sum = n * (n-1) / 2;
    // ll md = sum % n;
    // ll res = INF;
    // sum = 0;
    // for (int i = 1; i <= n; i++){
    //     sum += i;
    //     ll p = (sum + x) % n;
    //     ll d2 = n - p;
    //     if (d2 % md == 0){
    //
    //     }
    // }
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
