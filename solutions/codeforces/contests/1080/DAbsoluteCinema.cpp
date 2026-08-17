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

// we are given x = 1, to x = n 
//


void solve(){
    int n;
    cin >> n;
    vl f(n);
    for (auto& z:f) cin >> z;
    vi res(n,-1);
    // to solve a[i] -> we need [i-1, i + 1]
    for (int i = 1; i + 1 < n; i++ ){
        ll d1 = f[i] - f[i-1];
        ll d2 = f[i+1] - f[i];
        ll evl = (d2 - d1)/2;
        res[i] = evl;

    }
    ll x = f[n-1];
    for (int i = 1; i < n; i++){
        ll d = abs(i + 1 - n );
        x -= (res[i]*d);
    }
    res[0] = x / (n-1);

    ll y = f[0];
    for (int i = 1; i + 1 < n; i++){
        ll d = abs(i + 1- 1);
        y -= (res[i]*d);
    }
    res[n-1] = y / (n-1);
    // now we need to solve a[0] and a[n-1] 
    //
    // we can use f[n-1] to solve a[0] 

    // i know how to find a[0] 
    // idk how to generalize it 

    debug(res);
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;


    // a[i] <= 1000 
    // wtf is this 
    // we are gien x = n and n values 
    // so its complete in a sense 
    // does the sum tell us anything 
    // f(n) - f(1) ? 
    // f(n) + f(1) = 
    // this has to be construction or some sort 
    // we know a[i] = [-1000, 1000]
    // can we brute force on this ? its very close to TLe 
    //
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
