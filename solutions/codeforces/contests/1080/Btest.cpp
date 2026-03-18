#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using vll = vector<long long>;
using vb = vector<bool>;
using vin = vector<int>;
using pll = pair<ll,ll>;
using mpll = map<ll,ll>;
using sl = set<ll>;
using usl = unordered_set<ll>;
#define F first
#define S second
#define pb push_back
#define I insert
#define E erase
#define sz(v) (ll)v.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f(i,x,n) for(int i=(x); i<(n); i++)
#define printall(x) for(auto& val:(x)) cout<<val<<" ";
vll primes;
void sieve(ll n, vll& lp) {
    lp.assign(n + 1, 0);
    vll pr;
    lp[1] = 1;
    f(i, 2, n + 1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int p : pr) {
            if (p > lp[i] || 1LL * i * p > n) break;
            lp[i * p] = p;
        }
    }
}

ll mfact(ll k, vll& lp) {
    ll v=1;
    while (k > 1) {
        v=max(v, lp[k]);
        k /= lp[k];
    }
    return v;
}
void solve(){
	ll n; cin>>n;
	vll v(n+1); f(i,1,n+1) cin>>v[i];
	bool valid=true;
	f(j,1,n+1){
		ll x=mfact(v[j], primes);
		ll y=mfact(j, primes);
		if(x==y||(x==1&&y==2)||(x==2&&y==1)){}
		else valid=false;
	}
	if(valid) cout<<"YES\n"; else cout<<"NO\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve(200001, primes);
	int t=1; 
	cin>>t;
	while(t--) solve();
	return 0;
}
