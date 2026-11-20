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

// make the MODE X 
// -> maintain X as mode as long as we can? 
// 1. add the MAX 
// n prefixes -> n modes 
// 4 4 3 3 3 3 1 1 1 
// spam all the max, f = freq[max]
// spam all numbers but with freq = f-1
// until its no longer possible, the you need a new mode to take over
// the second largest number, might not have enough to take over 
//
// freq < f -> can never take over
// sort desc 
// v1 . v2   v3 
// 
// 4 4 4 , 3 , 2 2 2 , 1 1 1 
// 
// 2 1 4 3 2 1 4 
//
// 3, 4 4 
// 4  4 4 
//
// 1. put f of MAX first 
// 2. put all frequencyes of max(fi, f)
// 2. 
//
// 1. take the person with the highest remaining and SPAM all 

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi b;
    for (auto& z:a) cin >> z;
    vi freq(101,0);
    vi added(101);
    for (auto& z:a) freq[z]++;
    int mx = MAX(a);
    int left = n;
    int mode = freq[mx];
    int cur = mx;

    while(left > 0 && cur >= 1){
        // add the current mode element
        while(added[cur] < freq[cur]){
            b.pb(cur);
            added[cur]++;
            left--;
            mode = freq[cur];
        }
        for (int i = 1; i < cur; i++){
            while(added[i] < mode && added[i] < freq[i]){
                b.pb(i);
                added[i]++;
                left--;
            }
        }
        for (int i = cur-1; i >= 1; i--){
            if (added[i] < freq[i]) {
                cur = i;
                break;
            }
        }
    }
    debug(a);
    debug(b);
    for (auto& z:b) cout << z << " ";
    cout << endl;
    // for (auto& z:a) freq[z]++;
    // int m = MAX(a);
    // for (int i = 0; i < freq[m]; i++){
    //     b.pb(m);
    //     freq[m]--;
    // }
    

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
