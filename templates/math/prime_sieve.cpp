#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-11-30 17:13:42
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



vector<bool> gen_sieve(int N){
    vector<bool> prime(N+1, true);    
    prime[0] =  prime[1] = false;
    for (int i = 2; i*i <= N ;i++){
        if (prime[i] && (ll)i*i <= N){
            for (int j=i*i; j<= N; j+=i){
                prime[j] = false;
            }
        }
    }
    return prime;
};

// use sieve to generate primes up to n 
vector<int> gen_primes(int n){
    vector<bool> primes = gen_sieve(n);
    vector<int> res;
    for (int i=2;i<=n;i++){
        if (primes[i]) res.push_back(i);
    }
    return res;
};

vector<int> prime_factors(int n){
    int m = (int)ceil(sqrt(n+.01));
    vector<int> res;
    vector<int> prime_list = gen_primes(m);
    for (int p: prime_list){
        if (p*p>n) break;
        while(n%p == 0){
            res.push_back(p);
            n /=p;
        }  
    }
    if (n>1){
        res.push_back(n);
    }
    return res;
}


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