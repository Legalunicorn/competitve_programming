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

// #define endl '\n' 
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

// if at any point two indexes are the same 
// we found a 0 

// difference -> one COULD be 0 , both could be numbers 
// it makes sense that we try many different pairs 
//
// if we make n-1 queries 
// we guantee at least 1 if the remaining 2 itens is a "0" 
// then we can just pick a random pair 
//
// {0,0} or {0,1} 
//
// then random pair is {zero, nonzero] }
// then we just need to try one random with another pair 
// if both different the otherh


void solve(){
    int n;
    cin >> n;
    // 1,2   3,4.. 4,5 .. 2n-1, 2n
    for (int i = 1; i <= n-1; i++){
        int l = 2*i -1;
        int r = l + 1;
        cout << "? "<< l << " " << r << endl;
        int evl; 
        cin >> evl;
        if (evl == 1){ // l == r  <->  l==0 && r ==0
            cout << "! " << l << endl;
            return;
        }
    }
    int x = 2*n - 1;
    int y = 2 *n;
    int evl;

    cout << "? " << x << " " << 1 << endl;
    cin >> evl;
    if (evl == 1){
        cout << "! " << x << endl;
        return;
    } 

    cout << "? " << x << " " << 2 << endl;
    cin >> evl;
    if (evl == 1){
        cout << "! " << x << endl;
        return;
    }
    // must be y 
    cout << "! " << y << endl;



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
