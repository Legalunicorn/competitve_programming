#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2026-01-07 21:26:40
File: prime_sieve
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:prime_sieve
int MAXN = (int)(3e5+5);
vector<bool> is_prime(MAXN, true);
vector<int> primes;
void init_sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i<= MAXN ; i++){
        if (is_prime[i] && (ll)i * i  <= MAXN){
            for (int j = i *i ; j <= MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
    // for (int i=2; i<=MAXN;i++) {
    //     if (is_prime[i]) primes.push_back(i);
    // }
};

vector<int> trial_div(int n){
    vector<int> fac;
    for (auto& d: primes){
        if (d* d > n) break;
        while(n% d == 0){
            fac.push_back(d);
            n /= d;
        }
    }
    if (n>1) fac.push_back(n);
    return fac;
}
//END_SNIPPET:prime_sieve


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



