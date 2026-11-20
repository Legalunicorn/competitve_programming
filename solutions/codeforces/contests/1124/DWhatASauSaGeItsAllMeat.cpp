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
// divisible by 3 ?
// 0 = 0000
// 3 = 0011
// 6 = 1100
// 9 = 1001
// 12= 1100
// 15= 1111
//
// 0 is divisible by 3, so that is cool
// can we try to spam set 0? 
// we can only xor 
//
//
//
// (i, i+1) -> XOR(3.k) or one of those numbers 
// is there binary rule for divisalbeb y 3? 
// 16 is oddly specifc, 2 ^4 
//
// we know 16 = 10000
// we know that the MSB is bounded to 5
//
// i have feeling the (i, i+1) thing is distraction, like maybe we can operate backwards, then we can set n-1 .. 1, but not 0
//

void test(){
    set<int> f;
    vi v= {0,3,6,9,12,15};
    for (int z = 0; z < 9; z++){
        set<int> st;
        for (int i = 0; i < 5;i++){
            for (int j = i+1; j < 5; j++) st.insert(v[i]^v[j]);
        }
        v.clear();
        for (auto& z: st) v.pb(z);
        debug(st);
        f = st;
    }
    for (int t = 0; t <= 16; t++){
        bool yes = 0;
        for (auto& z:f) if ((z^t) % 3 ==0) yes = 1;
        debug(t, yes);
    }

}


void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    for (auto& z:a) cin >> z;
    set<int> magic = {0,3,5,6,9,10,12,15};
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (magic.count(a[i]))  cnt++;
    }
    cout << cnt << " ";
    while(q--){
        int p,x;
        cin >> p >> x;
        p--;
        if (magic.count(a[p])) cnt--;
        if (magic.count(x)) cnt++;
        a[p] = x;
        cout << cnt << " ";
    }
    cout << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
