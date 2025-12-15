#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-15 22:38:19
File: euler_totient_phi
Author: Takeb from cp-algorithims https://cp-algorithms.com/algebra/phi-function.html
Test status: 
Description: Computes Phi in Sqrt root (n)
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:euler_totient_phi
int phi(int n){
    int res = n;
    for (int i=2; i*i <=n ;i++){
        if (n % i == 0){
            while( n% i ==0) n/=i;
            res -= res/i;
        }
    }
    if (n > 1) res -= res/n;
    return res;
}

//END_SNIPPET:euler_totient_phi


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



