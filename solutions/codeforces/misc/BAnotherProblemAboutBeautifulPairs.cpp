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
// split by cases 
// ai > n   ignore 
// ai >= sqrt(n) 
//  -> iterate for sqrt(n) multiples   --> O(sqrt(n))
//  ai < sq(n) 
//  -> 
//
//  ai . aj = j - i 
//
//  j = AI. aj + I
//  aj = (j-I) / AI
//
// n = 100 
// ai = 20, 
// multiples 20, 40, 60, 80, 100 
// each multiple -> j  = 40 + i -> we can see if a[j] = 40/[ai] 
//
// if ai = 2 
// 2,4,6,8,10,12,14,16,18,20,22,... 
//
//
// s,s   -> small will check right for at most b times 
// s,l   l, s   -> l will check both direction

void solve(){
    ll n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll res = 0;
    // this problem is very nasty for 1600 
    // sqrt decomposition case
    ll b = (ll) ceil(sqrt(n*1.0));
    debug(n,b);
    for (int i = 0; i < n; i++){
        if (a[i] <= b){ // small case, 
            for (int m = 1; m <= b; m++){
                ll j = a[i]*m + i;
                if (j < n && a[j] <= b && (a[j]*a[i]==j-i)) res++;
            }
        } else {
            for (int m = 1; m <= b; m++){
                ll j = i - a[i]*m;
                if (j >= 0 && (a[j]*a[i]) == i-j) res++;
                j = a[i]*m + i;
                if (j < n && ((a[j]*a[i]) == j-i)) res++;
            }
        }
        debug(i ,res);
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
    while(T--) solve();
    return 0;
}
