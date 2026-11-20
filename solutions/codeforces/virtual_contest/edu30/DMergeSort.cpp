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

// NOTE:
// one way is to try to maximise the number of calls 
// then cut it down to fit k 
//
// k has to be odd 
// max k = n -1 
// NOTE: OBV#1:  K <= n-1;
//
// we cant split >= n times 
//
//
// if k == 1, the permutation is sorted 
// else we need to construct the flips some how 
// we can construct k by flipping with our own merge sort 
// something something amortized 
//


// i think this is a bfs 
// becuase if we dfs 
//

void solve(){
    int n,k;
    cin >> n >> k;
    vi res(n);
    for (int i = 0; i < n;i++) res[i] = i+1;

    if (k==1){
        for (auto&r:res)cout << r << " ";
        return;
    }
    int cnt = 1; // make this = k 

    auto go = [&](auto& go, int l, int r) -> void{
        if (l==r) return;
        if (cnt >= k) return;
        int m = (l+r)/2;
        int p = (r-l+1)%2;
        cnt +=2;
        if (p==0){
            swap(res[m],res[m+1]);
            go(go, l, m);
            go(go, m+1, r);
        } else{
            swap(res[m-1], res[m]);
            go(go, l, m-1);
            go(go, m, r);
        }
        // cnt+=2;
        // go(go,l,m-1);
        // go(go,m, r);
    };

    go(go, 0, n-1);
    if (cnt != k){
        cout << -1 << endl;
        return;
    }
    for (auto&r:res)cout<<r << " ";
    

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
