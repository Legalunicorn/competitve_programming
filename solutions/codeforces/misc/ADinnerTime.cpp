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


int tc = 0;


void solve(){
    tc ++;
    debug(tc);
    int n,m, p ,q ;
    cin >> n >> m >> p >> q;

    int r = p -1;
    int l = n - p ;
    debug(l,r);
    if (r > l){
        
        if (m % n != 0){
            cout << "NO" << endl;
            return;
        }
        int x = m / n;
        debug(x);
        if (x * p != q){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
    } else{
        int k = n - (r-l+1);
        if (m % k !=0){
            cout << "NO" << endl;
            return;
        }
        int x = m / k;
        debug(x);
        if (x * p != q){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
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
