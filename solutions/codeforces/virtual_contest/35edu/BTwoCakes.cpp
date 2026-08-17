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


// n >= 2 
// JJJJJJ

void solve(){
    int a,b,n;
    cin >> n >> a >> b;
    int res = 0;
    debug(a,b,n);
    for (int x = 1 ; x <= 1000; x++){
        int one = a, two = b;
        bool valid = true;
        if (a < x || b < x) break;
        for (int i = 0; i < n; i++){
            if (one >= x) one -= x;
            else if (two >= x) two -= x;
            else {
                valid =  false;
                break;
            }
        }
        if (valid) res = max(res, x);
    }
    cout << res << endl;

    // for (int i = 1; i < 1000; i++){
    //     int x = a / i;
    //     int  y = b / i;
    //     if (x+y >= n) res = max(res, i);
    //     // bool valid = true;
    //     // int x = a, y = b;
    //     // for (int j = 0; j < n; j++){
    //     //     if (x < i && y < i){
    //     //         valid = false;
    //     //         break;
    //     //     }
    //     //     if (x >= i) x-= i;
    //     //     else if (y >= i) y -= i;
    //     // }
    //     // if (valid) res = i;
    // }
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
