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

// interesting adhoc quesiton 
// observation is case work 
// b = 0 
//  try c >= n 
//  c = n-1
//  c = n-2 
//  and c < n-2 
//
//  then otherwose 
//  observse DISTINCT values 
//  and not that its c , b + c , 2b + c 
//  and so on, in either case its unique and will exceed n 
//
//  another idea is DISTINCT and MEX 
//  the MEX will ignore elements already inside 
//  but how many elements aare inside ? 
//
//  1: c 
//  2: b + c 
//  3: 2b + c 
//  4: 3b + c 
//  5: 4b + c 
//
//
//  x : (x-1)b + c < n 
//
//  x - 
//


void solve(){

    ll n,b,c;
    cin >> n >> b >> c;
    if (b == 0){
        if (c >= n){
            cout << n << endl;
        } else if (c == n-1 || c == n-2) cout << n -1<< endl;
        else cout << "-1" << endl;
        return;
    }

    if (c >= n) cout << n << endl;
    else cout << n - max(0LL, 1 + (n-c-1)/b) << endl;
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
