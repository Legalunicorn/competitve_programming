#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

//to add pbds 

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;

// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair


/*
n-th harmonic number is the sum of the reciprocals of the first n naturla numbers 
1 + 1/2 + 1/3 + 1/4 

Mathematicians have shown that the sum of the first k reciprocals (1+1/2+1/3+
dots+1/k) grows roughly at the same rate as the natural logarithm of k (
ln(k)
*/

void solve(){
    int N = 1000001;
    vector<ll> divs(N,0);
    for (int i=1;i<N;i++){ //go from every number 1 -> N, i
        // go from EVERY multiple of i
        for (int j=i;j<N;j+=i){
            divs[j]++;
        }
        // if a numbre [x] is a multiple if [i] then j will reach it 
    }

    
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        cout << divs[x]  << endl;
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=1;
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