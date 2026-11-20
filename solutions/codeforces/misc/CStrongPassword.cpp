#include <bits/stdc++.h>
#include <iomanip>
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
    string s; // database string 
    cin >> s;
    int m; 
    cin >> m; 
    string l,r; 
    cin >> l >> r;
    int n = s.size();
    int INV = 10000000;

    vvi next(n + 1, vi(11, INV));
    for (int  d = 0; d < 11; d++){
        for (int i = n-1; i >=0; i --){
            if (s[i]-'0' == d) next[i][d] = i;
            next[i][d] = min(next[i][d], next[i+1][d]);

        }
    }
    debug(next);
    int pos = 0; 
    for (int i = 0; i < m; i ++ ){
        int left = l[i]-'0';
        int right = r[i] - '0';
        // find the furthest 
        int far = pos-1;
        for (int j = left ; j <= right ; j++){
            if (next[pos][j] == INV){
                cout << "YES" << endl;
                return;
            } else{
                far = max(far, next[pos][j]);
            }
        }
        pos = far+1;
    }
    cout << "NO" << endl;
    return;
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
