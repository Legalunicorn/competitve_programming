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

//#define endl '\n' 
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

// NOTE:
// distance betwee npoints 
// distance is not necessarily integetrs 
// we have 2n queries 
// COUNT -> number of pairs where distance is aty most one 
//
// this is just binary search isnt it ? 
// for each i, we want to qwuery the max j that distaince is within boundfs
// wait 
// N log N >= 2N 
// this is a two pointer question 
// we ahve L and R poointer 
// both initieralize to 
// 0, 1 respectively 
// we just expand R until it makes snese


void solve(){
    ll n;
    cin >> n;
    ll res =0;
    ll r = 2;

    auto check = [&](int i, int j) -> bool{
        string resp;
        cout << "? " << i << " " << j << endl;;
        cin >> resp;
        debug(resp);
        return resp=="Yes";
    };

    for (ll l = 1 ; l < n; l++){
        while(r<=l) r++;
        while(r <= n && check(l, r)){
            r++;
        }
        if (r > l) res += (r-l-1);
        debug(l,r);
    }
    cout << "! " << res << endl;



    // points [1,N], we can skip N
    // for (int s = 1; s < n; s++ ){
    //     int l = s+1, r = n;
    //     int ans = 0;
    //     while(l<=r){
    //         int m = (l+r)/2;
    //         // query 
    //         cout << "? " << s << " " << m;
    //         string resp;
    //         cin >> resp;
    //         if (resp == "")
    //
    //     }
    // }


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
