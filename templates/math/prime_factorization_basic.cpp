#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-15 22:28:18
File: prime_factorization_basic
Author: github@legalunicorn
Test status: 
Description: Basic prime factorization in sqrt(n) time complexity 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/

//SNIPPET_ID:prime_factorization_basic
vector<int> factor(int n){
    vector<int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res.push_back(i);
            n /= i;
        }
    }
    if (n>1) res.push_back(n);
    return res;
}

//END_SNIPPET:prime_factorization_basic


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



