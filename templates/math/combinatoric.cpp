#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-30 03:35:28
File: combinatoric
Author: taken from tin.le submission
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:combinatoric
// CHECK
const int MX = 1e5+5;
template<class T>
class Combinatoric {
    public: 
    int N;  
    vector<T> fact, inv;
    Combinatoric(int _N) : N(_N) {
        fact.resize(N + 1), inv.resize(N + 1);
        init();
    }

    void init() {
        fact[0] = 1;
        for(int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i;
        }
        inv[N] = fact[N].inv();
        for(int i = N - 1; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1);
        }
    }

    T nCk(int a, int b) {
        if(a < b) return 0;
        return fact[a] * inv[b] * inv[a - b];
    }
 
    T nPk(int n, int k) {
        if (k < 0 || k > n) return 0; 
        return fact[n] * inv[n - k];
    }
 
}; 
// Combinatoric<mint> comb(MX-1);
//END_SNIPPET:combinatoric


// FOR TESTING 
void solve(){
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    return 0;
}



