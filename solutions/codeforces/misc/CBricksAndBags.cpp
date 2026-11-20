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

int tc = 0;
void solve(){
    tc++;
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    debug(a);
    ll l = a[0], h = a[n-1];
    ll diff = h - l;
    set<ll> st(all(a));
    if (st.size()==1){
        cout << diff << endl;
        return;
    } 
    if (st.size()==2){
        cout << diff*2 << endl;
        return;
    }
    vl b;
    ll  res = 0;
    for (auto& x: st) b.pb(x);
    for (int i=0;i<b.size()-2;i++){
        res = max(res, b.back() - 2*b[i]+b[i+1]);
    }
    for (int j = b.size()-2; j>0;j--){
        res = max(res, 2*b[j+1]-b[j] - b.front());
    }
    cout << res << endl;

    // // l -> bag 1 
    // debug(diff);
    // ll ans1 = INF, ans2 = INF;
    // // L , H , ( ? )
    // for (int i =1; i+1<n;i++){
    //     if (a[i] == h) break;
    //     ans1 = min(ans1, diff + h - a[i]);
    // }
    // for (int i=1;i+1<n;i++){
    //     if (a[i] == l) continue;
    //     ans2 = min(ans2, diff + a[i] - l);
    // }
    //
    // debug(ans1,ans2);
    // ll res = max(ans1,ans2);
    // // if (res == 924858246){
    // //     string db = to_string(ans1)+":"+to_string(ans2);
    // //     cout << db << endl;
    // //     return;
    // // }
    //
    // cout << max(ans1,ans2) << endl;
};

// oh.. MAX score with est possitble dsitrubition 
// 1. how do we distribute? 
//

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
