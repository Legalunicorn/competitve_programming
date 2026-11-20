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
    vvi g(n, vi(n));
    vvi f(n, vi(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char x; cin >> x;
            g[i][j] = x-'A'-14;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char x; cin >> x;
            f[i][j] = x-'A'-14;
        }
    }
    debug(g);
    debug(f);
    cerr << "========" << endl;


    auto check = [&]() -> bool{
        return f==g;
        // bool valid = true;
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<n;j++){
        //         if (g[i][j]!=f[i][j]){
        //             return false;
        //         }
        //     }
        // }
        // return true;
    };

    auto fx = [&]()->void{
        for (int i=0;i<n;i++){
            for (int j=0;j<n/2;j++){
                swap(f[i][j], f[i][n-j-1]);
            }
        }
    };

    auto fy = [&]() -> void{
        for (int i=0;i<n;i++){
            for (int j=0;j<n/2;j++){
                swap(f[i][j], f[n-i-1][j]);
            }
        }
    };

    auto rotate = [&]() -> void{
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                swap(f[i][j],f[j][i]);
            }
        }
        fx();
 
    };
    for (int i=0;i<5;i++){
        int id = 0;
        for (int j = 0; j<4;j++){
            id = (id+1)%2;
            if (check()){
                cout << "Yes" << endl;
                return;
            }
            if (id==0) fx();
            else fy();
        }
        rotate();
    }
    cout << "No" << endl;
    return;

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
