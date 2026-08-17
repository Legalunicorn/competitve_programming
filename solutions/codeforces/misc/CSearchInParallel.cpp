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
// i think the only way to solve is to formalize this 
// and solve mathly 
// we have two list
// then we will prefix sum it 
// then we will sum THAT 
// and we want to minimise the output from both lists 
//
// its woth noting the list with smaller "s" will have 
// at most half the elements, otherwise we can greedily swap lists 
//
//
// i think we can consider all lengths of a,b 
// then use math to miniimse the answer 


// NOTE: READING Editorial :(  
//
//  how the hell did they reduce this to Sigma( ai * bi) where 
//  both array are length m 
//
//  I MISINTERPRETED THE FUCK OUT OF THIS PROBLEM

// NOTE:
// DO NOT greedily minimise (sum1 vs sum2)
// the goal is to minimise total sum, hence we compared deltas
void solve(){
    int n; cin >> n;
    ll s1, s2; cin >> s1 >> s2;
    vpl a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].F;
        a[i].S = i +1;
    }
    sort(all(a));
    reverse(all(a));

    ll sum1 = 0, sum2 = 0;
    vl r1, r2;
    for (int i = 0; i < n; i++){
        ll x = a[i].F;
        ll one =  (r1.size()+1) * s1;
        ll two =  (r2.size()+1) * s2;
        if (one <= two){
            sum1 += one;
            // c1 += x;
            r1.pb(a[i].S);
        } else{
            sum2 += two;
            // c2 += x;
            r2.pb(a[i].S);
        }
    }
    cout << r1.size() << " ";
    for (auto& r: r1) cout << r << " ";
    cout << endl;
    cout << r2.size() << " ";
    for (auto& r: r2) cout << r << " ";
    cout << endl;
    // just greedily add them
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
