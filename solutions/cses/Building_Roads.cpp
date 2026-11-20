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

int cnt;

int find(int a, vector<int>& par){
    if (par[a]==a) return a;
    else return par[a] = find(par[a],par);
}

void join(int a, int b, vector<int>& par, vector<int>& rank){
    a = find(a,par);
    b=  find(b,par);
    if (a==b) return;
    cnt--; //minus the number of groups 
    if (rank[a]<rank[b]) swap(a,b);
    par[a] = b;
    if (rank[a]==rank[b]) rank[b]++;
}


void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> par(n),rank(n);
    for (int i=1;i<n;i++) par[i] = i;
    cnt = n; 
    // i indexes 
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        join(a,b,par,rank);
    }
    cout << cnt-1 << endl;
    set<int> grps;
    for (int i=0;i<n;i++){
        // cerr << find(i,par) << endl;
        grps.insert(find(i,par));
    }
    int prev = -1;
    for (int s : grps){
        // s + prev 
        if (prev==-1){
            prev = s;
        } else{
            cout << prev+1 << " " << s+1 << endl;
        }
    }

};
/*
1. find the number of components (DSU) -1 
*/


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