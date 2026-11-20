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

// differ in exaclty one position 
// s s d 
// s d s 
// d s s 
// 
// s s d 
// will we double count if there are repeated occurances? 
// 1. store a freq of all triplets (cannot be same in all 3 positions)
// store all 
// p1 -> p2 
// p2 -> p3 
// p1 -> p3 
//
// t


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    ll res = 0;
    map<array<int,3> , int> mp;
    map<pi, int> p12, p23, p13;
    for (int i=0; i+2<n; i++){
        mp[{a[i],a[i+1],a[i+2]}]++;
        p12[{a[i],a[i+1]}]++;
        p23[{a[i+1],a[i+2]}]++;
        p13[{a[i],a[i+2]}]++;
    }
    for (int i=0; i+2<n; i++){
        int c12 =  p12[{a[i],a[i+1]}];
        int c23 = p23[{a[i+1],a[i+2]}];
        int c13 = p13[{a[i],a[i+2]}];
        int dup = mp[{a[i],a[i+1],a[i+2]}];
        res += (c12 - dup);
        res += (c23 - dup);
        res += (c13 - dup);
    }
    cout << res/2 << endl;
    
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
