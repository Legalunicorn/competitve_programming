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


void solve(){
    int n;
    cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return;
    }
    if (n<4) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (n%4>=2){
        cout << n-((n%4)-2) << " ";
    }
    for (int i=0;i<(n/4);i++){
        int v = i*4;
        cout << v+2 << " " << v+4 << " " << v+1 << " " << v+3 << " ";
    }
    if (n%4>=1) cout << n-(n%4)+1 << " ";
    if (n%4==3) cout << n << " ";

};
/*
2413

 (10) 2413 6857 (9) (11)  --3 (-1)
 (10) 2413 6857 (9)       --2 (-0)
      2413 6857 (9)


      0 1 2, 

i believe every number greater than n has a solution? 

proof:

group the number into pairs 
i+1, i+3, i, i+2
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