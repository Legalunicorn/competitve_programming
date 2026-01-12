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


// this is some math, i just counldnt figure it out 
// its a observation thingfrom summation 
// sj - si 
// sj appears j times (0 2 3 4 5 )
// si appeers each time the j for it appears 
// which is (n - 1 -i )
//
// totla is 
// - n +1 + i
// 2i -n + 1


void solve(){
    int n,m;
    cin >> n >> m;
    map<int, pair<vi,vi>> mp;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int c;
            cin >> c;
            mp[c].F.pb(i);
            mp[c].S.pb(j);
        }
    }
    ll res = 0;
    for (auto& [c, pvi]: mp){
        vi x = pvi.F;
        vi y = pvi.S;
        sort(all(x));
        sort(all(y));
        int k;
        k = x.size();
        for (int i=0;i<k;i++){
            ll val = (2 * i + 1 - k)*(ll)x[i];
            res += val;
        }
        k = y.size();
        for (int i=0;i<k;i++){
            ll val = (2*i+1-k)*(ll)y[i];
            res += val;
        }
    }
    cout << res << endl;
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
