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


// -1 -> 0 or 1 
// 10001001001001 
// why would u every choose to put a "1" ? unless there are 
// we can  cheese this with dp
//
// but the easy soluition is 
// if there are "1" and "1" to the L and R never choose 1 
// we need to mark OR create the left most, right most "1" 
// the edge case is that ONLY one "1" and "-1" then the answerm ust be 0 

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    // find left
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) break;
        else if (a[i] == -1){ // greedy set right? a zero here does no good
            a[i] = 1;
            break;
        }
    }
    for (int i = n -1; i >= 0; i--){
        if (a[i] == 1) break;
        else if (a[i] == -1) {
            a[i] = 1;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] == -1) a[i] = 0;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
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
