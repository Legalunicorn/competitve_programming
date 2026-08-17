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

void solve(){
    ll n;
    ll k;
    cin >> n >> k;
    // maybe this is binary searchable? 
    // I dont know what kind of function it is 
    // i tink its a convave function 
    auto nat = [&](ll v) -> ll{
        return v*(v+1)/2;
    };

    auto comp = [&](ll l, ll r)->ll{
        ll temp = nat(r) - nat(l);
        // debug(l,r,temp );
        return temp;
    };

    auto findx = [&](ll i)-> ll{
        ll evl = k*(i+1) - k*(n -i - 1);
        // debug(evl);
        evl += comp(0,i);
        evl -= comp(i, n-1);
        evl = abs(evl);
        // debug(i,evl);
        // cerr << endl;
        return abs(evl);

        // ll evl = k*(i+1) - k*(n - i);
        // evl += comp(0,i);
        // evl -= comp(i+1,n);
        // return abs(evl);
        // ll add = comp(0,i) 
        // ll minus = comp(i+1,n] -
    };
    // if (n<1000){
    //     vi ans(n);
    //     for (int i =0;i<n;i++){
    //         ans[i] = findx(i);
    //     }
    //     debug(ans);
    // }
    
    ll l = 0, r = n-1;
    ll res = findx(0);
    while(l<=r){
        ll m = l+(r-l)/2;
        ll a = findx(m);
        ll b = findx(m+1);
        if (b < a){
            res = min(res,b);
            l = m +1;
        } else r = m -1;
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
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
