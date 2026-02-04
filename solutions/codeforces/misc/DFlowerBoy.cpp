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



// I sense a greedy solution among this 
// we want the most options for the remaining m2 floewr lefts to pick 
// its possible this is dp 
// without k, we just find the first flowr for the currnet index that fits 
// then from there 
// k corresponds to one of the m flowers (unless its not needed)
// 1. maybe we check if its not needed, easy in O(n) and check if our pointer in m reaches the end 
// otherwise we need a flower to be k 
// when a flower is selected as "k", we only care about left and rght in m 
// 1. alternatively its deleting b[i] 
//
//
// there is only one person allowed to be impossible i thoight 
//
// try out the prefix suffic idea though its not very clear now 
void solve(){
    int n,m;
    cin >> n >> m;
    vl a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    int id = 0;
    vl prefix(m,-1), suffix(m,-1);
    for (int i = 0; i < n; i++){
        if (id >= m ) continue;
        if (a[i] >= b[id]){
            prefix[id] = i;
            id++;
        }
    }
    id = m -1;
    for (int i = n-1; i>=0; i--){
        if (id<0) continue;
        if (a[i] >= b[id]){
            suffix[id] = i;
            id--;
        }
    }
    debug(prefix);
    debug(suffix);

    if (prefix[m-1]!=-1){
        cout << 0 << endl;
        return;
    }
    if (m == 1){
        cout << b[0] << endl;
        return;
    }
    ll res = INF;
    for (int i = 0; i<m;i++){
        if (i == 0 ){
            if (suffix[1] != -1) res = min(res, b[0]);
        } else if (i == m - 1){
            if (prefix[i-1] != -1) res = min(res,b[i]);
        } else{
            if (prefix[i-1] != -1 && suffix[i+1]!=-1 && prefix[i-1] < suffix[i+1]){
                res = min(res,b[i]);
            }
        }
    }
    if (res == INF) res = -1;
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
