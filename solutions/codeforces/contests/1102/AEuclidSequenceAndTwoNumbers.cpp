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
    vi a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    reverse(all(a));
    int x = a[0], y = a[1];
    int valid = false;
    for (int i = 2; i < n; i++){
        int need = x % y;
        if(a[i] != need) {
            cout << -1 << endl;
            return;
        }
        x = y;
        y = need;
    }
    cout << a[0] << " " << a[1] << endl;
    // if (n == 2){
    //
    // }
    // map<int,int> mp;
    // for (auto& z:a) mp[z]++;
    // for (int i = 0; i < n; i++){
    //     for (int j = i+1; j < n; j++){
    //         map<int,int> freq = mp;
    //         freq[a[i]]--;
    //         freq[a[j]]--;
    //         // we need to build the sequence 
    //         bool valid = true;
    //         int low = min(a[i],a[j]);
    //         int high = max(a[j], a[i]);
    //         int x= high, y = low;
    //         int cur = high;
    //         debug(x,y);
    //         for (int k = 0; k + 2 < n; k++){
    //             int need = high % low;
    //             debug(need);
    //             if (freq[need] <= 0){
    //                 valid = false;
    //                 break;
    //             } else{
    //                 freq[need]--;
    //                 int temp = low;
    //                 high = low;
    //                 low = need;
    //             }
    //         }
    //         if (valid){
    //             cout << x << " " << y << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << -1 << endl;
    // just try any two numbers
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
