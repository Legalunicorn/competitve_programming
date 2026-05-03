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
// If not im not crazy 
// this is just a xor prefix sum problem 
// the 1 L R 
// we just need to xor both some by said number it doesnt exactually ma
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    string s; cin >> s;
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') one ^= a[i];
        else zero ^= a[i];
    }
    for (int i = 1; i < n; i++) a[i] ^= a[i-1];

    int q; cin >> q;
    while(q--) {
        int id; cin >> id;
        if (id == 1){
            int l,r; cin >> l >> r;
            l--, r--;
            int xs = a[r] ^ (l > 0 ? a[l-1]: 0);
            one ^= xs;
            zero ^= xs;
        } else {
            int x; cin >> x;
            if (x == 0) cout << zero << endl;
            else cout << one << endl;
        }
    }


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
