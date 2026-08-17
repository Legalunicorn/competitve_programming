#include <bits/stdc++.h>
#include <pthread.h>
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
    int n,t,p;
    cin >> n >> t >> p;
    vi a(n);
    for(auto& z:a) cin >> z;
    for (int d = 0; d <= 150; d++){
        int cnt = 0;
        for (auto& x: a){
            if (x+d >= t) cnt++;
            if (cnt >= p){
                cout << d << endl;
                return;
            }
        }
        // the fucking wording 
        // we want T or more 
    }
    // number of days 
    // at leat T, become T for the firs time 
    // p <= 100
    // int res = 0;
    //
    // for (int d = 1; d < 150; d++){
    //     bool found = false;
    //     for (int i =0; i <n; i++){
    //         if (a[i] >= t && a[i] < p && a[i]+d >=p) found = true;
    //     }
    //     if (found) res++;
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
