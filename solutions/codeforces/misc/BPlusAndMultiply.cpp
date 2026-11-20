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

// im so bad at math 
// i dont how why i didnt see it 
// the observation is that no matter how u mix a and b 
// 
// u can see the thing express as a^k + D b, fomr some k and D 
//
//

void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    if (b==1){
        cout <<"Yes" << endl;
        return;
    }
    ll mod = n % b;

    vl pows;
    ll curr = 1;

    for (int i = 0; i < 100; i++){
        if (curr > n) break;
        if (curr % b == mod){
            cout << "Yes" << endl;
            return;
        }
        curr *= a;
    }
    cout << "No" << endl;

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
