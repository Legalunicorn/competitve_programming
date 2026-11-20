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
    vi p(n), a(n);
    for (auto& z:p) cin >> z;
    for (auto& z:a) cin >> z;
    // i might be retarded
               // 

    map<int,int> mp;
    for (int i =0; i< n;i++) mp[p[i]] = i;
    
    vi test(n);

    for (int i = 0; i < n; i++){
        int p = mp[a[i]];
        test[i] = p;
    }
    for (int i = 1 ; i < n; i++){
        if (test[i] < test[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    // int far = 0;
    // for (int i = 0; i < n; i++){
    //     if (i < far && a[i] != p[far]){
    //         debug(p, i, 1,far);
    //         cout << "NO" << endl;
    //         return;
    //     }
    //     far = max(far, mp[a[i]]);
    // }
    // far = n - 1;
    // for (int i = n-1; i >= 0; i-- ){
    //     if (i > far && a[i] != p[far]){
    //         debug(p,i,2);
    //         cout << "NO" << endl;
    //         return;
    //     }
    //     far = min(far,mp[a[i]]);
    // }
    // cout << "YES" << endl;



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
