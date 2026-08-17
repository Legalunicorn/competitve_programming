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
    int n,m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i=0;i<n;i++){
        string s; cin >> s;
        for (int j=0; j<m ;j++) a[i][j] = s[j]-'0';
    }

    int n2, m2;
    cin >> n2 >> m2;

    vvi b(n2, vi(m2));
    for (int i=0;i<n2;i++){
        string s; cin >> s;
        for (int j=0;j<m2;j++) b[i][j] = s[j] -'0';
    }


    // print the shift with max value 
    ll mx = 0;  
    int x_res = 0, y_res = 0;

    int mxn = max(n,n2);
    int mxm = max(m,m2);
    

    for (int x = -mxn ; x < mxn ; x++){
        for (int y =-mxm; y < mxm; y++){
            ll sum = 0;
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    if (i+x >= 0 && i+x < n2 && j+y < m2 && j+y >=0){
                        sum += (a[i][j]*b[i+x][j+y]);
                    }
                }
            }
            debug(x,y, sum);
            if (sum > mx){
                mx = sum;
                x_res = x;
                y_res = y;
            }
        }
    }
    cout << x_res << " " << y_res << endl;

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
