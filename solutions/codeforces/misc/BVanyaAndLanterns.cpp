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
    int n,l;
    cin >> n >> l;
    vi a(n);
    for(auto& z:a) cin >> z;
    sort(all(a));

    ld mx = max(a[0], l - a[n-1]);
    for (int i = 1; i <n ;i++){
        mx = max(mx, (a[i]-a[i-1])/2.0);
    }
    cout << to_string(mx) << endl;



    // ld left = 0.0, right = (ld)(l+1);
    //
    // debug(a);
    // auto check = [&](ld x) -> bool{
    //     debug(x);
    //     if (a[0] > x) return false;
    //     if (l -a[n-1] > x) return false;
    //     for (int i = 1; i < n; i++){
    //         if ((a[i]-a[i-1]/2.0 > x)) return false;
    //     }
    //     return true;
    // };
    //
    //
    // ld res = right;
    // while(left <= right){
    //     ld mid = left = (right - left)/2;
    //     if (check(mid)){
    //         res = mid;
    //         right = mid - 0.001;
    //     } else
    //         left = mid + 0.001;
    // }
    // cout << to_string(res) << endl;
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
