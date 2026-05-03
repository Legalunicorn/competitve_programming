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

// for each k we need to print the answer? 
// how is that possible 
// k = 1 is just pairs 
// k = 2 i
// we somehow 

void solve(){
    int n;
    cin >> n;
    n *=2;
    vl a(n), p;
    for(auto& z:a) cin >> z;
    ll s1 = 0, s2 = 0;
    deque<ll> one, two;
    for (int i = 1; i < n; i++){
        ll v = a[i] - a[i-1];
        p.pb(v);
        if (i % 2 == 1) {
            s1 += v;
            one.pb(v);
        } else {
            s2 += v;
            two.pb(v);
        }
    }
    for (int i = 1; i < p.size(); i++) p[i] += p[i-1];

    // how to get next answer 
    // minus always the previously used sum 
    // reduce the sum by its first and last value 
    debug(p);
    debug(one);
    debug(two);
    debug(s1,s2);

    ll res = s1;
    int st = 0, ed = p.size()-1;
    for (int i = 0; i < n/2; i++){
        if (i == 0){
            cout << res << " ";
            continue;
        }
        res -= s1;
        s1 -= (one.front() + one.back()); // 
        one.pop_front();
        one.pop_back();
        ll pf = p[ed] - (st > 0 ? p[st-1]:0);
        debug(pf,res);
        st++, ed--;
        res += pf;
        res += s2;
        cout << res << " ";
        swap(one,two);
        swap(s1,s2);
    }
    cerr << endl;
    cout << endl;



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
