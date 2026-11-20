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


// NOTE -> didnt think through the impl very well 
// instead of mapping to id 
// why not i store freq of values 
// bit -> cout of values 
// then when i want to remove a value 
// i just reduce the cout of value across all bits by 1 
// then the remainig space i just uyse the unusd values remaining easy
//
//
// we should make the id to the real id? 
//
//
// NOTE: direciotn has to change 
// its longest subsequence of bits 
// map each number to 32 bit strong right 
// then we want to query from i, which number has the longest string of bits 
// if its tied 110xxx 110xxx
// thne idk 
//


// NOTE:
// hint 1: only the first ~ LOG MAX mattters 
// ie. only the firtst ~ 30 values matter 
//

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto&z:a)cin>>z;
    int it = min(n, 32);
    int sor = 0;
    debug(a);
    for (int i = 0; i < it; i++){
        int mx = sor;
        int pos = i;
        for (int j = i; j < n; j++){
            int evl  = a[j] | sor;
            if (evl > mx){
                mx = evl;
                pos = j;
            }
        }
        debug(i, pos, a, mx, pos);
        sor = mx;
        swap(a[i], a[pos]);
        debug(a, sor);
    }
    for (int i = 0; i< n ;i++) cout << a[i] << " ";
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
