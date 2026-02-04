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
    int n,m;
    cin >> n >> m;
    ll h;
    cin >> h;
    vl a(n);
    for (auto& z:a) cin >> z; // this is the original 
    vl w  = a;
    map<int,int> delta;

    for (int i =0; i<m;i++){
        ll idx, add;
        cin >> idx >> add;
        idx--;
        if (a[idx] + delta[idx] + add > h ){
            delta.clear();
        } else{
            delta[idx] +=add;
        }
    }
    for (int i =0;i < n; i++){
        cout << a[i] + delta[i] << " ";
    }
    cout << endl;

    // for (int i =0; i <m ;i++){
    //     ll idx, add;
    //     cin >> idx >> add;
    //     idx--;
    //
    //     if (w[idx] + add > h){
    //         swap(w,a);
    //     } else{
    //         w[idx] += add;
    //     }
    // }
    // for (auto& z:w) cout << z << " "; 
    // cout << endl;


};

// n is large we cant reset manually,
// whenever an element create than h, everyone resets 
// if we know the last reset 
// we can start from there 
//
// lets think brute force first, 
// for each operatoin
// we add, then what do we do if it overflows? 
// maybe we just swap the current array with the original? 
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
