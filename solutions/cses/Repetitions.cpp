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
    string s;
    cin >> s;
    int n = s.size();
    int curr = 1;
    int res = 1;
    for (int i=1;i<n;i++){
        if (s[i]==s[i-1]){
            curr++;
            res = max(res,curr);
        } else{
            curr = 1;
        }
    }
    cout << res << endl;
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