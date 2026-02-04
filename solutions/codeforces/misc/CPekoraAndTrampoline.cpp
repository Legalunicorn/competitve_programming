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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// we can redice a[i] to n 
// but now if we try to brute force, its n^2 per index 
// making it n^3 for the whole array 
// there is a chance that due to some funny constraints, 
// it would actuall reach n^3, and be bounded smaller 
//
// suppose a[i] = n for all i 
//
// [1k, 1k, 1k, 1k, 1k, ... 1000]
// the sum is bounded by n^2, 
// its probabilty greedy just hard to prove 
// greedy + simulation as well 
// how to avoid tle though? 
//
// read the editorial
// still dont understand shit
// im skipping this 

void solve(){
    int n;
    cin >> n;
    vl a(n);
    ll res = 0;
    vl temp(n+5,0);
    int start = 0;

    cout << res << endl;
    // for (int i=0;i<n;i++){
    //     if (a[i]>1) {
    //         start = i;
    //         break;
    //     }
    // }
    // // we are claculate how many jumps to START 
    // //
    // for (int i = start; i<n; i++){
    //     res += max(0, a[i] - peron[i] - 1);
    //     int left = i + 2;
    //     int right = min(m, i + a[i]);
    //     for (; left <= right; left++){
    //         peron[left]++;
    //         peron[min(n-1,i+1)] += max(0LL, person[i] - a[i]-)
    //     }
    // }
    //
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
