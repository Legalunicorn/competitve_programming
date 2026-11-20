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
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    map<int,int> freq;
    map<int,int> mp;
    for (auto& z:a) freq[z]++;
    mp[a[0]]++;
    mp[a[1]]++;
    mp[a[2]]++;
    debug(freq,mp);
    if (mp.size() == 1){
        ll x = freq[a[0]];
        ll res = x * (x-1) * (x-2) / 6;
        cout << res << endl;
        return;
    } else if (mp.size()==2){
        ll x = freq[a[0]], y = freq[a[2]];
        ll res;
        if (a[1]==a[0]){
            res = x * (x-1) / 2 * y;
        } else{
            res = y * (y-1) /2 * x;
        }
        cout << res << endl;
        return;
    } else{
        debug(freq[a[0]]);
        debug(freq[a[1]]);
        // debug(frq)
        debug("hi");
        ll res = (ll)(freq[a[0]]) * (ll)freq[a[1]] * (ll)freq[a[2]];
        cout << res << endl;
    }
    
    // a * a * a = size_a choose 3 
    // a * a * b = size_a choose 2 * size_b
    // a * b * c = size_a * size_b * size_b
    //
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
