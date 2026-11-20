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

// NOTE 
// 0 = (ax) +  b 
// x = -b/a 
// wait it doesnt need to be integer 
//
// we need to represnet this real numer properly 
// top/bom 

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    for(auto&z:a)cin>>z;
    for(auto&z:b)cin>>z;
    map<pi,int> mp;
    int extra = 0;
    // note: if B = 0, d = 0 is best 
    for (int i = 0; i < n;i++){
        if (b[i] == 0 && a[i] == 0) extra++;
        else if (b[i] == 0) mp[{0,0}]++;
        else if (a[i] == 0) continue;
        else{
            int g = __gcd(b[i],a[i]);
            int x = b[i]/g;
            int y = a[i]/g;
            mp[{x,y}]++;
        }
        // if (b[i] == 0) mp[{0,0}]++;
        // else if (a[i] == 0) continue;
        // else{
        // }
    }
    int res = 0;
    for (auto& [v,c]: mp) res = max(res,c);
    cout << extra+res << endl;

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
