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


// count the number of groups 
// 1 _> repreent inumber as bits 
// 2 -> we know that bit[i] same = differne group 
// so if x numbers have a[i] = 1, then what> 
//
//
// wait a fucking fuck... 
// it seems like the max size of a group is 2! 
// a number AND its inverse 
// so for each number 
// 1. 

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for(auto& z: a) cin >> z;
    int res = 0;
    map<ll,int> mp;
    for (auto& x: a){
        ll y = 0;
        for (int i =0; i < 31; i ++){
            if ((x >> i & 1)==0) y = y | (1 << i);
        }
        debug(x,y);
        if (mp[y]>0){
            mp[y]--;
        } else{
            res++;
            mp[x]++;
        }
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
