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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    debug(a);
    // pos k, k+1
    if (k == n){
        cout << 1000000000<< endl;
        return;
    } else if (k == 0){
        cout << (a[0]==1? -1:1) << endl;

    } else{
        cout << (a[k]==a[k-1]? -1: a[k-1]) << endl;
    }
  

    // int l = 0, r = n -1;
    // while(l<=r){
    //     int m = (l+r)/2;
    //     if ()
    // }
    // // find x, which is k pos 
    // for (int i = 0; i < n ; i++){
    //     if (i>0 && a[i]==a[i-1]) continue;
    //     if ()
    // }
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
