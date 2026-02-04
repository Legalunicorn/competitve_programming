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


/*
 
    MEX (1, i) != 
    MEX (i+1, n )

    determine if its possible? 
    how do we make the mex different ? 

    sort ? 



*/


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    // brute force mex from left and right 
    for (int i = 0; i + 1 < n ; i++){
        // 0 to i ...  (i + 1 to  n)
        set<int> left, right;
        int lm = 0, rm = 0;
        for (int j = 0; j <= i ; j++ ) left.insert(a[j]);
        for (int j = i+1; j< n ; j++) right.insert(a[j]);
        for (int v = 0;v < 105; v++){
            if (!left.count(v)){
                lm = v;
                break;
            }
        }
        for (int v = 0;v < 105; v++){
            if (!right.count(v)){
                rm = v;
                break;
            }
        }
        if (lm == rm){
            cout << "NO" << endl;
            return;
        }
        debug(i, lm, rm);


    }

    cout << "YES" << endl;


    // 
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
