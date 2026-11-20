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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    int l =0, r=  n-1;
    bool one = true;
    // alice cannot remove the smalelst 
    // bob cannot remove the largest
    ll x = a.front();
    ll y = a.back();
    if (n%2==0){
        // alice makes the final move 
        if (abs(max(x,y)) >= 10) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    } else{
        // bob maxes 
        if (abs(min(x,y)) >= 10) cout <<  "Alice" << endl;
        else cout << "Bob" << endl;
    }

    // while(l < r){
    //     if (one){
    //         l++;
    //     }
    // }
    // why not simulate? 
    // alice will always remove the MIN and will go as small as possible 
    // /
    // // alice starts
    // int d = n/2;
    // // int c1 =0, c2=0;
    // int l = 0, m = 0, r = 0;
    // for (auto& z:a){
    //     if (z <= -10) l++;
    //     else if (z >= 10) r++;
    //     else m++;
    // }
    // if (a[d] < )
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
