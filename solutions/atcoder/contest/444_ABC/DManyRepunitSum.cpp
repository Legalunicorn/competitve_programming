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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto& z:a) cin >> z;
    sort(all(a));
    debug(a);
    int cf = 0; // carry forward 
    int idx = 0; // array pointer 
    int lim = MAX(a);
    lim += 10;
    string res;
    for (int d = 1; d <= 400000; d++){
        while(idx < n && a[idx] <  d){
            idx++;
        }
        
        int cont = n - idx + cf;
        if (cont == 0) break;
        else if (cont < 10) {
            res += (char)(cont+'0');
            cf = 0;
        } else {
            int rem = cont % 10;
            res += (char)(rem+'0');
            cf = cont/10;
        }
        debug(d,idx, cont);
        debug(res);
    }
    reverse(all(res));
    cout << res << endl;


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
