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
monotonic 
*/

void solve(){
    //val, pos
    stack<pair<int,int>> mono;
    mono.push(pair<int,int>(-1,0));

    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        while (mono.size()>1 && mono.top().F>=x){
            mono.pop();
        }
        cout << mono.top().S << " ";
        mono.push(pair<int,int>(x,i+1));
        
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