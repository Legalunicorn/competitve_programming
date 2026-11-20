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
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;

    //NOTE: dont ever forget: a ^ a ^ a = a 
    //this is veryuseful here because it means we can merge 
    //any 3 segments into 1 
    //this means there are either 2 or 3 segments if its possible 


    vl b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) b[i] = a[i] ^ b[i-1];


    // two segments
    for (int i = 0; i + 1 < n; i++){
        ll x = b[n-1] ^ b[i];
        ll y = b[i];
        if (x == y){
            cout << "YES" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j + 1< n; j++){
            ll x = b[i];
            ll y = b[j] ^ b[i];
            ll z = b[n-1] ^ b[j];
            if (x == y && y == z){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;




    // i dont think this workse we need to try dp maybe 
    // we know the first segment has a length from 1 to N 
    // why cant we 


    // for (int i = 0; i < n -1; i++){
    //     ll x = 0;
    //     for (int j = 0; j <= i; j++) x ^= a[j];
    //     debug(i,x);
    //     // x is our reference
    //     ll cur = 0;
    //     for (int j = i+1; j < n; j++){
    //         cur ^= a[j];
    //         debug(j,cur);
    //         if (cur == x) {
    //             if (j == n-1){
    //                 cout << "YES" << endl;
    //                 return;
    //             } else {
    //                 if (a[j+1] != 0) cur = 0;
    //             }
    //         }
    //     }
    // }
    // cout << "NO" << endl;
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
