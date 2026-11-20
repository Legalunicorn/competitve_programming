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

void solve(){
    int n,t;
    cin >> n >> t;
    vi a(n);
    for (auto& z:a)cin>>z;
    if (t==1){
        cout << 7;
    } else if (t==2){
        if (a[0] > a[1]) cout << "Bigger";
        else if (a[0] < a[1]) cout << "Smaller";
        else cout << "Equal";
    } else if (t== 3){
        vi z = {a[0], a[1],a[2]};
        sort(all(z));
        cout << z[1];
    } else if (t==4){
        ll s =0;
        for (auto& z:a) s +=z;
        cout << s ;
    } else if (t== 5){
        ll s =0;
        for (auto& z:a) if (z%2==0) s+=z;
        cout << s;
    } else if (t==6){
        for (auto&z:a) cout << (char)((z%26)+'a');
    } else if (t==7){
        int c = 0;
        c = a[0];
        set<int> seen;
        while(true){
            if (c < 0 || c >= n) {
                cout << "Out";
                return;
            } else if ( c == n-1){
                cout << "Done";
                return;
            }
            c = a[c];
            if (seen.count(c)){
                cout << "Cyclic";
                return;
            }
            seen.insert(c);
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
    // cin >> T; 
    while(T--) solve();
    return 0;
}
