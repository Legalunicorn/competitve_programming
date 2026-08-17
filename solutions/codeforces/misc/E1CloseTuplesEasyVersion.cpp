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
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    map<ll, ll> mp;
    vvl pre(n, vl(5));
    vvl suf(n, vl(5));
    for (int i = 0; i + 1 < n; i++){
        mp[a[i]]++;
        int id = 0;
        for (int j = a[i+1]-2; j <= a[i+1]+2; j++){
            pre[i][id] = mp[j];
            id++;
        }
    }
    mp.clear();
    for (int i = n-1; i > 0; i--){
        mp[a[i]]++;
        int id = 0;
        for (int j = a[i-1]-2; j <= a[i-1]+2; j++){
            suf[i][id] = mp[j];
            id++;
        }
    }
    // for (auto& z: a) mp[z]++;
    ll res = 0;
    for (int i = 1; i + 1 < n; i++){
        res += (pre[i-1][2] * suf[i+1][2]);
        res += (pre[i-1][2] * suf[i+1][3]);
        res += (pre[i-1][2] * suf[i+1][4]);

        res += (pre[i-1][1] * suf[i+1][2]);
        res += (pre[i-1][1] * suf[i+1][3]);

        res += (pre[i-1][0] * suf[i+1][2]);
    }
    cout << res << endl;


    // for (int i = 1; i + 1 < n; i++){
    //     // distance = 2 
    //     int x = a[i];
    //     int f = mp[x];
    //
    //     res += (f-1) * mp[x+1];
    //     res += (f-1) * mp[x+2];
    //     res += (f)
    //
    //     res += mp[x-1] * (f-1);
    //     res += mp[x-1] * mp[x+1];
    //     res += mp[x-2] * (f-1);
    // }
    // cout << res << endl;
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
