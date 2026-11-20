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



void solve(){
    int n,x;
    cin >> n >> x;
    vi a(n);
    for (auto& z:a) cin >> z;
    // 0, 1 , 2 
    int xc = 0;
    int sum = x;
    int vs = x * (n+1);
    for (auto& z: a) if(z==x) xc++;
    for (auto& z: a) sum+=z;
    if (xc==n){
        cout << 0 << endl;
        return;
    }
    if (xc > 0 ){
        cout << 1 << endl;
        return;
    }
    cout << (sum == vs ? 1 : 2) << endl;
    // if (x == 0){
    //     cout << (sum == 0 ? 1 : 2) << endl;
    // } else if (x < 0 ){
    //     cout << ( sum<0 && sum%x==0 ? 1 : 2) << endl;
    // } else {
    //     cout << (sum>0 && )
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
