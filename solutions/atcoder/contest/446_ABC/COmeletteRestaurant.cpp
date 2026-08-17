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

// NOTE: eggs in stock for more than D days thrown away 
// egged used in order purchased so earlier eggs get used first 
// N eggs 
// N buckets  
// there are always enough for noon 
//
// [0 ,0, 0,0]
//
// we only care about day N (last day)
// how many eggs remain. 
// why cant i just check for the stock of the last D days from N? 
//
//idk but lets just try simulate 
//

void solve(){
    int n,d;
    cin >> n >> d;
    vi a(n), b(n), stock(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    int j = 0;

    int cnt = 0;

    for (int i = 0; i < n; i++){
        cnt += a[i];
        int debt = b[i];
        stock[i] = a[i];
        while(debt > 0 && j < i) {
            int mn = min(debt, stock[j]);
            debt -= mn;
            stock[j] -= mn;
            if (stock[j]==0) j++;
        }
        if (debt > 0){
            stock[i] -= debt;
        }
        debug("bef", i,j,stock);
        while(j + d <= i) {
            stock[j] = 0;
            j++;
        }
        debug(i,j,stock);
    }
    ll res = 0;
    for (int i = n - d - 1; i < n; i++) res += stock[i];
    cout << res << endl;
    debug(stock);

 
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
