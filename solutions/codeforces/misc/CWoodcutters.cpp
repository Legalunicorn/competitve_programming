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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// i Dont have proof but i think
// fall all in one direction might work 
//
// I read the first line of the editoral
// it says "dynamic programming" ook greedy is also accepted
// would never have guessed that shit in a million years 
//
// 1. status: LEFT, STAY, RIGHT 
// 2. differnces: which tree to which tree? 
//

void solve(){
    int n;
    cin >> n;
    vl a(n), b(n);
    for (int i=0;i<n;i++){
        ll x,h; cin >> x >> h;
        a[i] = x;
        b[i] = h;
    }
    int res = 0;
    // if cant go left, check right and its always optimal to go right if possible
    // why? suppose we dont go right, then its for the next guy to go left? 
    // but both are worht the same, and go right will always be better 
    ll mx = -INF;
    for (int i=0;i+1<n;i++){
        // check left
        if (a[i]-b[i] > mx) {
            res++;
            mx = a[i];
        } else if (a[i]+b[i] < a[i+1]){
            res ++;
            mx = a[i] + b[i];
        } else mx = a[i];
    }
    res++;
    cout << res << endl;


    // int res = 0;
    // int ans = 1;
    // vb fell(n,false);
    // fell[0] = true;
    // for (int i =1;i<n;i++){
    //     if (a[i]-b[i] > a[i-1]){
    //         fell[i] = true;
    //         ans++;
    //     }
    // }
    // ll far = INF;
    // for (int i = n -1; i>=0;i--){
    //     if (fell[i]) {
    //         far = min(far, a[i] - b[i]);
    //     } else{
    //         if (a[i]+b[i] < far){
    //             fell[i] = true;
    //             ans++;
    //         }
    //         far = a[i];
    //     }
    // }
    // res = max(res,ans);
    // ans = 1;
    // fell.assign(n,false);
    // fell[n-1] = true;
    // for (int i = n -2; i>=0;i--){
    //     if (a[i] + b[i] < a[i+1]){
    //         fell[i] = true;
    //         ans++;
    //     }
    // }
    // far = -INF;
    // for(int i =0;i<n;i++){
    //     if (fell[i]){
    //         far = max(far, a[i]+b[i]);
    //     } else{
    //         if (a[i] - b[i] > far) {
    //             ans++;
    //         }
    //         far = a[i];
    //     }
    // }
    // res = max(res,ans);
    // cout << res << endl;

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
