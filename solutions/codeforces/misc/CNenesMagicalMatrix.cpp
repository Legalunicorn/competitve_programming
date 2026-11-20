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
    int n;
    cin >> n;
    ll sum = 0;
    for (int i=1;i<=n;i++){
        sum += i*((i*2)-1);
    }
    cout << sum << " " << 2*n-1 <<endl;
    int d = 1;
    int l = n - 1;
    int is_d = true;
    for (int i=0;i<2*n-1;i++){
        if (is_d){
            cout << 2 << " ";
            cout << d << " ";
            for (int i = 1;i<=n;i++) cout << i << " ";
            cout << endl;
            d++;
        } else{
            cout << 1 << " ";
            cout << l << " ";
            for (int i=n;i>=1;i--) cout << i << " ";
            cout << endl;
            l--;
        }
        is_d = !is_d;
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
