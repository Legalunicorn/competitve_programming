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


// 1 2 3 4 5 
// 3 2 1 4 5 
// 3 4 1 2 5 
// 3 4 5 2 1 
//
// 1 2 3 4 5 6 7 8 
// 4 3 2 1 5 6 7 8 
// 4 5 1 2 3 6 7 8 
// 4 5 6 3 2 1 7 8 
// 4 5 6 7 1 2 3 8 
// 4 5 6 7 8 3 2 1 
//
//
// 1 2 3 4 5 
// 4 3 2 1 5 
// 4 5 1 2 3
//
//
// 1 2 3 4 5 6 7 8 9 
// 5 4 3 2 1 6 7 8 9 
// 5 6 1 2 3 4 7 8 9 
// 5 6 7 4 3 2 1 8 9 
// 5 6 7 8 1 2 3 4 9 
// 5 6 7 8 9 4 3 2 1 


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string mn = s;
    int kres = 1;
    // n - k + 1  forward
    for (int k=2;k<=n;k++){
        int l = n - k + 1;
        debug(n,k,l);
        string left  = s.substr(n - l);
        string right = s.substr(0,n-l);
        int flips =  n - k + 1;
        if (flips%2==1) reverse(all(right));
        string ck = left + right;
        if (ck<mn){
            mn = ck;
            kres = k;
        }
        debug(s.substr(n-l), s.substr(0,n-l));
        debug(ck);

        // if (ck < mn){
        //     mn = ck;
        //     kres = k;
        // }
    }
    cout << mn << endl;
    cout << kres << endl;
    debug("   ");
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
