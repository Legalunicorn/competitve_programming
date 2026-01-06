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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


void solve(){
    int n,m;
    cin >> n >> m;
    vi a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    debug(a,b);

    // multiset<int> s1,s2;
    // for (auto& z:a) s1.insert(z);
    // for (auto& z:b) s2.insert(z);
    //
    // bool pt = 
    //

    
    priority_queue<int> p,q;
    for (auto& z:a) p.push(z);
    for (auto& z:b) q.push(z);


    bool pturn = true;
    while(p.size()>0 && q.size()>0){
        int x = p.top(); p.pop();
        int y = q.top(); q.pop();
        if (pturn){
            if (x>=y) p.push(x);
            else {
                p.push(x);
                q.push(y-x);
            }
        } else{
            if (y>=x) q.push(y);
            else{
                q.push(y);
                p.push(x-y);
            }
        }
        pturn = !pturn;
    }
    if (p.empty()) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    //





    // pq<int> q1,q2;
    // for (int i=0;i<n;i++) q1.push(a[i]);
    // for (int i=0;i<m;i++) q2.push(b[i]);
    // 

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
