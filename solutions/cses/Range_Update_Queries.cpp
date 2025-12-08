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


//Lets try with sqrt decomposition 
//Its also possible with lazy propagation segment trree

void update(vector<int>& b){

}
void solve(){
    int n,q;
    cin >> n >> q;
    //get the input
    vector<ll> arr(n,0);
    for (ll&z :arr) cin >> z;

    //preprocessing 
    //size of blocsk + no of blocsk
    ll len = (ll) sqrt(n+.0)+1;
    // cout << "len is: " << len << endl << endl;
    vector<ll> blocks(len);

    while(q--){     
        ll id;
        cin >> id;
        if (id==1){ //incremenet range by u 
            ll a,b,u;
            cin >> a >> b >> u;
            a--;
            b--;
            ll l = a/len;
            ll r = b/len;
            if (l==r){
                for (ll i=a;i<=b;i++) arr[i]+=u;
            } else{
                //end -> move to the start of the next block, minus one
                for (ll i=a, end=((l+1)*len)-1;i<=end;i++){
                    arr[i]+=u;
                }
                for (ll i=l+1;i<=r-1;i++){
                    blocks[i]+=u;
                }
                for (ll i=len*r;i<=b;i++){
                    arr[i]+=u;
                }
            }

        } else{
            ll x; 
            cin >> x;
            x--;
            cout << arr[x]+blocks[x/len] << endl;
        }
    }

    //Answer queries? 

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