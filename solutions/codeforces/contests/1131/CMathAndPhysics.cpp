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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE:
// 1 1 -> impossible 
// x 1 -> possible 
// values cannot decrease 
// values can disappear 
// 
// 1 1 1 1 1 2 
// IMPOSSIBLE CASE 
// -> n = 2, {1,1}
// -> all 1's '
// only impossible case is all 1s
// other than that we just split at the edge
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] ==1) cnt++;
    }
    if (cnt == n){
        cout << -1 << endl;
        return;
    }

    int mid = 0;
    ll sum = 0;
    for (auto& z: a) sum += z;
    for (int i = 1; i + 1 < n; i++){
        if (a[i] ==1) mid++;
    }
    if (mid == n-2){ // alls
        cout << sum - (n-1) << endl;
        return;
    }

    cout << sum - 1 << endl;

    
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
