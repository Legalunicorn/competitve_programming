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
// I read 1 line of the editorial 
// and it helped me fine the entire solution 
// 
// i couldnt find the constraint but it was just 
// sum the odd and even (or alternate) segmets = n 
//
// i didnt realise i could group alternate segmenets 
//
// i know sum width = n 
// sum height = n 
//
// but once u realise its alternate, and each is at least one 
// it becomes really easy

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    pl even = {a[0], a[0]};
    pl odd = {a[1], a[1]};
    ll res = n * a[0] + n * a[1];
    for (int i = 2; i < n; i++ ){
        if (i % 2 == 0){
            even.F = min(even.F, a[i]);
            even.S += a[i];
        } else {
            odd.F = min(odd.F, a[i]);
            odd.S += a[i];
        }
        ll oddsize = (i + 1) /2, evensize = (i + 2) / 2;
        ll oddcost = odd.S - odd.F + odd.F * (n - (oddsize-1));
        ll evencost = even.S - even.F + even.F * (n - (evensize-1));
        debug(even, odd);
        debug(i, oddsize, oddcost, evensize, evencost);
        res = min(res, oddcost + evencost);
    }
    cout << res << endl;
    debug(' ');
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
