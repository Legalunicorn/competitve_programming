#include <bits/stdc++.h>
#include <queue>
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
// a[0] is already in the correct spot if that batters 
//kk// BUG: counter 
// he is picking up alot of unused balls each time 
// -> there should be some sort of divide and conquer involved
// -> Hence choose smallest "T1" and "T2" 
//  -> then 
//
// the overhead comes from repeatedly picking up balls that will go back to the same spot 
// NOTE:
// strategies 
// 1. fill up the heavy boxses first 
// 2. fill up the light boxes and give them 1x heavy weight
// k = 3 
// -> t1,t2 ,t3 + excess 
//
// the question is how to distribute? 
// NOTE: 
// ive proven with counter example we cant just distribute to max weight 
// but we need to split the weights some how 
// the optimal strategy is uncleary but i suspect its divide and conquer 
// 

// alternative MIGHT be binary search
// -> although i double so 


// he chooses EMPTY boxes as the output
// well isnt this just divide and conquery? 
// we recusivle split the load into 3 
// say we have bases {a,b,c} 
//
// i feel like this depends on the delta of b- a 
// NOTE: if we split into 2 bases, it literally does not 
// matter which goes where 
// the sum is the same 
// all the matters is should we spill to the next base? 

// NOTE:
// observatoin 
// if it has 3 items or less -> its fine to not spill 
// otherwise 4 or more items -> someone has to repeat twice 

// we can calculate how many times an item needs to be lifted? 
// min -> 1 
// every move we split into 3 
// log3(n) -> 
// maybe if we can somhoe w
// whatif its hella unbalanced 
// 1 1 1 1 1 1 1 1 1 100000 (!)
// then obviously we dont want to use the last element twice 
// -> we probably need to use the sums 
// i thin 

// NOTE:
// there is some splitting to bases 
// but with priority 
// if 2 * a[i] > a[i+1]

void solve(){
    int n;
    cin >> n;
    ll res = 0;
    priority_queue<ll, vl, greater<ll>> pq;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    while(pq.size()>1){
        if (pq.size()%2==0) pq.push(0);
        ll one = pq.top();
        pq.pop();
        ll two = pq.top();
        pq.pop();
        ll three = pq.top();
        pq.pop();
        ll s = one + two + three;
        res += s;
        pq.push(s);
    }
    cout << res << endl;

    // vl a(n);
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
