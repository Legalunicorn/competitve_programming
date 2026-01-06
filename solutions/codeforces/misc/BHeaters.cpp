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
    int n,r;
    cin >> n >> r;
    vi a(n);
    for (auto& z:a) cin >> z;
    // check if impossible first 
    // this just looks like a greedy problem no ? 
    // or maybe its DP 
    // i dont understand just active the last heater 

    vvi dp(n, vi(n,-1));

    int count = 0;
    int last = -1; // last position untounched
    for (int i=0;i<n;i++){
        // find the further heater within R 
        if (i>last){
            debug(i, last);
            int found = -1;
            for (int d = 0; d < r; d++){
                if (a[i+d] == 1) found = i+d;
            }
            if (found==-1){
                cout << -1 << endl;
                return;
            }
            last = max(last, found + r - 1 );
            debug(found);
            debug(last);
            count ++;
        }
    }
    cout << count << endl;
};

/*
 
   there is a variant with greedy and binary search 
   but here the heater must be swtiched on to use it 
   i think the bs logic might still owrk? 
   we can try for all 

   the radius is already given 

   we just need to activate the heaters 

   what if we try for x amount of heaters 


   0 1 0 1 1 0 0 1  1 0 



*/



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
