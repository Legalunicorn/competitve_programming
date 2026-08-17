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
    vi a(n);
    for (auto& z:a) cin >> z;
    for (int i = n/2 - 1; i>=0;i--){
        int j = n - i - 1;
        if (a[i] == a[j]) continue;
        if (a[i]== a[i+1] || a[j]==a[j-1])  swap(a[i],a[j]);
    }
    int res =0; 
    for( int i=0;i<n-1;i++){
        if (a[i]==a[i+1]) res++;
    }
    debug(a);
    cout << res << endl;

    // wtf is this ? 
    //



    // int m = n/2;
    // for (int i=n/2-1;i>=0;i--){
    // // for (int i= 0; i<n/2;i++){
    //     int j = n - i -1; 
    //     // debug(i,j);
    //     if (a[i] == a[j]) continue;
    //     // check if total decresed? 
    //     int stay = 0, change = 0;
    //     if (i==0){
    //         if (a[i] == a[i+1]) stay++;
    //         if (a[j] == a[j-1]) stay++;
    //         swap(a[i],a[j]);
    //         if (a[j]== a[j-1]) change++;
    //         if (a[i] == a[i+1]) change++;
    //         if (change > stay) swap(a[i],a[j]);
    //     } else{
    //         if (a[i]==a[i+1]) stay++;
    //         if (a[i]==a[i-1]) stay++;
    //         if (a[j]==a[j+1]) stay++;
    //         if (a[j]==a[j-1]) stay++;
    //         swap(a[i],a[j]);
    //         if (a[i]==a[i+1]) change++;
    //         if (a[i]==a[i-1]) change++;
    //         if (a[j]==a[j+1]) change++;
    //         if (a[j]==a[j-1]) change++;
    //         if (change > stay) swap(a[i],a[j]);
    //
    //
    //     }
    // }
    // debug(a);
    // int res = 0;
    // for (int i=0;i<n-1;i++){
    //     if (a[i]==a[i+1]) res++;
    // }
    // cout << res << endl;
    // int len = 0;
    // int curr = -1;
    // for (int i=0;i<n;i++){
    //     if (a[i] == curr){
    //         len ++;
    //     } else{
    //         if (len >=2) res++;
    //         len = 1;
    //     }
    //     curr = a[i];
    // }
    // if (len>=2) res++;
    // cout << res << endl;

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
