#include<bits/stdc++.h>
using namespace std;

/*-------------------------- DEBUG -------------------------*/
void debug(){cerr<<'\n';}

template<typename T> auto is_iterable(int)->decltype(begin(declval<T>()),true_type{});
template<typename T> false_type is_iterable(...);
template<typename T> auto is_pair(int)->decltype(declval<T>().first,declval<T>().second,true_type{});
template<typename T> false_type is_pair(...);

template<typename T>
void print(const T& x){
    if constexpr(decltype(is_iterable<T>(0))::value && !is_same_v<T,string>){
        if constexpr(decltype(is_pair<typename T::value_type>(0))::value){
            cerr<<"{\n";
            for(auto& it:x) cerr<<"  "<<it.first<<" : "<<it.second<<'\n';
            cerr<<"}";
        }else{
            cerr<<"[ ";
            for(auto& e:x) print(e), cerr<<" ";
            cerr<<"]";
        }
    }else if constexpr(decltype(is_pair<T>(0))::value)
        cerr<<"{ "<<x.first<<" : "<<x.second<<" }";
    else cerr<<x;
}

template<typename T>
void debug(const string&, const vector<vector<T>>& a){
    for(const auto& row : a){
        for(const auto& x : row) cerr << x << " ";
        cerr << '\n';
    }
}

template<typename T,typename... Args>
void debug(const string& n,const T& v,Args... a){
    cerr<<n<<" = "; print(v);
    if constexpr(sizeof...(a)) cerr<<" | ";
    debug(a...);
}

/*-------------------------- INPUT OUTPUT Vectors -------------------------*/
template<typename T> void inputvec(vector<T>& v){for(auto& x:v) cin>>x;}
template<typename T,typename U> void inputvec(vector<pair<T,U>>& v){for(auto& p:v) cin>>p.first>>p.second;}

template<typename T> void printvec(const T& v){ for(const auto& x:v) cout<<x<<" "; cout<<"\n"; }
template<typename T,typename U> void printvec(const vector<pair<T,U>>& v){ for(const auto& p:v) cout<<p.first<<" "<<p.second<<"\n"; }

/*------------------------- MACROS ------------------------------*/
using ll = long long;
using str = string;
const ll M = 1e9+7;
#define forp(i,a,b) for(ll i=a; i<b; i++)
#define forn(i,a,b) for(ll i=a; i>=b; i--)
#define even(x) ((x)%2==0)
#define inv(x) modpow((x), M-2)
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yepp cout<<"YES"<<'\n'
#define nope cout<<"NO"<<'\n'
#define yepps cout<<"Yes"<<'\n'
#define nopes cout<<"No"<<'\n'

/* ------------------------ CONTAINERS --------------------------*/
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define mll map<ll,ll>

/*-------------------------- FUNCTIONS -------------------------*/

bool isSquare(ll x) { return (ll)sqrt(x)*(ll)sqrt(x) == x; }

ll ceil(ll x, ll y) { return (x+y-1)/y; }

ll log2(ll x) { return x ? 63-__builtin_clzll(x) : -1; }

// sort(all(v), [](const auto& a, const auto& b){
//     if(a.first != b.first) return a.first < b.first;
//     return a.second > b.second;
// });

bool isPrime(ll n) {
    if(n<=1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2) == 0)  return false;
    }
    return true;
}

vector<ll> primeFactors(ll n) {
    vector<ll> f;
    for(ll i=2; i*i<=n; i++){
        while(n%i == 0){
            f.pb(i);
            n /= i;
        }
    }
    if(n>1) f.pb(n);
    return f;
}

vector<ll> divisors(ll n) {
    vector<ll> d;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            d.pb(i);
            if(i!=(n/i)) d.pb(n/i);
        }
    }
    sort(all(d));
    return d;
}

string toBinary(ll x) {
    if(x==0) return "0";
    string s;
    while(x){
        s.pb('0' + (x&1));
        x >>= 1;
    }
    reverse(all(s));
    return s;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res = (res*a);
        a = (a*a);
        b >>= 1;
    }
    return res;
}

/*------------------------ Solution --------------------------*/

bool adj(ll a, ll b){
    if(a==b || a+b==7) return true;
    else return false;
}

void solve(){
    ll n;
    cin>>n;
    vll v(n);
    inputvec(v);
    if(n==2){
        if(adj(v[0], v[1])) cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    ll ans = 0;
    // forp(i,1,n-1){
    //     if(adj(v[i], v[i-1]) || adj(v[i], v[i+1])){
    //         forp(j,1,7){
    //             if(!adj(j, v[i-1]) && !adj(j, v[i+1])){
    //                 v[i] = j;
    //                 i++;
    //                 break;
    //             }
    //         }
    //         ans++;
    //     }
    // }
    forp(i,0,n-1){
        if(adj(v[i], v[i+1])){
            ans++;
            i++;
        }
    }
    // debug("v",v);
    cout<<ans<<endl;
}

/*--------------------------------------------------------------*/
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t; while(t--) 
        solve();
    return 0;
}
