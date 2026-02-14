#include <bits/stdc++.h>
#include <numeric>
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

// the third person will always join in no matter who you choose 
// the new person will be second, means they are on the subtract list 
// i tink this can be done greedily


// NOTE: I read the editorial for this 
// I tried a greedy method but it didnt work 
// . Lesson: if you want to use greedy you must be able to 
//  proove it. cannot go on "intuition"
//
//  The answer was just a simple observation 
//  -> if we fix the unchosen child, everyone 
//  after must be "minus" i didnt see this clearly

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    

    ll s = 0;
    vl sf(n);
    for (int i = n - 1; i >=0; i--){
        s -= a[i];
        sf[i] = s;
    }
    debug(sf);

    ll res = -INF;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        // i -> unchosen
        if (i == 0) res = max(res, sf[i+1]);
        else {
            ll evl = a[0] + sum; 
            if (i+1<n) evl += sf[i+1];
            res = max(res, evl);
            sum += abs(a[i]);
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
