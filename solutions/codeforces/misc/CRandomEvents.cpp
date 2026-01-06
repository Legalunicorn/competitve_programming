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

    we want to find the first shitty position from the right of the array 
    the outcome of any experiment less than or equal to pos is useless
    because even if the experiment sorts, the array still sucks 

    [1...r1] 

    OHHHH 

    ri >= R 
    sorts [1... ri]
    if we sort this 
    it GUARANTEES [1..R} is sorted, and hence [1,N] is sorted 

    as long as ONE works, all works 
    we count the case where ALL Fails 

*/


void solve(){
    // this seems more like a math problem 
    int n,m;
    cin >> n >> m;
    vi a(n);
    for (auto& z:a) cin >> z;
    int cnt = 0;
    for (int i = n-1; i>=0;i--){
        if (a[i] == i+1) cnt++;
        else break;
    }

    ld ans = 1.0;
    if (cnt == n) ans = 0.0;
    int last = n - cnt -1 ;

    while(m--){
        int r;
        ld p ;
        cin >> r >> p;
        r--; 
        if (r  >= last){
            ans *= (1.0 - p);
        }
    }
    ans = 1.0 - ans;
    cout << to_string(ans) << endl;



    // i think this is DP?? 
    // or some kind of inverse math 
    
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
