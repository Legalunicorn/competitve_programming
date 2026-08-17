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
// - we can remove everything of VAL 
// - otherwise from the remaining elements the MIN will prevail 
// - else c = [0,n] 
//
// might have some amortized analysis but nevermind 
// i dont think this is binary searchable ecause its not monotonic or concave 
// let x = chosen c 
// all elements with freq < x are deleted 
// all elements with freq > x are trimmed 
// -> if we can do this in <= log n, we can solve the problem 
//  map<val, freq>  
//  say we sorted by frequencies 
//  the sum = n 
//  1 2 2 3 3 5 6 
//  then we only care for unique values ie (a[i] != a[i-1]) 
//  then what we do is 
//  - delete all lesser elements: this can be sum a[0] to a[i-1] 
//  - compute sum a[i] to a[n] and minus a[i] * length 


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> mp;
    for (auto& z:a) mp[z]++;
    vi freq;
    for (auto& [v,c]: mp) freq.pb(c);
    sort(all(freq));
    int m = freq.size();
    vi pf = freq;
    int res = n; //delete all
    for (int i  = 1; i < m; i++) pf[i] += pf[i-1];
    debug(freq);
    debug(pf);
    for (int i = 0; i < m; i++){
        if (i == 0 || freq[i] != freq[i-1]){
            int left = (i > 0 ? pf[i-1]: 0);
            int right = pf[m-1] - (i > 0 ? pf[i-1] : 0);
            int dist = m - i;
            debug(left,right,dist);
            right -= dist * freq[i];
            debug(right);
            int evl = left + right;
            res = min(res, evl);
        }
    }
    cout << res << endl;
    cerr << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("pf","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
