#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int  main(){
    string s;
    cin >> s;
    int n = s.size();
    ll mod = 998244353, res = 0;
    vl sums(3, 0);
    for (int i = n; i >= 1; i--){
        ll evl = 1;
        int k = s[i-1]-'a';
        for (int j = 0; j < 3; j++){
            if (j != k) evl  = (evl +  sums[j]) % mod;
        }
        sums[k] = (sums[k] + evl) % mod;
        res = (res + evl) % mod;
    }

    cout << res << "\n";
};

