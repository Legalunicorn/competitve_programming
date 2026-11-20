#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;
constexpr double PI = 3.14159265358979323846;

// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
// #define M_PI 3.14159265358979323846


void solve(){
    int n,q;
    cin >> n >> q;
    vector<ll> arr(n,0);
    for (ll& val: arr) cin >> val;

    ll len = (ll) sqrt(n+.0)+1;
    vector<ll> update(len), sum(len);

    //populate sum 
    for (int i=0;i<n;i++){
        sum[i/len] += arr[i];
    }

    while(q--){
        int id;
        cin >> id;
        if (id == 1){ // [a,b] +delta
            ll a,b,x;
            cin >> a >> b >> x;
            a--;b--;
            int lb = a/len, rb = b/len;
            if (lb==rb){
                for (int i=a;i<=b;i++){
                    sum[lb]+=x;
                    arr[i]+=x;
                }
            } else{
                for (int i=a,end=(lb+1)*len-1; i<=end;i++){
                    sum[lb] += x;
                    arr[i] += x;
                }
                for (int i= lb+1; i<=rb-1; i++){
                    sum[i] += x*len;
                    update[i] += x;
                }
                for (int i=rb*len; i<=b;i++){
                    sum[rb] += x;
                    arr[i] += x;
                }
            }

        } else if (id == 2){ // [a,b] = val
            ll a,b,x;
            cin >> a >> b >> x;
            a--; b--;
            int lb = a/len, rb = b/len;
            if (lb==rb){
                for (int i=a;i<=b;i++){
                    int diff = x-arr[i];
                    sum[lb] += diff;
                    arr[i] = x;
                } 
            } else{
                
            }

        } else{ // sum [a,b]

        }
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T =1;
    // cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}