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

// every subarray must be non zero 
// and the rest are in groups 
// [-1] 1 subarray 
// {1,1} -> 3 subarryas 
// 6 , 10 , 15, 21 ,28 ,
// until n, n * (n+1)/2;
// 

void solve(){
    int n,k;
    cin  >> n >> k;


    


    // vi a(n);
    // int val  = 1;
    // int diff = 2;
    // for (int i = n-1; i>=0; i--){
    //     a[i] = val;
    //     val += diff;
    //     diff++;
    // }
    // int pos = 0;
    //
    // vi res(n,-1000);
    // int i = 0; // i_> pointer res, pos -> a
    // while(i<n  ){
    //     if (k >= a[pos]){
    //         debug(k,a[pos],pos);
    //         int size = n - pos; 
    //         for (int l = 0; l < size; l++){
    //             res[i] = 1;
    //             i++;
    //         }
    //         i++;
    //         k -= a[pos];
    //
    //     } else{
    //         pos++;
    //     }
    // }
    // debug(res);
    // for (auto& r: res) cout <<r <<  " ";
    // cout << endl;
    debug(a);


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
