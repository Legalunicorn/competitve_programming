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

// NOTE: 
// didnt see: each cell has a max of 1 card 
//
// we need to rearrange the permutation 
// we can map the position 
// for each number, there are x numbers above it 
// what we care about is 
//  - of all the numbers above it, how many is less 
//  - we need at least nm -2 cell free
//  
//  how to answer queries? 
//  map position? 



void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    vl a(k);
    vb placed(k+1); // what is this for ? 
    for (auto& z:a) cin >> z;

    ll free = n * m - 2;
    ll cur = k;

    for (int i = 0; i < k; i++){
        if (cur == a[i]){
            if (free <= 1){
                cout << "TIDAK" << endl;
                return;
            } else {
                free--;
                placed[cur] = true;
                while(cur >=1 && placed[cur]){
                    placed[cur] = false;
                    cur--;
                    free++;
                }
            }
        } else {
            if (free <= 1){
                cout << "TIDAK" << endl;
                return;
            } else {
                free--; // place on arbitarary free block
                placed[a[i]] = true; // we place this 
            }
        }
        debug(i, free);
    }
    cout << "YA" << endl;
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
