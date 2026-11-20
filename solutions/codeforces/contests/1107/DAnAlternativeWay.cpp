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

// the distance from a[i]
// i - l is oddd? 
// + - + - + - + - 
// 
//
// smallest is either 
// + -
// +
//
// can we greedt from the back? 
//


// perfet square? 
// all powers are divisible by 2 
// so we need to factor every node 
// what is the produce of 3 paths? 
// im not sure but from drawingin it looks like 
// every node appers exaclty twice
// so this is not really a tree problem 
// merging sets? 
// we can try iterate for each node try to find 
// wait we need distrinct triplets unordered
// we can root arbitararily then consider all pairs from childrens
// dfs 1 -> children return map upwards then we do small to large merging 
// i think i can dp this 
// for each node i want to pick some children
//  
//
//  dont hook on ideas too long. 
//
//
//  1) 
//  for each node consider childern paths 
//  note the wait a fucking second isnt all paths perfect squares 
//  we just need to return how many chilren 

void solve(){
    int n;
    cin >> n;
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z: b) cin >> z;
    for (int i = n-1; i >= 1; i--){
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]){
            ll d = a[i] -  b[i];
            a[i-1] += d;
            a[i] = b[i];
        } else{
            a[i] = b[i];
        }
    }
    if (a[0] > b[0]){
        cout << "NO" << endl;
    } else cout << "YES" << endl;
    debug(a);
    debug(b);


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
