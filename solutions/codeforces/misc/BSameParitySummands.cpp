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
    int n, k;
    cin >> n >> k;
    // n is odd 
    // k must be odd 
    //
    // n is even 
    // k can be either
    if (k > n){
        cout << "NO" << endl;
        return;
    }
    if (n%2==1){
        if (k%2==0){
            cout << "NO" << endl;
            return;
        }
        // k is odd and k is out 
        cout << "YES" << endl;
        for (int i = 0; i +1 < k; i++) cout << 1 << " ";
        cout << n - (k-1) << endl;
        return;
    } else{
        if ((n - (k-1)) %2==1){
            cout << "YES" << endl;
           for (int i = 0; i +1 < k; i++) cout << 1 << " ";
           cout << n - (k-1) << endl;
        } else {
            int x = n - 2 * (k-1);
            if (x>0 && x%2==0){
                cout << "YES" << endl;
                for (int i =0 ; i + 1 < k; i++) cout << 2 << " ";
                cout << x << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }



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
