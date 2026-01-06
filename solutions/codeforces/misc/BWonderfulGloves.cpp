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

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    ll res = 0;
    vi mins, maxs;
    for (int i=0;i<n;i++){
        int x = a[i], y = b[i];
        if (x<y) swap(x,y);
        res += x;
        mins.pb(y);
        maxs.pb(x);
    }
    debug(a);
    debug(b);
    debug(mins);
    debug(maxs);
    cerr << endl;
    sort(mins.rbegin(),mins.rend());
    for (int i=0;i+1<k;i++){
        res += mins[i];
    }
    res++;
    cout << res << endl;

    // vi c(2*n);
    // for (int i=0;i<n;i++){
    //     c[i] = a[i];
    //     c[i+n] = b[i];
    // }
    // sort(c.rbegin(),c.rend)
    // vpi x(n);
    // for (int i=0;i<n;i++){
    //     x[i] = {a[i],b[i]};
    // }
    // sort(all(x), [&](const auto& p, const auto& q){
    //     // return p.F + p.S > q.F + q.S;
    //     return max(p.F,p.S) > max(q.F,q.S);
    // });
    //
    // debug(x);
    // vi rem;
    // ll res = 0;
    // for (int i=0;i<n;i++){
    //     if (i<k) {
    //         res += (x[i].F + x[i].S);
    //     } else{
    //         res += max(x[i].F,x[i].S);
    //     }
    // }
    // cout << res << endl;




    //
    // sort(a.rbegin(),a.rend());
    // sort(b.rbegin(),b.rend());
    // // sort(all(a));
    // // sort(all(b));
    // // see who has higher sum 
    // ll s1 = 0, s2 = 0;
    // for (int i=0;i<n;i++){
    //     s1 += a[i];
    //     s2 += b[i];
    // }
    // debug(s1,s2);
    // debug(a);
    // debug(b);
    // ll opt1 = s1;
    // ll p2 = 0;
    // for (int i=0;i<k;i++) p2+=b[i];
    // opt1 += max(s2-p2, p2);
    //
    //
    //
    // ll opt2 = s2;
    // ll p1 = 0;
    // for (int i=0;i<k;i++) p1 += a[i];
    // opt2 += max(s1-p1, p1);
    //
    // cerr << endl;
    // cout << max(opt1,opt2) << endl;
    //
    // ll res = max(opt1,opt2);
    // cerr << endl;
    // cout << res << endl;


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
