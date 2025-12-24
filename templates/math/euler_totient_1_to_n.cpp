#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-15 22:41:31
File: fast_euler_totient
Author: https://cp-algorithms.com/algebra/phi-function.html#etf_1_to_n
Test status: 
Description: Euler totient functions from 1 to n in O(n log log n) 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:euler_totient_1_to_n
void phi_1_to_n(int n){
    vector<int> phi(n+1);
    for (int i=0;i<=n;i++) phi[i] = i;
    for (int i=2;i<=n; i++){
        if (phi[i] == i){
            for (int j=i; j<=n ; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}

//END_SNIPPET:euler_totient_1_to_n


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



