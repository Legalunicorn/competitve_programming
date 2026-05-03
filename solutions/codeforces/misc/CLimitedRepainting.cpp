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


bool check(vi& a, string& s, int x,int k){
    bool active = false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] <= x) continue; // we dont have to start or stop;
        if (s[i] == 'B'){
            // we must convert it to BLUE from RED
            if (!active){
                if (k ==0) return false;
                k--;
                active = true;
            }
        } else {
            // we must not convert it 
            if (active){
                active = false;
            }
        }
    }
    debug(x, "pass");
    return true;
};


void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    for (auto& z:a) cin >> z;
    debug(s,a);
    int l = 0;
    int r = MAX(a);
    int res = r;
    while(l<=r){
        int m = l + (r-l)/2;
        if (check(a,s, m, k)) {
            res = m;
            r = m -1;
        } else l = m +1;
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
