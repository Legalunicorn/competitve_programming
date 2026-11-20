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


// some dumb xor properties 
// b ^ b = 0 
// [1,n] = ??..
// maybe this is some strange construction, 
// we just delta the bit 
// 0 1 0 0 (4)
// 0 1 0 1  (5) 
// 0 0 0 1 (1) 





int tc = 0;
void solve(){
    tc ++;
    int n,l,r;
    cin >> n >> l >> r;
    l--; 
    r--;

    vi a(n,0);
    a[0] = 1;
    a[1] = 9;
    for (int i=2;i<n;i++){
        int x = a[i-2];
        int y = a[i-1];
        int no = x^y;
        a[i] = no-1;
    }
    debug(a);



    // int cumxor = 1;
    // vi a(n,0);
    // for (int i=0;i<n;i++){
    //     a[i] = (cumxor+1) % 67;
    //     cumxor ^= a[i];
    // }
    // // for (int i=0;i<n;i++) a[i] = 2*(i+1);
    int cumxor = 0;
    for (int i= l+1; i<=r; i++){
        cumxor ^= a[i];
    }
    a[l] = cumxor;
    for (auto& z:a) cout << z << " ";
    cout << endl;
    //
    //
    // for (int i=0;i<n;i++){
    //     int cxo = 0;
    //     for (int j=i;j<n;j++){
    //         cxo ^= a[j];
    //         if (!(i==l && j==r) && cxo==0){
    //             debug(tc);
    //             debug(i,j);
    //
    //         }
    //     }
    // }
    // cerr << " =========" << endl;
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
