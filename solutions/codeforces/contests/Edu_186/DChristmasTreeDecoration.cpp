#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
constexpr ll MOD = 998244353;
#define endl '\n'

// ========== HELPER =================
ll fac[60];

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

ll inverse(ll num){
    return binpowmod(num,MOD-2,MOD);
}

ll ncr_mine(int n, int k){
    return fac[n] * inverse(fac[k]*fac[n-k] % MOD) % MOD;
}

void start(){ // precompute factorial
    fac[0] = 1;
    for (int x = 1; x <= 55; x++){
        fac[x] = (fac[x-1] * x % MOD);
    }
}

// ==========  SOLUTION ===============

void solve(){
    int n;
    cin >> n;
    vl a(n+1);
    for (auto& z:a) cin >> z;

    ll sum =0;
    for (auto& x:a) sum += x;
    ll mod = sum % n;  
    ll rounds = sum/n; 

    bool invalid = false;
    int count = 0; // count of rounds + 1
    for (int i= 1; i<n+1;i++){
        int x = a[i];
        if (x > rounds+1) invalid = true;
        else if (x == rounds+1) count++;

    }
    if (invalid || count > mod){
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    // mod PERMUATE count
    // = mod! divide by (mod - count)! = 
    // = mod! times modular_inverse((mod-conut)!)
    ans = ans * fac[mod] % MOD;
    ans = ans * inverse(fac[mod - count]) % MOD;
    // times the permutation of remaining people
    ans = ans * fac[n-count] % MOD;
    cout << ans << endl;
};


int main(){
    start();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
