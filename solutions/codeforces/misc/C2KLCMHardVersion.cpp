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

// NOTE:
// we can have two values 
// 1,1,1,1,1 
// x,x,x,x,x 
// we can chose n/2-1 
void solve(){
    ll n,k;
    cin >> n >> k;
    if (n == k){
        for (int i = 0; i < n; i++){
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    ll rem = n - (k-1);
    if (rem <= n/2){
        for (int i = 0; i +1<k; i++) cout << 1 << " ";
        cout << rem << endl;
        return;
    }
    if (rem % 2 == 1){
        ll x = rem/2+1;
        for (int i = 0; i+2 < k; i++) cout << 1 << " ";
        cout << x << " " << x << endl;
        return;
    }
    // k >= 5, there is a distribution trick 
    // k = 3 and k = 4 ? .. 
    if (k==4){
        cout << 1 << " ";
        n--, k--;
    }
    if (k == 3){
        ll x = n/2;
        if (n%2==1){ // 
            cout << x << " " << x << " " << 1 << endl;
        } else{
            if (x%2==1) cout << x-1 << " " << x-1 << " " << 2 << endl;
            else {
                cout << x << " " << x/2 << " " << x/2 << endl;
                // if cout << x-2 << " " << x-2 << " " << 4 << endl;
            }
        }
        return;
    } 
    if (rem/2 % 2 == 0){
        ll t = rem/2;
        cout << t << " " << t << " " << 2 << " ";
        for (int i = 0; i < k-3; i++) cout << 1 << " ";
        cout << endl;
        return;
    }

    ll t = rem/2 -1;
    cout << t << " " << t << " ";
    for (int i = 0; i < 3; i++) cout << 2 << " ";
    for (int i = 0; i < k-5; i++) cout << 1 << " ";
    cout << endl;
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
