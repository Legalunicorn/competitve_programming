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


// geometric sequence -> common ratio of "r" 
// ok sounds familiar 
// 1. sort the array by abs value 


void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a),[&](const auto& p, const auto& q){
        return abs(p) < abs(q);
    } );
    debug(a);

    set<ll> st;
    for (auto& x: a){
        st.insert(abs(x));
    }
    if (st.size() ==1 ){
        int neg = 0;
        int pos = 0;
        for (auto& x :a){
            if (x < 0) neg++;
            else pos++;
        }
        if (neg > pos) swap(neg,pos);
        debug(neg);
        // neg == low 
        if (abs(pos-neg)<=1 || pos==0 || neg == 0){
            cout << "Yes" << endl;
        } else cout << "No" << endl;
        return;
    }
    if (st.size()<n){
        cout << "No" << endl;
        return;
    }


    for (int i=0; i+2< n; i++){
        ll x = a[i+1]*a[i+1];
        ll y = a[i] * a[i+2];
        debug(x,y);
        if (x!=y){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;

    







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
