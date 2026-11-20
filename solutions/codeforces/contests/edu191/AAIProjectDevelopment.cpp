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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    // x -> person one 
    //  AI: z + 107 
    //  NO: y 
    // how many hours to compelte it 
    int one = x + y;
    int a = n / one;
    if (n % one !=0) a++;

    // if (z * x >= n){
    //     cout << a << endl;
    //     return;
    // }
    // nowe we need to find b 
    // x x x x , z , y y y y 
    // first z hours is only x 
    // int b = 0;
    // int m = n - (z * x);
    // if (m)
    int b=  0;
    b += z; // take z hours 
    int rem = n - (z * x);
    int speed = 10*y + x;
    debug(rem,speed);
    b += (rem/speed);
    if (rem % speed != 0) b++;
    int res = min(a,b);
    debug(a,b);
    cout << res << endl;
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
