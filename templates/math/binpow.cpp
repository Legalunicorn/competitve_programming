#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-07 21:32:31
File: binpow
Author: github@legalunicorn
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:binpow_unbound
ll binpow(ll a, ll b){
    ll res = 1;
    while(b>0){
        if (b & 1) res = res *a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//END_SNIPPET:binpow_unbound

//SNIPPET_ID:binpow_mod
ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}
//END_SNIPPET:binpow_mod

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



